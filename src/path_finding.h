#ifndef PATH_FINDING_H
#define PATH_FINDING_H
#include "DAG.h"
#include <iostream>

struct path{
     node* start;
     node* end;
    std::vector<node*> flow;                     //Start and End points are part of the flow
    PATH_T pathtype;
};

void get_paths_recursive( node &n,  DAG &g, path whole_path, std::vector<path>& all_paths);

std::vector<path> get_paths_node( node &n, DAG &g);

std::vector<path> get_paths_graph( DAG &g);

#endif // PATH_FINDING_H
