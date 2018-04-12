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
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

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
     109,   110,   113,   119,   121,   125,   131,   132,   133,   136,
     137,   138,   139,   142,   145,   146,   150,   159,   157,   160,
     163,   166,   169,   175,   176,   177,   180,   186,   189,   190,
     194,   201,   204,   211,   212,   213,   216,   219,   220,   221,
     222,   223,   224,   227,   231,   233,   237,   240,   245,   249,
     255,   261,   264,   267,   268,   271,   272,   275,   276,   279,
     280,   281,   282,   283,   284,   285,   289,   290,   291,   294,
     295,   296,   297,   300,   301,   304,   305,   306,   308,   311,
     317,   318,   319,   322,   323,   326,   329,   332
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
  "define_mdarray", "define_const", "literal_const", "number_const",
  "string_const", "boolean_const", "function", "define_function", "$@1",
  "function_start", "function_name", "argument_list", "define_argument",
  "argument", "argument_start", "func_ret_type", "compound_statement",
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

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -103

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -110,    19,   -27,  -110,  -110,    30,  -110,     5,  -110,    -5,
    -110,     4,  -110,  -110,     1,     3,  -110,     4,     4,     4,
    -110,    17,  -110,  -110,    50,  -110,    55,    69,  -110,  -110,
    -110,  -110,  -110,   102,     3,  -110,    66,     3,    28,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
      74,  -110,    64,    77,  -110,  -110,  -110,  -110,    51,     0,
      79,    81,  -110,    83,    48,  -110,   104,  -110,  -110,    76,
    -110,  -110,     3,  -110,  -110,   120,   122,   125,   121,  -110,
     121,   131,   127,   134,  -110,  -110,  -110,   135,    64,   136,
      64,     3,    95,  -110,   138,   103,    18,  -110,  -110,  -110,
     117,  -110,   147,   150,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,   124,   -32,   121,    18,    45,    73,
    -110,  -110,  -110,   139,   141,  -110,  -110,   160,    49,  -110,
    -110,  -110,     0,  -110,   158,   157,  -110,   137,   144,   128,
      -3,   159,  -110,  -110,    18,    18,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,   143,   173,   150,
    -110,   132,  -110,   -32,     0,   148,  -110,   141,  -110,    49,
      49,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
     156,   122,  -110,  -110,   161,   155,  -110,  -110,  -110,     1,
       0,   152,  -110,   162,  -110,   163,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     4,     0,     6,     0,     8,     0,
      40,    12,     2,    51,    39,     0,     7,    12,    12,    12,
       5,     0,    41,    36,     0,    16,     0,    15,     9,    10,
      11,     8,    47,     0,     0,    56,     0,    45,     0,    21,
      35,    18,    19,    20,    34,    29,    30,    31,    32,    33,
       0,    17,     0,     0,    26,    27,    28,    14,     0,    51,
      49,     0,    42,    44,     0,    13,     0,    25,    50,     0,
      71,    71,     0,    71,    71,    16,    68,     0,    55,    52,
      55,     0,     0,     0,    58,    59,    60,     0,     0,     0,
       0,    45,     0,    22,     0,     0,     0,    64,    65,   107,
       0,    66,     0,    71,    54,    53,    57,    71,    62,    61,
      48,    51,    46,    43,     0,     0,    55,     0,     0,     0,
      98,    97,    70,    72,    74,    76,    78,    85,    88,    92,
      94,    96,    51,    71,   101,     0,    63,     0,    24,     0,
       0,     0,    93,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      99,     0,    23,     0,    51,     0,    95,    73,    75,    86,
      87,    79,    80,    81,    82,    83,    84,    89,    90,    91,
       0,    68,   100,    37,     0,     0,   104,   105,    67,    39,
      51,     0,    38,     0,   103,     0,   106
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,  -110,  -110,  -110,   164,  -110,    82,  -110,
      -2,    -8,   -42,   100,  -110,    53,  -110,   165,  -109,  -110,
    -110,  -110,     7,  -110,  -110,   -14,  -110,    98,  -110,  -110,
    -110,    -9,  -110,  -110,   -75,  -110,  -110,  -110,   -58,    13,
    -110,   -62,  -110,    80,  -110,    56,    54,   -39,  -110,  -107,
     -37,    84,   -57,    42,  -110,  -110,  -110,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     7,     8,    10,    11,    16,    17,
      61,    76,    50,    51,    18,    52,    19,   120,    54,    55,
      56,    13,    23,   189,    14,    77,    36,    62,    63,    37,
      89,    78,    21,    58,    79,    59,    80,    81,   121,   101,
     102,   134,    96,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   135,    84,    85,    86,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    82,    83,   104,    20,   105,   139,    27,    95,    97,
      66,    99,   100,    26,    98,    45,    46,    47,    48,     3,
      82,    83,    82,    83,   117,     4,    27,   164,   165,    27,
     118,   -55,    57,    69,     6,    70,     9,    71,    72,   169,
     170,   140,   119,    31,    73,   136,    74,    12,   112,    15,
      40,   117,    75,    22,   184,    25,    32,   157,    82,    83,
      33,    44,   154,   155,   156,    45,    46,    47,    48,    49,
      75,   158,    34,    60,    82,    83,    64,    40,    65,   117,
     143,    67,    68,    27,    88,   118,    90,    91,    44,   185,
      92,    39,    45,    46,    47,    48,    49,    75,    41,    28,
      29,    30,   137,    42,    43,    40,    82,    83,    93,   171,
     172,   173,   174,   175,   176,   193,    44,   177,   178,   179,
      45,    46,    47,    48,    49,    75,   -41,    38,    94,    39,
     -69,   103,    82,    83,    40,   106,    41,   107,   108,   109,
     111,    42,    43,   114,   116,    44,   132,   -51,   115,    45,
      46,    47,    48,    49,    69,   133,    70,  -102,    71,    72,
     138,   159,   144,   145,   160,    73,   166,    74,   161,    38,
     163,   146,   147,    75,   180,    24,   148,   149,   150,   151,
     152,   153,   181,   186,   183,   187,   191,   194,   110,   113,
     190,   162,   196,   195,   188,    35,   192,   141,    53,   168,
     167,   182,   142
};

static const yytype_uint8 yycheck[] =
{
      14,    59,    59,    78,    13,    80,   115,    15,    70,    71,
      52,    73,    74,    15,    72,    47,    48,    49,    50,     0,
      78,    78,    80,    80,     6,    52,    34,    30,    31,    37,
      12,    31,    34,    33,     4,    35,    31,    37,    38,   146,
     147,   116,    24,    26,    44,   107,    46,    52,    90,    45,
      32,     6,    52,    52,   163,    52,     6,   132,   116,   116,
       5,    43,    13,    14,    15,    47,    48,    49,    50,    51,
      52,   133,     3,     7,   132,   132,    48,    32,     4,     6,
     119,     4,    31,    91,     5,    12,     5,     4,    43,   164,
      42,    27,    47,    48,    49,    50,    51,    52,    34,    17,
      18,    19,   111,    39,    40,    32,   164,   164,     4,   148,
     149,   150,   151,   152,   153,   190,    43,   154,   155,   156,
      47,    48,    49,    50,    51,    52,     6,    25,    52,    27,
       8,     6,   190,   190,    32,     4,    34,    10,     4,     4,
       4,    39,    40,    48,    41,    43,    29,    26,    10,    47,
      48,    49,    50,    51,    33,     8,    35,     7,    37,    38,
      36,     3,    23,    22,     7,    44,     7,    46,    31,    25,
      42,    11,    12,    52,    31,   189,    16,    17,    18,    19,
      20,    21,     9,    35,    52,    29,    31,    35,    88,    91,
      29,   138,    29,    31,   181,    31,   189,   117,    33,   145,
     144,   159,   118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,    55,     0,    52,    56,     4,    57,    58,    31,
      59,    60,    52,    74,    77,    45,    61,    62,    67,    69,
      84,    85,    52,    75,    78,    52,    63,    64,    61,    61,
      61,    26,     6,     5,     3,    59,    79,    82,    25,    27,
      32,    34,    39,    40,    43,    47,    48,    49,    50,    51,
      65,    66,    68,    70,    71,    72,    73,    63,    86,    88,
       7,    63,    80,    81,    48,     4,    65,     4,    31,    33,
      35,    37,    38,    44,    46,    52,    64,    78,    84,    87,
      89,    90,    91,   105,   107,   108,   109,   110,     5,    83,
       5,     4,    42,     4,    52,    94,    95,    94,    91,    94,
      94,    92,    93,     6,    87,    87,     4,    10,     4,     4,
      66,     4,    65,    80,    48,    10,    41,     6,    12,    24,
      70,    91,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    29,     8,    94,   106,    94,    84,    36,    71,
      87,    96,   104,   100,    23,    22,    11,    12,    16,    17,
      18,    19,    20,    21,    13,    14,    15,    87,    94,     3,
       7,    31,    68,    42,    30,    31,     7,    98,    99,   102,
     102,   100,   100,   100,   100,   100,   100,   103,   103,   103,
      31,     9,   106,    52,    71,    87,    35,    29,    92,    76,
      29,    31,    75,    87,    35,    31,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      61,    61,    61,    62,    63,    63,    64,    65,    66,    66,
      66,    66,    67,    68,    68,    69,    70,    70,    70,    71,
      71,    71,    71,    72,    73,    73,    74,    76,    75,    75,
      77,    78,    79,    80,    80,    80,    81,    82,    83,    83,
      84,    85,    86,    87,    87,    87,    88,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    91,    92,    92,    93,
      94,    95,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   104,   104,   104,   105,
     106,   106,   106,   107,   107,   108,   109,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     1,     4,     0,     2,     0,     2,
       2,     2,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     6,     6,     5,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,    11,     0,
       0,     1,     2,     3,     1,     0,     3,     0,     2,     0,
       5,     0,     2,     2,     2,     0,     0,     2,     1,     1,
       1,     2,     2,     3,     2,     2,     2,     5,     0,     0,
       2,     0,     1,     3,     1,     3,     1,     2,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     3,     1,     1,     1,     4,
       3,     1,     0,     8,     6,     6,    10,     2
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
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "yacc.y" /* yacc.c:1646  */
    { debug_log("program node {");              depth++; }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "yacc.y" /* yacc.c:1646  */
    { debug_log("program name"); }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("program body }");
            depth--;
        }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 72 "yacc.y" /* yacc.c:1646  */
    { debug_log("program body {");                  depth++; }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 76 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("variable }");
            depth--;
        }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 82 "yacc.y" /* yacc.c:1646  */
    { debug_log("variable node {");            depth++; }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 92 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("variable declaration");
        }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 101 "yacc.y" /* yacc.c:1646  */
    { debug_log("variable name"); }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 107 "yacc.y" /* yacc.c:1646  */
    { debug_log("integer type"); }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 108 "yacc.y" /* yacc.c:1646  */
    { debug_log("real type"); }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "yacc.y" /* yacc.c:1646  */
    { debug_log("string type"); }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 110 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean type"); }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("array declaration");
        }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "yacc.y" /* yacc.c:1646  */
    { debug_log("array dimensional"); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 122 "yacc.y" /* yacc.c:1646  */
    { debug_log("array dimensional"); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 126 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("const declaration");
        }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 136 "yacc.y" /* yacc.c:1646  */
    { debug_log("integer const"); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 137 "yacc.y" /* yacc.c:1646  */
    { debug_log("integer const"); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 138 "yacc.y" /* yacc.c:1646  */
    { debug_log("float const"); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 139 "yacc.y" /* yacc.c:1646  */
    { debug_log("float const"); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 142 "yacc.y" /* yacc.c:1646  */
    { debug_log("string const"); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 145 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean const"); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 146 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean const"); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 151 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("function }");
            depth--;
        }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 159 "yacc.y" /* yacc.c:1646  */
    { debug_log("function declaration"); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 163 "yacc.y" /* yacc.c:1646  */
    { debug_log("function node {");                        depth++; }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 166 "yacc.y" /* yacc.c:1646  */
    { debug_log("function name"); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 170 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("argument }");                                    depth--;
        }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 181 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("argument declaration");
        }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 186 "yacc.y" /* yacc.c:1646  */
    { debug_log("argument node {");                        depth++; }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 190 "yacc.y" /* yacc.c:1646  */
    { debug_log("no return value"); }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 195 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("compound statement }");
            depth--;
        }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 201 "yacc.y" /* yacc.c:1646  */
    { debug_log("compound statement node {");    depth++; }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 205 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("statement }");
            depth--;
        }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 216 "yacc.y" /* yacc.c:1646  */
    { debug_log("statement node {");                      depth++; }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 228 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("simple statement");
        }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 232 "yacc.y" /* yacc.c:1646  */
    { debug_log("simple print"); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 234 "yacc.y" /* yacc.c:1646  */
    { debug_log("simple read"); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 241 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("index }");
            depth--;
        }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 249 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("index node {");
            depth++;
        }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 256 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("expression }");                                  depth--;
        }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 261 "yacc.y" /* yacc.c:1646  */
    { debug_log("expression node {");                    depth++; }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 267 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt or"); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 271 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt and"); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 275 "yacc.y" /* yacc.c:1646  */
    { debug_log("boolean opt not"); }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 279 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion less"); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 280 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion less eq"); }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 281 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion greater"); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 282 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion greater eq"); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 283 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion eq"); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 284 "yacc.y" /* yacc.c:1646  */
    { debug_log("comparsion no eq"); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 289 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator add"); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 290 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator del"); }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 294 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator mul"); }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 295 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator div"); }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 296 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator mod"); }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 300 "yacc.y" /* yacc.c:1646  */
    { debug_log("operator get negative"); }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 307 "yacc.y" /* yacc.c:1646  */
    { debug_log("variable reference"); }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 312 "yacc.y" /* yacc.c:1646  */
    {
            debug_log("function invocation");
        }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1888 "y.tab.c" /* yacc.c:1646  */
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
#line 335 "yacc.y" /* yacc.c:1906  */


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

