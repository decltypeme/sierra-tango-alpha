#ifndef 
#include <fstream>

//TODO: Include Dag.h and remove the typedef

using namespace std;
typedef unordered_map<string, cap_t> cap_map_t;
void write_random_net_cap(ostream& outs);
void read_net_cap_list(ifstream& ins, cap_map_t& cap_map);
void extract_nets(ifstream& ins);