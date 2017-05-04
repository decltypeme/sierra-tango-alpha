#ifndef NETLIST_H
#define NETLIST_H
#include "DAG.h"
#include <fstream>
#include <vector>

//std::vector<std::vector<>> nodes;

void read_netlist(std::ifstream &ifs)
{

}

void fill_DAG(DAG &g)
{

}

void parse_netlist(std::ifstream &ifs, DAG &g)
{
    read_netlist(ifs);
    fill_DAG(g);
}

#endif // NETLIST_H
