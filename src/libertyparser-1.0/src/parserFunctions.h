// ****************************************************************************
// ****************************************************************************
// parserFunctions.h
//
// Header file included by the yacc generated parser.
//
// *****************************************************************************



/*
 * Author: Puneet Sharma <sharma@ucsd.edu>
 * Date: Nov 06, 2006
 */

#ifndef __PARSER_H__
#define __PARSER_H__

extern "C"
{
	int yyparse(void);
	int yylex(void);
	int yywrap(void);
	int yyerror(char *str);
}

//extern liberty::Library __y_library;

#endif
