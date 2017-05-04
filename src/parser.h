#ifndef PARSER_H
#define PARSER_H
#include <fstream>
#include <vector>
#include <utility>
#include <regex>
#include "DAG.h"

struct pin{std::string pinName; std::string pinConn; };
struct compBox {std::string type;std:: string name; std::vector<pin> inputs; std::vector<pin> outputs;};
std::vector<compBox> vecComp;

void read_netlist(std::ifstream &ifs, std::vector<compBox>& vecComp, DAG& g);


#endif // PARSER_H
