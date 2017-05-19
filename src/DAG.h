#ifndef DAG_H
#define DAG_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class node;
class DAG;

typedef float cap_t;
typedef float delay_t;

typedef std::unordered_map<std::string, cap_t> cap_map_t;        //The capacitance list is a hashmap of the net name and the capacitance value

extern std::string NODE_T_NAMES[];
enum NODE_T {IN,OUT,CELL, FFD,FFQ,START};
extern std::string PATH_NAMES[];
enum PATH_T {NA = -1, IR, RR, RO, IO};

PATH_T get_path_type(const std::string &s, const NODE_T& start_node_type, const NODE_T& end_node_type);

class edge
{
public:
    //TODO: overload the constructor to pass the net capacitance  
    edge(const std::string &_name, const std::string &_n):name(_name),n(_n){}
    edge(const std::string &_name, const std::string &_n, cap_t &_net_capacitance):name(_name),n(_n),net_capacitance(_net_capacitance){}

    ~edge(){}
    //ToDO: pin/net name 
    std::string name;
    cap_t net_capacitance;
    std::string n;
};


class node
{
public:
    node(const std::string &name, const NODE_T &type): name(name), type(type){}
    node(const std::string &name, const NODE_T &type, const std::string& cell_type):
       name(name), type(type), cell_type(cell_type){}
    ~node(){}
    std::string name;
    NODE_T type;
    std::string cell_type;
    std::vector<edge> edges;
    cap_t output_cap;
    delay_t cell_delay;
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
    //TODO: change function to get cap from hashedMap
    cap_map_t cap_map;
    //TODO: get net name to join nodes 
    void join(std::string edgeName, std::string n1,std::string n2);
};

#endif
