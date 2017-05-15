#include "DAG.h"

std::string NODE_T_NAMES []= {"IN","OUT","CELL","FFD","FFQ","START"};
std::string PATH_NAMES []= {"I-R","R-R","R-O","I-O"};

PATH_T get_path_type(const std::string &s, const NODE_T& start_node_type, const NODE_T& end_node_type)
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
    nodes.push_back(node("START",START));
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
void DAG::join(std::string edgeName, std::string n1,std::string n2, std::string netName){

    node *n1_n= getNodeByName(n1);
    node *n2_n= getNodeByName(n2);
   //add cap
    auto cap =cap_map.find(netName) //*
    if(cap != example.end()) {
        n1_n->edges.push_back(edge(edgeName,*n2_n,cap->second));
    }
    // // else
    
    // n1_n->edges.push_back(edge(edgeName,*n2_n));


}
