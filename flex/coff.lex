%{

#include "scanner.hh"

int column = 0;

extern YYLTYPE yylloc;

%}

%option yylineno
%option 8bit
%option noyywrap
%option caseless
%option outfile = "scanner.cc"

/* flex declarations */
DIGIT		[0-9]
REAL		(({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)[eE][-+]?{DIGIT}+)|({DIGIT}*\.{DIGIT}+)|({DIGIT}+\.)
ID			[a-zA-Z_][a-zA-Z0-9_]*
STR			'([^'\n]|'')*'

/* code */
%%

\.			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_DOT;
			}

;			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_SEMICOLON;
			}

= 			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_EQ;
			}

\:			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_COLON;
			}

\(			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_LEFTPAR;	
			}

\)			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_RIGHTPAR;
			}

\[			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_LEFTBRACKET;	
			}

\]			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_RIGHTBRACKET;
			}

,			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_COMMA;
			}

\<			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_LESSTHAN;
			}

\>			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_GREATERTHAN;
			}

\+			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_ADD;
			}

\-			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_SUB;
			}

\*			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_MULT;
			}

\/			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				// TODO: return T_DIV;
			}

"\n"		{
				column = 0;
			}

\/\/.*$		column = 0; /* skip single line comment */

[[:blank:]]	{
				column++;
			}

<<EOF>>		yyterminate();

%%