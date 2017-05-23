#include "DAG.h"
#include <algorithm>

std::string NODE_T_NAMES []= {"IN","OUT","CELL","FFD","FFQ","START"};
std::string PATH_NAMES []= {"I-R","R-R","R-O","I-O"};

PATH_T get_path_type( std::string &s,  NODE_T& start_node_type,  NODE_T& end_node_type)
{
    if(s == "clk" && end_node_type == FFD)
        return RR;
    else if(s == "clk" && end_node_type == OUT)
        return RO;
    else if(start_node_type == IN && end_node_type == FFD)
        return IR;
    else if(start_node_type == IN && end_node_type == OUT)
        return IO;
    else return NA;
}

DAG::DAG()
{
    nodes.push_back(node(string("START"),START));
}

DAG::~DAG(){}

node* DAG::getNodeByName(std::string NodeName) {
    for(node &n:nodes)
    {
        if(n.name==NodeName)
            return &n;
    }
    return nullptr;
}
//TODO: Add the capacitance as optiona parameter to the function join
void DAG::join(std::string edgeName, std::string n1,std::string n2){

    node *n1_n= getNodeByName(n1);
    node *n2_n= getNodeByName(n2);
    if(n1_n == nullptr || n2_n == nullptr){
        throw(std::string("one of the calls to getNodeByName returned a nullptr"));
    }
   //add cap
	auto cap = cap_map.find(edgeName); //*
    if(cap != cap_map.end()) {
        n1_n->out_edges.push_back(edge(edgeName,n2_n->name,cap->second));
    }
	else
	{
        n1_n->out_edges.push_back(edge(edgeName, n2_n->name));
	}
}

delay_t DAG::getDelayConstraint( string& node_name, DAG& g){
    auto it = g.delay_map.find(node_name);                    //Let's pray the compiler would get it
    if(it != g.delay_map.end()){
        return (*it).second;
    }
    else{
        cerr  << "Couldnot retrieve delay from delay constraint map: " << node_name << endl;
        exit(EXIT_FAILURE);
    }
}


cap_t DAG::getAssignInputTransition(node* in_node,  Library &l){
    //Iterate over all the previous nodes
    //Compute their transition time
    //Return the maximum
    for(string in_node_name: in_node->in_nodes){                                      //Over all in_node names
        node* node_ref = this->getNodeByName(in_node_name);                     //Get a reference to this node
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

cap_t DAG::getAssignOutCapacitance(node* in_node,  Library &l){
    in_node->output_cap = 0;
    for(edge _e:in_node->out_edges){
        node* node_ref = getNodeByName(_e.n);
        in_node->output_cap += (get_input_pin_cap(node_ref->cell_type,l) + _e.net_capacitance);
    }
    return in_node->output_cap;
}
