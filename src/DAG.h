#ifndef DAG_H
#define DAG_H

#include <vector>
#include <string>

enum NODE_T {IN,OUT,CELL, FFD,FFQ};
enum PATH_T {NA = -1, IR, RR, RO, IO};

PATH_T get_path_type(const NODE_T& start_node_type, const NODE_T& end_node_type)
{
    if(start_node_type == IN && end_node_type == FFD)
        return IR;
    else if(start_node_type == FFQ && end_node_type == FFD)
        return RR;
    else if(start_node_type == FFQ && end_node_type == OUT)
        return RO;
    else if(start_node_type == IN && end_node_type == OUT)
        return IO;
    else return NA;
}


class edge
{
public:
    edge(const node &n):n(&n){}
    ~edge(){}
    node* n;
};


class node
{
public:
    node(const std::string &name): name(name){}
    ~node(){}
    std::string name;
    NODE_T type;
    std::vector<edge> edges;
};

class DAG
{
public:
    DAG(){}
    ~DAG(){}
    std::vector<node> nodes;
};

#endif
