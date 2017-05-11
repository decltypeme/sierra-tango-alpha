#include "netlist.h"
#include "path_finding.h"
#include <fstream>
using namespace std;

int pseudomain(int argc, char *argv[])
{
    DAG g;
    ifstream netlist;
    ofstream path_file;

    if (argc>1)
    {
        netlist.open(argv[1], std::ifstream::in);
        if(argc > 2){
           path_file.open(argv[2], std::ofstream::out);
        }

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

    ostream& out = (path_file.is_open())?path_file:cout;

    for (path &p: paths)
    {
        out << PATH_NAMES[p.pathtype] << ":\t\t" << p.start->name << " (" << NODE_T_NAMES[p.start->type] << ")\t";
        for (const node *n:p.flow)
        {
            out << n->name << " (" << NODE_T_NAMES[n->type] << ")\t";
        }
        out << endl;
    }
}
