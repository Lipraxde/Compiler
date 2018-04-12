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

%%

program      : program_start program_name SEMICOLON program_body KWend IDENT
        {
            debug_log("program }");
            depth--;
        }
        ;

program_start :         { debug_log("program node {");              depth++; }
        ;

program_name : IDENT    { debug_log("program name"); }
        ;

program_body : program_body_start var_and_const_declar function compound_statement
        {
            debug_log("program body }");
            depth--;
        }
        ;

program_body_start :    { debug_log("program body {");                  depth++; }

 /* declaration variable and constant part */
var_and_const_declar : var_and_const_declar_start define_var_and_const
        {
            debug_log("variable }");
            depth--;
        }
        ;

var_and_const_declar_start : { debug_log("variable node {");            depth++; }
        ;

define_var_and_const : define_variable define_var_and_const
                     | define_array define_var_and_const
                     | define_const define_var_and_const
                     |
        ;

define_variable  : KWvar var_list COLON var_type SEMICOLON
        {
            debug_log("variable declaration");
        }
        ;

var_list         : variable_name COMMA var_list
                 | variable_name
        ;

variable_name    : IDENT        { debug_log("variable name"); }
        ;

var_type         : scalar_type
        ;

scalar_type      : KWinteger    { debug_log("integer type"); }
                 | KWreal       { debug_log("real type"); }
                 | KWstring     { debug_log("string type"); }
                 | KWboolean    { debug_log("boolean type"); }
        ;

define_array     : KWvar var_list COLON define_mdarray var_type SEMICOLON
        {
            debug_log("array declaration");
        }
        ;

define_mdarray   : KWarray INTEGER KWto INTEGER KWof define_mdarray
                   { debug_log("array dimensional"); }
                 | KWarray INTEGER KWto INTEGER KWof
                   { debug_log("array dimensional"); }
        ;

define_const     : KWvar var_list COLON literal_const SEMICOLON
        {
            debug_log("const declaration");
        }
        ;

literal_const    : number_const
                 | string_const
                 | boolean_const
        ;

number_const     : OCTAL        { debug_log("integer const"); }
                 | INTEGER      { debug_log("integer const"); }
                 | FLOAT        { debug_log("float const"); }
                 | SCIENTIFIC   { debug_log("float const"); }
        ;

string_const     : STRING       { debug_log("string const"); }
        ;

boolean_const    : KWtrue       { debug_log("boolean const"); }
                 | KWfalse      { debug_log("boolean const"); }
        ;

 /* declaration function part */
function      : function_start define_function
        {
            debug_log("function }");
            depth--;
        }
        ;

define_function : function_name Lparenthese argument_list Rparenthese func_ret_type
                  SEMICOLON compound_statement KWend IDENT
                { debug_log("function declaration"); }define_function
                |
        ;

function_start : { debug_log("function node {");                        depth++; }
        ;

function_name : IDENT { debug_log("function name"); }
        ;

argument_list : argument_start define_argument
        {
            debug_log("argument }");                                    depth--;
        }
        ;

define_argument : argument SEMICOLON define_argument
                | argument
                |
        ;

argument      : var_list COLON var_type
        {
            debug_log("argument declaration");
        }
        ;

argument_start : { debug_log("argument node {");                        depth++; }
        ;

func_ret_type : COLON scalar_type
              | { debug_log("no return value"); }
        ;

 /* compound statement part */
compound_statement : compound_statement_start KWbegin var_and_const_declar statement_list KWend
        {
            debug_log("compound statement }");
            depth--;
        }
        ;

compound_statement_start : { debug_log("compound statement node {");    depth++; }
        ;

statement_list  : statement_start define_statement
        {
            debug_log("statement }");
            depth--;
        }
        ;

define_statement : statement_group define_statement
                 | compound_statement define_statement
                 |
        ;

statement_start : { debug_log("statement node {");                      depth++; }
        ;

statement_group : simp_statement  SEMICOLON
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

var_reference   : variable_name reference_list
        ;

reference_list  : reference_start Lbracket expression_node Rbracket reference_list
        {
            debug_log("index }");
            depth--;
        }
                |
        ;

reference_start :
        {
            debug_log("index node {");
            depth++;
        }
        ;

expression_node : expression_start expression
        {
            debug_log("expression }");                                  depth--;
        }
        ;

expression_start : { debug_log("expression node {");                    depth++; }
        ;

expression      : expr_order8
        ;

expr_order8     : expr_order8 TF_OR expr_order7     { debug_log("boolean opt or"); }
                | expr_order7
        ;

expr_order7     : expr_order7 TF_AND expr_order6    { debug_log("boolean opt and"); }
                | expr_order6
        ;

expr_order6     : TF_NOT expr_order5                { debug_log("boolean opt not"); }
                | expr_order5
        ;

expr_order5     : expr_order4 OP_LT expr_order5     { debug_log("comparsion less"); }
                | expr_order4 OP_LE expr_order5     { debug_log("comparsion less eq"); }
                | expr_order4 OP_GT expr_order5     { debug_log("comparsion greater"); }
                | expr_order4 OP_GE expr_order5     { debug_log("comparsion greater eq"); }
                | expr_order4 OP_EQ expr_order5     { debug_log("comparsion eq"); }
                | expr_order4 OP_NE expr_order5     { debug_log("comparsion no eq"); }
                | expr_order4
        ;


expr_order4     : expr_order4 OP_ADD expr_order3    { debug_log("operator add"); }
                | expr_order4 OP_DEL expr_order3    { debug_log("operator del"); }
                | expr_order3
        ;

expr_order3     : expr_order3 OP_MUL expr_order2    { debug_log("operator mul"); }
                | expr_order3 OP_DIV expr_order2    { debug_log("operator div"); }
                | expr_order3 OP_MOD expr_order2    { debug_log("operator mod"); }
                | expr_order2
        ;

expr_order2     : OP_DEL expr_order1                { debug_log("operator get negative"); }
                | expr_order1
        ;

expr_order1     : Lparenthese expression Rparenthese
                | func_invocation 
                | var_reference
                { debug_log("variable reference"); }
                | literal_const
        ;

func_invocation : function_name Lparenthese expression_list Rparenthese
        {
            debug_log("function invocation");
        }
        ;

expression_list : expression_node COMMA expression_list
                | expression_node
                |
        ;

cond_statement : KWif expression_node KWthen define_statement KWelse define_statement KWend KWif
               | KWif expression_node KWthen define_statement KWend KWif
        ;

whil_statement : KWwhile expression_node KWdo define_statement KWend KWdo
        ;

for__statement : KWfor IDENT ASSIGNMENT number_const KWto number_const KWdo define_statement KWend KWdo
        ;

ret__statement : KWreturn expression_node
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

