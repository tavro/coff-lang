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

// TODO: Write oprimizer

extern char *yytext;
extern int error_count;         // defined in error.cc
extern symbol_table *sym_tab;   // defined in symtab.cc
extern semantic *type_checker;

// TODO: code generator

extern int yylex();
extern void yyerror(string);

extern bool print_ast;
extern bool type_check;
// TODO: more flags

#define YYDEBUG 1

#line 95 "./parser/parser.cc"

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
  YYSYMBOL_T_ADD = 16,                     /* T_ADD  */
  YYSYMBOL_T_SUB = 17,                     /* T_SUB  */
  YYSYMBOL_T_MULT = 18,                    /* T_MULT  */
  YYSYMBOL_T_DIV = 19,                     /* T_DIV  */
  YYSYMBOL_T_IF = 20,                      /* T_IF  */
  YYSYMBOL_T_VAR = 21,                     /* T_VAR  */
  YYSYMBOL_T_ELSE = 22,                    /* T_ELSE  */
  YYSYMBOL_T_CONST = 23,                   /* T_CONST  */
  YYSYMBOL_T_ARRAY = 24,                   /* T_ARRAY  */
  YYSYMBOL_T_WHILE = 25,                   /* T_WHILE  */
  YYSYMBOL_T_ELSEIF = 26,                  /* T_ELSEIF  */
  YYSYMBOL_T_RETURN = 27,                  /* T_RETURN  */
  YYSYMBOL_T_STRING = 28,                  /* T_STRING  */
  YYSYMBOL_T_ID = 29,                      /* T_ID  */
  YYSYMBOL_T_PROGRAM = 30,                 /* T_PROGRAM  */
  YYSYMBOL_T_PROCEDURE = 31,               /* T_PROCEDURE  */
  YYSYMBOL_T_FUNCTION = 32,                /* T_FUNCTION  */
  YYSYMBOL_T_INT = 33,                     /* T_INT  */
  YYSYMBOL_T_REAL = 34,                    /* T_REAL  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_prog_decl = 37,                 /* prog_decl  */
  YYSYMBOL_prog_head = 38,                 /* prog_head  */
  YYSYMBOL_const_part = 39,                /* const_part  */
  YYSYMBOL_const_decls = 40,               /* const_decls  */
  YYSYMBOL_const_decl = 41,                /* const_decl  */
  YYSYMBOL_var_part = 42,                  /* var_part  */
  YYSYMBOL_var_decls = 43,                 /* var_decls  */
  YYSYMBOL_var_decl = 44,                  /* var_decl  */
  YYSYMBOL_subprog_part = 45,              /* subprog_part  */
  YYSYMBOL_subprog_decls = 46,             /* subprog_decls  */
  YYSYMBOL_subprog_decl = 47,              /* subprog_decl  */
  YYSYMBOL_proc_decl = 48,                 /* proc_decl  */
  YYSYMBOL_func_decl = 49,                 /* func_decl  */
  YYSYMBOL_proc_head = 50,                 /* proc_head  */
  YYSYMBOL_func_head = 51,                 /* func_head  */
  YYSYMBOL_opt_param_list = 52,            /* opt_param_list  */
  YYSYMBOL_param_list = 53,                /* param_list  */
  YYSYMBOL_param = 54,                     /* param  */
  YYSYMBOL_comp_stmt = 55,                 /* comp_stmt  */
  YYSYMBOL_stmt_list = 56,                 /* stmt_list  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_rvar = 58,                      /* rvar  */
  YYSYMBOL_elseif_list = 59,               /* elseif_list  */
  YYSYMBOL_elseif = 60,                    /* elseif  */
  YYSYMBOL_else_part = 61,                 /* else_part  */
  YYSYMBOL_opt_expr_list = 62,             /* opt_expr_list  */
  YYSYMBOL_expr_list = 63,                 /* expr_list  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_simple_expr = 65,               /* simple_expr  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_factor = 67,                    /* factor  */
  YYSYMBOL_func_call = 68,                 /* func_call  */
  YYSYMBOL_integer = 69,                   /* integer  */
  YYSYMBOL_real = 70,                      /* real  */
  YYSYMBOL_type_id = 71,                   /* type_id  */
  YYSYMBOL_const_id = 72,                  /* const_id  */
  YYSYMBOL_rvar_id = 73,                   /* rvar_id  */
  YYSYMBOL_proc_id = 74,                   /* proc_id  */
  YYSYMBOL_func_id = 75,                   /* func_id  */
  YYSYMBOL_array_id = 76,                  /* array_id  */
  YYSYMBOL_id = 77                         /* id  */
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
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,   110,   116,   127,   128,   129,   132,   133,
     136,   141,   146,   150,   167,   173,   174,   177,   178,   181,
     186,   191,   214,   215,   218,   219,   222,   243,   266,   272,
     279,   294,   302,   306,   312,   317,   323,   328,   339,   346,
     355,   369,   375,   381,   385,   390,   396,   417,   421,   425,
     432,   437,   442,   449,   454,   459,   464,   469,   473,   479,
     483,   488,   491,   495,   501,   505,   509,   514,   517,   521,
     527,   532,   535,   539,   545,   549,   553,   557,   562,   565,
     571,   577,   584,   591,   602,   626,   637,   648,   659,   670
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
  "T_GREATERTHAN", "T_ADD", "T_SUB", "T_MULT", "T_DIV", "T_IF", "T_VAR",
  "T_ELSE", "T_CONST", "T_ARRAY", "T_WHILE", "T_ELSEIF", "T_RETURN",
  "T_STRING", "T_ID", "T_PROGRAM", "T_PROCEDURE", "T_FUNCTION", "T_INT",
  "T_REAL", "$accept", "program", "prog_decl", "prog_head", "const_part",
  "const_decls", "const_decl", "var_part", "var_decls", "var_decl",
  "subprog_part", "subprog_decls", "subprog_decl", "proc_decl",
  "func_decl", "proc_head", "func_head", "opt_param_list", "param_list",
  "param", "comp_stmt", "stmt_list", "stmt", "rvar", "elseif_list",
  "elseif", "else_part", "opt_expr_list", "expr_list", "expr",
  "simple_expr", "term", "factor", "func_call", "integer", "real",
  "type_id", "const_id", "rvar_id", "proc_id", "func_id", "array_id", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,    17,    58,    -6,    67,   -95,   -95,    32,    41,   106,
      -6,   -95,    -6,    -6,    66,    66,    12,   -95,   -95,   165,
     165,   137,   -95,    85,    95,   -95,    83,   -95,   -95,   106,
     106,     9,   104,   108,   103,   103,    75,   165,    55,    55,
     -95,   -95,   -95,    88,    47,    68,   -95,   -95,   -95,   -95,
     -95,   113,   119,     3,    88,   153,   -95,   106,   146,   128,
     132,   131,   151,    10,   -95,    98,   111,   154,   103,   -95,
     103,   140,   -95,    16,    68,    68,   165,   165,   165,    95,
      55,    55,    55,    55,   146,    64,    95,   -95,   162,   164,
     153,   -95,   -95,   -95,   111,   149,   -95,    75,   179,   -95,
      26,   -95,   178,   140,   -95,   -95,    47,    47,    47,    14,
      68,    68,   -95,   -95,   175,   180,   135,   -95,   165,   -95,
     -95,   -95,    98,   182,   183,   185,   186,   187,   -95,     0,
     -95,   106,   165,   -95,   -95,   -95,   -95,   -95,   153,    75,
     -95,   -95,   -95,   -95,   -95,   188,   189,    95,    88,   -95,
      43,   -95,    95,   190,   191,   111,   111,   196,   197,   -95,
     -95
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    23,     0,     4,     1,     0,     0,    46,
      22,    24,    23,    23,    34,    34,     0,    30,    31,    61,
      61,    45,    89,     0,    38,    39,     0,    86,    25,    46,
      46,     0,     0,     0,     0,     0,    16,    61,    71,    71,
      81,    82,    74,    46,    59,    64,    70,    75,    76,    77,
      47,     0,     0,    85,    46,    44,     2,    46,    61,     0,
       0,     0,     0,     0,    35,     0,     0,     0,     6,     8,
       5,     0,     3,     0,    65,    66,    67,    67,    67,    51,
      71,    71,    78,    78,    61,     0,    42,    40,     0,    55,
      57,    26,    27,    33,     0,     0,    32,    16,     0,    83,
       0,     9,     0,    15,    17,    79,    60,    62,    63,    54,
      68,    69,    72,    73,     0,     0,     0,    43,    61,    37,
      36,    28,     0,     0,     0,     0,     0,     0,    84,     0,
      18,    46,    61,    50,    41,    80,    49,    48,    58,    16,
      14,    12,    10,    11,    13,     0,     0,    53,    46,    29,
       0,    19,    52,     0,     0,     0,     0,     0,     0,    20,
      21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   -95,   -60,   161,   -21,   -86,   -95,   101,
      99,   -95,   195,   -95,   -95,   -95,   -95,   192,   -95,   114,
     107,   -39,   155,   -95,   -95,   -95,   -95,   122,   -95,   -18,
      29,   -30,    90,   -95,   -94,   110,   -87,    61,   -95,   -95,
     -95,   -95,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    36,    68,    69,    72,   103,   104,
       9,    10,    11,    12,    13,    14,    15,    32,    63,    64,
      23,    24,    25,    42,   109,   133,   134,    88,    89,    90,
      44,    45,    46,    47,    48,    49,    98,   127,    50,    26,
      51,    52,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    43,    54,    55,    79,    97,   125,   119,    74,    75,
      61,   121,   -88,    34,   -87,    86,    95,    -7,    -7,    73,
      27,    27,    96,    76,   145,     7,     8,   123,   105,    22,
      77,    78,    -7,    -7,    27,    35,   131,    -7,    62,    -7,
     132,    -7,   146,    -7,    -7,    27,     5,   101,    27,   101,
     110,   111,     1,   149,   124,    22,   153,    99,     6,    40,
      41,    17,   139,    80,    81,   115,    37,   116,   157,   158,
      18,   -61,    22,    16,   -61,    37,    40,    31,   -61,   -61,
      38,    39,   -71,   -71,    22,    99,    82,    83,    40,    41,
      56,   128,   147,    22,    58,    76,    71,    40,    41,    34,
     138,    57,    77,    78,    -7,   106,   107,   108,    19,   152,
      65,    29,    30,    20,   148,    21,    66,    22,    -7,    -7,
      99,    35,    27,    -7,    84,    -7,    19,    -7,    85,    -7,
      -7,    20,    67,    21,    91,    22,    59,    60,    92,    27,
      22,   128,    76,    93,   -61,   137,    99,    99,    37,    77,
      78,   -61,   -61,    38,    39,   -71,   -71,    37,   -56,    94,
      76,   100,    38,    39,   -71,   -71,    22,    77,    78,   102,
      40,    41,   112,   113,   117,    22,    37,   118,    62,    40,
      41,    38,    39,   -71,   -71,   122,   129,   135,   140,   141,
     136,   142,   143,   144,    22,   151,    70,   150,    40,    41,
     155,   156,   159,   160,   130,    28,   114,    33,     0,   120,
     126,   154,    87
};

static const yytype_int16 yycheck[] =
{
       9,    19,    20,    21,    43,    65,   100,    94,    38,    39,
       1,    97,     9,     1,    11,    54,     6,     5,     6,    37,
      29,    30,    12,     7,    24,    31,    32,     1,    12,    29,
      14,    15,    20,    21,    43,    23,    22,    25,    29,    27,
      26,    29,   129,    31,    32,    54,    29,    68,    57,    70,
      80,    81,    30,   139,    28,    29,   150,    66,     0,    33,
      34,    29,   122,    16,    17,     1,    11,    85,   155,   156,
      29,     7,    29,     6,    10,    11,    33,    11,    14,    15,
      16,    17,    18,    19,    29,    94,    18,    19,    33,    34,
       5,   100,   131,    29,    11,     7,    21,    33,    34,     1,
     118,     6,    14,    15,     6,    76,    77,    78,    20,   148,
       6,    12,    13,    25,   132,    27,     8,    29,    20,    21,
     129,    23,   131,    25,    11,    27,    20,    29,     9,    31,
      32,    25,    29,    27,     6,    29,    29,    30,     6,   148,
      29,   150,     7,    12,     7,    10,   155,   156,    11,    14,
      15,    14,    15,    16,    17,    18,    19,    11,    12,     8,
       7,     7,    16,    17,    18,    19,    29,    14,    15,    29,
      33,    34,    82,    83,    12,    29,    11,    13,    29,    33,
      34,    16,    17,    18,    19,     6,     8,    12,     6,     6,
      10,     6,     6,     6,    29,     6,    35,     9,    33,    34,
      10,    10,     6,     6,   103,    10,    84,    15,    -1,    95,
     100,   150,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    36,    37,    38,    29,     0,    31,    32,    45,
      46,    47,    48,    49,    50,    51,     6,    29,    29,    20,
      25,    27,    29,    55,    56,    57,    74,    77,    47,    45,
      45,    11,    52,    52,     1,    23,    39,    11,    16,    17,
      33,    34,    58,    64,    65,    66,    67,    68,    69,    70,
      73,    75,    76,    77,    64,    64,     5,     6,    11,    55,
      55,     1,    29,    53,    54,     6,     8,    29,    40,    41,
      40,    21,    42,    64,    66,    66,     7,    14,    15,    56,
      16,    17,    18,    19,    11,     9,    56,    57,    62,    63,
      64,     6,     6,    12,     8,     6,    12,    39,    71,    77,
       7,    41,    29,    43,    44,    12,    65,    65,    65,    59,
      66,    66,    67,    67,    62,     1,    64,    12,    13,    71,
      54,    42,     6,     1,    28,    69,    70,    72,    77,     8,
      44,    22,    26,    60,    61,    12,    10,    10,    64,    39,
       6,     6,     6,     6,     6,    24,    71,    56,    64,    42,
       9,     6,    56,    69,    72,    10,    10,    71,    71,     6,
       6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    38,    39,    39,    39,    40,    40,
      41,    41,    41,    41,    41,    42,    42,    43,    43,    44,
      44,    44,    45,    45,    46,    46,    47,    47,    48,    49,
      50,    51,    52,    52,    52,    53,    53,    54,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      59,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     4,     2,     2,     2,     0,     1,     2,
       4,     4,     4,     4,     4,     2,     0,     1,     2,     4,
       8,     8,     1,     0,     1,     2,     4,     4,     5,     7,
       2,     2,     3,     3,     0,     1,     3,     3,     1,     1,
       3,     5,     3,     4,     2,     1,     0,     1,     4,     4,
       2,     0,     3,     2,     0,     1,     0,     1,     3,     1,
       3,     0,     3,     3,     1,     2,     2,     0,     3,     3,
       1,     0,     3,     3,     1,     1,     1,     1,     0,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* program: prog_decl subprog_part comp_stmt T_DOT  */
#line 83 "./parser/parser.y"
                    {
                        symbol *env = sym_tab->get_symbol((yyvsp[-3].procedure_head)->sym_p);

                        // following code depends on flags passed to compiler
                        if(type_check) {
                            type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
                        }

                        if(print_ast) {
                            cout << "Unoptimized AST for global level" << endl;
                            cout << (ast_statement_list *)(yyvsp[-1].statement_list) << endl;
                        }

                        // TODO: Implement optimizer

                        if(error_count == 0) {
                            // TODO: Implement code generation
                        }
                        else {
                            cout << "Found " << error_count << " errors. "
                                 << "Compilation aborted.\n";
                        }

                        sym_tab->close_scope();
                    }
#line 1422 "./parser/parser.cc"
    break;

  case 3: /* prog_decl: prog_head T_SEMICOLON const_part var_part  */
#line 111 "./parser/parser.y"
                    {
                        (yyval.procedure_head) = (yyvsp[-3].procedure_head);
                    }
#line 1430 "./parser/parser.cc"
    break;

  case 4: /* prog_head: T_PROGRAM T_ID  */
#line 117 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);

                        sym_index index = sym_tab->enter_procedure(pos, (yyvsp[0].pool_p));

                        (yyval.procedure_head) = new ast_procedure_head(pos, index);
                        sym_tab->open_scope();
                    }
#line 1443 "./parser/parser.cc"
    break;

  case 10: /* const_decl: T_ID T_EQ integer T_SEMICOLON  */
#line 137 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), int_type, (yyvsp[-1].integer)->value);
                    }
#line 1452 "./parser/parser.cc"
    break;

  case 11: /* const_decl: T_ID T_EQ real T_SEMICOLON  */
#line 142 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), real_type, (yyvsp[-1].real)->value);
                    }
#line 1461 "./parser/parser.cc"
    break;

  case 12: /* const_decl: T_ID T_EQ T_STRING T_SEMICOLON  */
#line 147 "./parser/parser.y"
                    {
                        // TODO: Not supported in Coff yet.
                    }
#line 1469 "./parser/parser.cc"
    break;

  case 13: /* const_decl: T_ID T_EQ const_id T_SEMICOLON  */
#line 151 "./parser/parser.y"
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
#line 1490 "./parser/parser.cc"
    break;

  case 14: /* const_decl: T_ID T_EQ error T_SEMICOLON  */
#line 168 "./parser/parser.y"
                    {
                        yyerrok;
                    }
#line 1498 "./parser/parser.cc"
    break;

  case 19: /* var_decl: T_ID T_COLON type_id T_SEMICOLON  */
#line 182 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-3]).first_line, (yylsp[-3]).first_column);
                        sym_tab->enter_variable(pos, (yyvsp[-3].pool_p), (yyvsp[-1].id)->sym_p);
                    }
#line 1507 "./parser/parser.cc"
    break;

  case 20: /* var_decl: T_ID T_COLON T_ARRAY T_LEFTBRACKET integer T_RIGHTBRACKET type_id T_SEMICOLON  */
#line 187 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-7]).first_line, (yylsp[-7]).first_column);
                        sym_tab->enter_array(pos, (yyvsp[-7].pool_p), (yyvsp[-1].id)->sym_p, (yyvsp[-3].integer)->value);
                    }
#line 1516 "./parser/parser.cc"
    break;

  case 21: /* var_decl: T_ID T_COLON T_ARRAY T_LEFTBRACKET const_id T_RIGHTBRACKET type_id T_SEMICOLON  */
#line 192 "./parser/parser.y"
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
#line 1541 "./parser/parser.cc"
    break;

  case 26: /* subprog_decl: proc_decl subprog_part comp_stmt T_SEMICOLON  */
#line 223 "./parser/parser.y"
                    {
                        symbol *env = sym_tab->get_symbol((yyvsp[-3].procedure_head)->sym_p);

                        if(type_check) {
                            type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
                        }

                        if(print_ast) {
                            cout << "\nUnoptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                            cout << (ast_statement_list *)(yyvsp[-1].statement_list) << endl;
                        }

                        // TODO: Implement optimizer

                        if(error_count == 0) {
                            // TODO: Implement code generation
                        }

                        sym_tab->close_scope();
                    }
#line 1566 "./parser/parser.cc"
    break;

  case 27: /* subprog_decl: func_decl subprog_part comp_stmt T_SEMICOLON  */
#line 244 "./parser/parser.y"
                    {
                        symbol *env = sym_tab->get_symbol((yyvsp[-3].function_head)->sym_p);

                        if(type_check) {
                            type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
                        }

                        if(print_ast) {
                            cout << "\nUnoptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                            cout << (ast_statement_list *)(yyvsp[-1].statement_list) << endl;
                        }

                        // TODO: Implement optimizer

                        if(error_count == 0) {
                            // TODO: Implement code generation
                        }

                        sym_tab->close_scope();
                    }
#line 1591 "./parser/parser.cc"
    break;

  case 28: /* proc_decl: proc_head opt_param_list T_SEMICOLON const_part var_part  */
#line 267 "./parser/parser.y"
                    {
                        (yyval.procedure_head) = (yyvsp[-4].procedure_head);
                    }
#line 1599 "./parser/parser.cc"
    break;

  case 29: /* func_decl: func_head opt_param_list T_COLON type_id T_SEMICOLON const_part var_part  */
#line 273 "./parser/parser.y"
                    {
                        sym_tab->get_symbol((yyvsp[-6].function_head)->sym_p)->type = (yyvsp[-3].id)->sym_p;
                        (yyval.function_head) = (yyvsp[-6].function_head);
                    }
#line 1608 "./parser/parser.cc"
    break;

  case 30: /* proc_head: T_PROCEDURE T_ID  */
#line 280 "./parser/parser.y"
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
#line 1625 "./parser/parser.cc"
    break;

  case 31: /* func_head: T_FUNCTION T_ID  */
#line 295 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                        sym_index func_loc = sym_tab->enter_procedure(pos, (yyvsp[0].pool_p));
                        sym_tab->open_scope();
                        (yyval.function_head) = new ast_function_head(pos, func_loc);
                    }
#line 1636 "./parser/parser.cc"
    break;

  case 32: /* opt_param_list: T_LEFTPAR param_list T_RIGHTPAR  */
#line 303 "./parser/parser.y"
                    {
                        (yyval.expression_list) = (yyvsp[-1].expression_list);
                    }
#line 1644 "./parser/parser.cc"
    break;

  case 33: /* opt_param_list: T_LEFTPAR error T_RIGHTPAR  */
#line 307 "./parser/parser.y"
                    {
                        yyerrok;
                        (yyval.expression_list) = NULL;
                    }
#line 1653 "./parser/parser.cc"
    break;

  case 34: /* opt_param_list: %empty  */
#line 312 "./parser/parser.y"
                    {
                        (yyval.expression_list) = NULL;
                    }
#line 1661 "./parser/parser.cc"
    break;

  case 35: /* param_list: param  */
#line 318 "./parser/parser.y"
                    {
                        /*
                        we use expr_lists for params
                        */
                    }
#line 1671 "./parser/parser.cc"
    break;

  case 36: /* param_list: param_list T_SEMICOLON param  */
#line 324 "./parser/parser.y"
                    {
                    }
#line 1678 "./parser/parser.cc"
    break;

  case 37: /* param: T_ID T_COLON type_id  */
#line 329 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                        
                        /*
                        param linking taken care of in enter_parameter
                        */
                        sym_index param_loc = sym_tab->enter_parameter(pos, (yyvsp[-2].pool_p), (yyvsp[0].id)->sym_p);
                    }
#line 1691 "./parser/parser.cc"
    break;

  case 38: /* comp_stmt: stmt_list  */
#line 340 "./parser/parser.y"
                    {
                        // TODO: Look over this, may need begin and end keywords
                        (yyval.statement_list) = (yyvsp[0].statement_list);
                    }
#line 1700 "./parser/parser.cc"
    break;

  case 39: /* stmt_list: stmt  */
#line 347 "./parser/parser.y"
                    {
                        if((yyvsp[0].statement) != NULL) {
                            (yyval.statement_list) = new ast_statement_list((yyvsp[0].statement)->pos, (yyvsp[0].statement));
                        }
                        else {
                            (yyval.statement_list) = NULL;
                        }
                    }
#line 1713 "./parser/parser.cc"
    break;

  case 40: /* stmt_list: stmt_list T_SEMICOLON stmt  */
#line 356 "./parser/parser.y"
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
#line 1729 "./parser/parser.cc"
    break;

  case 41: /* stmt: T_IF expr stmt_list elseif_list else_part  */
#line 370 "./parser/parser.y"
                    {
                        // TODO: may need end keyword
                        position_information* pos = new position_information((yylsp[-4]).first_line, (yylsp[-4]).first_column);
                        (yyval.statement) = new ast_if(pos, (yyvsp[-3].expression), (yyvsp[-2].statement_list), (yyvsp[-1].elseif_list), (yyvsp[0].statement_list));
                    }
#line 1739 "./parser/parser.cc"
    break;

  case 42: /* stmt: T_WHILE expr stmt_list  */
#line 376 "./parser/parser.y"
                    {
                        // TODO: may need end keyword
                        position_information* pos = new position_information((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                        (yyval.statement) = new ast_while(pos, (yyvsp[-1].expression), (yyvsp[0].statement_list));
                    }
#line 1749 "./parser/parser.cc"
    break;

  case 43: /* stmt: proc_id T_LEFTPAR opt_expr_list T_RIGHTPAR  */
#line 382 "./parser/parser.y"
                    {
                        (yyval.statement) = new ast_procedure_call((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression_list));
                    }
#line 1757 "./parser/parser.cc"
    break;

  case 44: /* stmt: T_RETURN expr  */
#line 386 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-1]).first_line, (yylsp[-1]).first_column);
                        (yyval.statement) = new ast_return(pos, (yyvsp[0].expression));
                    }
#line 1766 "./parser/parser.cc"
    break;

  case 45: /* stmt: T_RETURN  */
#line 391 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.statement) = new ast_return(pos);
                    }
#line 1775 "./parser/parser.cc"
    break;

  case 46: /* stmt: %empty  */
#line 396 "./parser/parser.y"
                    {
                        (yyval.statement) = NULL;
                    }
#line 1783 "./parser/parser.cc"
    break;

  case 47: /* rvar: rvar_id  */
#line 418 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].id);
                    }
#line 1791 "./parser/parser.cc"
    break;

  case 48: /* rvar: array_id T_LEFTBRACKET expr T_RIGHTBRACKET  */
#line 422 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_indexed((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression));
                    }
#line 1799 "./parser/parser.cc"
    break;

  case 49: /* rvar: array_id T_LEFTBRACKET error T_RIGHTBRACKET  */
#line 426 "./parser/parser.y"
                    {
                        yyerrok;
                        (yyval.expression) = NULL;
                    }
#line 1808 "./parser/parser.cc"
    break;

  case 50: /* elseif_list: elseif_list elseif  */
#line 433 "./parser/parser.y"
                    {
                        (yyval.elseif_list) = new ast_elseif_list((yyvsp[0].elseif)->pos, (yyvsp[0].elseif), (yyvsp[-1].elseif_list));
                    }
#line 1816 "./parser/parser.cc"
    break;

  case 51: /* elseif_list: %empty  */
#line 437 "./parser/parser.y"
                    {
                        (yyval.elseif_list) = NULL;
                    }
#line 1824 "./parser/parser.cc"
    break;

  case 52: /* elseif: T_ELSEIF expr stmt_list  */
#line 443 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[-2]).first_line, (yylsp[-2]).first_column);
                        (yyval.elseif) = new ast_elseif(pos, (yyvsp[-1].expression), (yyvsp[0].statement_list));
                    }
#line 1833 "./parser/parser.cc"
    break;

  case 53: /* else_part: T_ELSE stmt_list  */
#line 450 "./parser/parser.y"
                    {
                        (yyval.statement_list) = (yyvsp[0].statement_list);
                    }
#line 1841 "./parser/parser.cc"
    break;

  case 54: /* else_part: %empty  */
#line 454 "./parser/parser.y"
                    {
                        (yyval.statement_list) = NULL;
                    }
#line 1849 "./parser/parser.cc"
    break;

  case 55: /* opt_expr_list: expr_list  */
#line 460 "./parser/parser.y"
                    {
                        (yyval.expression_list) = (yyvsp[0].expression_list);
                    }
#line 1857 "./parser/parser.cc"
    break;

  case 56: /* opt_expr_list: %empty  */
#line 464 "./parser/parser.y"
                    {
                        (yyval.expression_list) = NULL;
                    }
#line 1865 "./parser/parser.cc"
    break;

  case 57: /* expr_list: expr  */
#line 470 "./parser/parser.y"
                    {
                        (yyval.expression_list) = new ast_expression_list((yyvsp[0].expression)->pos, (yyvsp[0].expression));
                    }
#line 1873 "./parser/parser.cc"
    break;

  case 58: /* expr_list: expr_list T_COMMA expr  */
#line 474 "./parser/parser.y"
                    {
                        (yyval.expression_list) = new ast_expression_list((yyvsp[-2].expression_list)->pos, (yyvsp[0].expression), (yyvsp[-2].expression_list));
                    }
#line 1881 "./parser/parser.cc"
    break;

  case 59: /* expr: simple_expr  */
#line 480 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 1889 "./parser/parser.cc"
    break;

  case 60: /* expr: expr T_EQ simple_expr  */
#line 484 "./parser/parser.y"
                    {
                        // $$ = new ast_equal($1->pos, $1, $3);
                    }
#line 1897 "./parser/parser.cc"
    break;

  case 61: /* expr: %empty  */
#line 488 "./parser/parser.y"
                    {
                        // TODO: not eq
                    }
#line 1905 "./parser/parser.cc"
    break;

  case 62: /* expr: expr T_LESSTHAN simple_expr  */
#line 492 "./parser/parser.y"
                    {
                        // $$ = new ast_less_than($1->pos, $1, $3);
                    }
#line 1913 "./parser/parser.cc"
    break;

  case 63: /* expr: expr T_GREATERTHAN simple_expr  */
#line 496 "./parser/parser.y"
                    {
                        // $$ = new ast_greater_than($1->pos, $1, $3);
                    }
#line 1921 "./parser/parser.cc"
    break;

  case 64: /* simple_expr: term  */
#line 502 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 1929 "./parser/parser.cc"
    break;

  case 65: /* simple_expr: T_ADD term  */
#line 506 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 1937 "./parser/parser.cc"
    break;

  case 66: /* simple_expr: T_SUB term  */
#line 510 "./parser/parser.y"
                    {
                        // TODO: uminus
                    }
#line 1945 "./parser/parser.cc"
    break;

  case 67: /* simple_expr: %empty  */
#line 514 "./parser/parser.y"
                    {
                        // TODO: or
                    }
#line 1953 "./parser/parser.cc"
    break;

  case 68: /* simple_expr: simple_expr T_ADD term  */
#line 518 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_add((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 1961 "./parser/parser.cc"
    break;

  case 69: /* simple_expr: simple_expr T_SUB term  */
#line 522 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_sub((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 1969 "./parser/parser.cc"
    break;

  case 70: /* term: factor  */
#line 528 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 1977 "./parser/parser.cc"
    break;

  case 71: /* term: %empty  */
#line 532 "./parser/parser.y"
                    {
                        // TODO: and, idiv/rdiv, mod
                    }
#line 1985 "./parser/parser.cc"
    break;

  case 72: /* term: term T_MULT factor  */
#line 536 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_mult((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 1993 "./parser/parser.cc"
    break;

  case 73: /* term: term T_DIV factor  */
#line 540 "./parser/parser.y"
                    {
                        (yyval.expression) = new ast_div((yyvsp[-2].expression)->pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2001 "./parser/parser.cc"
    break;

  case 74: /* factor: rvar  */
#line 546 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2009 "./parser/parser.cc"
    break;

  case 75: /* factor: func_call  */
#line 550 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].function_call);
                    }
#line 2017 "./parser/parser.cc"
    break;

  case 76: /* factor: integer  */
#line 554 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].integer);
                    }
#line 2025 "./parser/parser.cc"
    break;

  case 77: /* factor: real  */
#line 558 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[0].real);
                    }
#line 2033 "./parser/parser.cc"
    break;

  case 78: /* factor: %empty  */
#line 562 "./parser/parser.y"
                    {
                        // TODO: not
                    }
#line 2041 "./parser/parser.cc"
    break;

  case 79: /* factor: T_LEFTPAR expr T_RIGHTPAR  */
#line 566 "./parser/parser.y"
                    {
                        (yyval.expression) = (yyvsp[-1].expression);
                    }
#line 2049 "./parser/parser.cc"
    break;

  case 80: /* func_call: func_id T_LEFTPAR opt_expr_list T_RIGHTPAR  */
#line 572 "./parser/parser.y"
                    {
                        (yyval.function_call) = new ast_function_call((yyvsp[-3].id)->pos, (yyvsp[-3].id), (yyvsp[-1].expression_list));
                    }
#line 2057 "./parser/parser.cc"
    break;

  case 81: /* integer: T_INT  */
#line 578 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.integer) = new ast_int(pos, (yyvsp[0].ival));
                    }
#line 2066 "./parser/parser.cc"
    break;

  case 82: /* real: T_REAL  */
#line 585 "./parser/parser.y"
                    {
                        position_information* pos = new position_information((yylsp[0]).first_line, (yylsp[0]).first_column);
                        (yyval.real) = new ast_real(pos, (yyvsp[0].rval));
                    }
#line 2075 "./parser/parser.cc"
    break;

  case 83: /* type_id: id  */
#line 592 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_TYPE) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as type: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2088 "./parser/parser.cc"
    break;

  case 84: /* const_id: id  */
#line 603 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as const: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2101 "./parser/parser.cc"
    break;

  case 85: /* rvar_id: id  */
#line 627 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR && sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM && sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST ) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as var, param or const: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2114 "./parser/parser.cc"
    break;

  case 86: /* proc_id: id  */
#line 638 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PROC) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as procedure: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2127 "./parser/parser.cc"
    break;

  case 87: /* func_id: id  */
#line 649 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_FUNC) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as function: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2140 "./parser/parser.cc"
    break;

  case 88: /* array_id: id  */
#line 660 "./parser/parser.y"
                    {
                        if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_ARRAY) {
                            type_error((yyvsp[0].id)->pos) << "not declared "
                            << "as array: "
                            << yytext << endl << flush;
                        }
                        (yyval.id) = (yyvsp[0].id);
                    }
#line 2153 "./parser/parser.cc"
    break;

  case 89: /* id: T_ID  */
#line 671 "./parser/parser.y"
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
#line 2173 "./parser/parser.cc"
    break;


#line 2177 "./parser/parser.cc"

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

#line 688 "./parser/parser.y"
