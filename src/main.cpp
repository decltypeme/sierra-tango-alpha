#include "netlist.h"
#include "path_finding.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    DAG g;
    ifstream netlist;
    if (argc>1)
    {
        netlist.open(argv[1], std::ifstream::in);
    }
    if (netlist.is_open())
    {
        parse_netlist(netlist,g);
    }

    vector<path> paths;
    if (netlist.is_open())
    {
        paths = get_paths_graph(g);
    }

    for (path &p: paths)
    {
        cout << PATH_NAMES[p.pathtype] << "\t" << p.start->name << " (" << NODE_T_NAMES[p.start->type] << ")\t";
        for (const node *n:p.flow)
        {
            cout << n->name << " (" << NODE_T_NAMES[n->type] << ")\t";
        }
        cout << endl;
    }
}
