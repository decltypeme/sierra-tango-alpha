#include "DAG.h"
using namespace std;

struct path{
    node* start;
    node* end;
    vector<node*> flow;                     //Start and End points are part of the flow
    PATH_T pathtype;
};

//DFS bs hussam msh 3aez yesmeh DFS

void get_paths_recursive(const node &n, const DAG &g, path whole_path, vector<path>& all_paths)
{
    current_node_type = n.type;
    whole_path.flow.push_back(&n);
    PATH_T resolved_path_type = get_path_type(path.start->type, current_node_type);

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
        for (edge e: n.edges)
        {
            get_paths_recursive(e.n, g, whole_path, all_paths);
        }
    }
}

vector<path> get_paths(const node &n,const DAG &g)
{
    vector<path> paths;
    for (edge e: n.edges)
    {
        path local_path;
        local_path.start = &n;
        get_paths_recursive(e.n, g, local_path, paths);
    }
    return paths;
}

int main()
{
    DAG g;
    vector<path> paths;
    for(node n: g.nodes)
    {
        if ( n.type == OUT || n.type == FFD || n.type == CELL){
            continue;
        }
        vector<path> paths_new = get_paths(n,g);
        paths.insert( paths.end(), paths_new.begin(), paths_new.end() );
    }
}
