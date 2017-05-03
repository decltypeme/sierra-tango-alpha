#ifndef DAG_H
#define DAG_H

#include <vector>
#include <string>

class edge
{
public:
    edge(const node &n);
    ~edge();
    node* n;
};


class node
{
public:
    node(const std::string &name);
    ~node();
    void add_edge(const edge &e);
    void remove_edge(const edge &e);
    std::string name;
    std::vector<edge> edges;
};

class DAG
{
public:
    DAG();
    ~DAG();
    void add_node(const node &n);
    void remove_node(const node &n);
    std::vector<node> nodes;
};

#endif
