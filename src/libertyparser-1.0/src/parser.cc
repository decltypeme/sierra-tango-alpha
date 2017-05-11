#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 17 "parser.yy"
#include <cstdlib>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "liberty.h"
#include "utils.h"
#include "parserFunctions.h"


extern liberty::Library   __y_library;
liberty::Cell             __y_cell;
liberty::Pin              __y_pin;
liberty::Timing           __y_timing;
utils::Table              __y_table;

std::string               __y_string;
std::vector<double>       __y_values;
/*
int __y_retVal;
char __y_errString[500];
std::stack<std::string> __y_buffer_stack;
std::vector<std::string> __y_buffer_list;
double __y_value;
std::vector<double> __y_value_list;
tcfTolGroup __y_tolerance_group;
std::vector<tcfLayerTypeEnum> __y_layers;
tcfLayerInfo __y_layer_info;
std::pair<std::string, std::string> __y_labeled_string;
std::vector<std::pair<std::string, std::string> > __y_labeled_strings_list;
std::map<double, std::map<double, std::map<double, double> > >
	__y_min_tolerance_map_entries;
std::map<double, std::map<double, std::map<double, double> > >
	__y_max_tolerance_map_entries;
*/

#line 55 "parser.yy"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
int integer;
double decimal;
char *string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 69 "parser.cc"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define LBRACE 257
#define RBRACE 258
#define LPAREN 259
#define RPAREN 260
#define COLON 261
#define SEMICOLON 262
#define COMMA 263
#define INDEX_1 264
#define INDEX_2 265
#define INDEX_3 266
#define PIN 267
#define LIBRARY 268
#define CELL_LEAKAGE_POWER 269
#define CELL_FOOTPRINT 270
#define AREA 271
#define LEAKAGE_POWER 272
#define FUNCTION 273
#define CAPACITANCE 274
#define MAX_CAPACITANCE 275
#define WHEN 276
#define DIRECTION 277
#define VALUE 278
#define LIBRARY_FEATURES 279
#define CAPACITIVE_LOAD_UNIT 280
#define OPERATING_CONDITIONS 281
#define OUTPUT_VOLTAGE 282
#define INPUT_VOLTAGE 283
#define WIRE_LOAD 284
#define CELL 285
#define INTERNAL_POWER 286
#define TIMING 287
#define INPUT 288
#define OUTPUT 289
#define RISE_POWER 290
#define FALL_POWER 291
#define TIMING_SENSE 292
#define POSITIVE_UNATE 293
#define NEGATIVE_UNATE 294
#define NON_UNATE 295
#define CELL_RISE 296
#define CELL_FALL 297
#define RISE_TRANSITION 298
#define FALL_TRANSITION 299
#define SDF_COND 300
#define VALUES 301
#define RELATED_PIN 302
#define PROCESS 303
#define TEMPERATURE 304
#define VOLTAGE 305
#define TREE_TYPE 306
#define VARIABLE_1 307
#define VARIABLE_2 308
#define VARIABLE_3 309
#define VOL 310
#define VOH 311
#define VOMIN 312
#define VOMAX 313
#define VIL 314
#define VIH 315
#define VIMIN 316
#define VIMAX 317
#define RESISTANCE 318
#define SLOPE 319
#define FANOUT_LENGTH 320
#define EQUAL_OR_OPPOSITE_OUTPUT 321
#define TIMING_TYPE 322
#define RISE_CONSTRAINT 323
#define FALL_CONSTRAINT 324
#define CLOCK 325
#define TRUE 326
#define FALSE 327
#define MAX_TRANSITION 328
#define MIN_PULSE_WIDTH_HIGH 329
#define MIN_PULSE_WIDTH_LOW 330
#define FF 331
#define LATCH 332
#define DRIVER_TYPE 333
#define DONT_TOUCH 334
#define DONT_USE 335
#define THREE_STATE 336
#define POWER 337
#define SIGNAL_TYPE 338
#define TEST_CELL 339
#define INOUT 340
#define CLOCK_GATING_INTEGRATED_CELL 341
#define CLOCK_GATE_ENABLE_PIN 342
#define CLOCK_GATE_CLOCK_PIN 343
#define CLOCK_GATE_OUT_PIN 344
#define CLOCK_GATE_TEST_PIN 345
#define STATETABLE 346
#define STATE_FUNCTION 347
#define TABLE 348
#define INTERNAL_NODE 349
#define INTERNAL 350
#define INTEGER 351
#define DECIMAL 352
#define STRING 353
#define QUOTED_STRING 354
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    3,    4,    4,    4,    4,    4,    4,    4,    4,
    5,    5,    6,    7,    8,    8,    9,   10,   11,   11,
   11,   17,   17,   17,   17,   12,   12,   12,   12,   12,
   12,   12,   13,   13,   13,   13,   13,   14,   14,   14,
   14,   14,   15,   15,   15,   15,   15,   15,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
   16,   20,   20,   21,   21,   22,   23,   24,   25,   26,
   27,   28,   34,   33,   33,   33,   35,   36,   36,   36,
   36,   29,   29,   29,   29,   29,   29,   29,   29,   29,
   29,   29,   29,   29,   29,   29,   29,   29,   29,   29,
   30,   30,   31,   31,   32,   32,   46,   37,   37,   37,
   37,   38,   38,   39,   39,   40,   40,   41,   41,   42,
   42,   43,   43,   43,   43,   43,   43,   43,   44,   44,
   44,   44,   44,   44,   44,   44,   44,   44,   44,   44,
   47,   51,   45,   48,   49,   50,   52,   52,   52,   53,
   54,   55,   56,   57,   58,   59,   60,   60,   60,   60,
   60,   18,   18,   61,   61,   62,   62,    2,    2,    2,
    2,   19,   19,    1,    1,
};
static const short yylen[] = {                            2,
    7,    2,    0,    5,    6,    8,    2,    2,    2,    2,
    0,    2,    7,    7,    7,    7,    7,    7,    0,    1,
    3,    3,    3,    3,    3,    0,    5,    5,    5,    6,
    6,    6,    0,    5,    5,    5,    5,    0,    5,    5,
    5,    5,    0,    5,    5,    5,    5,    8,    0,    5,
    5,    2,    2,    5,    2,    2,    2,    2,    2,    2,
    2,    4,    4,    4,    4,    7,    4,    6,    9,    9,
    6,    9,    4,    0,    2,    2,    7,    0,    2,    5,
    5,    0,    2,    5,    5,    2,    2,    2,    2,    2,
    5,    5,    5,    5,    5,    7,    7,    5,    5,    5,
    2,    2,    0,    5,    0,    5,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    0,    2,    5,    2,    2,    2,    2,    0,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    4,    4,    4,    7,    7,    7,    4,    4,    4,    4,
    7,    7,    7,    7,    7,    7,    0,    6,    6,    6,
    6,    1,    1,    1,    3,    1,    3,    1,    1,    1,
    1,    1,    2,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,  170,  171,  168,  169,    0,    0,    3,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    0,    7,    8,    9,   10,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   12,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    0,    5,    0,    0,   33,   38,   43,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   49,    6,    0,    0,    0,    0,   13,    0,
   15,    0,    0,    0,    0,   16,    0,    0,    0,    0,
   17,    0,    0,    0,    0,    0,   14,    0,    0,    0,
    0,    0,    0,    0,  174,  175,   22,   23,   24,   25,
   21,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   18,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   52,   53,   55,   56,   57,   58,   59,
   60,   61,  172,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  164,  166,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   34,  173,
   35,   36,   37,   39,   40,   41,   42,   46,   45,   44,
   47,    0,    0,    0,    0,    0,    0,   27,   28,   29,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,  165,  167,   31,   32,
    0,   67,   50,   54,    0,    0,    0,   62,   63,   64,
   65,   74,   51,    0,    0,   82,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   48,    0,    0,    0,   68,
  101,  102,    0,    0,   71,    0,   76,   75,    0,   66,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   83,   86,
   87,   88,   89,   90,    0,    0,  103,  105,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  143,  107,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   69,    0,   70,    0,    0,    0,   72,   95,   94,
   98,  108,  109,  110,  111,  122,  129,  120,  121,   93,
   99,  100,   92,   91,  112,  113,  114,  115,  116,  117,
  118,  119,   85,   84,    0,    0,   78,    0,    0,    0,
    0,    0,    0,   73,   96,    0,    0,    0,    0,    0,
  125,  123,  126,  127,  128,   97,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  133,  130,  131,  132,  134,
  135,  136,  137,  138,  139,  140,  104,  106,   77,    0,
    0,   79,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  141,  124,
    0,  147,  148,  149,    0,    0,    0,    0,  150,  142,
    0,    0,   80,   81,  157,  157,  157,  157,  157,  157,
  157,  157,  157,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  145,    0,    0,    0,    0,  144,  146,  151,
  153,  152,  154,  155,  156,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  158,  159,  160,
  161,
};
static const short yydgoto[] = {                          2,
  168,  153,   11,   12,   21,   22,   23,   24,   25,   35,
   67,   72,   69,   70,   71,  104,   68,  169,  154,  144,
  145,  146,  147,  148,  149,  150,  151,  152,  257,  249,
  321,  322,  254,  325,  268,  393,  289,  290,  291,  292,
  293,  294,  389,  390,  250,  251,  402,  403,  404,  405,
  418,  419,  420,  421,  422,  423,  424,  425,  426,  494,
  170,  171,
};
static const short yysindex[] = {                      -255,
 -225,    0, -109,    0,    0,    0,    0, -197, -189,    0,
 -185,  -77,    0, -199, -183, -176, -173, -172, -171, -200,
 -191,    0,    0,    0,    0, -109, -109, -109, -109, -109,
 -109, -109, -109, -169,    0, -180, -166, -144, -136, -122,
 -118, -117, -157, -109,  -89, -109,  -82,  -74,  -71,  -65,
  -57,    0,  -51,    0,  -47,   40,    0,    0,    0,    0,
  -40,  -81,  -32,  -29,  -11,   -5,    1,   -4, -246,  -23,
 -179,  -46,    0,    0, -312, -312, -312, -109,    0,   40,
    0,    4,    9,   11,   17,    0,   18,   20,   21,   22,
    0,   28,   36,   39,   43,   54,    0,   75,   80,   81,
   56,   60,   69, -250,    0,    0,    0,    0,    0,    0,
    0, -109, -109, -109, -109, -109, -109, -109, -109, -312,
 -312, -312, -312, -312, -316, -316, -316, -109, -109, -109,
    0,   91,   90,   92,   94,   93,   97,   98,   99,  100,
  103,  104,  105,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -231, -217, -205, -192, -188, -184, -163,
 -158,   96,  107,  108,  109,  117,    0,    0,  106,  118,
  122,  126,  127,  128,  133,  134, -109, -312, -109, -312,
  129, -109, -109, -208, -198,  137, -109, -109,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -312,  136,   13, -312,  138,  139,    0,    0,    0,
  142,  141,  143,  144,  131,  145,  146,  148,  149,  150,
  151,  147,  152,  153,  155,    0,    0,    0,    0,    0,
  160,    0,    0,    0, -207, -109, -109,    0,    0,    0,
    0,    0,    0, -109,  156,    0,  158,  159,  163,  121,
  170,  162,  164, -214,  165,    0,  -76, -109, -312,    0,
    0,    0,  166,  169,    0,  168,    0,    0,  171,    0,
  174,  186,  187,  188,  191,  192,  193,  194,  195,  196,
  197,  198,  199,  200,  201,  202,  203,  204,    0,    0,
    0,    0,    0,    0,  167,  190,    0,    0, -109,   59,
 -109, -312, -312, -278,  206,  207, -195, -312, -312, -312,
 -109, -109, -155, -149,  -87,  -79, -109, -109,    0,    0,
 -251, -242,  208,  209,  211,  210,  212,  213,  214,  215,
  216,  217,  223,  224,  220,  221,  222,  225,  226,  227,
  228,  229,  230,  231,  232,  233,  234,  235,  236,  237,
  238,    0,  240,    0,  241,  246, -109,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -109, -109,    0,  242, -244,  -12,
  243,  244, -240,    0,    0,  248,  249,  250,  251,  254,
    0,    0,    0,    0,    0,    0,  253,  256,  257,  258,
  259,  261,  262,  265,  266,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  267,
  268,    0, -109, -109, -109, -109, -109, -239, -109, -109,
 -109, -109, -109, -109, -109, -109, -109, -109,  270,  271,
  247,  264,  272,  273,  274,  275,  278,  279,  280,  281,
  282,  283,  286,  287,  288,  289,  263,  276,    0,    0,
  277,    0,    0,    0,  285,  291,  292,  295,    0,    0,
  296,  297,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -151,  -50,   37,   41,   58,   62,   67,
   71,   83,    0,  284,  298,  299,  300,    0,    0,    0,
    0,    0,    0,    0,    0, -316, -316, -316, -316,  301,
  302,  303,  304,  293,  294,  305,  306,    0,    0,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -243,    0,    0,    0,    0,    0,    0,    0,    0,
  252,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  269,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  307,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  269,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  309,
  310,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
  -72,   -3,    0,    0,    0,    0,    0,    0,    0,    0,
  373,    0,    0,    0,    0,    0,    0, -125,  260,    0,
    0,    0,    0,    0,  219,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   78,    0,    0,    0,
    0,    0,    0,    0, -245,  316,   95,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -265,
    0,    0,
};
#define YYTABLESIZE 570
static const short yytable[] = {                          8,
  172,  173,  107,  108,  109,  262,  352,  131,   20,  329,
  330,   81,    1,  395,   11,  354,  132,  429,  133,  134,
  135,  136,   36,   37,   38,   39,   40,   41,   42,   43,
  189,  247,  430,    3,  105,  106,  274,  167,  105,  106,
   53,   11,   55,  265,  191,  396,  397,  162,  163,  164,
  165,  166,  266,  454,  455,  456,  192,  398,   32,   26,
   33,  331,    9,   82,   83,   84,   85,   10,  247,  193,
  248,  332,   13,  194,  110,   27,  399,  195,   91,   45,
  137,  138,   28,  139,  140,   29,   30,   31,  141,   44,
  142,   92,  400,   34,   93,  143,   46,  431,  196,    4,
    5,    6,    7,  197,   52,  212,  503,  214,    4,    5,
    6,    7,  504,  505,  506,   47,  137,  218,  219,    4,
    5,    6,    7,   48,  174,  175,  176,  220,  221,  225,
  335,  336,  228,    4,    5,    6,    7,   49,   94,   95,
   96,   50,   51,  401,  416,    4,    5,    6,    7,  507,
  190,  190,  190,  190,  190,  190,  190,  190,    4,    5,
    6,    7,    4,    5,    6,    7,    4,    5,    6,    7,
  342,  343,   54,  211,   56,  213,  344,  345,  216,  217,
   74,  270,   57,  223,  224,   58,  296,    4,    5,    6,
    7,   59,    4,    5,    6,    7,  271,  272,  273,   60,
  274,   14,   15,   16,   17,   18,   19,  508,   61,  275,
  276,   97,   62,  504,  505,  506,   73,   98,   99,  100,
  495,  496,  497,  498,  499,  500,  501,  502,   75,  327,
  328,   76,  252,  253,   86,  337,  338,  339,  346,  347,
  255,    4,    5,    6,    7,  406,  348,  349,  277,   77,
  507,  278,  279,  280,  295,   78,  281,   80,   79,  282,
  101,  102,  103,  247,  112,  283,  284,  285,  286,  113,
  287,  114,  288,    4,    5,    6,    7,  115,  116,  407,
  117,  118,  119,  408,  409,  410,  411,  412,  120,  398,
   87,   88,   89,   90,  509,  323,  121,  326,  510,  122,
  504,  505,  506,  123,  504,  505,  506,  340,  341,  413,
  414,  415,  124,  350,  351,  511,  128,  353,  355,  512,
  129,  504,  505,  506,  513,  504,  505,  506,  514,  130,
  504,  505,  506,  125,  504,  505,  506,  507,  126,  127,
  515,  507,   63,   64,   65,   66,  504,  505,  506,  177,
  178,  181,  179,  388,  180,  182,  183,  198,  507,  184,
  185,  186,  507,  188,  187,  203,  227,  507,  199,  200,
  201,  507,  155,  156,  157,  158,  159,  160,  161,  202,
  204,  391,  392,  507,  205,  206,  207,  235,  215,  208,
  520,  521,  522,  523,  209,  210,  222,  226,  248,  229,
  230,  231,  232,  242,  233,  234,  324,  236,  237,  238,
  239,  240,  241,  243,  245,  244,  246,  256,  258,  259,
  260,  263,  297,  264,  269,  298,  299,  300,  319,  449,
  450,  451,  452,  453,  301,  457,  458,  459,  460,  461,
  462,  463,  464,  465,  466,  247,  302,  303,  304,  305,
  306,  320,  111,  307,  308,  309,  310,  311,  312,  313,
  314,  315,  316,  317,  318,  333,  334,  356,  358,  357,
  432,  359,  267,  360,  361,  362,  363,  364,  365,  366,
  367,  368,  369,  370,  417,    0,  371,  372,  373,  374,
  375,  376,  377,  378,  379,  380,  381,  382,  383,  384,
  385,  386,  387,  394,  427,  428,  433,  434,  469,    2,
  435,  436,  437,  438,  439,  440,  441,  442,    0,  485,
    0,  443,  444,  445,  446,  470,   19,  447,  448,  467,
  468,  471,  486,  487,  472,  473,  474,  475,  476,  477,
  478,  488,  516,  479,  480,  481,  482,  489,  490,  483,
  484,  491,  492,  493,  528,  529,  517,  518,  519,    0,
  524,  525,  526,  527,   20,  261,  530,  531,  162,  163,
};
static const short yycheck[] = {                          3,
  126,  127,   75,   76,   77,  251,  258,  258,   12,  288,
  289,  258,  268,  258,  258,  258,  267,  258,  269,  270,
  271,  272,   26,   27,   28,   29,   30,   31,   32,   33,
  262,  276,  273,  259,  351,  352,  277,  354,  351,  352,
   44,  285,   46,  258,  262,  290,  291,  120,  121,  122,
  123,  124,  267,  293,  294,  295,  262,  302,  259,  259,
  261,  340,  260,  310,  311,  312,  313,  257,  276,  262,
  278,  350,  258,  262,   78,  259,  321,  262,  258,  260,
  331,  332,  259,  334,  335,  259,  259,  259,  339,  259,
  341,  271,  337,  285,  274,  346,  263,  338,  262,  351,
  352,  353,  354,  262,  262,  178,  258,  180,  351,  352,
  353,  354,  264,  265,  266,  260,  331,  326,  327,  351,
  352,  353,  354,  260,  128,  129,  130,  326,  327,  202,
  326,  327,  205,  351,  352,  353,  354,  260,  318,  319,
  320,  260,  260,  389,  390,  351,  352,  353,  354,  301,
  154,  155,  156,  157,  158,  159,  160,  161,  351,  352,
  353,  354,  351,  352,  353,  354,  351,  352,  353,  354,
  326,  327,  262,  177,  257,  179,  326,  327,  182,  183,
  262,  258,  257,  187,  188,  257,  259,  351,  352,  353,
  354,  257,  351,  352,  353,  354,  273,  274,  275,  257,
  277,  279,  280,  281,  282,  283,  284,  258,  260,  286,
  287,  258,  260,  264,  265,  266,  257,  264,  265,  266,
  486,  487,  488,  489,  490,  491,  492,  493,  261,  302,
  303,  261,  236,  237,  258,  308,  309,  310,  326,  327,
  244,  351,  352,  353,  354,  258,  326,  327,  325,  261,
  301,  328,  329,  330,  258,  261,  333,  262,  258,  336,
  307,  308,  309,  276,  261,  342,  343,  344,  345,  261,
  347,  261,  349,  351,  352,  353,  354,  261,  261,  292,
  261,  261,  261,  296,  297,  298,  299,  300,  261,  302,
  314,  315,  316,  317,  258,  299,  261,  301,  258,  261,
  264,  265,  266,  261,  264,  265,  266,  311,  312,  322,
  323,  324,  259,  317,  318,  258,  261,  321,  322,  258,
  261,  264,  265,  266,  258,  264,  265,  266,  258,  261,
  264,  265,  266,  259,  264,  265,  266,  301,  259,  259,
  258,  301,  303,  304,  305,  306,  264,  265,  266,  259,
  261,  259,  261,  357,  261,  259,  259,  262,  301,  261,
  261,  259,  301,  259,  261,  260,  354,  301,  262,  262,
  262,  301,  113,  114,  115,  116,  117,  118,  119,  263,
  263,  385,  386,  301,  263,  260,  260,  257,  260,  262,
  516,  517,  518,  519,  262,  262,  260,  262,  278,  262,
  262,  260,  262,  257,  262,  262,  348,  263,  263,  262,
  262,  262,  262,  262,  260,  263,  257,  262,  261,  261,
  258,  260,  257,  260,  260,  257,  259,  257,  262,  433,
  434,  435,  436,  437,  261,  439,  440,  441,  442,  443,
  444,  445,  446,  447,  448,  276,  261,  261,  261,  259,
  259,  262,   80,  261,  261,  261,  261,  261,  261,  261,
  261,  261,  261,  261,  261,  260,  260,  260,  258,  261,
  393,  262,  254,  262,  262,  262,  262,  262,  262,  257,
  257,  262,  262,  262,  390,   -1,  262,  262,  262,  262,
  262,  262,  262,  262,  262,  262,  262,  262,  262,  262,
  261,  261,  257,  262,  262,  262,  259,  259,  262,  258,
  261,  261,  259,  261,  259,  259,  259,  259,   -1,  257,
   -1,  261,  261,  259,  259,  262,  258,  261,  261,  260,
  260,  260,  257,  257,  262,  262,  262,  260,  260,  260,
  260,  257,  259,  262,  262,  260,  260,  257,  257,  262,
  262,  257,  257,  257,  262,  262,  259,  259,  259,   -1,
  260,  260,  260,  260,  258,  250,  262,  262,  260,  260,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 354
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"LBRACE","RBRACE","LPAREN",
"RPAREN","COLON","SEMICOLON","COMMA","INDEX_1","INDEX_2","INDEX_3","PIN",
"LIBRARY","CELL_LEAKAGE_POWER","CELL_FOOTPRINT","AREA","LEAKAGE_POWER",
"FUNCTION","CAPACITANCE","MAX_CAPACITANCE","WHEN","DIRECTION","VALUE",
"LIBRARY_FEATURES","CAPACITIVE_LOAD_UNIT","OPERATING_CONDITIONS",
"OUTPUT_VOLTAGE","INPUT_VOLTAGE","WIRE_LOAD","CELL","INTERNAL_POWER","TIMING",
"INPUT","OUTPUT","RISE_POWER","FALL_POWER","TIMING_SENSE","POSITIVE_UNATE",
"NEGATIVE_UNATE","NON_UNATE","CELL_RISE","CELL_FALL","RISE_TRANSITION",
"FALL_TRANSITION","SDF_COND","VALUES","RELATED_PIN","PROCESS","TEMPERATURE",
"VOLTAGE","TREE_TYPE","VARIABLE_1","VARIABLE_2","VARIABLE_3","VOL","VOH",
"VOMIN","VOMAX","VIL","VIH","VIMIN","VIMAX","RESISTANCE","SLOPE",
"FANOUT_LENGTH","EQUAL_OR_OPPOSITE_OUTPUT","TIMING_TYPE","RISE_CONSTRAINT",
"FALL_CONSTRAINT","CLOCK","TRUE","FALSE","MAX_TRANSITION",
"MIN_PULSE_WIDTH_HIGH","MIN_PULSE_WIDTH_LOW","FF","LATCH","DRIVER_TYPE",
"DONT_TOUCH","DONT_USE","THREE_STATE","POWER","SIGNAL_TYPE","TEST_CELL","INOUT",
"CLOCK_GATING_INTEGRATED_CELL","CLOCK_GATE_ENABLE_PIN","CLOCK_GATE_CLOCK_PIN",
"CLOCK_GATE_OUT_PIN","CLOCK_GATE_TEST_PIN","STATETABLE","STATE_FUNCTION",
"TABLE","INTERNAL_NODE","INTERNAL","INTEGER","DECIMAL","STRING","QUOTED_STRING",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : library",
"library : LIBRARY LPAREN string RPAREN LBRACE lib_data RBRACE",
"lib_data : header cells",
"header :",
"header : header string COLON string SEMICOLON",
"header : header LIBRARY_FEATURES LPAREN string RPAREN SEMICOLON",
"header : header CAPACITIVE_LOAD_UNIT LPAREN string COMMA string RPAREN SEMICOLON",
"header : header operating_conditions",
"header : header table_template",
"header : header pad_attribute",
"header : header wire_load",
"cells :",
"cells : cells cell",
"operating_conditions : OPERATING_CONDITIONS LPAREN string RPAREN LBRACE operating_conditions_dataset RBRACE",
"table_template : string LPAREN string RPAREN LBRACE table_data RBRACE",
"pad_attribute : OUTPUT_VOLTAGE LPAREN string RPAREN LBRACE output_voltage_data RBRACE",
"pad_attribute : INPUT_VOLTAGE LPAREN string RPAREN LBRACE input_voltage_data RBRACE",
"wire_load : WIRE_LOAD LPAREN string RPAREN LBRACE wire_load_data RBRACE",
"cell : CELL LPAREN string RPAREN LBRACE cell_data RBRACE",
"operating_conditions_dataset :",
"operating_conditions_dataset : operating_conditions_data",
"operating_conditions_dataset : operating_conditions_data SEMICOLON operating_conditions_dataset",
"operating_conditions_data : PROCESS COLON value",
"operating_conditions_data : TEMPERATURE COLON value",
"operating_conditions_data : VOLTAGE COLON value",
"operating_conditions_data : TREE_TYPE COLON string",
"table_data :",
"table_data : table_data VARIABLE_1 COLON string SEMICOLON",
"table_data : table_data VARIABLE_2 COLON string SEMICOLON",
"table_data : table_data VARIABLE_3 COLON string SEMICOLON",
"table_data : table_data INDEX_1 LPAREN multiple_values RPAREN SEMICOLON",
"table_data : table_data INDEX_2 LPAREN multiple_values RPAREN SEMICOLON",
"table_data : table_data INDEX_3 LPAREN multiple_values RPAREN SEMICOLON",
"output_voltage_data :",
"output_voltage_data : output_voltage_data VOL COLON strings SEMICOLON",
"output_voltage_data : output_voltage_data VOH COLON strings SEMICOLON",
"output_voltage_data : output_voltage_data VOMIN COLON strings SEMICOLON",
"output_voltage_data : output_voltage_data VOMAX COLON strings SEMICOLON",
"input_voltage_data :",
"input_voltage_data : input_voltage_data VIL COLON strings SEMICOLON",
"input_voltage_data : input_voltage_data VIH COLON strings SEMICOLON",
"input_voltage_data : input_voltage_data VIMIN COLON strings SEMICOLON",
"input_voltage_data : input_voltage_data VIMAX COLON strings SEMICOLON",
"wire_load_data :",
"wire_load_data : wire_load_data RESISTANCE COLON value SEMICOLON",
"wire_load_data : wire_load_data CAPACITANCE COLON value SEMICOLON",
"wire_load_data : wire_load_data AREA COLON value SEMICOLON",
"wire_load_data : wire_load_data SLOPE COLON value SEMICOLON",
"wire_load_data : wire_load_data FANOUT_LENGTH LPAREN value COMMA value RPAREN SEMICOLON",
"cell_data :",
"cell_data : cell_data CELL_FOOTPRINT COLON string SEMICOLON",
"cell_data : cell_data CLOCK_GATING_INTEGRATED_CELL COLON string SEMICOLON",
"cell_data : cell_data dont_touch",
"cell_data : cell_data dont_use",
"cell_data : cell_data AREA COLON value SEMICOLON",
"cell_data : cell_data pin",
"cell_data : cell_data cell_leakage_power",
"cell_data : cell_data leakage_power",
"cell_data : cell_data ff",
"cell_data : cell_data latch",
"cell_data : cell_data test_cell",
"cell_data : cell_data statetable",
"dont_touch : DONT_TOUCH COLON TRUE SEMICOLON",
"dont_touch : DONT_TOUCH COLON FALSE SEMICOLON",
"dont_use : DONT_USE COLON TRUE SEMICOLON",
"dont_use : DONT_USE COLON FALSE SEMICOLON",
"pin : PIN LPAREN string RPAREN LBRACE pin_data RBRACE",
"cell_leakage_power : CELL_LEAKAGE_POWER COLON value SEMICOLON",
"leakage_power : LEAKAGE_POWER LPAREN RPAREN LBRACE leakage_power_data RBRACE",
"ff : FF LPAREN string COMMA string RPAREN LBRACE ff_data RBRACE",
"latch : LATCH LPAREN string COMMA string RPAREN LBRACE latch_data RBRACE",
"test_cell : TEST_CELL LPAREN RPAREN LBRACE test_cell_data RBRACE",
"statetable : STATETABLE LPAREN string COMMA string RPAREN LBRACE statetable_data RBRACE",
"statetable_data : TABLE COLON string SEMICOLON",
"test_cell_data :",
"test_cell_data : test_cell_data test_pin",
"test_cell_data : test_cell_data ff",
"test_pin : PIN LPAREN string RPAREN LBRACE test_pin_data RBRACE",
"test_pin_data :",
"test_pin_data : test_pin_data pin_data_direction",
"test_pin_data : test_pin_data FUNCTION COLON string SEMICOLON",
"test_pin_data : test_pin_data SIGNAL_TYPE COLON string SEMICOLON",
"pin_data :",
"pin_data : pin_data pin_data_direction",
"pin_data : pin_data INTERNAL_NODE COLON string SEMICOLON",
"pin_data : pin_data STATE_FUNCTION COLON string SEMICOLON",
"pin_data : pin_data clock_gate_enable_pin",
"pin_data : pin_data clock_gate_clock_pin",
"pin_data : pin_data clock_gate_out_pin",
"pin_data : pin_data clock_gate_test_pin",
"pin_data : pin_data clock",
"pin_data : pin_data THREE_STATE COLON string SEMICOLON",
"pin_data : pin_data DRIVER_TYPE COLON string SEMICOLON",
"pin_data : pin_data MAX_TRANSITION COLON value SEMICOLON",
"pin_data : pin_data CAPACITANCE COLON value SEMICOLON",
"pin_data : pin_data FUNCTION COLON string SEMICOLON",
"pin_data : pin_data INTERNAL_POWER LPAREN RPAREN LBRACE internal_power_data RBRACE",
"pin_data : pin_data TIMING LPAREN RPAREN LBRACE timing_data RBRACE",
"pin_data : pin_data MAX_CAPACITANCE COLON value SEMICOLON",
"pin_data : pin_data MIN_PULSE_WIDTH_HIGH COLON value SEMICOLON",
"pin_data : pin_data MIN_PULSE_WIDTH_LOW COLON value SEMICOLON",
"leakage_power_data : when leakage_power_data_value",
"leakage_power_data : leakage_power_data_value when",
"ff_data :",
"ff_data : ff_data string COLON string SEMICOLON",
"latch_data :",
"latch_data : latch_data string COLON string SEMICOLON",
"leakage_power_data_value : VALUE COLON value SEMICOLON",
"pin_data_direction : DIRECTION COLON INPUT SEMICOLON",
"pin_data_direction : DIRECTION COLON OUTPUT SEMICOLON",
"pin_data_direction : DIRECTION COLON INOUT SEMICOLON",
"pin_data_direction : DIRECTION COLON INTERNAL SEMICOLON",
"clock_gate_enable_pin : CLOCK_GATE_ENABLE_PIN COLON TRUE SEMICOLON",
"clock_gate_enable_pin : CLOCK_GATE_ENABLE_PIN COLON FALSE SEMICOLON",
"clock_gate_clock_pin : CLOCK_GATE_CLOCK_PIN COLON TRUE SEMICOLON",
"clock_gate_clock_pin : CLOCK_GATE_CLOCK_PIN COLON FALSE SEMICOLON",
"clock_gate_out_pin : CLOCK_GATE_OUT_PIN COLON TRUE SEMICOLON",
"clock_gate_out_pin : CLOCK_GATE_OUT_PIN COLON FALSE SEMICOLON",
"clock_gate_test_pin : CLOCK_GATE_TEST_PIN COLON TRUE SEMICOLON",
"clock_gate_test_pin : CLOCK_GATE_TEST_PIN COLON FALSE SEMICOLON",
"clock : CLOCK COLON TRUE SEMICOLON",
"clock : CLOCK COLON FALSE SEMICOLON",
"internal_power_data :",
"internal_power_data : internal_power_data related_pin",
"internal_power_data : internal_power_data EQUAL_OR_OPPOSITE_OUTPUT COLON string SEMICOLON",
"internal_power_data : internal_power_data when",
"internal_power_data : internal_power_data fall_power",
"internal_power_data : internal_power_data rise_power",
"internal_power_data : internal_power_data power",
"timing_data :",
"timing_data : timing_data related_pin",
"timing_data : timing_data timing_type",
"timing_data : timing_data timing_sense",
"timing_data : timing_data when",
"timing_data : timing_data sdf_cond",
"timing_data : timing_data cell_rise",
"timing_data : timing_data rise_transition",
"timing_data : timing_data cell_fall",
"timing_data : timing_data fall_transition",
"timing_data : timing_data rise_constraint",
"timing_data : timing_data fall_constraint",
"related_pin : RELATED_PIN COLON string SEMICOLON",
"timing_type : TIMING_TYPE COLON string SEMICOLON",
"when : WHEN COLON string SEMICOLON",
"fall_power : FALL_POWER LPAREN string RPAREN LBRACE table RBRACE",
"rise_power : RISE_POWER LPAREN string RPAREN LBRACE table RBRACE",
"power : POWER LPAREN string RPAREN LBRACE table RBRACE",
"timing_sense : TIMING_SENSE COLON POSITIVE_UNATE SEMICOLON",
"timing_sense : TIMING_SENSE COLON NEGATIVE_UNATE SEMICOLON",
"timing_sense : TIMING_SENSE COLON NON_UNATE SEMICOLON",
"sdf_cond : SDF_COND COLON string SEMICOLON",
"cell_rise : CELL_RISE LPAREN string RPAREN LBRACE table RBRACE",
"rise_transition : RISE_TRANSITION LPAREN string RPAREN LBRACE table RBRACE",
"cell_fall : CELL_FALL LPAREN string RPAREN LBRACE table RBRACE",
"fall_transition : FALL_TRANSITION LPAREN string RPAREN LBRACE table RBRACE",
"rise_constraint : RISE_CONSTRAINT LPAREN string RPAREN LBRACE table RBRACE",
"fall_constraint : FALL_CONSTRAINT LPAREN string RPAREN LBRACE table RBRACE",
"table :",
"table : table INDEX_1 LPAREN multiple_values RPAREN SEMICOLON",
"table : table INDEX_2 LPAREN multiple_values RPAREN SEMICOLON",
"table : table INDEX_3 LPAREN multiple_values RPAREN SEMICOLON",
"table : table VALUES LPAREN multiple_values RPAREN SEMICOLON",
"multiple_values : multiple_quoted_strings",
"multiple_values : values_comma",
"multiple_quoted_strings : QUOTED_STRING",
"multiple_quoted_strings : multiple_quoted_strings COMMA QUOTED_STRING",
"values_comma : value",
"values_comma : values_comma COMMA value",
"string : STRING",
"string : QUOTED_STRING",
"string : INTEGER",
"string : DECIMAL",
"strings : string",
"strings : strings string",
"value : INTEGER",
"value : DECIMAL",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 169 "parser.yy"
	{
}
break;
case 11:
#line 188 "parser.yy"
	{
  __y_cell.clear();
}
break;
case 12:
#line 192 "parser.yy"
	{
  __y_library.addCell(__y_cell);
  __y_cell.clear();
}
break;
case 18:
#line 214 "parser.yy"
	{
  __y_cell.setName(yystack.l_mark[-4].string);
  free(yystack.l_mark[-4].string);
}
break;
case 50:
#line 266 "parser.yy"
	{
  __y_cell.setFootprint(yystack.l_mark[-1].string);
  free(yystack.l_mark[-1].string);
}
break;
case 54:
#line 274 "parser.yy"
	{
  __y_cell.setArea(yystack.l_mark[-1].decimal);
}
break;
case 55:
#line 278 "parser.yy"
	{
  __y_cell.addPin(__y_pin);
  __y_pin.clear();
}
break;
case 66:
#line 300 "parser.yy"
	{
  __y_pin.setName(yystack.l_mark[-4].string);
  free(yystack.l_mark[-4].string);
}
break;
case 82:
#line 342 "parser.yy"
	{
  __y_pin.clear();
}
break;
case 94:
#line 357 "parser.yy"
	{
  __y_pin.setCapacitance(yystack.l_mark[-1].decimal);
}
break;
case 97:
#line 363 "parser.yy"
	{
  __y_pin.addTiming(__y_timing);
}
break;
case 129:
#line 422 "parser.yy"
	{
  __y_timing.clear();
}
break;
case 135:
#line 431 "parser.yy"
	{
  __y_timing.setCellRise(__y_table);
}
break;
case 136:
#line 435 "parser.yy"
	{
  __y_timing.setRiseTransition(__y_table);
}
break;
case 137:
#line 439 "parser.yy"
	{
  __y_timing.setCellFall(__y_table);
}
break;
case 138:
#line 443 "parser.yy"
	{
  __y_timing.setFallTransition(__y_table);
}
break;
case 157:
#line 496 "parser.yy"
	{
  __y_table.clear();
}
break;
case 158:
#line 500 "parser.yy"
	{
  __y_table.setIndex1(__y_values);
}
break;
case 159:
#line 504 "parser.yy"
	{
  __y_table.setIndex2(__y_values);
}
break;
case 160:
#line 508 "parser.yy"
	{
  __y_table.setIndex3(__y_values);
}
break;
case 161:
#line 512 "parser.yy"
	{
  __y_table.setValues(__y_values);
}
break;
case 164:
#line 523 "parser.yy"
	{
  __y_values = utils::splitMultipleValues(yystack.l_mark[0].string);
  free(yystack.l_mark[0].string);
}
break;
case 165:
#line 528 "parser.yy"
	{
  std::vector<double> tmp = utils::splitMultipleValues(yystack.l_mark[0].string);
  free(yystack.l_mark[0].string);
  std::vector<double> tmp2(tmp.size() + __y_values.size());
  copy(tmp.begin(), tmp.end(), 
    copy(__y_values.begin(), __y_values.end(), tmp2.begin()));
  __y_values = tmp2;
}
break;
case 166:
#line 540 "parser.yy"
	{
  __y_values.clear();
  __y_values.push_back(yystack.l_mark[0].decimal);
}
break;
case 167:
#line 545 "parser.yy"
	{
  __y_values.push_back(yystack.l_mark[0].decimal);
}
break;
case 168:
#line 551 "parser.yy"
	{
  yyval.string = strdup(yystack.l_mark[0].string);
  free(yystack.l_mark[0].string);
}
break;
case 169:
#line 556 "parser.yy"
	{
  yyval.string = strdup(yystack.l_mark[0].string);
  free(yystack.l_mark[0].string);
}
break;
case 170:
#line 561 "parser.yy"
	{
  yyval.string = strdup("INTEGER");
}
break;
case 171:
#line 565 "parser.yy"
	{
  yyval.string = strdup("DECIMAL");
}
break;
case 172:
#line 572 "parser.yy"
	{
}
break;
case 173:
#line 575 "parser.yy"
	{
}
break;
case 174:
#line 580 "parser.yy"
	{
  yyval.decimal = yystack.l_mark[0].integer;
}
break;
case 175:
#line 584 "parser.yy"
	{
  yyval.decimal = yystack.l_mark[0].decimal;
}
break;
#line 1204 "parser.cc"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
