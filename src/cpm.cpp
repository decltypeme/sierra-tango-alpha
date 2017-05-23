#include <vector>
#include <algorithm>
#include <string>

#include "cpm.h"
#include "netlist.h"
#include "../libertyparser-1.0/src/liberty.h"

using namespace std;
using namespace utils;
using namespace liberty;

delay_t get_transtion_time (string cell_type, delay_t input_transition_time,cap_t output_cap,  Library &l)
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

delay_t get_cell_time(string cell_type, delay_t input_transition_time,cap_t output_cap,  Library &l)
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

cap_t get_input_pin_cap(string cell_type,  Library &l)
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

void print_path_report_footer(ostream& outs,  delay_t& total_path_delay){
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

delay_t put_AAT( Library &l, DAG &g, path analysis_path, ostream& outs)
{
    print_path_report_header(outs);
    delay_t path_delay = 0;
    for(node* (__n):analysis_path.flow)
    {
        node& _n = *__n;
        switch(_n.type){
            case NODE_T::IN :{                                      //If input node
                //Delay from file
                _n.input_transition_time =0;
                _n.node_delay = g.getDelayConstraint(_n.name,g);     //In case of input port, the transition is the same as the delay
            }
            case NODE_T::OUT : {
                //Previous transition time
                g.getAssignInputTransition(&_n, l);
                //Capacitance from fan-out nodes
                g.getAssignOutCapacitance(&_n, l);
                //Assign output node delay
                _n.node_delay=get_cell_time(_n.cell_type,_n.input_transition_time,0,l);
            }
            default:{
                //Previous transition time
                g.getAssignInputTransition(&_n, l);
                //Capacitance from fan-out nodes
                g.getAssignOutCapacitance(&_n, l);
                //Assign Cell Delay
                _n.node_delay=get_cell_time(_n.cell_type,_n.input_transition_time,_n.output_cap,l);
            }
        }   //End of the switch statement
        //Increment the total path delay
        path_delay+= _n.node_delay;
        print_node_report(outs, &_n, path_delay);
    }//End of path analysis
    print_path_report_footer(outs, path_delay);
    return path_delay;
}

void analyzePrintPathReports( liberty::Library &l, DAG &g, vector<path>& all_paths, ostream& outs){
  for (path path:all_paths){
    put_AAT(l, g, path, outs);
  }
}

//TODO: Implement this
path getCriticalPath( DAG &g)
{
  //TODO:
	return path();
}
//TODO: Implement this
/*
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
*/

delay_t getDelayConstraint( string& node_name, DAG& g){
    auto it = g.delay_map.find(node_name);                    //Let's pray the compiler would get it
    if(it != g.delay_map.end()){
        return (*it).second;
    }
    else{
        cerr  << "Couldnot retrieve delay from delay constraint map: " << node_name << endl;
        exit(EXIT_FAILURE);
    }
}


cap_t getAssignInputTransition(node* in_node,  Library &l, DAG& g){
    //Iterate over all the previous nodes
    //Compute their transition time
    //Return the maximum
    for(string in_node_name: in_node->in_nodes){                                      //Over all in_node names
        node* node_ref = g.getNodeByName(in_node_name);                     //Get a reference to this node
        //Compute its transition time
        //TODO: Make sure this is working!
        delay_t transition_time = get_transtion_time(node_ref->cell_type,node_ref->input_transition_time,node_ref->output_cap,l); 
        in_node->input_transition_time_list.push_back(transition_time);
    }
    //Find the maximum element
    auto it = max_element(in_node->input_transition_time_list.begin(),in_node->input_transition_time_list.end());
    if(it != in_node->input_transition_time_list.end()){
        return in_node->input_transition_time = *it;
    }
    else{
        cerr << "Warning: Calling the transition counting on an input node\n"; 
        return 0;
    }
    
}

cap_t getAssignOutCapacitance(node* in_node,  Library &l, DAG &g){
    in_node->output_cap = 0;
    for(edge _e:in_node->out_edges){
        node* node_ref = g.getNodeByName(_e.n);
        in_node->output_cap += (get_input_pin_cap(node_ref->cell_type,l) + _e.net_capacitance);
    }
    return in_node->output_cap;
}
