#ifndef NETLIST_H
#define NETLIST_H
#include "parser.h"
#include "netlist.h"



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
            //DONE: Add Cell Type Information for both the D and Q pins: Both are the same
            g.nodes.push_back(node("d_"+c.name,FFD,c.type));
            g.nodes.push_back(node("q_"+c.name,FFQ,c.type));
            
            g.join("clk_q_"+c.name,"clk","q_"+c.name);
        }
        else
        {
            //DONE: Add Cell Type Inormation using the new constructor signature
            
            g.nodes.push_back(node(c.name,CELL,c.type));
        }
    }
//input connected to componet
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
                            //updated 
                            g.join("in_"+n.name,n.name,"d_"+d.name,ipin.pinName);
                        }
                        else
                        {
                             //updated 

                            g.join("in_"+n.name,n.name,d.name,ipin.pinName);
                        }
                    }

                }
            }
        }
    }
//component connected to another component
// different join ?!!
    for( compBox &c: vecComp)
    {
        for(pin &opin:c.outputs )
        {
            for( compBox &d: vecComp)
            {
                for(pin &ipin:d.inputs)
                { 
                    if(ipin.pinConn==opin.pinConn)
                    {   //second component is FF
                        if (isFF(c.type))
                        { //first component is FF
                            if (isFF(d.type))
                            {
                               
                                g.join(ipin.pinConn,"q_"+c.name,"d_"+d.name,,ipin.pinName,ipin.pinName);//updated 
                            }
                            else //first component is a gate not FF
                            {
                                
                                g.join(ipin.pinConn,"q_"+c.name,d.name,ipin.pinName); //updated 
                            }
                        }
                        else //second component is a gate not FF
                        {
                            if (isFF(d.type)) //first component is  FF
                            {
                             
                                g.join(ipin.pinConn,c.name,"d_"+d.name,ipin.pinName); //updated 
                            }
                            else //first component is a gate not FF
                            {
                                
                                g.join(ipin.pinConn,c.name,d.name,ipin.pinName); //updated 
                            }
                        }

                    }
                }
            }
            //component connected to output node
            for( node &n: g.nodes)
            {
                if (n.type== OUT)
                {
                    if(opin.pinConn==n.name)
                    {
                        if (isFF(c.type))
                            g.join(opin.pinConn,"q_"+c.name,n.name,opin.pinName); //updated 
                        else
                            g.join(opin.pinConn,c.name,n.name,opin.pinName); //updated 
                    }

                }
            }


        }

    }
}

void read_caplist(std::ifstream &caplist, cap_map_t cap_map)
{
    string netname;
    cap_t  capvalue;
    
    if(caplist.is_open())
    {
        while(!caplist.eof())
        {
            caplist>>netname;
            caplist>>capvalue;
            cap_map.insert({netname,capvalue});
            
  
        }
       // caplist.close();

    }
    

};

void parse_netlist(std::ifstream &netlist, std::ifstream &caplist, DAG &g)
{
    read_netlist(netlist, vecComp, g);
    //open caplist fstream before passing !!
    //close afterwards
	read_caplist(caplist, g.cap_map);
	fill_DAG(g);
}


#endif // NETLIST_H
