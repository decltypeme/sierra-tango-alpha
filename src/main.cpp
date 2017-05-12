#include "cpm.h"
#include "netlist.h"
#include <vector>

using namespace std;
using namespace utils;
using namespace liberty;

int main(int argc, char ** argv)
{
    DAG g;
    ifstream netlist;

    netlist.open(argv[1], std::ifstream::in);
    parse_netlist(netlist,g);

    Library l = parse(argv[2]);
    put_AAT(l,g);

}
