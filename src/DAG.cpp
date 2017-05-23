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
        n2_n->in_nodes.push_back(n2);
    }
	else
	{
        n1_n->out_edges.push_back(edge(edgeName, n2_n->name));
        n2_n->in_nodes.push_back(n2);
	}
}
