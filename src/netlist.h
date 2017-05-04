#ifndef NETLIST_H
#define NETLIST_H
#include "parser.h"

bool isFF(std::string s)
{
    return (s.find("DFF") == 0);
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
    }

    for( node &n: g.nodes)
    {
        if (n.type== IN && n.name != "clk")
        {
            for( compBox &d: vecComp)
            {
                for(pin &ipin:d.inputs)
                {
                    if(ipin.pinConn==n.name)
                    {
                        if (isFF(d.type))
                        {
                            g.join("in_"+n.name,n.name,"d_"+d.name);
                        }
                        else
                        {
                            g.join("in_"+n.name,n.name,d.name);
                        }
                    }

                }
            }
        }
    }

    for( compBox &c: vecComp)
    {
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
            for( node &n: g.nodes)
            {
                if (n.type== OUT)
                {
                    if(opin.pinConn==n.name)
                    {
                        g.join(opin.pinConn,c.name,n.name);
                    }

                }
            }


        }

    }
}

void parse_netlist(std::ifstream &ifs, DAG &g)
{
    read_netlist(ifs, vecComp, g);
    fill_DAG(g);
}


#endif // NETLIST_H
