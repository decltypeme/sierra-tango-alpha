#ifndef DAG_H
#define DAG_H

#include <vector>
#include <string>
#include <iostream>

class node;

typedef float cap_t;
typedef float delay_t;

typedef unordered_map<string, cap_t> cap_map_t;        //The capacitance list is a hashmap of the net name and the capacitance value

extern std::string NODE_T_NAMES[];
enum NODE_T {IN,OUT,CELL, FFD,FFQ,START};
extern std::string PATH_NAMES[];
enum PATH_T {NA = -1, IR, RR, RO, IO};

PATH_T get_path_type(const std::string &s, const NODE_T& start_node_type, const NODE_T& end_node_type);

class edge
{
public:
    edge(const std::string &name, node &n):name(name),n(&n){}
    ~edge(){}
    std::string name;
    cap_t net_capacitence;
    node* n;
};


class node
{
public:
    //TODO: Overload(or update) the constructor format in .h file and .cpp file
    node(const std::string &name, const NODE_T &type): name(name), type(type){}
    node(const std::string &name, const NODE_T &type, const string& cell_type): name(name), type(type), cell_type(cell_type){}
    ~node(){}
    std::string name;
    NODE_T type;
    std::string cell_type;
    std::vector<edge> edges;
    cap_t output_cap;
    std::vector<cap_t> output_cap_list;
    delay_t AAT;
    delay_t input_transition_time;
    std::vector<delay_t> input_transition_time_list;
};

class DAG
{
public:
    DAG();
    ~DAG();
    std::vector<node> nodes;
    node* getNodeByName(std::string NodeName);
    void join(std::string edgeName, std::string n1,std::string n2);
};

#endif
