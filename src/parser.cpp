#include "parser.h"

std::vector<compBox> vecComp;

using namespace std;

NODE_T type_from_string(string type_str){
    if(type_str == "input")
        return NODE_T::IN;
    else if(type_str == "output")
        return NODE_T::OUT;
    else
        throw (string("Magically, I am here!"));
}

void process_component(string component_type, string component_name, string component_pins, std::vector<compBox>& vecComp){
    string line;
    compBox new_component;
    new_component.type = component_type;
    new_component.name = component_name;
    regex pin_pattern("\\s*\\.([A-z|0-9|_]+)\\(([A-z|0-9|_]+)\\)\\s*");
    stringstream ss(component_pins);
    while(getline(ss, line, ',')){
        pin new_pin;
        smatch sm;
        regex_search(line, sm, pin_pattern);
        new_pin.pinName = sm[1];
        new_pin.pinConn = sm[2];
        vector<pin>& target_pin_vector = ( (new_pin.pinName[0] == 'Y' || new_pin.pinName[0] == 'Q') ? new_component.outputs : new_component.inputs);
        target_pin_vector.push_back(new_pin);
    }
    vecComp.push_back(new_component);
}

void process_port_array(NODE_T node_type, string port_name, DAG& g, int start, int end){
    for(int ii = start; ii <= end; ii++){
        process_port(node_type, port_name + string("[") + to_string(ii) + string("]"), g);
    }
}

void process_port(NODE_T node_type, string port_name, DAG& g){
    g.nodes.push_back(node(port_name, node_type));
}



void read_netlist(std::ifstream &ifs, std::vector<compBox>& vecComp, DAG& g){
    smatch sm;
    string line;
    regex port_pattern("\\s*(input|output)\\s*(.+)\\s*");
    regex port_array_pattern("\\s*(input|output)\\s*\\[([0-9]+):([0-9]+)\\]\\s*([^\\s]*)\\s*");
    regex component_pattern("[\\s|\\n]*([A-z|0-9|_]+)[\\s|\\n]+([A-z|0-9|_]+)[\\s|\\n]*\\((.*)\\)[\\s|\\n]*");
    regex comment_pattern("\\s*/.*");
    //NOTE: Port Pattern captures a subset from port_array_pattern.
    //Port Array Pattern must be checked first
    while(getline(ifs, line, ';')){
        if(regex_match(line, port_array_pattern)){
            regex_search(line, sm, port_array_pattern);
            //Assign the matching
            NODE_T port_type   = type_from_string(sm[1]);
            int end         = stoi(sm[2]);
            int start       = stoi(sm[3]);
            string port_name   = sm[4];
            process_port_array(port_type,port_name, g, start,end);
        }else if(regex_match(line, port_pattern)){
            regex_search(line, sm, port_pattern);
            //Assign the matching
            NODE_T port_type   = type_from_string(sm[1]);
            string port_name   = sm[2];
            process_port(port_type,port_name, g);
        }else if((regex_match(line, component_pattern))){
            regex_search(line, sm, component_pattern);
            //Assign the matching
            string component_type = sm[1];
            string component_name = sm[2];
            string component_pins = sm[3];
            if (component_type != "module")
            {
                process_component(component_type, component_name, component_pins, vecComp);
            }
        }
    }

}
