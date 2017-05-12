#ifndef DAG_H
#define DAG_H

#include <vector>
#include <string>
#include <iostream>

class node;

typedef float cap_t;
typedef float delay_t;

extern std::string NODE_T_NAMES[];
enum NODE_T {IN,OUT,CELL, FFD,FFQ,START};
extern std::string PATH_NAMES[];
enum PATH_T {NA = -1, IR, RR, RO, IO};

PATH_T get_path_type(const std::string &s, const NODE_T& start_node_type, const NODE_T& end_node_type);

class edge
{
public:
    edge(const std::string &name, const node &n):name(name),n(&n){}
    ~edge(){}
    std::string name;
    cap_t net_capacitence;
    const node* n;
};


class node
{
public:
    node(const std::string &name, const NODE_T &type): name(name), type(type){}
    ~node(){}
    std::string name;
    NODE_T type;
    std::vector<edge> edges;
    delay_t AAT;
    delay_t input_transition_time;
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
