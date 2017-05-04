#ifndef PATH_FINDING_H
#define PATH_FINDING_H
#include "DAG.h"
#include <iostream>

struct path{
    const node* start;
    const node* end;
    std::vector<const node*> flow;                     //Start and End points are part of the flow
    PATH_T pathtype;
};

void get_paths_recursive(const node &n, const DAG &g, path whole_path, std::vector<path>& all_paths)
{
    NODE_T current_node_type = n.type;
    whole_path.flow.push_back(&n);
    PATH_T resolved_path_type = get_path_type(whole_path.start->type, current_node_type);

    if(resolved_path_type != -1){
        whole_path.end = &n;
        whole_path.pathtype = resolved_path_type;
        all_paths.push_back(whole_path);
        return;
    }
    else if(current_node_type == OUT){
        std::cout << "Magically, I am here!\n";
        return;
    }
    else{
        for (const edge &e: n.edges)
        {
            get_paths_recursive(*e.n, g, whole_path, all_paths);
        }
    }
}

std::vector<path> get_paths_node(const node &n,const DAG &g)
{
    std::vector<path> paths;
    for (const edge &e: n.edges)
    {
        path local_path;
        local_path.start = &n;
        get_paths_recursive(*e.n, g, local_path, paths);
    }
    return paths;
}

std::vector<path> get_paths_graph(const DAG &g)
{
    std::vector<path> paths;
    for(const node &n: g.nodes)
    {
        if ( n.type == OUT || n.type == FFD || n.type == CELL){
            continue;
        }
        std::vector<path> paths_new = get_paths_node(n,g);
        paths.insert( paths.end(), paths_new.begin(), paths_new.end() );
    }
    return paths;
}

#endif // PATH_FINDING_H