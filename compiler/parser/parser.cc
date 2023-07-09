/* A Bison parser, made by GNU Bison 3.8.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30800

/* Bison version string.  */
#define YYBISON_VERSION "3.8"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./parser/parser.y"

#include <iostream>
#include "../semantics/semantic.hh"
#include "../codegen/codegen.hh"
#include "../optimizer/optimize.hh"

extern char *yytext;
extern int error_count;         // defined in error.cc
extern symbol_table *sym_tab;   // defined in symtab.cc
extern semantic *type_checker;
extern code_generator *code_gen;

extern int yylex();
extern void yyerror(string);

extern bool print_ast;
extern bool print_quads;
extern bool type_check;
extern bool optimize;
extern bool quads;
extern bool assembler;

#define YYDEBUG 1

#line 96 "./parser/parser.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_EOF = 3,                      /* T_EOF  */
  YYSYMBOL_T_ERROR = 4,                    /* T_ERROR  */
  YYSYMBOL_T_DOT = 5,                      /* T_DOT  */
  YYSYMBOL_T_SEMICOLON = 6,                /* T_SEMICOLON  */
  YYSYMBOL_T_EQ = 7,                       /* T_EQ  */
  YYSYMBOL_T_COLON = 8,                    /* T_COLON  */
  YYSYMBOL_T_LEFTBRACKET = 9,              /* T_LEFTBRACKET  */
  YYSYMBOL_T_RIGHTBRACKET = 10,            /* T_RIGHTBRACKET  */
  YYSYMBOL_T_LEFTPAR = 11,                 /* T_LEFTPAR  */
  YYSYMBOL_T_RIGHTPAR = 12,                /* T_RIGHTPAR  */
  YYSYMBOL_T_COMMA = 13,                   /* T_COMMA  */
  YYSYMBOL_T_LESSTHAN = 14,                /* T_LESSTHAN  */
  YYSYMBOL_T_GREATERTHAN = 15,             /* T_GREATERTHAN  */
  YYSYMBOL_T_CURLYLEFT = 16,               /* T_CURLYLEFT  */
  YYSYMBOL_T_CURLYRIGHT = 17,              /* T_CURLYRIGHT  */
  YYSYMBOL_T_ADD = 18,                     /* T_ADD  */
  YYSYMBOL_T_SUB = 19,                     /* T_SUB  */
  YYSYMBOL_T_MULT = 20,                    /* T_MULT  */
  YYSYMBOL_T_DIV = 21,                     /* T_DIV  */
  YYSYMBOL_T_IF = 22,                      /* T_IF  */
  YYSYMBOL_T_VAR = 23,                     /* T_VAR  */
  YYSYMBOL_T_OF = 24,                      /* T_OF  */
  YYSYMBOL_T_DO = 25,                      /* T_DO  */
  YYSYMBOL_T_ASSIGN = 26,                  /* T_ASSIGN  */
  YYSYMBOL_T_NOTEQ = 27,                   /* T_NOTEQ  */
  YYSYMBOL_T_OR = 28,                      /* T_OR  */
  YYSYMBOL_T_ELSE = 29,                    /* T_ELSE  */
  YYSYMBOL_T_CONST = 30,                   /* T_CONST  */
  YYSYMBOL_T_ARRAY = 31,                   /* T_ARRAY  */
  YYSYMBOL_T_AND = 32,                     /* T_AND  */
  YYSYMBOL_T_NOT = 33,                     /* T_NOT  */
  YYSYMBOL_T_MOD = 34,                     /* T_MOD  */
  YYSYMBOL_T_WHILE = 35,                   /* T_WHILE  */
  YYSYMBOL_T_ELSEIF = 36,                  /* T_ELSEIF  */
  YYSYMBOL_T_RETURN = 37,                  /* T_RETURN  */
  YYSYMBOL_T_STRING = 38,                  /* T_STRING  */
  YYSYMBOL_T_SUBPROG = 39,                 /* T_SUBPROG  */
  YYSYMBOL_T_MAIN = 40,                    /* T_MAIN  */
  YYSYMBOL_T_ID = 41,                      /* T_ID  */
  YYSYMBOL_T_PROGRAM = 42,                 /* T_PROGRAM  */
  YYSYMBOL_T_PROCEDURE = 43,               /* T_PROCEDURE  */
  YYSYMBOL_T_FUNCTION = 44,                /* T_FUNCTION  */
  YYSYMBOL_T_INT = 45,                     /* T_INT  */
  YYSYMBOL_T_REAL = 46,                    /* T_REAL  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_prog_decl = 49,                 /* prog_decl  */
  YYSYMBOL_prog_head = 50,                 /* prog_head  */
  YYSYMBOL_const_part = 51,                /* const_part  */
  YYSYMBOL_const_decls = 52,               /* const_decls  */
  YYSYMBOL_const_decl = 53,                /* const_decl  */
  YYSYMBOL_var_part = 54,                  /* var_part  */
  YYSYMBOL_var_decls = 55,                 /* var_decls  */
  YYSYMBOL_var_decl = 56,                  /* var_decl  */
  YYSYMBOL_subprog_part = 57,              /* subprog_part  */
  YYSYMBOL_subprog_decls = 58,             /* subprog_decls  */
  YYSYMBOL_subprog_decl = 59,              /* subprog_decl  */
  YYSYMBOL_proc_decl = 60,                 /* proc_decl  */
  YYSYMBOL_func_decl = 61,                 /* func_decl  */
  YYSYMBOL_proc_head = 62,                 /* proc_head  */
  YYSYMBOL_func_head = 63,                 /* func_head  */
  YYSYMBOL_opt_param_list = 64,            /* opt_param_list  */
  YYSYMBOL_param_list = 65,                /* param_list  */
  YYSYMBOL_param = 66,                     /* param  */
  YYSYMBOL_comp_stmt = 67,                 /* comp_stmt  */
  YYSYMBOL_main_comp_stmt = 68,            /* main_comp_stmt  */
  YYSYMBOL_stmt_list = 69,                 /* stmt_list  */
  YYSYMBOL_stmt = 70,                      /* stmt  */
  YYSYMBOL_lvar = 71,                      /* lvar  */
  YYSYMBOL_rvar = 72,                      /* rvar  */
  YYSYMBOL_elseif_list = 73,               /* elseif_list  */
  YYSYMBOL_elseif = 74,                    /* elseif  */
  YYSYMBOL_else_part = 75,                 /* else_part  */
  YYSYMBOL_opt_expr_list = 76,             /* opt_expr_list  */
  YYSYMBOL_expr_list = 77,                 /* expr_list  */
  YYSYMBOL_expr = 78,                      /* expr  */
  YYSYMBOL_simple_expr = 79,               /* simple_expr  */
  YYSYMBOL_term = 80,                      /* term  */
  YYSYMBOL_factor = 81,                    /* factor  */
  YYSYMBOL_func_call = 82,                 /* func_call  */
  YYSYMBOL_integer = 83,                   /* integer  */
  YYSYMBOL_real = 84,                      /* real  */
  YYSYMBOL_type_id = 85,                   /* type_id  */
  YYSYMBOL_const_id = 86,                  /* const_id  */
  YYSYMBOL_lvar_id = 87,                   /* lvar_id  */
  YYSYMBOL_rvar_id = 88,                   /* rvar_id  */
  YYSYMBOL_proc_id = 89,                   /* proc_id  */
  YYSYMBOL_func_id = 90,                   /* func_id  */
  YYSYMBOL_array_id = 91,                  /* array_id  */
  YYSYMBOL_id = 92                         /* id  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,   131,   137,   148,   149,   150,   153,   154,
     157,   162,   167,   171,   188,   194,   195,   198,   199,   202,
     207,   212,   235,   236,   239,   240,   243,   281,   321,   327,
     334,   349,   357,   361,   367,   372,   378,   383,   394,   400,
     406,   415,   429,   435,   440,   444,   448,   453,   459,   464,
     468,   472,   478,   482,   486,   493,   498,   503,   510,   515,
     520,   525,   530,   534,   540,   544,   548,   552,   556,   562,
     566,   570,   574,   578,   582,   588,   593,   596,   600,   604,
     608,   614,   618,   622,   626,   630,   635,   641,   647,   654,
     661,   672,   683,   694,   705,   716,   727,   738
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_EOF", "T_ERROR",
  "T_DOT", "T_SEMICOLON", "T_EQ", "T_COLON", "T_LEFTBRACKET",
  "T_RIGHTBRACKET", "T_LEFTPAR", "T_RIGHTPAR", "T_COMMA", "T_LESSTHAN",
  "T_GREATERTHAN", "T_CURLYLEFT", "T_CURLYRIGHT", "T_ADD", "T_SUB",
  "T_MULT", "T_DIV", "T_IF", "T_VAR", "T_OF", "T_DO", "T_ASSIGN",
  "T_NOTEQ", "T_OR", "T_ELSE", "T_CONST", "T_ARRAY", "T_AND", "T_NOT",
  "T_MOD", "T_WHILE", "T_ELSEIF", "T_RETURN", "T_STRING", "T_SUBPROG",
  "T_MAIN", "T_ID", "T_PROGRAM", "T_PROCEDURE", "T_FUNCTION", "T_INT",
  "T_REAL", "$accept", "program", "prog_decl", "prog_head", "const_part",
  "const_decls", "const_decl", "var_part", "var_decls", "var_decl",
  "subprog_part", "subprog_decls", "subprog_decl", "proc_decl",
  "func_decl", "proc_head", "func_head", "opt_param_list", "param_list",
  "param", "comp_stmt", "main_comp_stmt", "stmt_list", "stmt", "lvar",
  "rvar", "elseif_list", "elseif", "else_part", "opt_expr_list",
  "expr_list", "expr", "simple_expr", "term", "factor", "func_call",
  "integer", "real", "type_id", "const_id", "lvar_id", "rvar_id",
  "proc_id", "func_id", "array_id", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    25,    88,    76,  -111,  -111,  -111,    47,  -111,    60,
      60,    79,    99,    60,  -111,    60,    73,    83,     4,  -111,
     117,    73,  -111,   125,    94,   129,   139,  -111,  -111,  -111,
     141,   142,   143,  -111,     2,  -111,    74,   140,  -111,  -111,
    -111,  -111,  -111,   148,   153,  -111,   119,   122,    74,  -111,
     152,   152,   156,   156,    -3,    37,  -111,  -111,  -111,  -111,
     176,  -111,  -111,     0,  -111,   167,   183,   183,    62,    11,
    -111,   150,  -111,   175,   178,   102,   179,   180,    79,   188,
     196,    19,  -111,   164,   183,   177,   177,   177,  -111,   205,
      81,    42,  -111,  -111,  -111,  -111,  -111,   198,   182,   135,
     124,   234,    -3,   197,   183,   162,   109,   164,   164,    83,
    -111,   164,   184,  -111,  -111,   223,    42,    42,  -111,   183,
     183,   183,   183,   215,   177,   177,   177,   177,   177,   177,
     177,   162,   151,    -3,  -111,  -111,   234,   214,   218,   234,
     224,     8,   227,   239,    -3,  -111,  -111,  -111,    81,    81,
      81,    81,    68,    42,    42,    42,  -111,  -111,  -111,  -111,
     235,   241,   229,    23,  -111,   183,  -111,  -111,  -111,  -111,
      58,    -3,   183,  -111,  -111,  -111,  -111,  -111,  -111,   234,
    -111,   215,   205,   215
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     4,     1,     0,     2,     0,
       0,    16,     0,     6,     8,     5,     0,    23,     0,     9,
       0,    15,    17,     0,     0,     0,     0,    97,    88,    89,
       0,     0,     0,    91,     0,    18,     0,     0,    14,    12,
      10,    11,    13,     0,     0,    90,     0,     0,    22,    24,
       0,     0,    34,    34,    48,     0,    19,    30,    31,    25,
       0,    26,    27,     0,    28,     0,    76,    76,    76,     0,
      40,     0,    49,     0,     0,    92,     0,     0,    16,     0,
       0,     0,    35,     0,    76,    76,    76,     0,    81,    48,
      64,    69,    75,    82,    83,    84,    52,     0,     0,    93,
       0,    46,    48,     0,    76,    76,     0,     0,     0,    23,
      33,     0,     0,    32,    29,     0,    70,    71,    85,    76,
      76,    76,    76,    56,    76,    76,    76,     0,     0,     0,
       0,    76,     0,    48,    41,    39,    45,     0,    60,    62,
       0,     0,     0,     0,    48,    37,    36,    86,    65,    67,
      68,    66,    59,    73,    74,    72,    79,    80,    78,    77,
       0,     0,     0,     0,    44,    76,    51,    50,    20,    21,
       0,    48,    76,    55,    42,    87,    54,    53,    43,    63,
      38,    58,    48,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,   192,   243,    54,   181,  -111,   233,
     146,  -111,   209,  -111,  -111,  -111,  -111,   207,  -111,   154,
     211,  -111,   -86,   161,  -111,  -111,  -111,  -111,  -111,   127,
    -111,   -60,  -110,   -65,   -74,  -111,    -4,   246,   -81,   210,
    -111,  -111,  -111,  -111,   -50,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    11,    13,    14,    17,    21,    22,
      24,    48,    49,    50,    51,    52,    53,    64,    81,    82,
      61,     8,    69,    70,    71,    88,   152,   173,   174,   137,
     138,   139,    90,    91,    92,    93,    94,    95,    44,    32,
      72,    96,    73,    97,    98,    99
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    79,   114,   123,    74,    25,    89,   100,   101,   148,
     149,   150,   151,   118,    30,   119,    45,   102,   167,    66,
     116,   117,   120,   121,   115,   112,   142,   143,   103,   102,
     145,   113,    67,    43,    68,   122,    75,    33,    27,    74,
     178,    80,    26,    27,   136,    27,   141,   163,     9,    28,
      29,    76,    74,   156,   157,   158,   159,     1,   170,   153,
     154,   155,   127,   128,   102,    45,     5,    19,   -47,    19,
      -7,    75,   162,    84,   129,   180,   130,    10,    27,   -47,
      85,    86,    28,    74,    75,   181,    -7,    -7,     6,    45,
      45,   -47,     7,    45,    74,    87,   183,   171,   -47,   124,
     125,    12,    16,    27,   172,   179,    18,    28,    29,   126,
     140,   -96,   182,   -94,    20,    75,   -76,    46,    47,   -76,
      84,    74,    23,   -76,   -76,    34,    75,    85,    86,   -76,
     -76,   119,    74,    36,    37,    38,   -76,   -76,   120,   121,
     133,   -76,    87,   -76,   -96,    39,   -95,    40,    41,    42,
      27,   122,   161,    75,    28,    29,    54,    55,   -76,    56,
      57,   -76,    84,    58,    75,   -76,   -76,    63,    60,    85,
      86,   -76,   -76,    84,   -61,    83,   104,     9,   -76,   -76,
      85,    86,    -7,   -76,    87,   -76,   105,   106,    84,   107,
     108,   132,    27,    -7,    84,    87,    28,    29,    -7,    -7,
     110,    85,    86,    27,   111,    27,    10,    28,    29,   131,
      87,    -7,   119,    -7,   135,    -7,    87,    -7,    27,   120,
     121,   102,    28,    29,    27,    80,   164,    66,    28,    29,
     119,   165,   122,   168,   166,   147,   119,   120,   121,   177,
      67,   119,    68,   120,   121,   169,    27,   175,   120,   121,
     122,   176,    78,    15,    35,   144,   122,    59,   160,   109,
      65,   122,    62,   134,    31,    77,   146
};

static const yytype_uint8 yycheck[] =
{
      18,     1,    83,    89,    54,     1,    66,    67,    68,   119,
     120,   121,   122,    87,    18,     7,    34,     6,    10,    22,
      85,    86,    14,    15,    84,     6,   107,   108,    17,     6,
     111,    12,    35,    31,    37,    27,    54,    55,    41,    89,
      17,    41,    38,    41,   104,    41,   106,   133,     1,    45,
      46,    55,   102,   127,   128,   129,   130,    42,   144,   124,
     125,   126,    20,    21,     6,    83,    41,    13,     6,    15,
      23,    89,   132,    11,    32,    17,    34,    30,    41,    17,
      18,    19,    45,   133,   102,   171,    39,    40,     0,   107,
     108,    29,    16,   111,   144,    33,   182,    29,    36,    18,
      19,    41,    23,    41,    36,   165,     7,    45,    46,    28,
       1,     9,   172,    11,    41,   133,     7,    43,    44,    10,
      11,   171,    39,    14,    15,     8,   144,    18,    19,    20,
      21,     7,   182,     8,    40,     6,    27,    28,    14,    15,
      16,    32,    33,    34,     9,     6,    11,     6,     6,     6,
      41,    27,     1,   171,    45,    46,    16,     9,     7,     6,
      41,    10,    11,    41,   182,    14,    15,    11,    16,    18,
      19,    20,    21,    11,    12,     8,    26,     1,    27,    28,
      18,    19,     6,    32,    33,    34,    11,     9,    11,    10,
      10,     9,    41,    17,    11,    33,    45,    46,    22,    23,
      12,    18,    19,    41,     8,    41,    30,    45,    46,    11,
      33,    35,     7,    37,    17,    39,    33,    41,    41,    14,
      15,     6,    45,    46,    41,    41,    12,    22,    45,    46,
       7,    13,    27,     6,    10,    12,     7,    14,    15,    10,
      35,     7,    37,    14,    15,     6,    41,    12,    14,    15,
      27,    10,    60,    10,    21,   109,    27,    48,   131,    78,
      53,    27,    51,   102,    18,    55,   112
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    48,    49,    50,    41,     0,    16,    68,     1,
      30,    51,    41,    52,    53,    52,    23,    54,     7,    53,
      41,    55,    56,    39,    57,     1,    38,    41,    45,    46,
      83,    84,    86,    92,     8,    56,     8,    40,     6,     6,
       6,     6,     6,    31,    85,    92,    43,    44,    58,    59,
      60,    61,    62,    63,    16,     9,     6,    41,    41,    59,
      16,    67,    67,    11,    64,    64,    22,    35,    37,    69,
      70,    71,    87,    89,    91,    92,    83,    86,    51,     1,
      41,    65,    66,     8,    11,    18,    19,    33,    72,    78,
      79,    80,    81,    82,    83,    84,    88,    90,    91,    92,
      78,    78,     6,    17,    26,    11,     9,    10,    10,    54,
      12,     8,     6,    12,    85,    78,    80,    80,    81,     7,
      14,    15,    27,    69,    18,    19,    28,    20,    21,    32,
      34,    11,     9,    16,    70,    17,    78,    76,    77,    78,
       1,    78,    85,    85,    57,    85,    66,    12,    79,    79,
      79,    79,    73,    80,    80,    80,    81,    81,    81,    81,
      76,     1,    78,    69,    12,    13,    10,    10,     6,     6,
      69,    29,    36,    74,    75,    12,    10,    10,    17,    78,
      17,    69,    78,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    51,    52,    52,
      53,    53,    53,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    61,
      62,    63,    64,    64,    64,    65,    65,    66,    67,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    72,    72,    72,    73,    73,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     0,     1,     2,
       4,     4,     4,     4,     4,     2,     0,     1,     2,     4,
       8,     8,     3,     0,     1,     2,     2,     2,     2,     4,
       2,     2,     3,     3,     0,     1,     3,     3,     6,     9,
       1,     3,     5,     5,     4,     3,     2,     1,     0,     1,
       4,     4,     1,     4,     4,     2,     0,     3,     2,     0,
       1,     0,     1,     3,     1,     3,     3,     3,     3,     1,
       2,     2,     3,     3,     3,     1,     0,     3,     3,     3,
       3,     1,     1,     1,     1,     2,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: prog_decl main_comp_stmt  */
#line 87 "./parser/parser.y"
                    {
                        symbol *env = sym_tab->get_symbol((yyvsp[-1].procedure_head)->sym_p);

                        // following code depends on flags passed to compiler
                        if(type_check) {
                            type_checker->do_typecheck(env, (yyvsp[0].statement_list));
                        }

                        if(print_ast) {
                            cout << "Unoptimized AST for global level" << endl;
                            cout << (ast_statement_list *)(yyvsp[0].statement_list) << endl;
                        }

                        if(optimize) {
                            optimizer->do_optimize((yyvsp[0].statement_list));
                            if(print_ast) {
                                cout << "\nOptimized AST for global level" << endl;
                                cout << (ast_statement_list *)(yyvsp[0].statement_list) << endl;
                            }
                        }

                        if(error_count == 0) {
                            if(quads) {
                                quad_list *q = (yyvsp[-1].procedure_head)->do_quads((yyvsp[0].statement_list));
                                if(print_quads) {
                                    cout << "\nQuad list for global level" << endl;
                                    cout << (quad_list *)q << endl;
                                }

                                if(assembler) {
                                    cout << "Generating assembler, global level" << endl;
                                    code_gen->generate_assembler(q, env);
                                }
                            }
                        }
                        else {
                            cout << "Found " << error_count << " errors. "
                                 << "Compilation aborted.\n";
                        }

                        sym_tab->close_scope();
                    }
#line 1479 "./parser/parser.cc"
    break;

  case 3: /* prog_decl: prog_head  */
#line 132 "./parser/parser.y"
                    {
                        (yyval.procedure_head) = (yyvsp[0].procedure_head);
                    }
#line 1487 "./parser/parser.cc"
    break;

  case 4: /* prog_head: T_PROGRAM T_ID  */
#line 138 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);

                        sym_index index = sym_tab->enter_procedure(pos, (yyvsp[0].pool_p));

                        (yyval.procedure_head) = new ast_procedure_head(pos, index);
                        sym_tab->open_scope();
                    }
#line 1500 "./parser/parser.cc"
    break;

  case 10: /* const_decl: T_ID T_EQ integer T_SEMICOLON  */
#line 158 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), int_type, (yyvsp[-1].integer)->value);
                    }
#line 1509 "./parser/parser.cc"
    break;

  case 11: /* const_decl: T_ID T_EQ real T_SEMICOLON  */
#line 163 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), real_type, (yyvsp[-1].real)->value);
                    }
#line 1518 "./parser/parser.cc"
    break;

  case 12: /* const_decl: T_ID T_EQ T_STRING T_SEMICOLON  */
#line 168 "./parser/parser.y"
                    {
                        // TODO: Not supported in Coff yet.
                    }
#line 1526 "./parser/parser.cc"
    break;

  case 13: /* const_decl: T_ID T_EQ const_id T_SEMICOLON  */
#line 172 "./parser/parser.y"
                    {
                        /*
                        EXAMPLE:
                        const foo = 0;
                        const bar = foo;
                        */
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        constant_symbol* sym = sym_tab->get_symbol((yyvsp[-1].id)->sym_p)->get_constant_symbol();

                        if((yyvsp[-1].id)->type == int_type) {
                            sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), (yyvsp[-1].id)->type, sym->const_value.ival);
                        }
                        else {
                            sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), (yyvsp[-1].id)->type, sym->const_value.rval);
                        }
                    }
#line 1547 "./parser/parser.cc"
    break;

  case 14: /* const_decl: T_ID T_EQ error T_SEMICOLON  */
#line 189 "./parser/parser.y"
                    {
                        yyerrok;
                    }
#line 1555 "./parser/parser.cc"
    break;

  case 19: /* var_decl: T_ID T_COLON type_id T_SEMICOLON  */
#line 203 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_variable(pos, (yyvsp[-3].pool_p), (yyvsp[-1].id)->sym_p);
                    }
#line 1564 "./parser/parser.cc"
    break;

  case 20: /* var_decl: T_ID T_COLON T_ARRAY T_LEFTBRACKET integer T_RIGHTBRACKET type_id T_SEMICOLON  */
#line 208 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-7]).first_line, (yylsp[-7]).first_column);
                        sym_tab->enter_array(pos, (yyvsp[-7].pool_p), (yyvsp[-1].id)->sym_p, (yyvsp[-3].integer)->value);
                    }
#line 1573 "./parser/parser.cc"
    break;

  case 21: /* var_decl: T_ID T_COLON T_ARRAY T_LEFTBRACKET const_id T_RIGHTBRACKET type_id T_SEMICOLON  */
#line 213 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-7]).first_line, (yylsp[-7]).first_column);
                        
                        /*
                        prevent entering real values for cardinality
                        */
                        symbol *tmp = sym_tab->get_symbol((yyvsp[-3].id)->sym_p);
                        if(tmp == NULL || tmp->tag != SYM_CONST) {
                            type_error(pos) << "bad index in array declaration: " << yytext << endl << flush;
                        }
                        else {
                            constant_symbol *con = tmp->get_constant_symbol();
                            if(con->type == int_type) {
                                sym_tab->enter_array(pos, (yyvsp[-7].pool_p), (yyvsp[-1].id)->sym_p, con->const_value.ival);
                            }
                            else {
                                sym_tab->enter_array(pos, (yyvsp[-7].pool_p), (yyvsp[-1].id)->sym_p, ILLEGAL_ARRAY_CARD);
                            }
                        }
                    }
#line 1598 "./parser/parser.cc"
    break;

  case 26: /* subprog_decl: proc_decl comp_stmt  */
#line 244 "./parser/parser.y"
                    {
                        symbol *env = sym_tab->get_symbol((yyvsp[-1].procedure_head)->sym_p);

                        if(type_check) {
                            type_checker->do_typecheck(env, (yyvsp[0].statement_list));
                        }

                        if(print_ast) {
                            cout << "\nUnoptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                            cout << (ast_statement_list *)(yyvsp[0].statement_list) << endl;
                        }

                        if(optimize) {
                            optimizer->do_optimize((yyvsp[0].statement_list));
                            if(print_ast) {
                                cout << "\nOptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                cout << (ast_statement_list*)(yyvsp[0].statement_list) << endl;
                            }
                        }

                        if(error_count == 0) {
                            if(quads) {
                                quad_list *q = (yyvsp[-1].procedure_head)->do_quads((yyvsp[0].statement_list));
                                if(print_quads) {
                                    cout << "\nQuad list for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                    cout << (quad_list *)q << endl;
                                }

                                if(assembler) {
                                    cout << "Generating assembler for procedure \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                    code_gen->generate_assembler(q, env);
                                }
                            }
                        }

                        sym_tab->close_scope();
                    }
#line 1640 "./parser/parser.cc"
    break;

  case 27: /* subprog_decl: func_decl comp_stmt  */
#line 282 "./parser/parser.y"
                    {
                        symbol *env = sym_tab->get_symbol((yyvsp[-1].function_head)->sym_p);

                        if(type_check) {
                            type_checker->do_typecheck(env, (yyvsp[0].statement_list));
                        }

                        if(print_ast) {
                            cout << "\nUnoptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                            cout << (ast_statement_list *)(yyvsp[0].statement_list) << endl;
                        }

                        if(optimize) {
                            optimizer->do_optimize((yyvsp[0].statement_list));
                            if(print_ast) {
                                cout << "\nOptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                cout << (ast_statement_list*)(yyvsp[0].statement_list) << endl;
                            }
                        }

                        if(error_count == 0) {
                            if(quads) {
                                quad_list *q = (yyvsp[-1].function_head)->do_quads((yyvsp[0].statement_list));
                                if(print_quads) {
                                    cout << "\nQuad list for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                    cout << (quad_list *)q << endl;
                                }

                                if(assembler) {
                                    cout << "Generating assembler for procedure \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                    code_gen->generate_assembler(q, env);
                                }
                            }
                        }

                        sym_tab->close_scope();
                    }
#line 1682 "./parser/parser.cc"
    break;

  case 28: /* proc_decl: proc_head opt_param_list  */
#line 322 "./parser/parser.y"
                    {
                        (yyval.procedure_head) = (yyvsp[-1].procedure_head);
                    }
#line 1690 "./parser/parser.cc"
    break;

  case 29: /* func_decl: func_head opt_param_list T_COLON type_id  */
#line 328 "./parser/parser.y"
                    {
                        sym_tab->get_symbol((yyvsp[-3].function_head)->sym_p)->type = (yyvsp[0].id)->sym_p;
                        (yyval.function_head) = (yyvsp[-3].function_head);
                    }
#line 1699 "./parser/parser.cc"
    break;

  case 30: /* proc_head: T_PROCEDURE T_ID  */
#line 335 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                        sym_index proc_loc = sym_tab->enter_procedure(pos, (yyvsp[0].pool_p));
                        sym_tab->open_scope();
                        
                        /*
                        this AST node is a temporary node
                        to provide the symbol table index
                        for proc
                        */
                        (yyval.procedure_head) = new ast_procedure_head(pos, proc_loc);
                    }
#line 1716 "./parser/parser.cc"
    break;

  case 31: /* func_head: T_FUNCTION T_ID  */
#line 350 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                        sym_index func_loc = sym_tab->enter_function(pos, (yyvsp[0].pool_p));
                        sym_tab->open_scope();
                        (yyval.function_head) = new ast_function_head(pos, func_loc);
                    }
#line 1727 "./parser/parser.cc"
    break;

  case 32: /* opt_param_list: T_LEFTPAR param_list T_RIGHTPAR  */
#line 358 "./parser/parser.y"
                    {
                        (yyval.expression_list) = (yyvsp[-1].expression_list);
                    }
#line 1735 "./parser/parser.cc"
    break;

  case 33: /* opt_param_list: T_LEFTPAR error T_RIGHTPAR  */
#line 362 "./parser/parser.y"
                    {
                        yyerrok;
                        (yyval.expression_list) = NULL;
                    }
#line 1744 "./parser/parser.cc"
    break;

  case 34: /* opt_param_list: %empty  */
#line 367 "./parser/parser.y"
                    {
                        (yyval.expression_list) = NULL;
                    }
#line 1752 "./parser/parser.cc"
    break;

  case 35: /* param_list: param  */
#line 373 "./parser/parser.y"
                    {
                        /*
                        we use expr_lists for params
                        */
                    }
#line 1762 "./parser/parser.cc"
    break;

  case 36: /* param_list: param_list T_SEMICOLON param  */
#line 379 "./parser/parser.y"
                    {
                    }
#line 1769 "./parser/parser.cc"
    break;

  case 37: /* param: T_ID T_COLON type_id  */
#line 384 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                        
                        /*
                        param linking taken care of in enter_parameter
                        */
                        sym_index param_loc = sym_tab->enter_parameter(pos, (yyvsp[-2].pool_p), (yyvsp[0].id)->sym_p);
                    }
#line 1782 "./parser/parser.cc"
    break;

  case 38: /* comp_stmt: T_CURLYLEFT const_part var_part subprog_part stmt_list T_CURLYRIGHT  */
#line 395 "./parser/parser.y"
                    {
                        (yyval.statement_list) = (yyvsp[-1].statement_list);
                    }
#line 1790 "./parser/parser.cc"
    break;

  case 39: /* main_comp_stmt: T_CURLYLEFT const_part var_part subprog_part T_MAIN T_CURLYLEFT stmt_list T_CURLYRIGHT T_CURLYRIGHT  */
#line 401 "./parser/parser.y"
                    {
                        (yyval.statement_list) = (yyvsp[-2].statement_list);
                    }
#line 1798 "./parser/parser.cc"
    break;

  case 40: /* stmt_list: stmt  */
#line 407 "./parser/parser.y"
                    {
                        if((yyvsp[0].statement) != NULL) {
                            (yyval.statement_list) = new ast_statement_list((yyvsp[0].statement)->pos, (yyvsp[0].statement));
                        }
                        else {
                            (yyval.statement_list) = NULL;
                        }
                    }
#line 1811 "./parser/parser.cc"
    break;

  case 41: /* stmt_list: stmt_list T_SEMICOLON stmt  */
#line 416 "./parser/parser.y"
                    {
                        if((yyvsp[-2].statement_list) != NULL && (yyvsp[0].statement) != NULL) {
                            (yyval.statement_list) = new ast_statement_list((yyvsp[-2].statement_list)->pos, (yyvsp[0].statement), (yyvsp[-2].statement_list));
                        }
                        else if((yyvsp[0].statement) != NULL) {
                            (yyval.statement_list) = new ast_statement_list((yyvsp[0].statement)->pos, (yyvsp[0].statement));
                        }
                        else {
                            (yyval.statement_list) = (yyvsp[-2].statement_list);
                        }
                    }
#line 1827 "./parser/parser.cc"
    break;

  case 42: /* stmt: T_IF expr stmt_list elseif_list else_part  */
#line 430 "./parser/parser.y"
                    {
                        // TODO: may need end keyword
                        position_information* pos = new position_information((yylsp[-4]).first_line, (yylsp[-4]).first_column);
                        (yyval.statement) = new ast_if(pos, (yyvsp[-3].expression), (yyvsp[-2].statement_list), (yyvsp[-1].elseif_list), (yyvsp[0].statement_list));
                    }
#line 1837 "./parser/parser.cc"
    break;

  case 43: /* stmt: T_WHILE expr T_CURLYLEFT stmt_list T_CURLYRIGHT  */
#line 436 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-4]).first_line, (yylsp[-4]).first_column);
                        (yyval.statement) = new ast_while(pos, (yyvsp[-3].expression), (yyvsp[-1].statement_list));
                    }
#line 1846 "./parser/parser.cc"
    break;

  case 44: /* stmt: proc_id T_LEFTPAR opt_expr_list T_RIGHTPAR  */
#line 441 "./parser/parser.y"
                    {
                        (yyval.statement) = new ast_procedure_call((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression_list));
                    }
#line 1854 "./parser/parser.cc"
    break;

  case 45: /* stmt: lvar T_ASSIGN expr  */
#line 445 "./parser/parser.y"
                    {
                        (yyval.statement) = new ast_assign((yyvsp[-2].lval)->pos, (yyvsp[-2].lval), (yyvsp[0].expression));
                    }
#line 1862 "./parser/parser.cc"
    break;

  case 46: /* stmt: T_RETURN expr  */
#line 449 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                        (yyval.statement) = new ast_return(pos, (yyvsp[0].expression));
                    }
#line 1871 "./parser/parser.cc"
    break;

  case 47: /* stmt: T_RETURN  */
#line 454 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.statement) = new ast_return(pos);
                    }
#line 1880 "./parser/parser.cc"
    break;

  case 48: /* stmt: %empty  */
#line 459 "./parser/parser.y"
                    {
                        (yyval.statement) = NULL;
                    }
#line 1888 "./parser/parser.cc"
    break;

  case 49: /* lvar: lvar_id  */
#line 465 "./parser/parser.y"
                    {
                        (yyval.lval) = (yyvsp[0].id);
                    }
#line 1896 "./parser/parser.cc"
    break;

  case 50: /* lvar: array_id T_LEFTBRACKET expr T_RIGHTBRACKET  */
#line 469 "./parser/parser.y"
                    {
                        (yyval.lval) = new ast_indexed((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression));
                    }
#line 1904 "./parser/parser.cc"
    break;

  case 51: /* lvar: array_id T_LEFTBRACKET error T_RIGHTBRACKET  */
#line 473 "./parser/parser.y"
                    {
                        (yyval.lval) = NULL;
                    }
#line 1912 "./parser/parser.cc"
    break;

  case 52: /* rvar: rvar_id  */
#line 479 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].id);
                    }
#line 1920 "./parser/parser.cc"
    break;

  case 53: /* rvar: array_id T_LEFTBRACKET expr T_RIGHTBRACKET  */
#line 483 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_indexed((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression));
                    }
#line 1928 "./parser/parser.cc"
    break;

  case 54: /* rvar: array_id T_LEFTBRACKET error T_RIGHTBRACKET  */
#line 487 "./parser/parser.y"
                    {
                        yyerrok;
                        (yyval.expression) = NULL;
                    }
#line 1937 "./parser/parser.cc"
    break;

  case 55: /* elseif_list: elseif_list elseif  */
#line 494 "./parser/parser.y"
                    {
                        (yyval.elseif_list) = new ast_elseif_list((yyvsp[0].elseif)->pos, (yyvsp[0].elseif), (yyvsp[-1].elseif_list));
                    }
#line 1945 "./parser/parser.cc"
    break;

  case 56: /* elseif_list: %empty  */
#line 498 "./parser/parser.y"
                    {
                        (yyval.elseif_list) = NULL;
                    }
#line 1953 "./parser/parser.cc"
    break;

  case 57: /* elseif: T_ELSEIF expr stmt_list  */
#line 504 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                        (yyval.elseif) = new ast_elseif(pos, (yyvsp[-1].expression), (yyvsp[0].statement_list));
                    }
#line 1962 "./parser/parser.cc"
    break;

  case 58: /* else_part: T_ELSE stmt_list  */
#line 511 "./parser/parser.y"
                    {
                        (yyval.statement_list) = (yyvsp[0].statement_list);
                    }
#line 1970 "./parser/parser.cc"
    break;

  case 59: /* else_part: %empty  */
#line 515 "./parser/parser.y"
                    {
                        (yyval.statement_list) = NULL;
                    }
#line 1978 "./parser/parser.cc"
    break;

  case 60: /* opt_expr_list: expr_list  */
#line 521 "./parser/parser.y"
                    {
                        (yyval.expression_list) = (yyvsp[0].expression_list);
                    }
#line 1986 "./parser/parser.cc"
    break;

  case 61: /* opt_expr_list: %empty  */
#line 525 "./parser/parser.y"
                    {
                        (yyval.expression_list) = NULL;
                    }
#line 1994 "./parser/parser.cc"
    break;

  case 62: /* expr_list: expr  */
#line 531 "./parser/parser.y"
                    {
                        (yyval.expression_list) = new ast_expression_list((yyvsp[0].expression)->pos, (yyvsp[0].expression));
                    }
#line 2002 "./parser/parser.cc"
    break;

  case 63: /* expr_list: expr_list T_COMMA expr  */
#line 535 "./parser/parser.y"
                    {
                        (yyval.expression_list) = new ast_expression_list((yyvsp[-2].expression_list)->pos, (yyvsp[0].expression), (yyvsp[-2].expression_list));
                    }
#line 2010 "./parser/parser.cc"
    break;

  case 64: /* expr: simple_expr  */
#line 541 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2018 "./parser/parser.cc"
    break;

  case 65: /* expr: expr T_EQ simple_expr  */
#line 545 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_equal((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2026 "./parser/parser.cc"
    break;

  case 66: /* expr: expr T_NOTEQ simple_expr  */
#line 549 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_not_equal((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2034 "./parser/parser.cc"
    break;

  case 67: /* expr: expr T_LESSTHAN simple_expr  */
#line 553 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_less_than((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2042 "./parser/parser.cc"
    break;

  case 68: /* expr: expr T_GREATERTHAN simple_expr  */
#line 557 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_greater_than((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2050 "./parser/parser.cc"
    break;

  case 69: /* simple_expr: term  */
#line 563 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2058 "./parser/parser.cc"
    break;

  case 70: /* simple_expr: T_ADD term  */
#line 567 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2066 "./parser/parser.cc"
    break;

  case 71: /* simple_expr: T_SUB term  */
#line 571 "./parser/parser.y"
                    {
                        // TODO: uminus
                    }
#line 2074 "./parser/parser.cc"
    break;

  case 72: /* simple_expr: simple_expr T_OR term  */
#line 575 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_or((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2082 "./parser/parser.cc"
    break;

  case 73: /* simple_expr: simple_expr T_ADD term  */
#line 579 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_add((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2090 "./parser/parser.cc"
    break;

  case 74: /* simple_expr: simple_expr T_SUB term  */
#line 583 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_sub((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2098 "./parser/parser.cc"
    break;

  case 75: /* term: factor  */
#line 589 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2106 "./parser/parser.cc"
    break;

  case 76: /* term: %empty  */
#line 593 "./parser/parser.y"
                    {
                        // TODO: idiv/rdiv
                    }
#line 2114 "./parser/parser.cc"
    break;

  case 77: /* term: term T_MOD factor  */
#line 597 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_mod((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2122 "./parser/parser.cc"
    break;

  case 78: /* term: term T_AND factor  */
#line 601 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_and((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2130 "./parser/parser.cc"
    break;

  case 79: /* term: term T_MULT factor  */
#line 605 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_mult((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2138 "./parser/parser.cc"
    break;

  case 80: /* term: term T_DIV factor  */
#line 609 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_div((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2146 "./parser/parser.cc"
    break;

  case 81: /* factor: rvar  */
#line 615 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2154 "./parser/parser.cc"
    break;

  case 82: /* factor: func_call  */
#line 619 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].function_call);
                    }
#line 2162 "./parser/parser.cc"
    break;

  case 83: /* factor: integer  */
#line 623 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].integer);
                    }
#line 2170 "./parser/parser.cc"
    break;

  case 84: /* factor: real  */
#line 627 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].real);
                    }
#line 2178 "./parser/parser.cc"
    break;

  case 85: /* factor: T_NOT factor  */
#line 631 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
		                (yyval.expression) = new ast_not(pos, (yyvsp[0].expression));
                    }
#line 2187 "./parser/parser.cc"
    break;

  case 86: /* factor: T_LEFTPAR expr T_RIGHTPAR  */
#line 636 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[-1].expression);
                    }
#line 2195 "./parser/parser.cc"
    break;

  case 87: /* func_call: func_id T_LEFTPAR opt_expr_list T_RIGHTPAR  */
#line 642 "./parser/parser.y"
                    {
                        (yyval.function_call) = new ast_function_call((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression_list));
                    }
#line 2203 "./parser/parser.cc"
    break;

  case 88: /* integer: T_INT  */
#line 648 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.integer) = new ast_int(pos, (yyvsp[0].ival));
                    }
#line 2212 "./parser/parser.cc"
    break;

  case 89: /* real: T_REAL  */
#line 655 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.real) = new ast_real(pos, (yyvsp[0].rval));
                    }
#line 2221 "./parser/parser.cc"
    break;

  case 90: /* type_id: id  */
#line 662 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_TYPE) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as type: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2234 "./parser/parser.cc"
    break;

  case 91: /* const_id: id  */
#line 673 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as const: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2247 "./parser/parser.cc"
    break;

  case 92: /* lvar_id: id  */
#line 684 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR && sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as var or param: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2260 "./parser/parser.cc"
    break;

  case 93: /* rvar_id: id  */
#line 695 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR && sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM && sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST ) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as var, param or const: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2273 "./parser/parser.cc"
    break;

  case 94: /* proc_id: id  */
#line 706 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PROC) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as procedure: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2286 "./parser/parser.cc"
    break;

  case 95: /* func_id: id  */
#line 717 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_FUNC) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as function: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2299 "./parser/parser.cc"
    break;

  case 96: /* array_id: id  */
#line 728 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_ARRAY) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as array: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2312 "./parser/parser.cc"
    break;

  case 97: /* id: T_ID  */
#line 739 "./parser/parser.y"
                    {
                        sym_index sym_p;
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);

                        /*
                        make sure symbol is declared
                        */
                        sym_p = sym_tab->lookup_symbol((yyvsp[0].pool_p));
                        if(sym_p == NULL_SYM) {
                            type_error(pos) << "not declared: " << yytext << endl << flush;
                        }

                        (yyval.id) = new ast_id(pos, sym_p);
                        (yyval.id)->type = sym_tab->get_symbol_type(sym_p);
                    }
#line 2332 "./parser/parser.cc"
    break;


#line 2336 "./parser/parser.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 756 "./parser/parser.y"
