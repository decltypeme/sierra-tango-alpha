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
    std::string name;
    std::vector<edge> edges;
};

class DAG
{
public:
    DAG();
    ~DAG();
    std::vector<node> nodes;
};

#endif
