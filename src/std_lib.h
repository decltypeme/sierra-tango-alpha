#ifndef STD_LIB_H
#define STD_LIB_H
#include <string>

typedef float cap_t;
typedef float delay_t;


class std_lib{
public:
    delay_t get_output_transition(string gate_type, delay_t input_transition, cap_t output_capacitance);
    delay_t get_cell_delay(string gate_type, delay_t input_transition, cap_t output_capacitance);
    delay_t interpolate(string gate_type, delay_t input_transition, cap_t output_capacitance);
};

#endif // STD_LIB_H
