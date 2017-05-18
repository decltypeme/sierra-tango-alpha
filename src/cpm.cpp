#include <vector>
#include <algorithm>
#include <string>

#include "cpm.h"
#include "netlist.h"
using namespace std;
using namespace utils;
using namespace liberty;


delay_t get_transtion_time (string cell_type, delay_t input_transition_time,cap_t output_cap, const Library &l)
{
    if (cell_type == "clk" || cell_type == "START") return 0;
    else
    {
        Cell c = l.getCell(cell_type);
        vector<Pin> pins = c.getPins();
        delay_t max_t = 0;
        for (Pin p: pins)
        {
            if(p.getDirection())
            {
                delay_t value;
                vector<Timing> tables = p.getTiming();
                Table t = tables.front().getRiseTransitionTable();
                value = t.getValue(output_cap,input_transition_time);
                max_t = max(value,max_t);
                t = tables.front().getFallTransitionTable();
                value = t.getValue(output_cap,input_transition_time);
                max_t = max(value,max_t);
            }
        }
        return max_t;
    }
}

delay_t get_cell_time(string cell_type, delay_t input_transition_time,cap_t output_cap, const Library &l)
{
    if (cell_type == "clk" || cell_type == "START") return 0;
    else
    {
        Cell c = l.getCell(cell_type);
        vector<Pin> pins = c.getPins();
        delay_t max_t = 0;
        for (Pin p: pins)
        {
            if(p.getDirection())
            {
                delay_t value;
                vector<Timing> tables = p.getTiming();
                Table t = tables.front().getCellFallTable();
                value = t.getValue(output_cap,input_transition_time);
                max_t = max(value,max_t);
                t = tables.front().getCellRiseTable();
                value = t.getValue(output_cap,input_transition_time);
                max_t = max(value,max_t);

            }
        }
        return max_t;
    }
}

cap_t get_input_pin_cap(string cell_type, const Library &l)
{
    if (cell_type == "clk" || cell_type == "START") return 0;
    else
    {
        Cell c = l.getCell(cell_type);
        vector<Pin> pins = c.getPins();
        cap_t max_c = 0;
        for (Pin p: pins)
        {
           if(p.getDirection()) max_c = max(p.getCapacitance(),max_c);
        }
        return max_c;
    }
}

void put_AAT(const Library &l, DAG &g)
{

    for(node &_n:g.nodes)
    {
        _n.input_transition_time=*max_element(_n.input_transition_time_list.begin(),_n.input_transition_time_list.end());

        for(edge &_e:_n.edges)
        {
            cap_t output_cap = get_input_pin_cap(_e.n->cell_type,l) + _e.net_capacitence;
            _n.output_cap_list.push_back(output_cap);
            delay_t transition_time = get_transtion_time(_n.cell_type,_n.input_transition_time,_n.output_cap,l);
            (_e.n->input_transition_time_list).push_back(transition_time);
        }
        _n.output_cap=*max_element(_n.output_cap_list.begin(),_n.output_cap_list.end());
        //unordered_map<string, cap_t> 
        //cap_map_t
        _n.AAT=get_cell_time(_n.cell_type,_n.input_transition_time,_n.output_cap,l);
    }
}

int main(int argc, char ** argv)
{
    DAG g;
    ifstream netlist;
	ifstream caplist;

    netlist.open(argv[2], std::ifstream::in);
	caplist.open(argv[3], std::ifstream::in);
    parse_netlist(netlist,caplist,g);

    Library l = parse(argv[1]);
    put_AAT(l,g);
	vector<node> critical = getCriticalPath(g);

}
