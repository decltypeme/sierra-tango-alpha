/* ****************************************************************************
*  ****************************************************************************
*  tokenizer.l
* 
*  Flex source file for Liberty tokenizer
* 
*  ****************************************************************************
*/



/*
 * Author: Puneet Sharma <sharma@ucsd.edu>
 * Date: Nov 03, 2006
 */


%{
#include <string.h>
#include "parser.h"

int __line_no = 1;
void yyeror(char *s);

%}

ws                     [ \t]+
nl                     \n
integervalue           -?[0-9]+
decimalvalue           -?[0-9]*"."[0-9]+|-?[0-9]+[eE][+-]?[0-9]+|-?[0-9]*"."[0-9]+[eE][+-]?[0-9]+
string                 [^:,;{}()%\" \t\n]+

%x                     S_COMMENT S_QUOTE

%%

"/*".                       { BEGIN S_COMMENT; }
"/*"\n                      { BEGIN S_COMMENT; __line_no++; }
<S_COMMENT>.                { ; }
<S_COMMENT>\n               { __line_no++; }
<S_COMMENT>"*/"             { BEGIN 0; }
<S_COMMENT><<EOF>>          { printf("ERROR: Unterminated comment\n"); exit(1);}
"\""                        { yymore(); BEGIN S_QUOTE; }
<S_QUOTE>\"                 { yylval.string = strdup(yytext); BEGIN 0; return QUOTED_STRING; }
<S_QUOTE>.                  { yymore(); }
<S_QUOTE>\n                 { yymore(); __line_no++; }
<S_QUOTE><<EOF>>            { printf("ERROR: Unterminated quote\n"); exit(1);}


"{"                     { return LBRACE; }
"}"                     { return RBRACE; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
":"                     { return COLON; }
";"                     { return SEMICOLON; }
","                     { return COMMA; }
"index_1"               { return INDEX_1; }
"index_2"               { return INDEX_2; }
"index_3"               { return INDEX_3; }
"variable_1"            { return VARIABLE_1; }
"variable_2"            { return VARIABLE_2; }
"variable_3"            { return VARIABLE_3; }
"pin"                   { return PIN; }
"library"               { return LIBRARY; }
"cell_leakage_power"    { return CELL_LEAKAGE_POWER; }
"cell_footprint"        { return CELL_FOOTPRINT; }
"area"                  { return AREA; }
"leakage_power"         { return LEAKAGE_POWER; }
"function"              { return FUNCTION; }
"capacitance"           { return CAPACITANCE; }
"max_capacitance"       { return MAX_CAPACITANCE; }
"when"                  { return WHEN; }
"direction"             { return DIRECTION; }
"value"                 { return VALUE; }
"library_features"      { return LIBRARY_FEATURES; }
"capacitive_load_unit"  { return CAPACITIVE_LOAD_UNIT; }
"operating_conditions"  { return OPERATING_CONDITIONS; }
"process"               { return PROCESS; }
"temperature"           { return TEMPERATURE; }
"voltage"               { return VOLTAGE; }
"tree_type"             { return TREE_TYPE; }
"output_voltage"        { return OUTPUT_VOLTAGE; }
"input_voltage"         { return INPUT_VOLTAGE; }
"vol"                   { return VOL; }
"vil"                   { return VIL; }
"voh"                   { return VOH; }
"vih"                   { return VIH; }
"vomin"                 { return VOMIN; }
"vimin"                 { return VIMIN; }
"vomax"                 { return VOMAX; }
"vimax"                 { return VIMAX; }
"wire_load"             { return WIRE_LOAD; }
"resistance"            { return RESISTANCE; }
"slope"                 { return SLOPE; }
"fanout_length"         { return FANOUT_LENGTH; }
"cell"                  { return CELL; }
"input"                 { return INPUT; }
"output"                { return OUTPUT; }
"inout"                 { return INOUT; }
"internal_power"        { return INTERNAL_POWER; }
"related_pin"           { return RELATED_PIN; }
"rise_power"            { return RISE_POWER; }
"fall_power"            { return FALL_POWER; }
"rise_transition"       { return RISE_TRANSITION; }
"fall_transition"       { return FALL_TRANSITION; }
"cell_rise"             { return CELL_RISE; }
"cell_fall"             { return CELL_FALL; }
"values"                { return VALUES; }
"timing"                { return TIMING; }
"timing_sense"          { return TIMING_SENSE; }
"positive_unate"        { return POSITIVE_UNATE; }
"negative_unate"        { return NEGATIVE_UNATE; }
"non_unate"             { return NON_UNATE; }
"sdf_cond"              { return SDF_COND; }
"equal_or_opposite_output" { return EQUAL_OR_OPPOSITE_OUTPUT; }
"timing_type"           { return TIMING_TYPE; }
"rise_constraint"       { return RISE_CONSTRAINT; }
"fall_constraint"       { return FALL_CONSTRAINT; }
"clock"                 { return CLOCK; }
"true"                  { return TRUE; }
"false"                 { return FALSE; }
"max_transition"        { return MAX_TRANSITION; }
"min_pulse_width_high"  { return MIN_PULSE_WIDTH_HIGH; }
"min_pulse_width_low"   { return MIN_PULSE_WIDTH_LOW; }
"ff"                    { return FF; }
"latch"                 { return LATCH; }
"driver_type"           { return DRIVER_TYPE; }
"dont_touch"            { return DONT_TOUCH; }
"dont_use"              { return DONT_USE; }
"three_state"           { return THREE_STATE; }
"power"                 { return POWER; }
"test_cell"             { return TEST_CELL; }
"signal_type"           { return SIGNAL_TYPE; }
"clock_gating_integrated_cell" {return CLOCK_GATING_INTEGRATED_CELL; }
"clock_gate_enable_pin" { return CLOCK_GATE_ENABLE_PIN; }
"clock_gate_clock_pin"  { return CLOCK_GATE_CLOCK_PIN; }
"clock_gate_out_pin"  { return CLOCK_GATE_OUT_PIN; }
"clock_gate_test_pin"  { return CLOCK_GATE_TEST_PIN; }
"statetable"            { return STATETABLE; } 
"state_function"        { return STATE_FUNCTION; }
"table"                 { return TABLE; }
"internal"              { return INTERNAL; }
"internal_node"         { return INTERNAL_NODE; }



"\\."                   { ; }
"\\\n"                  { __line_no++; }
{ws}                    { ; }
{nl}                    { __line_no++; }
{integervalue}          { yylval.integer = atoi(yytext); return INTEGER; }
{decimalvalue}          { yylval.decimal = atof(yytext); return DECIMAL; }
{string}                { yylval.string = strdup(yytext); return STRING; }
