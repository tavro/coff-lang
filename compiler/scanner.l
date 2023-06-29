%{

#include "scanner.hh"
#include "symtab.hh"

int column = 0;

extern YYLTYPE yylloc; // position information

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
				return T_DOT;
			}

;			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_SEMICOLON;
			}

= 			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_EQ;
			}

\:			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_COLON;
			}

\(			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_LEFTPAR;	
			}

\)			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_RIGHTPAR;
			}

\[			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_LEFTBRACKET;	
			}

\]			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_RIGHTBRACKET;
			}

,			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_COMMA;
			}

\<			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_LESSTHAN;
			}

\>			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_GREATERTHAN;
			}

\+			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_ADD;
			}

\-			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_SUB;
			}

\*			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_MULT;
			}

\/			{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_DIV;
			}

(?i:if)		{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_IF;
			}

(?i:else)	{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_ELSE;
			}

(?i:elseif)	{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_ELSEIF;
			}

(?i:const)	{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_CONST;
			}

(?i:while)	{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_WHILE;
			}

(?i:return)	{
				yylloc.first_line = yylineno;
				yylloc.first_column = column;
				column += yyleng;
				return T_RETURN;
			}

(?i:program) 	{
					yylloc.first_line = yylineno;
					yylloc.first_column = column;
					column += yyleng;
					return T_PROGRAM;
			 	}

(?i:function)	{
					yylloc.first_line = yylineno;
					yylloc.first_column = column;
					column += yyleng;
					return T_FUNCTION;
				}

{DIGIT}+	{
				yylloc.first_line = yylineno;
                yylloc.first_column = column;
                column += yyleng;

				/* 
				TODO:            
                long value = strtol(yytext, 0, 10);
                if(value == LONG_MAX && errno == ERANGE)
                    yyerror("Integer out of range");
                yylval.ival = value;
				*/

                return T_INT;
			}

{REAL}		{
				yylloc.first_line = yylineno;
                yylloc.first_column = column;
                column += yyleng;
                
				/*
				TODO:
				char *ptr;
                yylval.rval = strtod(yytext, &ptr);
				*/

            	return T_REAL;
			}

{ID}+		{
				yylloc.first_line = yylineno;
                yylloc.first_column = column;
                column += yyleng;

				/*
				TODO:
                yylval.pool_p = sym_tab->pool_install(sym_tab->capitalize(yytext));
				*/
				
                return T_ID;
			}

{STR}		{
				yylloc.first_line = yylineno;
                yylloc.first_column = column;
                column += yyleng;

				/*
				TODO:
				yylval.str = sym_tab->pool_install(sym_tab->fix_string(yytext));
				*/

                return T_STRING;
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