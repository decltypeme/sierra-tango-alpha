#ifndef DAG_H
#define DAG_H

#include <vector>
#include <string>
#include <iostream>

class node;

enum NODE_T {IN,OUT,CELL, FFD,FFQ};
extern std::string NODE_T_NAMES[];
enum PATH_T {NA = -1, IR, RR, RO, IO};

PATH_T get_path_type(const std::string &s, const NODE_T& start_node_type, const NODE_T& end_node_type);

class edge
{
public:
    edge(const std::string &name, const node &n):name(name),n(&n){}
    ~edge(){}
    std::string name;
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
};

class DAG
{
public:
    DAG(){}
    ~DAG(){}
    std::vector<node> nodes;
    inline node* getNodeByName(std::string NodeName) {
        for(node &n:nodes)
        {
            if(n.name==NodeName)
                return &n;
        }
        return nullptr;
    }
    void join(std::string edgeName, std::string n1,std::string n2){

        node *n1_n= getNodeByName(n1);
        node *n2_n= getNodeByName(n2);
        n1_n->edges.push_back(edge(edgeName,*n2_n));


    }
};

#endif
