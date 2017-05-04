#include "netlist.h"
#include "path_finding.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    DAG g;
    ifstream netlist(argv[1], std::ifstream::in);
    if (netlist.is_open())
    {
        parse_netlist(netlist,DAG &g);
    }

    //    g.nodes.push_back(node("a",IN));
    //    g.nodes.push_back(node("and",CELL));
    //    g.nodes.push_back(node("or",CELL));
    //    g.nodes.push_back(node("inr1",FFD));
    //    g.nodes.push_back(node("outr1",FFQ));
    //    g.nodes.push_back(node("inr2",FFD));
    //    g.nodes.push_back(node("outr2",FFQ));
    //    g.nodes.push_back(node("c",OUT));
    //    g.join("a","and");
    //    g.join("a","or");
    //    g.join("and","inr1");
    //    g.join("or","inr1");
    //    g.join("inr1","outr1");
    //    g.join("outr1","inr2");
    //    g.join("inr2","outr2");
    //    g.join("outr2","c");

    vector<path> paths = get_paths_graph(g);

    cin.get();
}
