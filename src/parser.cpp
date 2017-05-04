#ifndef PARSER_CPP
#define PARSER_CPP
#include "parser.h"

using namespace std;

NODE_T type_from_string(string type_str){
    if(type_str == "input")
        return NODE_T::IN;
    else if(type_str == "output")
        return NODE_T::OUT;
    else
        throw (string("Magically, I am here!"));
}

void process_component(string component_line, std::vector<compBox>& vecComp){

}

void process_ports(NODE_T node_type, string port_name, DAG& g, int start, int end){
    for(int ii = start; ii <= end; ii++){
        process_ports(node_type, port_name + string("[") + to_string(ii) + string("]"), g);
    }
}

void process_ports(NODE_T node_type, string port_name, DAG& g){
    g.nodes.push_back(node(port_name, node_type));
}



void read_netlist(std::ifstream &ifs, std::vector<compBox>& vecComp, DAG& g){
    smatch sm;
    string line;
    regex port_pattern("\\s*(wire|input|output)\\s*(.+)\\s*");
    regex port_array_pattern("\\s*(wire|input|output)\\s*\\[([0-9]+):([0-9]+)\\]\\s*([^\\s]*)\\s*");
    regex component_pattern("\\s*([A-z|0-9|_]+)\\s+([A-z|0-9|_]+)\\s*\\((.*)\\)\\s*");
    //NOTE: Port Pattern captures a subset from port_array_pattern.
    //Port Array Pattern must be checked first
    while(getline(ifs, line, ';')){
        if(regex_match(line, port_array_pattern)){
            regex_search(line, sm, port_array_pattern);
        }else if(regex_match(line, port_pattern)){


        }else if((regex_match(line, component_pattern))){

        }
    }

}

#endif // PARSER_CPP
