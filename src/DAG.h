#ifndef DAG_H
#define DAG_H

#include <vector>
#include <string>

class edge
{
public:
    edge(const node* n);
    ~edge();
private:
    node* node;
};


class node
{
public:
    node(const std::string &name);
    ~node();
private:
    std::string name;
    std::vector<edge> edges;
};

class DAG
{
public:
    DAG();
    ~DAG();
    void insert(const node &n);
    void add_edge(node &out, const node &in);
private:
    std::vector<node> nodes;
};

#endif
