%{
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
%}

%union {
    int    value;
    double dvalue;
    char*  text;
}

%token COMMA SEMICOLON COLON Lparenthese Rparenthese Lbracket Rbracket

%token ASSIGNMENT
%token OP_ADD   OP_DEL  OP_MUL  OP_DIV  OP_MOD
%token OP_LT    OP_LE   OP_GT   OP_GE   OP_EQ   OP_NE
%token TF_AND   TF_OR   TF_NOT

%token KWarray KWbegin KWboolean KWdef KWdo KWelse KWend KWfalse
%token KWfor KWinteger KWif KWof KWprint KWread KWreal KWstring
%token KWthen KWto KWtrue KWreturn KWvar KWwhile

%token <value>  OCTAL;
%token <value>  INTEGER;
%token <dvalue> FLOAT;
%token <dvalue> SCIENTIFIC;
%token <text>   STRING;

%token IDENT

%start program

%%

 /* name part */

program_name : IDENT    { debug_log("program name"); }
        ;

var_name     : IDENT        { debug_log("variable name"); }
        ;

func_name    : IDENT { debug_log("function name"); }
        ;


 /* constant data part */

int_const    : OCTAL
             | INTEGER
        ;

number_const : int_const    { debug_log("number const"); }
             | FLOAT        { debug_log("float const"); }
             | SCIENTIFIC   { debug_log("float const"); }
        ;

string_const : STRING       { debug_log("string const"); }
        ;

bool_const   : KWtrue       { debug_log("boolean const"); }
             | KWfalse      { debug_log("boolean const"); }
        ;

const_group  : number_const
             | string_const
             | bool_const
        ;


 /* type part */

scalar_type  : KWinteger    { debug_log("integer type"); }
             | KWreal       { debug_log("real type"); }
             | KWstring     { debug_log("string type"); }
             | KWboolean    { debug_log("boolean type"); }
        ;

var_type     : scalar_type
             | ddim_list scalar_type
        ;

func_ret_type : COLON var_type /* scalar_type */
              |
              { debug_log("no return value"); }
        ;


 /* list part */

vacd_list    : define_var   vacd_list
             | define_const vacd_list
             |
        ;

var_list     : var_name COMMA var_list
             | var_name
        ;

ddim_list    : KWarray int_const KWto int_const KWof ddim_list
             { debug_log("array dimensional"); }
             | KWarray int_const KWto int_const KWof
             { debug_log("array dimensional"); }
        ;

dfunc_list   : define_func dfunc_list
             |
        ;

arg_list     : _non_empty_arg_list
             |
        ;

_non_empty_arg_list : define_arg SEMICOLON _non_empty_arg_list
                    | define_arg
        ;

state_list   : define_state state_list
             |
        ;

expr_list    : _non_empty_expr_list
             |
        ;

_non_empty_expr_list : expression_node COMMA _non_empty_expr_list
                     | expression_node
        ;

ref_list     : Lbracket expression_node Rbracket ref_list
             { debug_log("variable reference argument"); }
             | Lbracket expression_node Rbracket
             { debug_log("variable reference argument"); }
        ;


 /* expression part */

expression   : expr_order8
        ;

expr_order8  : expr_order8 TF_OR expr_order7     { debug_log("boolean opt or"); }
             | expr_order7
        ;

expr_order7  : expr_order7 TF_AND expr_order6    { debug_log("boolean opt and"); }
             | expr_order6
        ;

expr_order6  : TF_NOT expr_order5                { debug_log("boolean opt not"); }
             | expr_order5
        ;

expr_order5  : expr_order4 OP_LT expr_order5     { debug_log("comparsion less"); }
             | expr_order4 OP_LE expr_order5     { debug_log("comparsion less eq"); }
             | expr_order4 OP_GT expr_order5     { debug_log("comparsion greater"); }
             | expr_order4 OP_GE expr_order5     { debug_log("comparsion greater eq"); }
             | expr_order4 OP_EQ expr_order5     { debug_log("comparsion eq"); }
             | expr_order4 OP_NE expr_order5     { debug_log("comparsion no eq"); }
             | expr_order4
        ;

expr_order4  : expr_order4 OP_ADD expr_order3    { debug_log("operator add"); }
             | expr_order4 OP_DEL expr_order3    { debug_log("operator del"); }
             | expr_order3
        ;

expr_order3  : expr_order3 OP_MUL expr_order2    { debug_log("operator mul"); }
             | expr_order3 OP_DIV expr_order2    { debug_log("operator div"); }
             | expr_order3 OP_MOD expr_order2    { debug_log("operator mod"); }
             | expr_order2
        ;

expr_order2  : OP_DEL expr_order2                { debug_log("operator get negative"); }
             | expr_order1
        ;

expr_order1  : Lparenthese expression Rparenthese
             | func_invocation 
             | var_reference
             | const_group
        ;


 /* variable and constant declartion part */

define_var   : KWvar var_list COLON var_type SEMICOLON
        {
            debug_log("variable declaration");
        }
        ;

define_const : KWvar var_list COLON const_group SEMICOLON
        {
            debug_log("const declaration");
        }
             | KWvar var_list COLON OP_DEL number_const SEMICOLON
        {
            debug_log("const declaration");
        }
        ;


 /* function declartion part */

define_func  : func_name Lparenthese arg_list Rparenthese func_ret_type
               SEMICOLON compound_statement KWend IDENT
             { debug_log("function declaration"); }
        ;

define_arg   : var_list COLON var_type
        {
            debug_log("argument declaration");
        }
        ;


 /* compound statement part */

define_state : compound_statement
             | simp_statement  SEMICOLON
             | cond_statement
             | whil_statement
             | for__statement
             | ret__statement  SEMICOLON
             | func_invocation SEMICOLON
        ;

simp_statement  : var_reference ASSIGNMENT expression_node
        {
            debug_log("simple statement");
        }
                | KWprint expression_node
                { debug_log("simple print"); }
                | KWread var_reference
                { debug_log("simple read"); }
        ;

var_reference   : var_name
                { debug_log("variable reference"); }
                | var_name ref_list
                { debug_log("array reference"); }
        ;

func_invocation : func_name Lparenthese expr_list Rparenthese
        {
            debug_log("function invocation");
        }
        ;

ret__statement : KWreturn expression_node { debug_log("return"); }
        ;


 /* Let expression be a node may not necessary */

expression_node : expression_start expression
        {
            debug_log("expression }");                                  depth--;
        }
        ;

expression_start : { debug_log("expression node {");                    depth++; }
        ;


 /* statement part node start */

 /** condition statement
  *
  *  this node --> expression node
  *            --> statement declartion node
  *
  *  statement declartion list --- this node 
  */

cond_statement : cond_start KWif expression_node KWthen statement_declar
                 cond_midd KWelse statement_declar KWend KWif
        {
            debug_log("condition }");
            depth--;
        }
               | cond_start KWif expression_node KWthen statement_declar KWend KWif
        {
            debug_log("condition }");
            depth--;
        }
        ;

cond_start   : { debug_log("condition node {");                           depth++; }
        ;

cond_midd    : { debug_log("else part"); }
        ;


 /** while statement
  *
  *  this node --> expression node
  *            --> statement declartion node
  *
  *  statement declartion list --- this node
  */

whil_statement : while_start KWwhile expression_node KWdo statement_declar KWend KWdo
        {
            debug_log("while }");
            depth--;
        }
        ;

while_start  : { debug_log("while node {");                              depth++; }
        ;


 /** for statement
  *
  *  this node --> statement declartion node
  *
  *  statement declartion list --- this node
  */

for__statement : for_start KWfor IDENT ASSIGNMENT number_const KWto
                 number_const KWdo statement_declar KWend KWdo
        {
            debug_log("for }");
            depth--;
        }
        ;

for_start    : { debug_log("for node {");                                  depth++; }
        ;

 /* statement part node end */


 /** statement declartion
  *
  *  this node --- statement list
  *
  *  compound statement              -->
  *  condition statement (then/else) -->
  *  for statement                   -->
  *  while statement                 --> this node
  */

statement_declar : statement_start state_list
        {
            debug_log("statement }");
            depth--;
        }
        ;

statement_start : { debug_log("statement declartion node {");           depth++; }
        ;


 /** variable and constant declartion
  *
  *  this node --- variable and constant declartion list
  *
  *  program            -->
  *  compound statement --> this node
  */

var_and_const_declar : vacd_start vacd_list
        {
            debug_log("variable declartion  }");
            depth--;
        }
        ;

vacd_start   : { debug_log("variable declartion node {");               depth++; }
        ;


 /** function declartion
  *
  *  this node --- function declartion list
  *
  *  program   --> this node
  */

function_declar : dfunc_start dfunc_list
        {
            debug_log("function decalartion }");
            depth--;
        }
        ;

dfunc_start  : { debug_log("function decalartion node {");              depth++; }
        ;


 /** compound statement
  *
  *  this node --> variable and constant declartion node
  *            --> statement node
  *
  *  program              -->
  *  function declartion  ---
  *  statement declartion --- this node
  */

compound_statement : compound_statement_start KWbegin var_and_const_declar
                     statement_declar KWend
        {
            debug_log("compound statement }");
            depth--;
        }
        ;

compound_statement_start : { debug_log("compound statement node {");    depth++; }
        ;


 /** program (main node)
  *
  *  this node --> variable and constant declartion node
  *            --> function declartion node
  *            --> compound statement node
  */

program      : prog_start program_name SEMICOLON program_body KWend IDENT
        {
            debug_log("program }");
            depth--;
        }
        ;

prog_start   :         { debug_log("program node {");                  depth++; }
        ;

program_body : program_body_start var_and_const_declar function_declar compound_statement
        ;

program_body_start :
        ;

%%

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

