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
    if (cell_type.empty()) return 0;
    else
    {
        Cell c = l.getCell(cell_type);
        vector<Pin> pins = c.getPins();
        delay_t max_t = 0;
        for (Pin p: pins)
        {
            if(p.getDirection())
            {
                
                //transistion time is max of rise and fall
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
    if (cell_type.empty()) return 0;
    else
    {
        Cell c = l.getCell(cell_type);
        vector<Pin> pins = c.getPins();
        delay_t max_t = 0;
        for (Pin p: pins)
        {    // o/p pin
            if(p.getDirection())
            {
                // max of fall,rise delay of o/p pin
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
    if (cell_type.empty()) return 0;
    else
    {
        Cell c = l.getCell(cell_type);
        vector<Pin> pins = c.getPins();
        cap_t max_c = 0;
        for (Pin p: pins)
        {
            //max cap of o/p pins
           if(p.getDirection()) max_c = max(p.getCapacitance(),max_c);
        }
        return max_c;
    }
}


void print_path_report_header(ostream& outs){
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Pin \t\t\t Type \t\t\t Increment \t\t\t Path Delay \t\t\t " << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}

void print_path_report_footer(ostream& outs, const delay_t& total_path_delay){
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Data Arrival Time \t\t\t\t\t\t\t\t\t" << total_path_delay << endl;
}

void print_node_report(ostream& outs, node* node_report_ptr, delay_t path_delay_so_far){
    cout << "Pin \t\t\t" << node_report_ptr->type << " \t\t\t" << node_report_ptr->node_delay << "\t\t\t" << path_delay_so_far << "\t\t\t " << endl;
}


/**
 * Return path delay
 * IMPORTANT: WHEN USING THIS, NODE DETAILS WILL BE OVERWRITTEN BY DATA SPECIFIC TO THIS PATH.
 */

delay_t put_AAT(const Library &l, DAG &g, vector<node> analysis_path, ostream& outs)
{
    print_path_report_header(outs);
    delay_t path_delay = 0;
    for(node &_n:analysis_path.nodes)
    {
        switch(_n.type){
            case NODE_T::IN :{                                      //If input node
                //Delay from file
                _n.transition_time =0;
                _n.node_delay = g.getDelayConstraint(_n.name);     //In case of input port, the transition is the same as the delay
            }
            case NODE_T::OUT : {
                //Previous transition time 
                g.getAssignInputTransition(&_n, l);
                //Capacitance from fan-out nodes
                g.getAssignOutCapacitance(&_n, l);
                //Assign output node delay
                _n.cell_delay=get_cell_time(_n.cell_type,_n.input_transition_time,0,l);
            }
            default:{
                //Previous transition time 
                g.getAssignInputTransition(&_n, l);
                //Capacitance from fan-out nodes
                g.getAssignOutCapacitance(&_n, l);
                //Assign Cell Delay
                _n.cell_delay=get_cell_time(_n.cell_type,_n.input_transition_time,_n.output_cap,l);
            }
        }   //End of the switch statement
        //Increment the total path delay
        path_delay+= _n.node_delay;
        print_node_report(outs, &_n, path_delay);
    }//End of path analysis
    print_path_report_footer(outs, path_delay);
    return path_delay;
}

vector<node> getCriticalPath(const DAG &g)
{
	return vector<node>();
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


void Identitfy_violation(std::vector<path> paths) {
//enum PATH_T {NA = -1, IR, RR, RO, IO};
for(path p: paths.size())
{
    if(p.pathtype==PATH_T::IR)
    {
        //using update path vector which has delays calculated for each node !!
        //Setup:
       // T ≥ Tpd + InputDelay + OutputDelay − Tskew 
         //Hold:
        // Tskew +Thold < InputDelay + Tpd
    }
    else if(p.pathtype==PATH_T::RR){
       // Setup:
        //T≥Tpd +Tcq +Tsetup−Tskew 
        //Hold:
       // Tskew +Thold < Tcq + Tpd
        
    }
    else if (p.pathtype==PATH_T::IO)
    {
        //Setup:
        //T ≥ Tpd + InputDelay + OutputDelay − Tskew
        
    }
    else  //RO
    {
       // Setup:
         //   T ≥ Tpd + InputDelay + OutputDelay − Tskew 
        //Hold:
          //  Tskew +Thold < InputDelay+ Tpd
        
    }
    
}
}
