#include "cpm.h"
using namespace std;
using namespace utils;
using namespace liberty;

void put_AAT(const Library &l, DAG &g)
{

    for(node &_n:g.nodes)
    {
        for(edge &_e:n.edges)
        {
            //Step1
            cap_t output_cap = get_input_pin_cap(*(_e.n)->name) + _e.net_capacitence;
            *(_e.n)->input_transition_time=get_transtion_time(_n,_e,output_cap);

            //Step2

        }
    }

}



