%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "err_check.h"
#include "main.h"
#include "stack.h"
#include "symbol.h"
#include "type.h"

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

extern struct stack *s;        /* declared in main.c */

int depth = 0;
int is_progcompound = 0;

int yylex (void);
int yyerror( char *msg );

%}

%union {
    int    value;
    double dvalue;
    char*  text;
    struct {
        union {
            int value;
            double dvalue;
            const char *text;
        };
        const char *method;
    } const_type;
    struct {
        struct symbol *symbol;
        int ref_dim;
    } var_ref;
    struct {
        struct type *type;
        int ref_dim;
    } exp;
    int n_ref;
}

%token COMMA SEMICOLON COLON Lparenthese Rparenthese Lbracket Rbracket

%token ASSIGNMENT
%token OP_ADD   OP_DEL  OP_MUL  OP_DIV  OP_MOD
%token OP_LT    OP_LE   OP_GT   OP_GE   OP_EQ   OP_NE
%token TF_AND   TF_OR   TF_NOT

%token KWarray KWbegin KWboolean KWdef KWdo KWelse KWend KWfalse
%token KWfor KWinteger KWif KWof KWprint KWread KWreal KWstring
%token KWthen KWto KWtrue KWreturn KWvar KWwhile

%token <value>  OCTAL
%token <value>  INTEGER
%token <dvalue> FLOAT
%token <dvalue> SCIENTIFIC
%token <text>   STRING
%token <text>   IDENT

%type <value>   int_const
%type <text>    program_name var_name func_name

%type <const_type> const_group number_const string_const bool_const

%type <exp>    expression_node expression expr_order1 expr_order2 expr_order3
%type <exp>    expr_order4 expr_order5 expr_order6 expr_order7 expr_order8

%type <var_ref>     var_reference
%type <type>        func_invocation
%type <n_ref>       ref_list

%start program

%%

 /* name part */

program_name : IDENT
        {
            $$ = $1;
            debug_log("program name");
        }
        ;

var_name     : IDENT
        {
            $$ = $1;
            debug_log("variable name");
        }
        ;

func_name    : IDENT
        {
            $$ = $1;
            debug_log("function name");
        }
        ;


 /* constant data part */

int_const    : OCTAL
             { $$ = $1; }
             | INTEGER
             { $$ = $1; }
        ;

number_const : int_const
             { $$.method = type_inte; $$.value = $1;  debug_log("number const"); }
             | FLOAT
             { $$.method = type_real; $$.dvalue = $1; debug_log("float const"); }
             | SCIENTIFIC
             { $$.method = type_real; $$.dvalue = $1; debug_log("float const"); }
        ;

string_const : STRING
             { $$.method = type_stri; $$.text = $1; debug_log("string const"); }
        ;

bool_const   : KWtrue
             { $$.method = type_bool; $$.value = 1; debug_log("boolean const"); }
             | KWfalse
             { $$.method = type_bool; $$.value = 0; debug_log("boolean const"); }
        ;

const_group  : number_const
             { $$ = $1; }
             | string_const
             { $$ = $1; }
             | bool_const
             { $$ = $1; }
        ;


 /* type part */

scalar_type  : KWinteger
        {
            add_type(type_inte);

            debug_log("integer type");
        }
             | KWreal
        {
            add_type(type_real);

            debug_log("real type");
        }
             | KWstring
        {
            add_type(type_stri);

            debug_log("string type");
        }
             | KWboolean
        {
            add_type(type_bool);

            debug_log("boolean type");
        }
        ;

var_type     :
             { construct_type(); }
               scalar_type
             { supply_type(); }
             | 
             { construct_type(); }
             ddim_list scalar_type
             { supply_type(); }
        ;

func_ret_type : COLON var_type /* scalar_type */
              |
        {
            construct_type();
            add_type(type_void);
            supply_type();

            debug_log("no return value");
        }
        ;


 /* list part */

vacd_list    : vacd_list define_var
             | vacd_list define_const
             |
        ;

var_list     : var_list COMMA var_name
             { push_ident($3); }
             | var_name
             { push_ident($1); }
        ;

ddim_list    : ddim_list KWarray int_const KWto int_const KWof
        {
            add_dim($5, $3);

            debug_log("array dimensional");
        }
             | KWarray int_const KWto int_const KWof
        {
            add_dim($4, $2);

            debug_log("array dimensional");
        }
        ;

dfunc_list   : dfunc_list define_func
             |
        ;

arg_list     : _non_empty_arg_list
             |
        ;

_non_empty_arg_list : _non_empty_arg_list SEMICOLON define_arg
                    | define_arg
        ;

state_list   : state_list define_state
             |
        ;

expr_list    : _non_empty_expr_list
             |
        ;

_non_empty_expr_list : _non_empty_expr_list COMMA expression_node
                     | expression_node
        ;

ref_list     : ref_list Lbracket expression_node Rbracket
             { debug_log("variable reference argument");        $$ = $1+1;}
             | Lbracket expression_node Rbracket
             { debug_log("variable reference argument");        $$ = 1; }
        ;


 /* expression part */

expression   : expr_order8
        { $$ = $1; }
        ;

expr_order8  : expr_order8 TF_OR expr_order7     { debug_log("boolean opt or"); }
             | expr_order7
             { $$ = $1; }
        ;

expr_order7  : expr_order7 TF_AND expr_order6    { debug_log("boolean opt and"); }
             | expr_order6
             { $$ = $1; }
        ;

expr_order6  : TF_NOT expr_order6                { debug_log("boolean opt not"); }
             | expr_order5
             { $$ = $1; }
        ;

expr_order5  : expr_order4 OP_LT expr_order5     { debug_log("comparsion less"); }
             | expr_order4 OP_LE expr_order5     { debug_log("comparsion less eq"); }
             | expr_order4 OP_GT expr_order5     { debug_log("comparsion greater"); }
             | expr_order4 OP_GE expr_order5     { debug_log("comparsion greater eq"); }
             | expr_order4 OP_EQ expr_order5     { debug_log("comparsion eq"); }
             | expr_order4 OP_NE expr_order5     { debug_log("comparsion no eq"); }
             | expr_order4
             { $$ = $1; }
        ;

expr_order4  : expr_order4 OP_ADD expr_order3    { debug_log("operator add"); }
             | expr_order4 OP_DEL expr_order3    { debug_log("operator del"); }
             | expr_order3
             { $$ = $1; }
        ;

expr_order3  : expr_order3 OP_MUL expr_order2    { debug_log("operator mul"); }
             | expr_order3 OP_DIV expr_order2    { debug_log("operator div"); }
             | expr_order3 OP_MOD expr_order2    { debug_log("operator mod"); }
             | expr_order2
             { $$ = $1; }
        ;

expr_order2  : OP_DEL expr_order2
        {
            debug_log("operator get negative");
        }
             | expr_order1
             { $$ = $1; }
        ;

expr_order1  : Lparenthese expression Rparenthese
             { $$ = $2; }
             | func_invocation
        {
            $$.type = $1;
            $$.ref_dim = 0;         //FIXME: function invocation not complete.
        }
             | var_reference
        {
            $$.type = $1.symbol->get_typeinst($1.symbol);
            $$.ref_dim = $1.ref_dim;
        }
             | const_group
        { 
            $$.type = type_create();
            $$.type->add_type($$.type, $1.method);
            $$.ref_dim = 0;
        }
        ;


 /* variable and constant declartion part */

define_var   : KWvar var_list COLON var_type SEMICOLON
        {
            supply_kind(kind_vari); /* Can not early, is variable or constant? */
            debug_log("variable declaration");
        }
        ;

define_const : KWvar var_list COLON const_group SEMICOLON
        {
            supply_kind(kind_cons);
            construct_type();
            add_type($4.method);
            supply_type();
            construct_attr();
            add_cons_attr(&($4.value), $4.method, 0);
            supply_cons_attr();
            debug_log("const declaration");
        }
             | KWvar var_list COLON OP_DEL number_const SEMICOLON
        {
            supply_kind(kind_cons);
            construct_type();
            add_type($5.method);
            supply_type();
            construct_attr();
            add_cons_attr(&($5.value), $5.method, 1);
            supply_cons_attr();
            debug_log("const declaration");
        }
        ;


 /* function declartion part */

define_func  : func_name
        {
            push_ident($1);
            supply_kind(kind_func);
            construct_attr();
            next_level();
        }
               Lparenthese arg_list Rparenthese
        {
            supply_func_attr();
        }
               func_ret_type SEMICOLON
               KWbegin var_and_const_declar
               statement_declar KWend
        {
            dump_symbol();
            exit_level();

            debug_log("function declaration");
        }
                _define_func_end
        ;

_define_func_end : KWend func_name
        {
            is_error |= check_funcname(s, $2);
        }
        ;

define_arg   : var_list
             { supply_kind(kind_para); /* Must supply parameter kind ASAP. */ }
               COLON var_type
             { debug_log("argument declaration"); }
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

            check_lhs($1.symbol, $1.ref_dim);
        }
                | KWprint expression_node
                { debug_log("simple print"); }
                | KWread var_reference
                { debug_log("simple read"); }
        ;

var_reference   : var_name
        {
            debug_log("variable reference");

            $$.symbol = find_variable($1);
            $$.ref_dim = 0;
            is_error |= check_declared($$.symbol, $1);
            is_error |= check_arrayref($$.symbol, $$.ref_dim);
            if($$.symbol == 0)
            {
                $$.symbol = default_symbol;
                fprintf(stdout, "Symbol replace with default symbol and type <integer>\n");
            }
        }
                | var_name ref_list
        {
            debug_log("array reference");

            $$.symbol = find_variable($1);
            $$.ref_dim = $2;
            is_error |= check_declared($$.symbol, $1);
            is_error |= check_arrayref($$.symbol, $$.ref_dim);
            if($$.symbol == 0)
            {
                $$.symbol = default_symbol;
                $$.ref_dim = 0;
                fprintf(stdout, "Symbol replace with default symbol and type <integer>\n");
            }
        }
        ;

func_invocation : func_name Lparenthese expr_list Rparenthese
        {
            debug_log("function invocation");
        }
        ;

ret__statement : KWreturn expression_node
        {
            debug_log("return");

            is_error |= check_rettype(s, $2);  // FIXME: exp_node.type not construct.
        }
        ;


 /* Let expression be a node may not necessary */

expression_node : expression_start expression
        {
            debug_log("expression }");
            depth--;

            $$ = $2;    // FIXME: temp type node.
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

for__statement : for_start KWfor var_name ASSIGNMENT int_const KWto int_const KWdo
        {
            next_level();
            push_ident($3);
            supply_kind(kind_forv);
            construct_type();
            add_type(type_inte);
            supply_type();
        }
                 statement_declar KWend KWdo
        {
            dump_symbol();
            exit_level();

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
            dump_symbol();
            exit_level();

            debug_log("compound statement }");
            depth--;
        }
        ;

compound_statement_start :
        {
            next_level();

            debug_log("compound statement node {");
            depth++;
        }
        ;


 /** program (main node)
  *
  *  this node --> variable and constant declartion node
  *            --> function declartion node
  *            --> compound statement node
  */

program      : prog_start program_name
        {
            push_ident($2);
            supply_kind(kind_prog);
            construct_type();
            add_type(type_void);
            supply_type();

            is_error |= check_progname(prog_name, $2);
        }
               SEMICOLON program_body KWend program_name
        {
            dump_symbol();

            debug_log("program }");
            depth--;

            is_error |= check_progname(prog_name, $7);
        }
        ;

prog_start   :
        {

            debug_log("program node {");
            depth++;
        }
        ;

program_body : program_body_start var_and_const_declar function_declar
        { is_progcompound = 1; }
        compound_statement
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

