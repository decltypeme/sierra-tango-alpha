#ifndef NETLIST_H
#define NETLIST_H
#include "parser.h"

bool isFF(std::string s);
void fill_DAG(DAG &g);
void parse_netlist(std::ifstream &netlist, std::ifstream &caplist, DAG &g);
void read_caplist(std::ifstream &caplist, cap_map_t cap_map);

#endif // NETLIST_H
