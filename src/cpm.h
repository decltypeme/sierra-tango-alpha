#include "DAG.h"
#include <string>
#include "../libertyparser-1.0/src/liberty.h"

delay_t get_transtion_time (std::string name, delay_t input_transition_time,cap_t output_cap, const liberty::Library &l);
delay_t get_cell_time(std::string name, delay_t input_transition_time,cap_t output_cap, const liberty::Library &l);
cap_t get_input_pin_cap(std::string name, const liberty::Library &l);
void put_AAT(const liberty::Library &l, DAG &g);
