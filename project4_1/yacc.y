%{
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

%}

%union {
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
}

%token COMMA SEMICOLON COLON Lparenthese Rparenthese Lbracket Rbracket

%token ASSIGNMENT
%token OP_ADD   OP_DEL  OP_MUL  OP_DIV  OP_MOD
%token OP_LT    OP_LE   OP_GT   OP_GE   OP_EQ   OP_NE
%token TF_AND   TF_OR   TF_NOT

%token KWarray KWbegin KWboolean KWdef KWdo KWelse KWend KWfalse
%token KWfor KWinteger KWif KWof KWprint KWread KWreal KWstring
%token KWthen KWto KWtrue KWreturn KWvar KWwhile

%token <int_val>    OCTAL
%token <int_val>    INTEGER
%token <real_val>   FLOAT
%token <real_val>   SCIENTIFIC
%token <text_val>   STRING
%token <text_val>   IDENT

%type  <text_val>   program_name var_name func_name

%type  <int_val>    int_const

%type <cn>  number_const    string_const bool_const     const_group

%type <tn>  scalar_type     var_type                    func_ret_type

%type <dl>  ddim_list
%type <en>  ref_list

%type <rn>  var_reference
%type <en>  expression_node expr_list       _non_empty_expr_list
%type <en>  expression      expr_order8     expr_order7
%type <en>  expr_order6     expr_order5     expr_order4
%type <en>  expr_order3     expr_order2     expr_order1

%type <simp> simp_statement
%type <cond> cond_statement
%type <whil> whil_statement
%type <for_> for__statement
%type <ret_> ret__statement
%type <finv> func_invocation
%type <sn>  state_list      define_state                statement_declar

%type <vn>  vacd_list       var_list arg_list           _non_empty_arg_list
%type <vn>  define_var      define_const define_arg     var_and_const_declar

%type <fn>  dfunc_list      define_func                 function_declar

%type <cpn> compound_statement

%type <pn>  program

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
        {
            $$ = calloc(1, sizeof(struct const_node));
            $$->int_val = $1;
            $$->type = INTE_TYPE;
            $$->loc = @$;

            debug_log("number const");
        }
             | FLOAT
        {
            $$ = calloc(1, sizeof(struct const_node));
            $$->real_val = $1;
            $$->type = REAL_TYPE;
            $$->loc = @$;

            debug_log("float const");
        }
             | SCIENTIFIC
        {
            $$ = calloc(1, sizeof(struct const_node));
            $$->real_val = $1;
            $$->type = REAL_TYPE;
            $$->loc = @$;

            debug_log("float const");
        }
        ;

string_const : STRING
        {
            $$ = calloc(1, sizeof(struct const_node));
            $$->text_val = $1;
            $$->type = TEXT_TYPE;
            $$->loc = @$;

            debug_log("string const");
        }
        ;

bool_const   : KWtrue
        {
            $$ = calloc(1, sizeof(struct const_node));
            $$->bool_val = true;
            $$->type = BOOL_TYPE;
            $$->loc = @$;

            debug_log("boolean const");
        }
             | KWfalse
        {
            $$ = calloc(1, sizeof(struct const_node));
            $$->bool_val = false;
            $$->type = BOOL_TYPE;
            $$->loc = @$;

            debug_log("boolean const");
        }
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
            $$ = calloc(1, sizeof(struct type_node));
            $$->type = INTE_TYPE;
            $$->loc = @$;

            debug_log("integer type");
        }
             | KWreal
        {
            $$ = calloc(1, sizeof(struct type_node));
            $$->type = REAL_TYPE;
            $$->loc = @$;

            debug_log("real type");
        }
             | KWstring
        {
            $$ = calloc(1, sizeof(struct type_node));
            $$->type = TEXT_TYPE;
            $$->loc = @$;

            debug_log("string type");
        }
             | KWboolean
        {
            $$ = calloc(1, sizeof(struct type_node));
            $$->type = BOOL_TYPE;
            $$->loc = @$;

            debug_log("boolean type");
        }
        ;

var_type     : scalar_type
             { $$ = $1; }
             | ddim_list scalar_type
             { $$ = $2; $$->dim = $1; }
        ;

func_ret_type : COLON var_type /* scalar_type */
              { $$ = $2; }
              |
        {
            $$ = calloc(1, sizeof(struct type_node));
            $$->type = VOID_TYPE;
            $$->loc = @$;

            debug_log("no return value");
        }
        ;


 /* list part */

vacd_list    : vacd_list define_var
        {
            if($1 != 0)
            {
                $$ = $1;
                struct variable_node *tail = $$;
                while(tail->sibling != 0)
                    tail = tail->sibling;
                tail->sibling = $2;
            }
            else
                $$ = $2;
        }
             | vacd_list define_const
        {
            if($1 != 0)
            {
                $$ = $1;
                struct variable_node *tail = $$;
                while(tail->sibling != 0)
                    tail = tail->sibling;
                tail->sibling = $2;
            }
            else
                $$ = $2;
        }
             |
             { $$ = 0; }
        ;

var_list     : var_list COMMA var_name
        {
            $$ = $1;
            struct variable_node *tail = $$;
            while(tail->sibling != 0)
                tail = tail->sibling;
            tail->sibling = calloc(1, sizeof(struct variable_node));
            tail->sibling->name = $3;
        }
             | var_name
        {
            $$ = calloc(1, sizeof(struct variable_node));
            $$->name = $1;
            $$->loc = @1;
        }
        ;

ddim_list    : ddim_list KWarray int_const KWto int_const KWof
        {
            $$ = $1;
            struct dim_list *tail = $$;
            while(tail->next != 0)
                tail = tail->next;
            tail->next = calloc(1, sizeof(struct dim_list));
            tail->next->lower = $3;
            tail->next->upper = $5;

            debug_log("array dimensional");
        }
             | KWarray int_const KWto int_const KWof
        {
            $$ = calloc(1, sizeof(struct dim_list));
            $$->lower = $2;
            $$->upper = $4;

            debug_log("array dimensional");
        }
        ;

dfunc_list   : dfunc_list define_func
        {
            if($1 != 0)
            {
                $$ = $1;
                struct function_node *tail = $$;
                while(tail->sibling != 0)
                    tail = tail->sibling;
                tail->sibling = $2;
            }
            else
                $$ = $2;
        }
             |
            { $$ = 0; }
        ;

arg_list     : _non_empty_arg_list
             { $$ = $1; }
             |
             { $$ = 0; }
        ;

_non_empty_arg_list : _non_empty_arg_list SEMICOLON define_arg
        {
            $$ = $1;
            struct variable_node *tail = $$;
            while(tail->sibling != 0)
                tail = tail->sibling;
            tail->sibling = $3;
        }
                    | define_arg
                    { $$ = $1; }
        ;

state_list   : state_list define_state
        {
            if($1 != 0)
            {
                $$ = $1;
                struct statment_node *tail = $$;
                while(tail->sibling != 0)
                    tail = tail->sibling;
                tail->sibling = $2;
            }
            else
                $$ = $2;
        }
             |
             { $$ = 0; }
        ;

expr_list    : _non_empty_expr_list
             { $$ = $1; }
             |
             { $$ = 0; }
        ;

_non_empty_expr_list : _non_empty_expr_list COMMA expression_node
        {
            $$ = $1;
            struct expr_node *tail = $$;
            while(tail->sibling != 0)
                tail = tail->sibling;
            tail->sibling = $3;
        }
                     | expression_node
                     { $$ = $1; }
        ;

ref_list     : ref_list Lbracket expression_node Rbracket
        {
            $$ = $1;
            struct expr_node *tail = $$;
            while(tail->sibling != 0)
                tail = tail->sibling;
            tail->sibling = $3;

            debug_log("variable reference argument");
        }
             | Lbracket expression_node Rbracket
        {
            $$ = $2;

            debug_log("variable reference argument");
        }
        ;


 /* expression part */

expression   : expr_order8
             { $$ = $1; }
        ;

expr_order8  : expr_order8 TF_OR expr_order7     { debug_log("boolean opt or"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = bool_or;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order7
             { $$ = $1; }
        ;

expr_order7  : expr_order7 TF_AND expr_order6    { debug_log("boolean opt and"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = bool_and;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order6
             { $$ = $1; }
        ;

expr_order6  : TF_NOT expr_order6                { debug_log("boolean opt not"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->rsite = $2;
            $$->opt = bool_not;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order5
             { $$ = $1; }
        ;

expr_order5  : expr_order4 OP_LT expr_order5     { debug_log("comparsion less"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = cmp_less;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order4 OP_LE expr_order5     { debug_log("comparsion less eq"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = cmp_leq;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order4 OP_GT expr_order5     { debug_log("comparsion greater"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = cmp_gt;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order4 OP_GE expr_order5     { debug_log("comparsion greater eq"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = cmp_geq;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order4 OP_EQ expr_order5     { debug_log("comparsion eq"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = cmp_eq;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order4 OP_NE expr_order5     { debug_log("comparsion no eq"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = cmp_neq;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = BOOL_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order4
             { $$ = $1; }
        ;

expr_order4  : expr_order4 OP_ADD expr_order3    { debug_log("operator add"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = opt_add;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = REAL_TYPE;     // type coercion
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order4 OP_DEL expr_order3    { debug_log("operator del"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = opt_del;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = REAL_TYPE;     // type coercion
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order3
             { $$ = $1; }
        ;

expr_order3  : expr_order3 OP_MUL expr_order2    { debug_log("operator mul"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = opt_mul;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = REAL_TYPE;     // type coercion
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order3 OP_DIV expr_order2    { debug_log("operator div"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = opt_div;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = REAL_TYPE;     // type coercion
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order3 OP_MOD expr_order2    { debug_log("operator mod"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->lsite = $1;
            $$->rsite = $3;
            $$->opt = opt_mod;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = INTE_TYPE;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order2
             { $$ = $1; }
        ;

expr_order2  : OP_DEL expr_order2                { debug_log("operator get negative"); }
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->rsite = $2;
            $$->opt = opt_nega;
            $$->type = calloc(1, sizeof(struct type_node));
            $$->type->type = $2->type->type;
            $$->mode = EXPRESSION;
            $$->loc = @$;
        }
             | expr_order1
             { $$ = $1; }
        ;

expr_order1  : Lparenthese expression Rparenthese
             { $$ = $2; }
             | func_invocation
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->type = calloc(1, sizeof(struct type_node));
            $$->finv = $1;
            $$->mode = FUNCT_INVO;
            $$->loc = @$;
        }
             | var_reference
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->type = calloc(1, sizeof(struct type_node));
            $$->vref = $1;
            $$->mode = VARIA_REFE;
            $$->loc = @$;
        }
             | const_group
        {
            $$ = calloc(1, sizeof(struct expr_node));
            $$->type = calloc(1, sizeof(struct type_node));
            $$->cont = $1;
            $$->mode = CONST_DATA;
            $$->loc = @$;
        }
        ;


 /* variable and constant declartion part */

define_var   : KWvar var_list COLON var_type SEMICOLON
        {
            $$ = $2;
            struct variable_node *temp = $$;
            while(temp != 0)
            {
                temp->type = $4;
                temp = temp->sibling;
            }

            debug_log("variable declaration");
        }
        ;

define_const : KWvar var_list COLON const_group SEMICOLON
        {
            $$ = $2;
            struct variable_node *temp = $$;
            while(temp != 0)
            {
                temp->const_val = $4;
                temp = temp->sibling;
            }

            debug_log("const declaration");
        }
             | KWvar var_list COLON OP_DEL number_const SEMICOLON
        {
            $$ = $2;
            struct variable_node *temp = $$;
            while(temp != 0)
            {
                if($5->type == INTE_TYPE)
                    $5->int_val = -$5->int_val;
                else /* REAL_TYPE */
                    $5->real_val = -$5->real_val;
                temp->const_val = $5;
                temp = temp->sibling;
            }

            debug_log("const declaration");
        }
        ;


 /* function declartion part */

define_func  : func_name Lparenthese arg_list Rparenthese
               func_ret_type SEMICOLON
               compound_statement /* KWbegin var_and_const_declar statement_declar KWend */
               KWend IDENT
        {
            $$ = calloc(1, sizeof(struct function_node));
            $$->name = $1;
            $$->arg = $3;
            $$->ret_type = $5;
            $$->comp = $7;
            $$->loc = @1;

            debug_log("function declaration");
        }
        ;

define_arg   : var_list COLON var_type
        {
            $$ = $1;
            struct variable_node *temp = $$;
            while(temp != 0)
            {
                temp->type = $3;
                temp = temp->sibling;
            }

            debug_log("argument declaration");
        }
        ;


 /* compound statement part */

define_state : compound_statement
        {
            $$ = calloc(1, sizeof(struct statment_node));
            $$->comp = $1;
            $$->mode = COMP_STAT;
            $$->loc = @$;
        }
             | simp_statement  SEMICOLON
        {
            $$ = calloc(1, sizeof(struct statment_node));
            $$->simp = $1;
            $$->mode = SIMP_STAT;
            $$->loc = @$;
        }
             | cond_statement
        {
            $$ = calloc(1, sizeof(struct statment_node));
            $$->cond = $1;
            $$->mode = COND_STAT;
            $$->loc = @$;
        }
             | whil_statement
        {
            $$ = calloc(1, sizeof(struct statment_node));
            $$->whil = $1;
            $$->mode = WHIL_STAT;
            $$->loc = @$;
        }
             | for__statement
        {
            $$ = calloc(1, sizeof(struct statment_node));
            $$->for_ = $1;
            $$->mode = FOR__STAT;
            $$->loc = @$;
        }
             | func_invocation SEMICOLON
        {
            $$ = calloc(1, sizeof(struct statment_node));
            $$->finv = $1;
            $$->mode = FINV_STAT;
            $$->loc = @$;
        }
             | ret__statement  SEMICOLON
        {
            $$ = calloc(1, sizeof(struct statment_node));
            $$->ret_ = $1;
            $$->mode = RET__STAT;
            $$->loc = @$;
        }
        ;

simp_statement  : var_reference ASSIGNMENT expression_node
        {
            $$ = calloc(1, sizeof(struct simp_node));
            $$->lhs = $1;
            $$->rhs = $3;
            $$->loc = @$;

            debug_log("simple statement");
        }
                | KWprint expression_node
        {
            $$ = calloc(1, sizeof(struct simp_node));
            $$->rhs = $2;
            $$->loc = @$;

            debug_log("simple print");
        }
                | KWread var_reference
        {
            $$ = calloc(1, sizeof(struct simp_node));
            $$->lhs = $2;
            $$->loc = @$;

            debug_log("simple read");
        }
        ;

var_reference   : var_name
        {
            $$ = calloc(1, sizeof(struct varirefe_node));
            $$->type = calloc(1, sizeof(struct type_node));
            $$->name = $1;
            $$->loc = @$;

            debug_log("variable reference");
        }
                | var_name ref_list
        {
            $$ = calloc(1, sizeof(struct varirefe_node));
            $$->type = calloc(1, sizeof(struct type_node));
            $$->name = $1;
            $$->ref = $2;
            $$->loc = @$;

            debug_log("variable reference");
        }
        ;

func_invocation : func_name Lparenthese expr_list Rparenthese
        {
            $$ = calloc(1, sizeof(struct finv_node));
            $$->name = $1;
            $$->exprs = $3;
            $$->ret_type = calloc(1, sizeof(struct type_node));
            $$->loc = @$;

            debug_log("function invocation");
        }
        ;

ret__statement : KWreturn expression_node
        {
            $$ = calloc(1, sizeof(struct ret__node));
            $$->expr = $2;
            $$->loc = @$;

            debug_log("return");
        }
        ;


 /* Let expression be a node may not necessary */

expression_node : expression_start expression
        {
            $$ = $2;
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
            $$ = calloc(1, sizeof(struct cond_node));
            $$->condition = $3;
            $$->tpath = $5;
            $$->fpath = $8;
            $$->loc = @$;

            debug_log("condition }");
            depth--;
        }
               | cond_start KWif expression_node KWthen statement_declar KWend KWif
        {
            $$ = calloc(1, sizeof(struct cond_node));
            $$->condition = $3;
            $$->tpath = $5;
            $$->loc = @$;

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
            $$ = calloc(1, sizeof(struct whil_node));
            $$->condition = $3;
            $$->stat = $5;
            $$->loc = @$;

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
                 statement_declar KWend KWdo
        {
            $$ = calloc(1, sizeof(struct for__node));
            $$->i = calloc(1, sizeof(struct variable_node));
            $$->i->name = $3;
            $$->i->type = calloc(1, sizeof(struct type_node));
            $$->i->type->type = INTE_TYPE;
            $$->start = $5;
            $$->end = $7;
            $$->stat = $9;
            $$->loc = @$;

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
            $$ = $2;
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
            $$ = $2;

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
            $$ = $2;

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
            $$ = calloc(1, sizeof(struct compound_node));
            $$->loc_var = $3;
            $$->stat = $4;
            $$->loc = @$;

            debug_log("compound statement }");
            depth--;
        }
        ;

compound_statement_start :
        {
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

program      : prog_start program_name SEMICOLON
               var_and_const_declar function_declar compound_statement
               KWend IDENT
        {
            $$ = calloc(1, sizeof(struct program_node));
            $$->name = $2;
            $$->end_name = $8;
            $$->vacd = $4;
            $$->func = $5;
            $$->comp = $6;
            $$->loc = @2;
            $$->end_loc = @8;
            ast = $$;
            debug_log("program }");
            depth--;
        }
        ;

prog_start   :
        {
            debug_log("program node {");
            depth++;
        }
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

