#include "cpm.h"
#include <vector>

using namespace std;
using namespace utils;
using namespace liberty;


int main(int argc, char ** argv)
{
    Library l = parse(argv[1]);
    for(const Cell &c: l.getCells())
    {
        cout << c.getName()<<endl;
    }
}

