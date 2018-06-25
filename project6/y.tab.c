/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define debug_log(fmt, ...) do { \
                                if (Opt_P) \
                                { \
                                    for(int i=0; i<depth; i++) printf("\t"); \
                                        printf("\033[35m#Parser: \033[33m" fmt "\033[0m\n", ##__VA_ARGS__); \
                                } \
                            } while(0)

extern int Opt_P;
extern int linenum;             /* declared in lex.l */
extern FILE *yyin;              /* declared by lex */
extern char *yytext;            /* declared by lex */
extern char buf[256];           /* declared in lex.l */

int depth = 0;

int yylex (void);
int yyerror( char *msg );

struct program_node *ast;


#line 95 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMA = 258,
    SEMICOLON = 259,
    COLON = 260,
    Lparenthese = 261,
    Rparenthese = 262,
    Lbracket = 263,
    Rbracket = 264,
    ASSIGNMENT = 265,
    OP_ADD = 266,
    OP_DEL = 267,
    OP_MUL = 268,
    OP_DIV = 269,
    OP_MOD = 270,
    OP_LT = 271,
    OP_LE = 272,
    OP_GT = 273,
    OP_GE = 274,
    OP_EQ = 275,
    OP_NE = 276,
    TF_AND = 277,
    TF_OR = 278,
    TF_NOT = 279,
    KWarray = 280,
    KWbegin = 281,
    KWboolean = 282,
    KWdef = 283,
    KWdo = 284,
    KWelse = 285,
    KWend = 286,
    KWfalse = 287,
    KWfor = 288,
    KWinteger = 289,
    KWif = 290,
    KWof = 291,
    KWprint = 292,
    KWread = 293,
    KWreal = 294,
    KWstring = 295,
    KWthen = 296,
    KWto = 297,
    KWtrue = 298,
    KWreturn = 299,
    KWvar = 300,
    KWwhile = 301,
    OCTAL = 302,
    INTEGER = 303,
    FLOAT = 304,
    SCIENTIFIC = 305,
    STRING = 306,
    IDENT = 307
  };
#endif
/* Tokens.  */
#define COMMA 258
#define SEMICOLON 259
#define COLON 260
#define Lparenthese 261
#define Rparenthese 262
#define Lbracket 263
#define Rbracket 264
#define ASSIGNMENT 265
#define OP_ADD 266
#define OP_DEL 267
#define OP_MUL 268
#define OP_DIV 269
#define OP_MOD 270
#define OP_LT 271
#define OP_LE 272
#define OP_GT 273
#define OP_GE 274
#define OP_EQ 275
#define OP_NE 276
#define TF_AND 277
#define TF_OR 278
#define TF_NOT 279
#define KWarray 280
#define KWbegin 281
#define KWboolean 282
#define KWdef 283
#define KWdo 284
#define KWelse 285
#define KWend 286
#define KWfalse 287
#define KWfor 288
#define KWinteger 289
#define KWif 290
#define KWof 291
#define KWprint 292
#define KWread 293
#define KWreal 294
#define KWstring 295
#define KWthen 296
#define KWto 297
#define KWtrue 298
#define KWreturn 299
#define KWvar 300
#define KWwhile 301
#define OCTAL 302
#define INTEGER 303
#define FLOAT 304
#define SCIENTIFIC 305
#define STRING 306
#define IDENT 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "yacc.y" /* yacc.c:355  */

    int    int_val;
    double real_val;
    char*  text_val;
    struct const_node *cn;
    struct dim_list *dl;
    struct type_node *tn;

    struct varirefe_node *rn;
    struct expr_node     *en;

    struct simp_node     *simp;
    struct cond_node     *cond;
    struct whil_node     *whil;
    struct for__node     *for_;
    struct ret__node     *ret_;
    struct finv_node     *finv;

    struct statment_node *sn;
    struct variable_node *vn;
    struct function_node *fn;
    struct compound_node *cpn;
    struct program_node *pn;

#line 264 "y.tab.c" /* yacc.c:355  */
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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 295 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   120,   127,   137,   139,   143,   152,   161,
     172,   183,   192,   203,   205,   207,   214,   222,   230,   238,
     248,   250,   258,   261,   272,   285,   299,   302,   312,   320,
     332,   342,   356,   359,   362,   365,   373,   377,   391,   394,
     397,   400,   409,   413,   424,   436,   440,   440,   452,   456,
     456,   468,   472,   472,   483,   487,   487,   499,   499,   511,
     511,   523,   523,   535,   535,   547,   547,   559,   563,   563,
     575,   575,   587,   591,   591,   603,   603,   615,   615,   627,
     631,   631,   642,   646,   648,   657,   666,   680,   696,   712,
     737,   755,   773,   780,   787,   794,   801,   808,   815,   824,
     833,   841,   851,   860,   872,   884,   897,   904,   918,   930,
     942,   945,   957,   969,   980,  1003,  1019,  1027,  1039,  1048,
    1059,  1068,  1082,  1096,  1110,  1132
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "SEMICOLON", "COLON",
  "Lparenthese", "Rparenthese", "Lbracket", "Rbracket", "ASSIGNMENT",
  "OP_ADD", "OP_DEL", "OP_MUL", "OP_DIV", "OP_MOD", "OP_LT", "OP_LE",
  "OP_GT", "OP_GE", "OP_EQ", "OP_NE", "TF_AND", "TF_OR", "TF_NOT",
  "KWarray", "KWbegin", "KWboolean", "KWdef", "KWdo", "KWelse", "KWend",
  "KWfalse", "KWfor", "KWinteger", "KWif", "KWof", "KWprint", "KWread",
  "KWreal", "KWstring", "KWthen", "KWto", "KWtrue", "KWreturn", "KWvar",
  "KWwhile", "OCTAL", "INTEGER", "FLOAT", "SCIENTIFIC", "STRING", "IDENT",
  "$accept", "program_name", "var_name", "func_name", "int_const",
  "number_const", "string_const", "bool_const", "const_group",
  "scalar_type", "var_type", "func_ret_type", "vacd_list", "var_list",
  "ddim_list", "dfunc_list", "arg_list", "_non_empty_arg_list",
  "state_list", "expr_list", "_non_empty_expr_list", "ref_list",
  "expression", "expr_order8", "$@1", "expr_order7", "$@2", "expr_order6",
  "$@3", "expr_order5", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "expr_order4", "$@10", "$@11", "expr_order3", "$@12", "$@13", "$@14",
  "expr_order2", "$@15", "expr_order1", "define_var", "define_const",
  "define_func", "define_arg", "define_state", "simp_statement",
  "var_reference", "func_invocation", "ret__statement", "expression_node",
  "expression_start", "cond_statement", "cond_start", "cond_midd",
  "whil_statement", "while_start", "for__statement", "for_start",
  "statement_declar", "statement_start", "var_and_const_declar",
  "vacd_start", "function_declar", "dfunc_start", "compound_statement",
  "compound_statement_start", "program", "prog_start", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -155

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-155)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -155,    19,   -24,  -155,  -155,    27,  -155,  -155,  -155,  -155,
    -155,    -9,    22,    16,    -2,     7,  -155,  -155,    18,  -155,
    -155,    62,  -155,  -155,  -155,    13,  -155,  -155,     7,     7,
      57,    40,  -155,    43,    67,    71,  -155,  -155,    38,   -35,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,    79,  -155,    88,   -17,  -155,
      76,    85,    90,     7,    89,    56,  -155,  -155,   -35,  -155,
    -155,     7,  -155,    93,    95,   109,  -155,    97,   106,   113,
     114,  -155,    86,  -155,    83,  -155,   110,  -155,  -155,    85,
     126,  -155,  -155,   -35,   102,  -155,    15,  -155,  -155,  -155,
     137,   139,  -155,  -155,  -155,  -155,  -155,  -155,     7,  -155,
    -155,   111,   -35,    15,    29,    15,  -155,  -155,   125,   127,
    -155,  -155,   115,    11,  -155,  -155,  -155,  -155,   141,  -155,
     144,   149,  -155,  -155,   112,   128,   145,   123,  -155,   120,
     151,  -155,  -155,    15,    15,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,  -155,   150,  -155,  -155,
    -155,  -155,   -35,   108,  -155,  -155,  -155,  -155,   127,  -155,
      11,    11,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,   130,   131,   121,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
     132,   135,   140,   -35,  -155,  -155,  -155,   142,   143,  -155,
     133,   146,  -155,   147,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     125,     0,     0,     1,     2,     0,   119,   121,    26,   123,
      32,   118,     0,     0,   120,     0,    24,    25,     0,   119,
       4,     0,    31,     3,    28,     0,   124,   117,    34,     0,
       0,     0,    38,     0,     0,    33,    36,    27,     0,     0,
      19,    12,    16,    17,    18,    11,     5,     6,     8,     9,
      10,     7,    13,    14,    15,     0,    20,     0,     0,   122,
     116,     0,    23,     0,     0,     0,    88,    87,     0,    21,
     107,     0,   107,     3,   102,     0,    37,     0,     0,     0,
       0,    94,     0,    95,     0,    96,     0,    92,    91,     0,
       0,    35,    89,     0,     0,   100,     0,   101,   105,   107,
     103,   107,    93,   107,    97,    98,   107,   107,     0,    22,
     123,     0,     0,     0,     0,     0,    86,   106,    45,    48,
      51,    54,    67,    72,    79,    82,    85,    84,     0,   107,
       0,    39,    42,    99,     0,     0,     0,     0,    30,     0,
       0,    80,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,     0,   104,   107,
     117,   117,     0,     0,    29,    83,    81,    53,    46,    49,
      68,    70,    55,    57,    59,    61,    63,    65,    73,    75,
      77,    43,    41,   111,     0,     0,    90,    47,    50,    69,
      71,    56,    58,    60,    62,    64,    66,    74,    76,    78,
       0,     0,     0,     0,   109,   117,   112,     0,     0,   117,
       0,     0,   108,     0,   114
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,   -14,   152,   -39,   134,  -155,  -155,   148,   117,
     -56,  -155,  -155,   155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,    60,  -155,  -155,    36,  -155,  -104,  -155,   -10,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,   -89,
    -155,  -155,  -155,  -110,  -155,  -155,  -155,  -155,  -155,   118,
    -155,  -155,   -51,   122,  -155,   -69,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -154,  -155,   161,  -155,  -155,  -155,
     -58,  -155,  -155,  -155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    74,    75,    51,    52,    53,    54,   116,    56,
      57,    90,    11,    33,    58,    14,    34,    35,    60,   130,
     131,   100,   117,   118,   187,   119,   188,   120,   167,   121,
     191,   192,   193,   194,   195,   196,   122,   189,   190,   123,
     197,   198,   199,   124,   166,   125,    16,    17,    22,    36,
      76,    77,   126,   127,    80,    95,    96,    81,    82,   201,
      83,    84,    85,    86,    31,    32,     7,     8,     9,    10,
      12,    13,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    24,    87,    98,   141,    88,   183,   184,    68,    78,
      40,   142,    46,    47,    24,    37,    29,    42,    30,     3,
      97,   113,    43,    44,   153,   154,   155,   114,     4,    94,
     128,     6,   132,   109,   133,   113,    15,   134,   135,   115,
     169,   114,    19,   178,   179,   180,    29,    41,    61,    24,
      20,   208,   137,    18,   111,   211,   170,   171,    45,    23,
     157,    41,    46,    47,    48,    49,    50,    73,    28,    38,
      26,    59,    45,   139,    62,    63,    46,    47,    48,    49,
      50,    73,    39,    66,    40,    46,    47,    48,    49,    41,
     182,    42,    67,    92,   136,    89,    43,    44,    93,    -4,
      45,   102,  -123,    99,    46,    47,    48,    49,    50,  -115,
      39,  -110,    40,    70,    71,   101,   103,   104,   105,    42,
      72,   106,  -113,   185,    43,    44,   145,   146,    73,   107,
     110,   147,   148,   149,   150,   151,   152,   172,   173,   174,
     175,   176,   177,   108,   112,   129,   -40,   138,   143,   144,
     156,   158,   159,   160,   163,   162,   164,   161,   165,   181,
     186,   200,   202,   203,   207,   205,    21,   204,   212,   206,
      25,   209,    64,   140,   210,    69,   214,   213,    55,   168,
      27,    91,    79
};

static const yytype_uint8 yycheck[] =
{
      39,    15,    60,    72,   114,    61,   160,   161,    25,    60,
      27,   115,    47,    48,    28,    29,     3,    34,     5,     0,
      71,     6,    39,    40,    13,    14,    15,    12,    52,    68,
      99,     4,   101,    89,   103,     6,    45,   106,   107,    24,
     144,    12,    26,   153,   154,   155,     3,    32,     5,    63,
      52,   205,   110,    31,    93,   209,   145,   146,    43,    52,
     129,    32,    47,    48,    49,    50,    51,    52,     6,    12,
      52,    31,    43,   112,     7,     4,    47,    48,    49,    50,
      51,    52,    25,     4,    27,    47,    48,    49,    50,    32,
     159,    34,     4,     4,   108,     5,    39,    40,    42,     6,
      43,     4,    26,     8,    47,    48,    49,    50,    51,    33,
      25,    35,    27,    37,    38,     6,    10,     4,     4,    34,
      44,    35,    46,   162,    39,    40,    11,    12,    52,    46,
       4,    16,    17,    18,    19,    20,    21,   147,   148,   149,
     150,   151,   152,    33,    42,     8,     7,    36,    23,    22,
       9,     7,     3,    41,    31,    10,    36,    29,     7,     9,
      52,    31,    31,    42,   203,    30,    14,    35,    35,    29,
      15,    29,    38,   113,    31,    58,    29,    31,    30,   143,
      19,    63,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   125,   126,     0,    52,    54,     4,   119,   120,   121,
     122,    65,   123,   124,    68,    45,    99,   100,    31,    26,
      52,    56,   101,    52,    55,    66,    52,   119,     6,     3,
       5,   117,   118,    66,    69,    70,   102,    55,    12,    25,
      27,    32,    34,    39,    40,    43,    47,    48,    49,    50,
      51,    57,    58,    59,    60,    61,    62,    63,    67,    31,
      71,     5,     7,     4,    58,    57,     4,     4,    25,    62,
      37,    38,    44,    52,    55,    56,   103,   104,   105,   106,
     107,   110,   111,   113,   114,   115,   116,   123,    63,     5,
      64,   102,     4,    42,    57,   108,   109,   105,   108,     8,
      74,     6,     4,    10,     4,     4,    35,    46,    33,    63,
       4,    57,    42,     6,    12,    24,    61,    75,    76,    78,
      80,    82,    89,    92,    96,    98,   105,   106,   108,     8,
      72,    73,   108,   108,   108,   108,    55,   123,    36,    57,
      75,    96,    80,    23,    22,    11,    12,    16,    17,    18,
      19,    20,    21,    13,    14,    15,     9,   108,     7,     3,
      41,    29,    10,    31,    36,     7,    97,    81,    78,    80,
      92,    92,    82,    82,    82,    82,    82,    82,    96,    96,
      96,     9,   108,   117,   117,    57,    52,    77,    79,    90,
      91,    83,    84,    85,    86,    87,    88,    93,    94,    95,
      31,   112,    31,    42,    35,    30,    29,    57,   117,    29,
      31,   117,    35,    31,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    56,    57,    57,    58,    58,    58,
      59,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    77,    76,    76,    79,
      78,    78,    81,    80,    80,    83,    82,    84,    82,    85,
      82,    86,    82,    87,    82,    88,    82,    82,    90,    89,
      91,    89,    89,    93,    92,    94,    92,    95,    92,    92,
      97,    96,    96,    98,    98,    98,    98,    99,   100,   100,
     101,   102,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   106,   107,   108,   109,   110,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     0,     3,     1,     6,
       5,     2,     0,     1,     0,     3,     1,     2,     0,     1,
       0,     3,     1,     4,     3,     1,     0,     4,     1,     0,
       4,     1,     0,     3,     1,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     1,     0,     4,
       0,     4,     1,     0,     4,     0,     4,     0,     4,     1,
       0,     3,     1,     3,     1,     1,     1,     5,     5,     6,
       9,     3,     1,     2,     1,     1,     1,     2,     2,     3,
       2,     2,     1,     2,     4,     2,     2,     0,    10,     7,
       0,     0,     7,     0,    11,     0,     2,     0,     2,     0,
       2,     0,     5,     0,     8,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 114 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.text_val) = (yyvsp[0].text_val);
            debug_log("program name");
        }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 121 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.text_val) = (yyvsp[0].text_val);
            debug_log("variable name");
        }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 128 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.text_val) = (yyvsp[0].text_val);
            debug_log("function name");
        }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "yacc.y" /* yacc.c:1646  */
    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 140 "yacc.y" /* yacc.c:1646  */
    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 144 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cn) = calloc(1, sizeof(struct const_node));
            (yyval.cn)->int_val = (yyvsp[0].int_val);
            (yyval.cn)->type = INTE_TYPE;
            (yyval.cn)->loc = (yyloc);

            debug_log("number const");
        }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 153 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cn) = calloc(1, sizeof(struct const_node));
            (yyval.cn)->real_val = (yyvsp[0].real_val);
            (yyval.cn)->type = REAL_TYPE;
            (yyval.cn)->loc = (yyloc);

            debug_log("float const");
        }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 162 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cn) = calloc(1, sizeof(struct const_node));
            (yyval.cn)->real_val = (yyvsp[0].real_val);
            (yyval.cn)->type = REAL_TYPE;
            (yyval.cn)->loc = (yyloc);

            debug_log("float const");
        }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 173 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cn) = calloc(1, sizeof(struct const_node));
            (yyval.cn)->text_val = (yyvsp[0].text_val);
            (yyval.cn)->type = TEXT_TYPE;
            (yyval.cn)->loc = (yyloc);

            debug_log("string const");
        }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 184 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cn) = calloc(1, sizeof(struct const_node));
            (yyval.cn)->bool_val = true;
            (yyval.cn)->type = BOOL_TYPE;
            (yyval.cn)->loc = (yyloc);

            debug_log("boolean const");
        }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 193 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cn) = calloc(1, sizeof(struct const_node));
            (yyval.cn)->bool_val = false;
            (yyval.cn)->type = BOOL_TYPE;
            (yyval.cn)->loc = (yyloc);

            debug_log("boolean const");
        }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 204 "yacc.y" /* yacc.c:1646  */
    { (yyval.cn) = (yyvsp[0].cn); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 206 "yacc.y" /* yacc.c:1646  */
    { (yyval.cn) = (yyvsp[0].cn); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 208 "yacc.y" /* yacc.c:1646  */
    { (yyval.cn) = (yyvsp[0].cn); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 215 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.tn) = calloc(1, sizeof(struct type_node));
            (yyval.tn)->type = INTE_TYPE;
            (yyval.tn)->loc = (yyloc);

            debug_log("integer type");
        }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 223 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.tn) = calloc(1, sizeof(struct type_node));
            (yyval.tn)->type = REAL_TYPE;
            (yyval.tn)->loc = (yyloc);

            debug_log("real type");
        }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 231 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.tn) = calloc(1, sizeof(struct type_node));
            (yyval.tn)->type = TEXT_TYPE;
            (yyval.tn)->loc = (yyloc);

            debug_log("string type");
        }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 239 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.tn) = calloc(1, sizeof(struct type_node));
            (yyval.tn)->type = BOOL_TYPE;
            (yyval.tn)->loc = (yyloc);

            debug_log("boolean type");
        }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 249 "yacc.y" /* yacc.c:1646  */
    { (yyval.tn) = (yyvsp[0].tn); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.tn) = (yyvsp[0].tn);
            (yyval.tn)->dim = (yyvsp[-1].dl);
            (yyval.tn)->loc = (yyloc);
        }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "yacc.y" /* yacc.c:1646  */
    { (yyval.tn) = (yyvsp[0].tn); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 261 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.tn) = calloc(1, sizeof(struct type_node));
            (yyval.tn)->type = VOID_TYPE;

            debug_log("no return value");
        }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 273 "yacc.y" /* yacc.c:1646  */
    {
            if((yyvsp[-1].vn) != 0)
            {
                (yyval.vn) = (yyvsp[-1].vn);
                struct variable_node *tail = (yyval.vn);
                while(tail->sibling != 0)
                    tail = tail->sibling;
                tail->sibling = (yyvsp[0].vn);
            }
            else
                (yyval.vn) = (yyvsp[0].vn);
        }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 286 "yacc.y" /* yacc.c:1646  */
    {
            if((yyvsp[-1].vn) != 0)
            {
                (yyval.vn) = (yyvsp[-1].vn);
                struct variable_node *tail = (yyval.vn);
                while(tail->sibling != 0)
                    tail = tail->sibling;
                tail->sibling = (yyvsp[0].vn);
            }
            else
                (yyval.vn) = (yyvsp[0].vn);
        }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 299 "yacc.y" /* yacc.c:1646  */
    { (yyval.vn) = 0; }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 303 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.vn) = (yyvsp[-2].vn);
            struct variable_node *tail = (yyval.vn);
            while(tail->sibling != 0)
                tail = tail->sibling;
            tail->sibling = calloc(1, sizeof(struct variable_node));
            tail->sibling->name = (yyvsp[0].text_val);
            tail->sibling->loc = (yylsp[0]);
        }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 313 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.vn) = calloc(1, sizeof(struct variable_node));
            (yyval.vn)->name = (yyvsp[0].text_val);
            (yyval.vn)->loc = (yylsp[0]);
        }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 321 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.dl) = (yyvsp[-5].dl);
            struct dim_list *tail = (yyval.dl);
            while(tail->next != 0)
                tail = tail->next;
            tail->next = calloc(1, sizeof(struct dim_list));
            tail->next->lower = (yyvsp[-3].int_val);
            tail->next->upper = (yyvsp[-1].int_val);

            debug_log("array dimensional");
        }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 333 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.dl) = calloc(1, sizeof(struct dim_list));
            (yyval.dl)->lower = (yyvsp[-3].int_val);
            (yyval.dl)->upper = (yyvsp[-1].int_val);
            (yyval.dl)->loc = (yyloc);
            debug_log("array dimensional");
        }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 343 "yacc.y" /* yacc.c:1646  */
    {
            if((yyvsp[-1].fn) != 0)
            {
                (yyval.fn) = (yyvsp[-1].fn);
                struct function_node *tail = (yyval.fn);
                while(tail->sibling != 0)
                    tail = tail->sibling;
                tail->sibling = (yyvsp[0].fn);
            }
            else
                (yyval.fn) = (yyvsp[0].fn);
        }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 356 "yacc.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 360 "yacc.y" /* yacc.c:1646  */
    { (yyval.vn) = (yyvsp[0].vn); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 362 "yacc.y" /* yacc.c:1646  */
    { (yyval.vn) = 0; }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 366 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.vn) = (yyvsp[-2].vn);
            struct variable_node *tail = (yyval.vn);
            while(tail->sibling != 0)
                tail = tail->sibling;
            tail->sibling = (yyvsp[0].vn);
        }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 374 "yacc.y" /* yacc.c:1646  */
    { (yyval.vn) = (yyvsp[0].vn); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 378 "yacc.y" /* yacc.c:1646  */
    {
            if((yyvsp[-1].sn) != 0)
            {
                (yyval.sn) = (yyvsp[-1].sn);
                struct statment_node *tail = (yyval.sn);
                while(tail->sibling != 0)
                    tail = tail->sibling;
                tail->sibling = (yyvsp[0].sn);
            }
            else
                (yyval.sn) = (yyvsp[0].sn);
        }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 391 "yacc.y" /* yacc.c:1646  */
    { (yyval.sn) = 0; }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 395 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 397 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = 0; }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 401 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = (yyvsp[-2].en);
            struct expr_node *tail = (yyval.en);
            while(tail->sibling != 0)
                tail = tail->sibling;
            tail->sibling = (yyvsp[0].en);
            (yyval.en)->loc = (yyloc);
        }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 410 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 414 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = (yyvsp[-3].en);
            struct expr_node *tail = (yyval.en);
            while(tail->sibling != 0)
                tail = tail->sibling;
            tail->sibling = (yyvsp[-1].en);
            (yyval.en)->loc = (yyloc);

            debug_log("variable reference argument");
        }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 425 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = (yyvsp[-1].en);
            (yyval.en)->loc = (yyloc);

            debug_log("variable reference argument");
        }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 437 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 440 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt or"); }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 441 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = bool_or;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 453 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 456 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt and"); }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 457 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = bool_and;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 469 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 472 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt not"); }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 473 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = bool_not;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 484 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 487 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion less"); }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 488 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = cmp_less;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 499 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion less eq"); }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 500 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = cmp_leq;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 511 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion greater"); }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 512 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = cmp_gt;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 523 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion greater eq"); }
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 524 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = cmp_geq;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 535 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion eq"); }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 536 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = cmp_eq;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 547 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion no eq"); }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 548 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = cmp_neq;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = BOOL_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 560 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 563 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator add"); }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 564 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = opt_add;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = REAL_TYPE;     // type coercion
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 575 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator del"); }
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 576 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = opt_del;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = REAL_TYPE;     // type coercion
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 588 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 591 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator mul"); }
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 592 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = opt_mul;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = REAL_TYPE;     // type coercion
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 603 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator div"); }
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 604 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = opt_div;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = REAL_TYPE;     // type coercion
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 615 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator mod"); }
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 616 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->lsite = (yyvsp[-3].en);
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = opt_mod;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = INTE_TYPE;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 628 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 631 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator get negative"); }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 632 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->rsite = (yyvsp[-1].en);
            (yyval.en)->opt = opt_nega;
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            // $$->type->type = $2->type->type;
            (yyval.en)->mode = EXPRESSION;
            (yyval.en)->loc = (yyloc);
        }
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 643 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[0].en); }
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 647 "yacc.y" /* yacc.c:1646  */
    { (yyval.en) = (yyvsp[-1].en); }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 649 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            (yyval.en)->finv = (yyvsp[0].finv);
            (yyval.en)->mode = FUNCT_INVO;
            (yyval.en)->loc = (yyloc);
        }
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 658 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            (yyval.en)->vref = (yyvsp[0].rn);
            (yyval.en)->mode = VARIA_REFE;
            (yyval.en)->loc = (yyloc);
        }
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 667 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = calloc(1, sizeof(struct expr_node));
            (yyval.en)->type = calloc(1, sizeof(struct type_node));
            (yyval.en)->type->loc = (yyloc);
            (yyval.en)->cont = (yyvsp[0].cn);
            (yyval.en)->mode = CONST_DATA;
            (yyval.en)->loc = (yyloc);
        }
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 681 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.vn) = (yyvsp[-3].vn);
            struct variable_node *temp = (yyval.vn);
            while(temp != 0)
            {
                temp->type = (yyvsp[-1].tn);
                temp->var_mode = 0; // variable
                temp = temp->sibling;
            }
            (yyval.vn)->loc = (yylsp[-1]);
            
            debug_log("variable declaration");
        }
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 697 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.vn) = (yyvsp[-3].vn);
            struct variable_node *temp = (yyval.vn);

            while(temp != 0)
            {
                temp->type = calloc(1, sizeof(struct type_node));
                temp->type->type = (yyvsp[-1].cn)->type;
                temp->const_val = (yyvsp[-1].cn);
                temp->var_mode = 1; // constant
                temp = temp->sibling;
            }

            debug_log("const declaration");
        }
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 713 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.vn) = (yyvsp[-4].vn);
            struct variable_node *temp = (yyval.vn);
            while(temp != 0)
            {
                temp->type = calloc(1, sizeof(struct type_node));
                temp->type->type = (yyvsp[-1].cn)->type;
                if((yyvsp[-1].cn)->type == INTE_TYPE)
                    (yyvsp[-1].cn)->int_val = -(yyvsp[-1].cn)->int_val;
                else /* REAL_TYPE */
                    (yyvsp[-1].cn)->real_val = -(yyvsp[-1].cn)->real_val;
                temp->const_val = (yyvsp[-1].cn);
                temp->type->type = temp->const_val->type;
                temp->var_mode = 1; // constant
                temp = temp->sibling;
            }

            debug_log("const declaration");
        }
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 741 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.fn) = calloc(1, sizeof(struct function_node));
            (yyval.fn)->name = (yyvsp[-8].text_val);
            (yyval.fn)->end_name = (yyvsp[0].text_val);
            (yyval.fn)->arg = (yyvsp[-6].vn);
            (yyval.fn)->ret_type = (yyvsp[-4].tn);
            (yyval.fn)->comp = (yyvsp[-2].cpn);
            (yyval.fn)->loc = (yylsp[-8]);
            (yyval.fn)->end_loc = (yylsp[0]);

            debug_log("function declaration");
        }
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 756 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.vn) = (yyvsp[-2].vn);
            struct variable_node *temp = (yyval.vn);
            while(temp != 0)
            {
                temp->type = (yyvsp[0].tn);
                temp->var_mode = 0; // variable
                temp = temp->sibling;
            }

            debug_log("argument declaration");
        }
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 774 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.sn) = calloc(1, sizeof(struct statment_node));
            (yyval.sn)->comp = (yyvsp[0].cpn);
            (yyval.sn)->mode = COMP_STAT;
            (yyval.sn)->loc = (yyloc);
        }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 781 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.sn) = calloc(1, sizeof(struct statment_node));
            (yyval.sn)->simp = (yyvsp[-1].simp);
            (yyval.sn)->mode = SIMP_STAT;
            (yyval.sn)->loc = (yyloc);
        }
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 788 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.sn) = calloc(1, sizeof(struct statment_node));
            (yyval.sn)->cond = (yyvsp[0].cond);
            (yyval.sn)->mode = COND_STAT;
            (yyval.sn)->loc = (yyloc);
        }
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 795 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.sn) = calloc(1, sizeof(struct statment_node));
            (yyval.sn)->whil = (yyvsp[0].whil);
            (yyval.sn)->mode = WHIL_STAT;
            (yyval.sn)->loc = (yyloc);
        }
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 802 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.sn) = calloc(1, sizeof(struct statment_node));
            (yyval.sn)->for_ = (yyvsp[0].for_);
            (yyval.sn)->mode = FOR__STAT;
            (yyval.sn)->loc = (yyloc);
        }
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 809 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.sn) = calloc(1, sizeof(struct statment_node));
            (yyval.sn)->finv = (yyvsp[-1].finv);
            (yyval.sn)->mode = FINV_STAT;
            (yyval.sn)->loc = (yyloc);
        }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 816 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.sn) = calloc(1, sizeof(struct statment_node));
            (yyval.sn)->ret_ = (yyvsp[-1].ret_);
            (yyval.sn)->mode = RET__STAT;
            (yyval.sn)->loc = (yyloc);
        }
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 825 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.simp) = calloc(1, sizeof(struct simp_node));
            (yyval.simp)->lhs = (yyvsp[-2].rn);
            (yyval.simp)->rhs = (yyvsp[0].en);
            (yyval.simp)->loc = (yyloc);

            debug_log("simple statement");
        }
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 834 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.simp) = calloc(1, sizeof(struct simp_node));
            (yyval.simp)->rhs = (yyvsp[0].en);
            (yyval.simp)->loc = (yylsp[0]);

            debug_log("simple print");
        }
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 842 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.simp) = calloc(1, sizeof(struct simp_node));
            (yyval.simp)->lhs = (yyvsp[0].rn);
            (yyval.simp)->loc = (yylsp[0]);

            debug_log("simple read");
        }
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 852 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.rn) = calloc(1, sizeof(struct varirefe_node));
            (yyval.rn)->name = (yyvsp[0].text_val);
            (yyval.rn)->loc = (yyloc);
            (yyval.rn)->type = calloc(1, sizeof(struct type_node));

            debug_log("variable reference");
        }
#line 2715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 861 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.rn) = calloc(1, sizeof(struct varirefe_node));
            (yyval.rn)->name = (yyvsp[-1].text_val);
            (yyval.rn)->ref = (yyvsp[0].en);
            (yyval.rn)->loc = (yyloc);
            (yyval.rn)->type = calloc(1, sizeof(struct type_node));

            debug_log("variable reference");
        }
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 873 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.finv) = calloc(1, sizeof(struct finv_node));
            (yyval.finv)->name = (yyvsp[-3].text_val);
            (yyval.finv)->exprs = (yyvsp[-1].en);
            (yyval.finv)->loc = (yyloc);
            (yyval.finv)->ret_type = calloc(1, sizeof(struct type_node));

            debug_log("function invocation");
        }
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 885 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.ret_) = calloc(1, sizeof(struct ret__node));
            (yyval.ret_)->expr = (yyvsp[0].en);
            (yyval.ret_)->loc = (yyloc);

            debug_log("return");
        }
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 898 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.en) = (yyvsp[0].en);
            debug_log("expression }");                                  depth--;
        }
#line 2764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 904 "yacc.y" /* yacc.c:1646  */
    { debug_log("expression node {");                    depth++; }
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 920 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cond) = calloc(1, sizeof(struct cond_node));
            (yyval.cond)->condition = (yyvsp[-7].en);
            (yyval.cond)->tpath = (yyvsp[-5].sn);
            (yyval.cond)->fpath = (yyvsp[-2].sn);
            (yyval.cond)->loc = (yyloc);

            debug_log("condition }");
            depth--;
        }
#line 2785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 931 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cond) = calloc(1, sizeof(struct cond_node));
            (yyval.cond)->condition = (yyvsp[-4].en);
            (yyval.cond)->tpath = (yyvsp[-2].sn);
            (yyval.cond)->loc = (yyloc);

            debug_log("condition }");
            depth--;
        }
#line 2799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 942 "yacc.y" /* yacc.c:1646  */
    { debug_log("condition node {");                           depth++; }
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 945 "yacc.y" /* yacc.c:1646  */
    { debug_log("else part"); }
#line 2811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 958 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.whil) = calloc(1, sizeof(struct whil_node));
            (yyval.whil)->condition = (yyvsp[-4].en);
            (yyval.whil)->stat = (yyvsp[-2].sn);
            (yyval.whil)->loc = (yyloc);

            debug_log("while }");
            depth--;
        }
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 969 "yacc.y" /* yacc.c:1646  */
    { debug_log("while node {");                              depth++; }
#line 2831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 982 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.for_) = calloc(1, sizeof(struct for__node));
            (yyval.for_)->i = calloc(1, sizeof(struct variable_node));
            (yyval.for_)->i->name = (yyvsp[-8].text_val);
            (yyval.for_)->i->type = calloc(1, sizeof(struct type_node));
            (yyval.for_)->i->type->type = INTE_TYPE;
            (yyval.for_)->i->var_mode = 2;// loop parameter
            (yyval.for_)->i->loc = (yylsp[-8]);
            (yyval.for_)->start = (yyvsp[-6].int_val);
            (yyval.for_)->end = (yyvsp[-4].int_val);
            (yyval.for_)->stat = (yyvsp[-2].sn);
            (yyval.for_)->ploc = (yylsp[-6]);
            (yyval.for_)->ploc.last_line = (yylsp[-4]).last_line;
            (yyval.for_)->ploc.last_column = (yylsp[-4]).last_column;
            (yyval.for_)->loc = (yyloc);

            debug_log("for }");
            depth--;
        }
#line 2855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1003 "yacc.y" /* yacc.c:1646  */
    { debug_log("for node {");                                  depth++; }
#line 2861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1020 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.sn) = (yyvsp[0].sn);
            debug_log("statement }");
            depth--;
        }
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1027 "yacc.y" /* yacc.c:1646  */
    { debug_log("statement declartion node {");           depth++; }
#line 2877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1040 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.vn) = (yyvsp[0].vn);

            debug_log("variable declartion  }");
            depth--;
        }
#line 2888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1048 "yacc.y" /* yacc.c:1646  */
    { debug_log("variable declartion node {");               depth++; }
#line 2894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1060 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.fn) = (yyvsp[0].fn);

            debug_log("function decalartion }");
            depth--;
        }
#line 2905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1068 "yacc.y" /* yacc.c:1646  */
    { debug_log("function decalartion node {");              depth++; }
#line 2911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1084 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.cpn) = calloc(1, sizeof(struct compound_node));
            (yyval.cpn)->loc_var = (yyvsp[-2].vn);
            (yyval.cpn)->stat = (yyvsp[-1].sn);
            (yyval.cpn)->loc = (yyloc);

            debug_log("compound statement }");
            depth--;
        }
#line 2925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1096 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("compound statement node {");
            depth++;
        }
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1113 "yacc.y" /* yacc.c:1646  */
    {
            (yyval.pn) = calloc(1, sizeof(struct program_node));
            (yyval.pn)->name = (yyvsp[-6].text_val);
            (yyval.pn)->end_name = (yyvsp[0].text_val);
            (yyval.pn)->vacd = (yyvsp[-4].vn);
            (yyval.pn)->func = (yyvsp[-3].fn);
            (yyval.pn)->comp = (yyvsp[-2].cpn);
            (yyval.pn)->loc = (yylsp[-6]);
            (yyval.pn)->end_loc = (yylsp[0]);
            (yyval.pn)->type = calloc(1, sizeof(struct type_node));
            (yyval.pn)->type->type = VOID_TYPE;
            (yyval.pn)->type->loc = (yyloc);
            ast = (yyval.pn);
            debug_log("program }");
            depth--;
        }
#line 2955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1132 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("program node {");
            depth++;
        }
#line 2964 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2968 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1138 "yacc.y" /* yacc.c:1906  */


int yyerror( char *msg )
{
    fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
    fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
    fprintf( stderr, "|\n" );
    fprintf( stderr, "| Unmatched token: %s\n", yytext );
    fprintf( stderr, "|--------------------------------------------------------------------------\n" );
    exit(-1);
}

