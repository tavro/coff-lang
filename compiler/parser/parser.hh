/* A Bison parser, made by GNU Bison 3.8.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_PARSER_HH_INCLUDED
# define YY_YY_PARSER_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_EOF = 258,                   /* T_EOF  */
    T_ERROR = 259,                 /* T_ERROR  */
    T_DOT = 260,                   /* T_DOT  */
    T_SEMICOLON = 261,             /* T_SEMICOLON  */
    T_EQ = 262,                    /* T_EQ  */
    T_COLON = 263,                 /* T_COLON  */
    T_LEFTBRACKET = 264,           /* T_LEFTBRACKET  */
    T_RIGHTBRACKET = 265,          /* T_RIGHTBRACKET  */
    T_LEFTPAR = 266,               /* T_LEFTPAR  */
    T_RIGHTPAR = 267,              /* T_RIGHTPAR  */
    T_COMMA = 268,                 /* T_COMMA  */
    T_LESSTHAN = 269,              /* T_LESSTHAN  */
    T_GREATERTHAN = 270,           /* T_GREATERTHAN  */
    T_ADD = 271,                   /* T_ADD  */
    T_SUB = 272,                   /* T_SUB  */
    T_MULT = 273,                  /* T_MULT  */
    T_DIV = 274,                   /* T_DIV  */
    T_IF = 275,                    /* T_IF  */
    T_VAR = 276,                   /* T_VAR  */
    T_OF = 277,                    /* T_OF  */
    T_DO = 278,                    /* T_DO  */
    T_ASSIGN = 279,                /* T_ASSIGN  */
    T_NOTEQ = 280,                 /* T_NOTEQ  */
    T_OR = 281,                    /* T_OR  */
    T_ELSE = 282,                  /* T_ELSE  */
    T_CONST = 283,                 /* T_CONST  */
    T_ARRAY = 284,                 /* T_ARRAY  */
    T_AND = 285,                   /* T_AND  */
    T_NOT = 286,                   /* T_NOT  */
    T_MOD = 287,                   /* T_MOD  */
    T_WHILE = 288,                 /* T_WHILE  */
    T_ELSEIF = 289,                /* T_ELSEIF  */
    T_RETURN = 290,                /* T_RETURN  */
    T_STRING = 291,                /* T_STRING  */
    T_ID = 292,                    /* T_ID  */
    T_PROGRAM = 293,               /* T_PROGRAM  */
    T_PROCEDURE = 294,             /* T_PROCEDURE  */
    T_FUNCTION = 295,              /* T_FUNCTION  */
    T_INT = 296,                   /* T_INT  */
    T_REAL = 297                   /* T_REAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "./parser/parser.y"

    ast_node            *ast;
    ast_id              *id;
    ast_statement_list  *statement_list;
    ast_statement       *statement;
    ast_expression_list *expression_list;
    ast_expression      *expression;
    ast_elseif_list     *elseif_list;
    ast_elseif          *elseif;
    ast_lval            *lval;
    ast_function_call   *function_call;
    ast_function_head   *function_head;
    ast_procedure_head  *procedure_head;
    ast_int             *integer;
    ast_real            *real;

    long                ival;
    double              rval;
    pool_index          str;
    pool_index          pool_p;

#line 128 "./parser/parser.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_HH_INCLUDED  */
