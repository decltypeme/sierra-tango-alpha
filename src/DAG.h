#ifndef DAG_H
#define DAG_H

#include <vector>
#include <string>

class edge
{
public:
    edge(const node &n);
    ~edge();
private:
    node* n;
};


class node
{
public:
    node(const std::string &name);
    ~node();
    void add_edge(const edge &e);
    void remove_edge(const edge &e);
    std::vector<edge> get_edges() const;
private:
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
    std::vector<node> get_nodes() const;
    node& get_start() const;
private:
    std::vector<node> nodes;
    node* start;
};

#endif
