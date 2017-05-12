#ifndef NETLIST_H
#define NETLIST_H
#include "parser.h"

bool isFF(std::string s);
void fill_DAG(DAG &g);
void parse_netlist(std::ifstream &ifs, DAG &g);

#endif // NETLIST_H
