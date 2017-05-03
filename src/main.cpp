#include "DAG.h"
using namespace std;

enum {IN,OUT,CELL, FFD,FFQ} NODE_T;
enum {IR,RR,RO,IO} PATH_T;

struct path{
    node* start;
    node* end;
    vector<node*> flow;
    PATH_T pathtype;
};

vector<path> get_paths(node n, DAG g);

int main()
{
    DAG g;
    vector<path> paths;
    for(node n: g.nodes)
    {
        get_paths(n,g);
    }
}
