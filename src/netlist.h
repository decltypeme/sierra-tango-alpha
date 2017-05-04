#ifndef NETLIST_H
#define NETLIST_H
#include "DAG.h"
#include <fstream>
#include <vector>
#include <utility>

//std::vector<std::pair<std::string,std::vector<std::string>>> inputs;
//std::vector<std::pair<std::string,std::vector<std::string>>> inputs;
//std::vector<> cells;
//std::vector<DFF> DFFs;

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
