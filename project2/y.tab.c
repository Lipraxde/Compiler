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

#line 90 "y.tab.c" /* yacc.c:339  */

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
#line 25 "yacc.y" /* yacc.c:355  */

    int    value;
    double dvalue;
    char*  text;

#line 240 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

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
       0,    52,    52,    59,    62,    65,    72,    75,    82,    85,
      86,    87,    88,    91,    97,    98,   101,   104,   107,   108,
     109,   110,   113,   119,   125,   126,   127,   130,   131,   132,
     133,   136,   139,   140,   144,   151,   153,   156,   159,   162,
     168,   169,   170,   173,   179,   182,   183,   187,   194,   197,
     204,   205,   208,   211,   212,   213,   214,   215,   216,   219,
     225,   228,   233,   237,   243,   249,   252,   255,   256,   259,
     260,   263,   264,   267,   268,   269,   270,   271,   272,   273,
     277,   278,   279,   282,   283,   284,   285,   288,   289,   292,
     293,   294,   296,   299,   305,   306,   307,   310,   311,   314,
     317,   320
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
  "$accept", "program", "program_start", "program_name", "program_body",
  "program_body_start", "var_and_const_declar",
  "var_and_const_declar_start", "define_var_and_const", "define_variable",
  "var_list", "variable_name", "var_type", "scalar_type", "define_array",
  "define_const", "literal_const", "number_const", "string_const",
  "boolean_const", "function", "define_function", "function_start",
  "function_name", "argument_list", "define_argument", "argument",
  "argument_start", "func_ret_type", "compound_statement",
  "compound_statement_start", "statement_list", "define_statement",
  "statement_start", "statement_group", "simp_statement", "var_reference",
  "reference_list", "reference_start", "expression_node",
  "expression_start", "expression", "expr_order8", "expr_order7",
  "expr_order6", "expr_order5", "expr_order4", "expr_order3",
  "expr_order2", "expr_order1", "func_invocation", "expression_list",
  "cond_statement", "whil_statement", "for__statement", "ret__statement", YY_NULLPTR
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

#define YYPACT_NINF -122

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-122)))

#define YYTABLE_NINF -97

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -122,    14,   -31,  -122,  -122,    19,  -122,    -1,  -122,   -21,
    -122,   -11,  -122,  -122,   -15,    -9,  -122,   -11,   -11,   -11,
    -122,    12,  -122,  -122,    34,  -122,    39,    59,  -122,  -122,
    -122,  -122,  -122,    88,    -9,  -122,    56,    -9,    30,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
      92,  -122,    93,  -122,  -122,  -122,  -122,    72,   -20,    99,
     100,  -122,   108,    75,  -122,  -122,  -122,    62,  -122,  -122,
    -122,   110,   111,   112,  -122,   -20,   117,   113,   120,  -122,
    -122,  -122,   125,     2,   126,     2,    -9,    84,   123,   101,
      21,  -122,   105,  -122,   135,   137,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,   115,    10,   -20,    21,    33,
      43,  -122,  -122,  -122,   130,   132,  -122,  -122,   129,    74,
    -122,  -122,  -122,   -20,  -122,   149,   148,  -122,   127,     2,
     114,   -19,   150,  -122,  -122,    21,    21,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,   128,   152,
     137,  -122,   116,   158,    10,   -20,   131,  -122,   132,  -122,
      74,    74,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,   134,   111,  -122,   -15,  -122,   136,   133,  -122,  -122,
    -122,  -122,   -20,   138,   139,  -122,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     4,     0,     6,     0,     8,     0,
      37,    12,     2,    48,    36,     0,     7,    12,    12,    12,
       5,     0,    38,    34,     0,    16,     0,    15,     9,    10,
      11,     8,    44,     0,     0,    52,     0,    42,     0,    21,
      33,    18,    19,    20,    32,    27,    28,    29,    30,    31,
       0,    17,     0,    24,    25,    26,    14,     0,    51,    46,
       0,    39,    41,     0,    13,    23,    47,     0,    65,    65,
      65,    16,    62,     0,    49,    51,     0,     0,     0,    54,
      55,    56,     0,     0,     0,     0,    42,     0,     0,     0,
       0,   101,     0,    60,     0,    65,    50,    53,    65,    58,
      57,    45,    48,    43,    40,     0,     0,     0,     0,     0,
       0,    92,    91,    64,    66,    68,    70,    72,    79,    82,
      86,    88,    90,     0,    65,    95,     0,    59,     0,     0,
       0,     0,     0,    87,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    93,     0,     0,     0,     0,     0,    89,    67,    69,
      80,    81,    73,    74,    75,    76,    77,    78,    83,    84,
      85,     0,    62,    94,    36,    22,     0,     0,    98,    99,
      61,    35,     0,     0,     0,    97,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,  -122,  -122,   140,  -122,    29,  -122,
      -6,   -12,   -75,    86,  -122,  -122,   141,   -98,  -122,  -122,
    -122,    -7,  -122,   -14,  -122,    89,  -122,  -122,  -122,    70,
    -122,  -122,   102,  -122,  -103,  -122,   -57,     4,  -122,   -63,
    -122,    71,  -122,    45,    42,   -33,  -122,  -121,   -45,    73,
     -56,    31,  -122,  -122,  -122,  -122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     7,     8,    10,    11,    16,    17,
      60,    72,    50,    51,    18,    19,   111,    53,    54,    55,
      13,    23,    14,    73,    36,    61,    62,    37,    84,    20,
      21,    57,    74,    58,    75,    76,   112,    93,    94,   125,
      90,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   126,    79,    80,    81,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    77,    78,    27,   131,    89,    91,    92,   130,    26,
     103,   155,   156,    67,     3,    68,   160,   161,    77,    78,
     148,     4,    27,     6,    69,    27,    70,   108,    56,    39,
       9,    12,    71,   109,    15,   127,    41,    22,    31,   108,
      32,    42,    43,    25,    33,   110,    28,    29,    30,   108,
      77,    78,   177,    40,   153,   109,   176,    45,    46,    47,
      48,   149,    34,    59,    44,    40,    77,    78,    45,    46,
      47,    48,    49,    71,    27,    40,    44,   134,    63,   184,
      45,    46,    47,    48,    49,    71,    44,   145,   146,   147,
      45,    46,    47,    48,    49,    71,    64,    65,    77,    78,
     168,   169,   170,    66,    83,    85,   162,   163,   164,   165,
     166,   167,    86,    38,    88,    39,   -38,    87,    95,   -63,
      40,    97,    41,    98,    99,    77,    78,    42,    43,   100,
     102,    44,   105,   106,   123,    45,    46,    47,    48,    49,
     137,   138,   107,   124,   -96,   139,   140,   141,   142,   143,
     144,   129,   150,   135,   136,   151,   154,   157,   152,   171,
      24,   172,   175,   179,   183,   182,   178,   181,   174,   101,
     186,    35,   128,   185,    52,   104,   180,    96,   159,   132,
     158,   173,   133
};

static const yytype_uint8 yycheck[] =
{
      14,    58,    58,    15,   107,    68,    69,    70,   106,    15,
      85,    30,    31,    33,     0,    35,   137,   138,    75,    75,
     123,    52,    34,     4,    44,    37,    46,     6,    34,    27,
      31,    52,    52,    12,    45,    98,    34,    52,    26,     6,
       6,    39,    40,    52,     5,    24,    17,    18,    19,     6,
     107,   107,   155,    32,   129,    12,   154,    47,    48,    49,
      50,   124,     3,     7,    43,    32,   123,   123,    47,    48,
      49,    50,    51,    52,    86,    32,    43,   110,    48,   182,
      47,    48,    49,    50,    51,    52,    43,    13,    14,    15,
      47,    48,    49,    50,    51,    52,     4,     4,   155,   155,
     145,   146,   147,    31,     5,     5,   139,   140,   141,   142,
     143,   144,     4,    25,    52,    27,     6,    42,     6,     8,
      32,     4,    34,    10,     4,   182,   182,    39,    40,     4,
       4,    43,    48,    10,    29,    47,    48,    49,    50,    51,
      11,    12,    41,     8,     7,    16,    17,    18,    19,    20,
      21,    36,     3,    23,    22,     7,    42,     7,    31,    31,
     174,     9,     4,    29,    31,    29,    35,   174,    52,    83,
      31,    31,   102,    35,    33,    86,   172,    75,   136,   108,
     135,   150,   109
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,    55,     0,    52,    56,     4,    57,    58,    31,
      59,    60,    52,    73,    75,    45,    61,    62,    67,    68,
      82,    83,    52,    74,    76,    52,    63,    64,    61,    61,
      61,    26,     6,     5,     3,    59,    77,    80,    25,    27,
      32,    34,    39,    40,    43,    47,    48,    49,    50,    51,
      65,    66,    69,    70,    71,    72,    63,    84,    86,     7,
      63,    78,    79,    48,     4,     4,    31,    33,    35,    44,
      46,    52,    64,    76,    85,    87,    88,    89,   103,   105,
     106,   107,   108,     5,    81,     5,     4,    42,    52,    92,
      93,    92,    92,    90,    91,     6,    85,     4,    10,     4,
       4,    66,     4,    65,    78,    48,    10,    41,     6,    12,
      24,    69,    89,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    29,     8,    92,   104,    92,    82,    36,
      70,    87,    94,   102,    98,    23,    22,    11,    12,    16,
      17,    18,    19,    20,    21,    13,    14,    15,    87,    92,
       3,     7,    31,    65,    42,    30,    31,     7,    96,    97,
     100,   100,    98,    98,    98,    98,    98,    98,   101,   101,
     101,    31,     9,   104,    52,     4,    70,    87,    35,    29,
      90,    74,    29,    31,    87,    35,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      61,    61,    61,    62,    63,    63,    64,    65,    66,    66,
      66,    66,    67,    68,    69,    69,    69,    70,    70,    70,
      70,    71,    72,    72,    73,    74,    74,    75,    76,    77,
      78,    78,    78,    79,    80,    81,    81,    82,    83,    84,
      85,    85,    86,    87,    87,    87,    87,    87,    87,    88,
      89,    90,    90,    91,    92,    93,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      99,    99,    99,   100,   100,   100,   100,   101,   101,   102,
     102,   102,   102,   103,   104,   104,   104,   105,   105,   106,
     107,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     1,     4,     0,     2,     0,     2,
       2,     2,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,    10,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,    10,     0,     0,     1,     2,
       3,     1,     0,     3,     0,     2,     0,     5,     0,     2,
       2,     0,     0,     2,     1,     1,     1,     2,     2,     3,
       2,     5,     0,     0,     2,     0,     1,     3,     1,     3,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     1,     3,
       1,     1,     1,     4,     3,     1,     0,     8,     6,     6,
       9,     2
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 53 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("program }");
            depth--;
        }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "yacc.y" /* yacc.c:1646  */
    { debug_log("program node {");              depth++; }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "yacc.y" /* yacc.c:1646  */
    { debug_log("program name"); }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("program body }");
            depth--;
        }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 72 "yacc.y" /* yacc.c:1646  */
    { debug_log("program body {");                  depth++; }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 76 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("variable }");
            depth--;
        }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 82 "yacc.y" /* yacc.c:1646  */
    { debug_log("variable node {");            depth++; }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 92 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("variable declaration");
        }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 101 "yacc.y" /* yacc.c:1646  */
    { debug_log("variable name"); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 107 "yacc.y" /* yacc.c:1646  */
    { debug_log("integer type"); }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 108 "yacc.y" /* yacc.c:1646  */
    { debug_log("real type"); }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "yacc.y" /* yacc.c:1646  */
    { debug_log("string type"); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 110 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean type"); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("array declaration");
        }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("const declaration");
        }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 130 "yacc.y" /* yacc.c:1646  */
    { debug_log("integer const"); }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 131 "yacc.y" /* yacc.c:1646  */
    { debug_log("integer const"); }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 132 "yacc.y" /* yacc.c:1646  */
    { debug_log("float const"); }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 133 "yacc.y" /* yacc.c:1646  */
    { debug_log("float const"); }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 136 "yacc.y" /* yacc.c:1646  */
    { debug_log("string const"); }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 139 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean const"); }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 140 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean const"); }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 145 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("function }");
            depth--;
        }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 156 "yacc.y" /* yacc.c:1646  */
    { debug_log("function node {");                        depth++; }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 159 "yacc.y" /* yacc.c:1646  */
    { debug_log("function name"); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 163 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("argument }");                                    depth--;
        }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 174 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("argument declaration");
        }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 179 "yacc.y" /* yacc.c:1646  */
    { debug_log("argument node {");                        depth++; }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 183 "yacc.y" /* yacc.c:1646  */
    { debug_log("no return value"); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 188 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("compound statement }");
            depth--;
        }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 194 "yacc.y" /* yacc.c:1646  */
    { debug_log("compound statement node {");    depth++; }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 198 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("statement }");
            depth--;
        }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 208 "yacc.y" /* yacc.c:1646  */
    { debug_log("statement node {");                      depth++; }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 220 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("simple statement");
        }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 229 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("index }");
            depth--;
        }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 237 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("index node {");
            depth++;
        }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 244 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("expression }");                                  depth--;
        }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 249 "yacc.y" /* yacc.c:1646  */
    { debug_log("expression node {");                    depth++; }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 255 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt or"); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 259 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt and"); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 263 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt not"); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 267 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion less"); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 268 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion less eq"); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 269 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion greater"); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 270 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion greater eq"); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 271 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion eq"); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 272 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion no eq"); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 277 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator add"); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 278 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator del"); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 282 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator mul"); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 283 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator div"); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 284 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator mod"); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 288 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator get negative"); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 295 "yacc.y" /* yacc.c:1646  */
    { debug_log("variable reference"); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 300 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("function invocation");
        }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1851 "y.tab.c" /* yacc.c:1646  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 340 "yacc.y" /* yacc.c:1906  */


int yyerror( char *msg )
{
    fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
    fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
    fprintf( stderr, "|\n" );
    fprintf( stderr, "| Unmatched token: %s\n", yytext );
    fprintf( stderr, "|--------------------------------------------------------------------------\n" );
    exit(-1);
}

int  main( int argc, char **argv )
{
    if( argc != 2 ) {
        fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
        exit(0);
    }

    FILE *fp = fopen( argv[1], "r" );
    
    if( fp == NULL )  {
        fprintf( stdout, "Open  file  error\n" );
        exit(-1);
    }
    
    yyin = fp;
    yyparse();

    fprintf( stdout, "\n" );
    fprintf( stdout, "|--------------------------------|\n" );
    fprintf( stdout, "|  There is no syntactic error!  |\n" );
    fprintf( stdout, "|--------------------------------|\n" );
    exit(0);
}

