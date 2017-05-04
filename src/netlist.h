#ifndef NETLIST_H
#define NETLIST_H
#include "parser.h"

bool isFF(std::string s)
{
    return (s=="DFF");
}

void fill_DAG(DAG &g)
{
    for( compBox &c: vecComp)
    {
        if (isFF(c.type))
        {
            g.nodes.push_back(node("d_"+c.name,FFD));
            g.nodes.push_back(node("q_"+c.name,FFQ));
            g.join("clk_q_"+c.name,"clk","q_"+c.name);
        }
        else
        {
            g.nodes.push_back(node(c.name,CELL));
        }

        for(pin &opin:c.outputs )
        {
            for( compBox &d: vecComp)
            {
                for(pin &ipin:d.inputs)
                {
                    if(ipin.pinConn==opin.pinConn)
                    {
                        if (isFF(c.type))
                        {
                            if (isFF(d.type))
                            {
                                g.join(ipin.pinConn,"q_"+c.name,"d_"+d.name);
                            }
                            else
                            {
                                g.join(ipin.pinConn,"q_"+c.name,d.name);
                            }
                        }
                        else
                        {
                            if (isFF(d.type))
                            {
                                g.join(ipin.pinConn,c.name,"d_"+d.name);
                            }
                            else
                            {
                                g.join(ipin.pinConn,c.name,d.name);
                            }
                        }

                    }
                }
            }
        }

    }
}

void parse_netlist(std::ifstream &ifs, DAG &g)
{
    read_netlist(ifs, g);
    fill_DAG(g);
}


#endif // NETLIST_H
