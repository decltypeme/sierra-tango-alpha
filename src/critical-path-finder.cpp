#include "libertyparser-1.0/src/liberty.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using namespace utils;
using namespace liberty;

int main(int argc, char *argv[])
{
    Library l = parse("/home/hussam/sierra-tango-alpha/lib/osu035.lib");
    vector<string> v = l.getCellNames();
    for(const string &s: v)
    {
        cout << s << endl;
    }
}
