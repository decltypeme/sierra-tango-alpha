#include "DAG.h"
#include <iostream>
using namespace std;

struct path{
    const node* start;
    const node* end;
    vector<const node*> flow;                     //Start and End points are part of the flow
    PATH_T pathtype;
};

//DFS bs hussam msh 3aez yesmeh DFS

void get_paths_recursive(const node &n, const DAG &g, path whole_path, vector<path>& all_paths)
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
        cout << "Magically, I am here!\n";
        return;
    }
    else{
        for (const edge &e: n.edges)
        {
            get_paths_recursive(*e.n, g, whole_path, all_paths);
        }
    }
}

vector<path> get_paths(const node &n,const DAG &g)
{
    vector<path> paths;
    for (const edge &e: n.edges)
    {
        path local_path;
        local_path.start = &n;
        get_paths_recursive(*e.n, g, local_path, paths);
    }
    return paths;
}

int main()
{
    DAG g;
    vector<path> paths;
    g.nodes.push_back(node("a",IN));
    g.nodes.push_back(node("and",CELL));
    g.nodes.push_back(node("or",CELL));
    g.nodes.push_back(node("inr1",FFD));
    g.nodes.push_back(node("outr1",FFQ));
    g.nodes.push_back(node("inr2",FFD));
    g.nodes.push_back(node("outr2",FFQ));
    g.nodes.push_back(node("c",OUT));
    g.join("a","and");
    g.join("a","or");
    g.join("and","inr1");
    g.join("or","inr1");
    g.join("inr1","outr1");
    g.join("outr1","inr2");
    g.join("inr2","outr2");
    g.join("outr2","c");


    for(node &n: g.nodes)
    {
        if ( n.type == OUT || n.type == FFD || n.type == CELL){
            continue;
        }
        vector<path> paths_new = get_paths(n,g);
        paths.insert( paths.end(), paths_new.begin(), paths_new.end() );
    }
    cout << "Before done!";
}
