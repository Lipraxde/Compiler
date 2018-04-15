/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 25 "yacc.y" /* yacc.c:1909  */

    int    value;
    double dvalue;
    char*  text;

#line 164 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
