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
  YYSYMBOL_T_ID = 40,                      /* T_ID  */
  YYSYMBOL_T_PROGRAM = 41,                 /* T_PROGRAM  */
  YYSYMBOL_T_PROCEDURE = 42,               /* T_PROCEDURE  */
  YYSYMBOL_T_FUNCTION = 43,                /* T_FUNCTION  */
  YYSYMBOL_T_INT = 44,                     /* T_INT  */
  YYSYMBOL_T_REAL = 45,                    /* T_REAL  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_prog_decl = 48,                 /* prog_decl  */
  YYSYMBOL_prog_head = 49,                 /* prog_head  */
  YYSYMBOL_const_part = 50,                /* const_part  */
  YYSYMBOL_const_decls = 51,               /* const_decls  */
  YYSYMBOL_const_decl = 52,                /* const_decl  */
  YYSYMBOL_var_part = 53,                  /* var_part  */
  YYSYMBOL_var_decls = 54,                 /* var_decls  */
  YYSYMBOL_var_decl = 55,                  /* var_decl  */
  YYSYMBOL_subprog_part = 56,              /* subprog_part  */
  YYSYMBOL_subprog_decls = 57,             /* subprog_decls  */
  YYSYMBOL_subprog_decl = 58,              /* subprog_decl  */
  YYSYMBOL_proc_decl = 59,                 /* proc_decl  */
  YYSYMBOL_func_decl = 60,                 /* func_decl  */
  YYSYMBOL_proc_head = 61,                 /* proc_head  */
  YYSYMBOL_func_head = 62,                 /* func_head  */
  YYSYMBOL_opt_param_list = 63,            /* opt_param_list  */
  YYSYMBOL_param_list = 64,                /* param_list  */
  YYSYMBOL_param = 65,                     /* param  */
  YYSYMBOL_comp_stmt = 66,                 /* comp_stmt  */
  YYSYMBOL_stmt_list = 67,                 /* stmt_list  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_lvar = 69,                      /* lvar  */
  YYSYMBOL_rvar = 70,                      /* rvar  */
  YYSYMBOL_elseif_list = 71,               /* elseif_list  */
  YYSYMBOL_elseif = 72,                    /* elseif  */
  YYSYMBOL_else_part = 73,                 /* else_part  */
  YYSYMBOL_opt_expr_list = 74,             /* opt_expr_list  */
  YYSYMBOL_expr_list = 75,                 /* expr_list  */
  YYSYMBOL_expr = 76,                      /* expr  */
  YYSYMBOL_simple_expr = 77,               /* simple_expr  */
  YYSYMBOL_term = 78,                      /* term  */
  YYSYMBOL_factor = 79,                    /* factor  */
  YYSYMBOL_func_call = 80,                 /* func_call  */
  YYSYMBOL_integer = 81,                   /* integer  */
  YYSYMBOL_real = 82,                      /* real  */
  YYSYMBOL_type_id = 83,                   /* type_id  */
  YYSYMBOL_const_id = 84,                  /* const_id  */
  YYSYMBOL_lvar_id = 85,                   /* lvar_id  */
  YYSYMBOL_rvar_id = 86,                   /* rvar_id  */
  YYSYMBOL_proc_id = 87,                   /* proc_id  */
  YYSYMBOL_func_id = 88,                   /* func_id  */
  YYSYMBOL_array_id = 89,                  /* array_id  */
  YYSYMBOL_id = 90                         /* id  */
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
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,   131,   137,   148,   149,   150,   153,   154,
     157,   162,   167,   171,   188,   194,   195,   198,   199,   202,
     207,   212,   235,   236,   239,   240,   243,   281,   321,   327,
     334,   349,   357,   361,   367,   372,   378,   383,   394,   400,
     409,   423,   429,   435,   439,   443,   448,   454,   459,   463,
     467,   473,   477,   481,   488,   493,   498,   505,   510,   515,
     520,   525,   529,   535,   539,   543,   547,   551,   557,   561,
     565,   569,   573,   577,   583,   588,   591,   595,   599,   603,
     609,   613,   617,   621,   625,   630,   636,   642,   649,   656,
     667,   678,   689,   700,   711,   722,   733
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
  "T_ID", "T_PROGRAM", "T_PROCEDURE", "T_FUNCTION", "T_INT", "T_REAL",
  "$accept", "program", "prog_decl", "prog_head", "const_part",
  "const_decls", "const_decl", "var_part", "var_decls", "var_decl",
  "subprog_part", "subprog_decls", "subprog_decl", "proc_decl",
  "func_decl", "proc_head", "func_head", "opt_param_list", "param_list",
  "param", "comp_stmt", "stmt_list", "stmt", "lvar", "rvar", "elseif_list",
  "elseif", "else_part", "opt_expr_list", "expr_list", "expr",
  "simple_expr", "term", "factor", "func_call", "integer", "real",
  "type_id", "const_id", "lvar_id", "rvar_id", "proc_id", "func_id",
  "array_id", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,   -15,    38,    65,    76,  -144,  -144,   180,  -144,  -144,
      52,    52,    78,    91,    52,  -144,    52,    64,    71,    20,
    -144,   110,    64,  -144,   118,   -13,   121,   131,  -144,  -144,
    -144,   132,   135,   140,  -144,    -5,  -144,    28,     0,     0,
     156,    11,  -144,    98,  -144,   139,   145,    32,  -144,  -144,
    -144,  -144,  -144,   151,   155,  -144,   123,   124,    28,  -144,
      65,    65,   157,   157,     0,    72,    72,    72,  -144,   107,
     195,   174,  -144,  -144,  -144,  -144,  -144,   165,   170,    58,
     107,    73,   -13,  -144,     0,   193,    75,    22,  -144,  -144,
    -144,  -144,  -144,  -144,     7,   169,   172,   116,   174,   174,
    -144,     0,     0,     0,     0,   181,    72,    72,    72,    72,
      72,    72,    72,   193,   138,   181,  -144,    73,   176,   177,
      73,   183,   214,   189,   197,   204,   201,    36,  -144,   168,
     178,  -144,   195,   195,   195,   195,    -6,   174,   174,   174,
    -144,  -144,  -144,  -144,   210,   215,   220,  -144,     0,  -144,
    -144,   178,   178,  -144,   178,   191,  -144,    78,   224,   -13,
       0,  -144,  -144,  -144,  -144,  -144,    73,   230,   233,  -144,
    -144,  -144,   168,   181,   107,  -144,  -144,    78,   181,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     1,     0,     2,     3,
       0,     0,    16,     0,     6,     8,     5,     0,    23,     0,
       9,     0,    15,    17,     0,    47,     0,     0,    96,    87,
      88,     0,     0,     0,    90,     0,    18,     0,    75,    75,
      75,     0,    39,     0,    48,     0,     0,    91,    14,    12,
      10,    11,    13,     0,     0,    89,     0,     0,    22,    24,
       0,     0,    34,    34,    75,    75,    75,     0,    80,    47,
      63,    68,    74,    81,    82,    83,    51,     0,     0,    92,
      47,    45,    47,    38,    75,    75,     0,     0,    19,    30,
      31,    25,    26,    27,     0,     0,     0,     0,    69,    70,
      84,    75,    75,    75,    75,    55,    75,    75,    75,     0,
       0,     0,     0,    75,     0,    42,    40,    44,     0,    59,
      61,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,    85,    64,    66,    67,    65,    58,    72,    73,    71,
      78,    79,    77,    76,     0,     0,     0,    43,    75,    50,
      49,     0,     0,    33,     0,     0,    32,    16,     0,    47,
      75,    54,    41,    86,    53,    52,    62,     0,     0,    37,
      36,    28,     0,    57,    47,    20,    21,    16,    56,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -116,   229,    83,  -143,  -144,   226,
    -144,  -144,   188,  -144,  -144,  -144,  -144,   186,  -144,    95,
      17,   -68,   171,  -144,  -144,  -144,  -144,  -144,   142,  -144,
     -35,   141,   -34,   -57,  -144,   -12,   232,  -115,   167,  -144,
    -144,  -144,  -144,   -23,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    12,    14,    15,    18,    22,    23,
      25,    58,    59,    60,    61,    62,    63,    95,   127,   128,
       8,    41,    42,    43,    68,   136,   161,   162,   118,   119,
     120,    70,    71,    72,    73,    74,    75,    54,    33,    44,
      76,    45,    77,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   105,    46,    69,    80,    81,    47,    31,   125,    38,
     100,    64,   115,   157,   171,   158,    55,    82,    65,    66,
       1,    26,    39,   159,    40,     5,    53,    28,    83,    97,
     160,    98,    99,    67,   179,    28,   167,   168,     6,   169,
      28,   -95,   155,   -93,    29,    30,    46,   126,   156,   117,
      47,   122,   140,   141,   142,   143,   177,    46,    27,    46,
      28,    47,    28,    47,    29,    30,    29,   -95,    34,   -94,
      56,    57,   137,   138,   139,   123,   121,    92,    93,   146,
     101,     7,   -75,    64,     9,   -75,    64,   102,   103,   -75,
     -75,   173,    13,    65,    66,   -75,   -75,    20,    19,    20,
     104,    17,   -75,   -75,    21,    67,   178,   -75,    67,   -75,
      24,    55,    28,   166,   101,    28,    29,    30,    35,    29,
      30,   102,   103,   101,    84,   174,    37,    48,   131,    38,
     102,   103,    55,    55,   104,    55,    46,    49,    50,   145,
      47,    51,    39,   104,    40,   -75,    52,    28,   -75,    64,
      85,    46,   -75,   -75,    86,    47,    65,    66,   -75,   -75,
      87,    88,   -46,    89,    90,   -75,   -75,    64,    94,    10,
     -75,    67,   -75,   -46,    65,    66,   113,   129,    28,   114,
     130,    10,    29,    30,    -7,   -46,    -7,    82,   147,    67,
     148,    -7,   -46,   149,   109,   110,    28,    -7,    11,   151,
      29,    30,    -7,    -7,    64,   -60,   111,   152,   112,   154,
      11,    65,    66,   106,   107,    -7,   153,    -7,    28,    -7,
      -7,   101,   163,   108,   150,   164,    67,   101,   102,   103,
     165,   126,   172,    28,   102,   103,   175,    29,    30,   176,
      16,   104,   132,   133,   134,   135,    91,   104,    36,    96,
     170,    32,     0,   116,   124,   144
};

static const yytype_int16 yycheck[] =
{
      19,    69,    25,    38,    39,    40,    25,    19,     1,    22,
      67,    11,    80,   129,   157,   130,    35,     6,    18,    19,
      41,     1,    35,    29,    37,    40,    31,    40,    17,    64,
      36,    65,    66,    33,   177,    40,   151,   152,     0,   154,
      40,     9,     6,    11,    44,    45,    69,    40,    12,    84,
      69,    86,   109,   110,   111,   112,   172,    80,    38,    82,
      40,    80,    40,    82,    44,    45,    44,     9,    87,    11,
      42,    43,   106,   107,   108,    87,     1,    60,    61,   114,
       7,    16,     7,    11,     8,    10,    11,    14,    15,    14,
      15,   159,    40,    18,    19,    20,    21,    14,     7,    16,
      27,    23,    27,    28,    40,    33,   174,    32,    33,    34,
      39,   130,    40,   148,     7,    40,    44,    45,     8,    44,
      45,    14,    15,     7,    26,   160,     8,     6,    12,    22,
      14,    15,   151,   152,    27,   154,   159,     6,     6,     1,
     159,     6,    35,    27,    37,     7,     6,    40,    10,    11,
      11,   174,    14,    15,     9,   174,    18,    19,    20,    21,
       9,     6,     6,    40,    40,    27,    28,    11,    11,     1,
      32,    33,    34,    17,    18,    19,    11,     8,    40,     9,
       8,     1,    44,    45,    16,    29,     6,     6,    12,    33,
      13,    23,    36,    10,    20,    21,    40,    17,    30,    10,
      44,    45,    22,    23,    11,    12,    32,    10,    34,     8,
      30,    18,    19,    18,    19,    35,    12,    37,    40,    39,
      40,     7,    12,    28,    10,    10,    33,     7,    14,    15,
      10,    40,     8,    40,    14,    15,     6,    44,    45,     6,
      11,    27,   101,   102,   103,   104,    58,    27,    22,    63,
     155,    19,    -1,    82,    87,   113
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    47,    48,    49,    40,     0,    16,    66,     8,
       1,    30,    50,    40,    51,    52,    51,    23,    53,     7,
      52,    40,    54,    55,    39,    56,     1,    38,    40,    44,
      45,    81,    82,    84,    90,     8,    55,     8,    22,    35,
      37,    67,    68,    69,    85,    87,    89,    90,     6,     6,
       6,     6,     6,    31,    83,    90,    42,    43,    57,    58,
      59,    60,    61,    62,    11,    18,    19,    33,    70,    76,
      77,    78,    79,    80,    81,    82,    86,    88,    89,    90,
      76,    76,     6,    17,    26,    11,     9,     9,     6,    40,
      40,    58,    66,    66,    11,    63,    63,    76,    78,    78,
      79,     7,    14,    15,    27,    67,    18,    19,    28,    20,
      21,    32,    34,    11,     9,    67,    68,    76,    74,    75,
      76,     1,    76,    81,    84,     1,    40,    64,    65,     8,
       8,    12,    77,    77,    77,    77,    71,    78,    78,    78,
      79,    79,    79,    79,    74,     1,    76,    12,    13,    10,
      10,    10,    10,    12,     8,     6,    12,    50,    83,    29,
      36,    72,    73,    12,    10,    10,    76,    83,    83,    83,
      65,    53,     8,    67,    76,     6,     6,    50,    67,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    49,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    60,
      61,    62,    63,    63,    63,    64,    64,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    71,    71,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     1,     2,
       4,     4,     4,     4,     4,     2,     0,     1,     2,     4,
       8,     8,     3,     0,     1,     2,     2,     2,     5,     7,
       2,     2,     3,     3,     0,     1,     3,     3,     6,     1,
       3,     5,     3,     4,     3,     2,     1,     0,     1,     4,
       4,     1,     4,     4,     2,     0,     3,     2,     0,     1,
       0,     1,     3,     1,     3,     3,     3,     3,     1,     2,
       2,     3,     3,     3,     1,     0,     3,     3,     3,     3,
       1,     1,     1,     1,     2,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
  case 2: /* program: prog_decl comp_stmt  */
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
#line 1472 "./parser/parser.cc"
    break;

  case 3: /* prog_decl: prog_head T_COLON  */
#line 132 "./parser/parser.y"
                    {
                        (yyval.procedure_head) = (yyvsp[-1].procedure_head);
                    }
#line 1480 "./parser/parser.cc"
    break;

  case 4: /* prog_head: T_PROGRAM T_ID  */
#line 138 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);

                        sym_index index = sym_tab->enter_procedure(pos, (yyvsp[0].pool_p));

                        (yyval.procedure_head) = new ast_procedure_head(pos, index);
                        sym_tab->open_scope();
                    }
#line 1493 "./parser/parser.cc"
    break;

  case 10: /* const_decl: T_ID T_EQ integer T_SEMICOLON  */
#line 158 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), int_type, (yyvsp[-1].integer)->value);
                    }
#line 1502 "./parser/parser.cc"
    break;

  case 11: /* const_decl: T_ID T_EQ real T_SEMICOLON  */
#line 163 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), real_type, (yyvsp[-1].real)->value);
                    }
#line 1511 "./parser/parser.cc"
    break;

  case 12: /* const_decl: T_ID T_EQ T_STRING T_SEMICOLON  */
#line 168 "./parser/parser.y"
                    {
                        // TODO: Not supported in Coff yet.
                    }
#line 1519 "./parser/parser.cc"
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
#line 1540 "./parser/parser.cc"
    break;

  case 14: /* const_decl: T_ID T_EQ error T_SEMICOLON  */
#line 189 "./parser/parser.y"
                    {
                        yyerrok;
                    }
#line 1548 "./parser/parser.cc"
    break;

  case 19: /* var_decl: T_ID T_COLON type_id T_SEMICOLON  */
#line 203 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_variable(pos, (yyvsp[-3].pool_p), (yyvsp[-1].id)->sym_p);
                    }
#line 1557 "./parser/parser.cc"
    break;

  case 20: /* var_decl: T_ID T_COLON T_ARRAY T_LEFTBRACKET integer T_RIGHTBRACKET type_id T_SEMICOLON  */
#line 208 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-7]).first_line, (yylsp[-7]).first_column);
                        sym_tab->enter_array(pos, (yyvsp[-7].pool_p), (yyvsp[-1].id)->sym_p, (yyvsp[-3].integer)->value);
                    }
#line 1566 "./parser/parser.cc"
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
#line 1591 "./parser/parser.cc"
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
#line 1633 "./parser/parser.cc"
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
#line 1675 "./parser/parser.cc"
    break;

  case 28: /* proc_decl: proc_head opt_param_list T_COLON const_part var_part  */
#line 322 "./parser/parser.y"
                    {
                        (yyval.procedure_head) = (yyvsp[-4].procedure_head);
                    }
#line 1683 "./parser/parser.cc"
    break;

  case 29: /* func_decl: func_head opt_param_list T_COLON type_id T_COLON const_part var_part  */
#line 328 "./parser/parser.y"
                    {
                        sym_tab->get_symbol((yyvsp[-6].function_head)->sym_p)->type = (yyvsp[-3].id)->sym_p;
                        (yyval.function_head) = (yyvsp[-6].function_head);
                    }
#line 1692 "./parser/parser.cc"
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
#line 1709 "./parser/parser.cc"
    break;

  case 31: /* func_head: T_FUNCTION T_ID  */
#line 350 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                        sym_index func_loc = sym_tab->enter_function(pos, (yyvsp[0].pool_p));
                        sym_tab->open_scope();
                        (yyval.function_head) = new ast_function_head(pos, func_loc);
                    }
#line 1720 "./parser/parser.cc"
    break;

  case 32: /* opt_param_list: T_LEFTPAR param_list T_RIGHTPAR  */
#line 358 "./parser/parser.y"
                    {
                        (yyval.expression_list) = (yyvsp[-1].expression_list);
                    }
#line 1728 "./parser/parser.cc"
    break;

  case 33: /* opt_param_list: T_LEFTPAR error T_RIGHTPAR  */
#line 362 "./parser/parser.y"
                    {
                        yyerrok;
                        (yyval.expression_list) = NULL;
                    }
#line 1737 "./parser/parser.cc"
    break;

  case 34: /* opt_param_list: %empty  */
#line 367 "./parser/parser.y"
                    {
                        (yyval.expression_list) = NULL;
                    }
#line 1745 "./parser/parser.cc"
    break;

  case 35: /* param_list: param  */
#line 373 "./parser/parser.y"
                    {
                        /*
                        we use expr_lists for params
                        */
                    }
#line 1755 "./parser/parser.cc"
    break;

  case 36: /* param_list: param_list T_SEMICOLON param  */
#line 379 "./parser/parser.y"
                    {
                    }
#line 1762 "./parser/parser.cc"
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
#line 1775 "./parser/parser.cc"
    break;

  case 38: /* comp_stmt: T_CURLYLEFT const_part var_part subprog_part stmt_list T_CURLYRIGHT  */
#line 395 "./parser/parser.y"
                    {
                        (yyval.statement_list) = (yyvsp[-1].statement_list);
                    }
#line 1783 "./parser/parser.cc"
    break;

  case 39: /* stmt_list: stmt  */
#line 401 "./parser/parser.y"
                    {
                        if((yyvsp[0].statement) != NULL) {
                            (yyval.statement_list) = new ast_statement_list((yyvsp[0].statement)->pos, (yyvsp[0].statement));
                        }
                        else {
                            (yyval.statement_list) = NULL;
                        }
                    }
#line 1796 "./parser/parser.cc"
    break;

  case 40: /* stmt_list: stmt_list T_SEMICOLON stmt  */
#line 410 "./parser/parser.y"
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
#line 1812 "./parser/parser.cc"
    break;

  case 41: /* stmt: T_IF expr stmt_list elseif_list else_part  */
#line 424 "./parser/parser.y"
                    {
                        // TODO: may need end keyword
                        position_information* pos = new position_information((yylsp[-4]).first_line, (yylsp[-4]).first_column);
                        (yyval.statement) = new ast_if(pos, (yyvsp[-3].expression), (yyvsp[-2].statement_list), (yyvsp[-1].elseif_list), (yyvsp[0].statement_list));
                    }
#line 1822 "./parser/parser.cc"
    break;

  case 42: /* stmt: T_WHILE expr stmt_list  */
#line 430 "./parser/parser.y"
                    {
                        // TODO: may need end keyword
                        position_information* pos = new position_information((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                        (yyval.statement) = new ast_while(pos, (yyvsp[-1].expression), (yyvsp[0].statement_list));
                    }
#line 1832 "./parser/parser.cc"
    break;

  case 43: /* stmt: proc_id T_LEFTPAR opt_expr_list T_RIGHTPAR  */
#line 436 "./parser/parser.y"
                    {
                        (yyval.statement) = new ast_procedure_call((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression_list));
                    }
#line 1840 "./parser/parser.cc"
    break;

  case 44: /* stmt: lvar T_ASSIGN expr  */
#line 440 "./parser/parser.y"
                    {
                        (yyval.statement) = new ast_assign((yyvsp[-2].lval)->pos, (yyvsp[-2].lval), (yyvsp[0].expression));
                    }
#line 1848 "./parser/parser.cc"
    break;

  case 45: /* stmt: T_RETURN expr  */
#line 444 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                        (yyval.statement) = new ast_return(pos, (yyvsp[0].expression));
                    }
#line 1857 "./parser/parser.cc"
    break;

  case 46: /* stmt: T_RETURN  */
#line 449 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.statement) = new ast_return(pos);
                    }
#line 1866 "./parser/parser.cc"
    break;

  case 47: /* stmt: %empty  */
#line 454 "./parser/parser.y"
                    {
                        (yyval.statement) = NULL;
                    }
#line 1874 "./parser/parser.cc"
    break;

  case 48: /* lvar: lvar_id  */
#line 460 "./parser/parser.y"
                    {
                        (yyval.lval) = (yyvsp[0].id);
                    }
#line 1882 "./parser/parser.cc"
    break;

  case 49: /* lvar: array_id T_LEFTBRACKET expr T_RIGHTBRACKET  */
#line 464 "./parser/parser.y"
                    {
                        (yyval.lval) = new ast_indexed((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression));
                    }
#line 1890 "./parser/parser.cc"
    break;

  case 50: /* lvar: array_id T_LEFTBRACKET error T_RIGHTBRACKET  */
#line 468 "./parser/parser.y"
                    {
                        (yyval.lval) = NULL;
                    }
#line 1898 "./parser/parser.cc"
    break;

  case 51: /* rvar: rvar_id  */
#line 474 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].id);
                    }
#line 1906 "./parser/parser.cc"
    break;

  case 52: /* rvar: array_id T_LEFTBRACKET expr T_RIGHTBRACKET  */
#line 478 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_indexed((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression));
                    }
#line 1914 "./parser/parser.cc"
    break;

  case 53: /* rvar: array_id T_LEFTBRACKET error T_RIGHTBRACKET  */
#line 482 "./parser/parser.y"
                    {
                        yyerrok;
                        (yyval.expression) = NULL;
                    }
#line 1923 "./parser/parser.cc"
    break;

  case 54: /* elseif_list: elseif_list elseif  */
#line 489 "./parser/parser.y"
                    {
                        (yyval.elseif_list) = new ast_elseif_list((yyvsp[0].elseif)->pos, (yyvsp[0].elseif), (yyvsp[-1].elseif_list));
                    }
#line 1931 "./parser/parser.cc"
    break;

  case 55: /* elseif_list: %empty  */
#line 493 "./parser/parser.y"
                    {
                        (yyval.elseif_list) = NULL;
                    }
#line 1939 "./parser/parser.cc"
    break;

  case 56: /* elseif: T_ELSEIF expr stmt_list  */
#line 499 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                        (yyval.elseif) = new ast_elseif(pos, (yyvsp[-1].expression), (yyvsp[0].statement_list));
                    }
#line 1948 "./parser/parser.cc"
    break;

  case 57: /* else_part: T_ELSE stmt_list  */
#line 506 "./parser/parser.y"
                    {
                        (yyval.statement_list) = (yyvsp[0].statement_list);
                    }
#line 1956 "./parser/parser.cc"
    break;

  case 58: /* else_part: %empty  */
#line 510 "./parser/parser.y"
                    {
                        (yyval.statement_list) = NULL;
                    }
#line 1964 "./parser/parser.cc"
    break;

  case 59: /* opt_expr_list: expr_list  */
#line 516 "./parser/parser.y"
                    {
                        (yyval.expression_list) = (yyvsp[0].expression_list);
                    }
#line 1972 "./parser/parser.cc"
    break;

  case 60: /* opt_expr_list: %empty  */
#line 520 "./parser/parser.y"
                    {
                        (yyval.expression_list) = NULL;
                    }
#line 1980 "./parser/parser.cc"
    break;

  case 61: /* expr_list: expr  */
#line 526 "./parser/parser.y"
                    {
                        (yyval.expression_list) = new ast_expression_list((yyvsp[0].expression)->pos, (yyvsp[0].expression));
                    }
#line 1988 "./parser/parser.cc"
    break;

  case 62: /* expr_list: expr_list T_COMMA expr  */
#line 530 "./parser/parser.y"
                    {
                        (yyval.expression_list) = new ast_expression_list((yyvsp[-2].expression_list)->pos, (yyvsp[0].expression), (yyvsp[-2].expression_list));
                    }
#line 1996 "./parser/parser.cc"
    break;

  case 63: /* expr: simple_expr  */
#line 536 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2004 "./parser/parser.cc"
    break;

  case 64: /* expr: expr T_EQ simple_expr  */
#line 540 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_equal((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2012 "./parser/parser.cc"
    break;

  case 65: /* expr: expr T_NOTEQ simple_expr  */
#line 544 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_not_equal((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2020 "./parser/parser.cc"
    break;

  case 66: /* expr: expr T_LESSTHAN simple_expr  */
#line 548 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_less_than((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2028 "./parser/parser.cc"
    break;

  case 67: /* expr: expr T_GREATERTHAN simple_expr  */
#line 552 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_greater_than((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2036 "./parser/parser.cc"
    break;

  case 68: /* simple_expr: term  */
#line 558 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2044 "./parser/parser.cc"
    break;

  case 69: /* simple_expr: T_ADD term  */
#line 562 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2052 "./parser/parser.cc"
    break;

  case 70: /* simple_expr: T_SUB term  */
#line 566 "./parser/parser.y"
                    {
                        // TODO: uminus
                    }
#line 2060 "./parser/parser.cc"
    break;

  case 71: /* simple_expr: simple_expr T_OR term  */
#line 570 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_or((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2068 "./parser/parser.cc"
    break;

  case 72: /* simple_expr: simple_expr T_ADD term  */
#line 574 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_add((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2076 "./parser/parser.cc"
    break;

  case 73: /* simple_expr: simple_expr T_SUB term  */
#line 578 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_sub((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2084 "./parser/parser.cc"
    break;

  case 74: /* term: factor  */
#line 584 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2092 "./parser/parser.cc"
    break;

  case 75: /* term: %empty  */
#line 588 "./parser/parser.y"
                    {
                        // TODO: idiv/rdiv
                    }
#line 2100 "./parser/parser.cc"
    break;

  case 76: /* term: term T_MOD factor  */
#line 592 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_mod((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2108 "./parser/parser.cc"
    break;

  case 77: /* term: term T_AND factor  */
#line 596 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_and((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2116 "./parser/parser.cc"
    break;

  case 78: /* term: term T_MULT factor  */
#line 600 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_mult((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2124 "./parser/parser.cc"
    break;

  case 79: /* term: term T_DIV factor  */
#line 604 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_div((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2132 "./parser/parser.cc"
    break;

  case 80: /* factor: rvar  */
#line 610 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2140 "./parser/parser.cc"
    break;

  case 81: /* factor: func_call  */
#line 614 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].function_call);
                    }
#line 2148 "./parser/parser.cc"
    break;

  case 82: /* factor: integer  */
#line 618 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].integer);
                    }
#line 2156 "./parser/parser.cc"
    break;

  case 83: /* factor: real  */
#line 622 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].real);
                    }
#line 2164 "./parser/parser.cc"
    break;

  case 84: /* factor: T_NOT factor  */
#line 626 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
		                (yyval.expression) = new ast_not(pos, (yyvsp[0].expression));
                    }
#line 2173 "./parser/parser.cc"
    break;

  case 85: /* factor: T_LEFTPAR expr T_RIGHTPAR  */
#line 631 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[-1].expression);
                    }
#line 2181 "./parser/parser.cc"
    break;

  case 86: /* func_call: func_id T_LEFTPAR opt_expr_list T_RIGHTPAR  */
#line 637 "./parser/parser.y"
                    {
                        (yyval.function_call) = new ast_function_call((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression_list));
                    }
#line 2189 "./parser/parser.cc"
    break;

  case 87: /* integer: T_INT  */
#line 643 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.integer) = new ast_int(pos, (yyvsp[0].ival));
                    }
#line 2198 "./parser/parser.cc"
    break;

  case 88: /* real: T_REAL  */
#line 650 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.real) = new ast_real(pos, (yyvsp[0].rval));
                    }
#line 2207 "./parser/parser.cc"
    break;

  case 89: /* type_id: id  */
#line 657 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_TYPE) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as type: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2220 "./parser/parser.cc"
    break;

  case 90: /* const_id: id  */
#line 668 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as const: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2233 "./parser/parser.cc"
    break;

  case 91: /* lvar_id: id  */
#line 679 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR && sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as var or param: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2246 "./parser/parser.cc"
    break;

  case 92: /* rvar_id: id  */
#line 690 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR && sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM && sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST ) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as var, param or const: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2259 "./parser/parser.cc"
    break;

  case 93: /* proc_id: id  */
#line 701 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PROC) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as procedure: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2272 "./parser/parser.cc"
    break;

  case 94: /* func_id: id  */
#line 712 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_FUNC) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as function: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2285 "./parser/parser.cc"
    break;

  case 95: /* array_id: id  */
#line 723 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_ARRAY) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as array: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2298 "./parser/parser.cc"
    break;

  case 96: /* id: T_ID  */
#line 734 "./parser/parser.y"
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
#line 2318 "./parser/parser.cc"
    break;


#line 2322 "./parser/parser.cc"

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

#line 751 "./parser/parser.y"
