#include "DAG.h"

std::string NODE_T_NAMES []= {"IN","OUT","CELL","FFD","FFQ"};
std::string PATH_NAMES []= {"I-R","R-R","R-O","I-O"};

PATH_T get_path_type(const std::string &s, const NODE_T& start_node_type, const NODE_T& end_node_type)
{
    if(s == "clk" && end_node_type == FFD)
        return RR;
    else if(s == "clk" && end_node_type == OUT)
        return RO;
    else if(start_node_type == IN && end_node_type == FFD)
        return IR;
    else if(start_node_type == IN && end_node_type == OUT)
        return IO;
    else return NA;
}
