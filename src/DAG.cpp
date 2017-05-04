#include "DAG.h"

PATH_T get_path_type(const NODE_T& start_node_type, const NODE_T& end_node_type)
{
    if(start_node_type == IN && end_node_type == FFD)
        return IR;
    else if(start_node_type == FFQ && end_node_type == FFD)
        return RR;
    else if(start_node_type == FFQ && end_node_type == OUT)
        return RO;
    else if(start_node_type == IN && end_node_type == OUT)
        return IO;
    else return NA;
}
