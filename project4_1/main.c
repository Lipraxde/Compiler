/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "main.h"

extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
extern int Opt_D;
extern struct program_node *ast;

#define STRUCT_PROG 1
#define STRUCT_VARI 2
#define STRUCT_FUNC 3

#define push_prog(pointer)  push_symbol(pointer, STRUCT_PROG)
#define push_vari(pointer)  push_symbol(pointer, STRUCT_VARI)
#define push_func(pointer)  push_symbol(pointer, STRUCT_FUNC)

struct symbol sym_table[200] = {0};
int sym_conut = 0;
int now_level = 0;
int in_progcomp = 0;

char prog_name[256];
char *prog_line[10000];
char tree_lead[1024];

void push_symbol(void *data, int whitch_struct)
{
    if(data == 0)   // Shoult not push null pointer
        return;

    for(int i=sym_conut-1; (i>=0)&&(now_level==sym_table[i].level); i--)
    {
        struct base_node *p1 = sym_table[i].data;
        struct base_node *p2 = data;

        if(check_redeclar(p1->name, p2->name, &p1->loc, &p2->loc))
            return;
    }

    if((whitch_struct == STRUCT_FUNC)&&
        (check_funcrettypeisscalar(((struct function_node *)data)->ret_type)))
        return;
        

    sym_table[sym_conut].data = data;
    sym_table[sym_conut].level = now_level;
    sym_table[sym_conut].whitch_struct = whitch_struct;

    sym_conut++;
}


// When exit_level(); will auto pop.
void pop_symbol(int level)
{
    while((sym_conut!=0)&&(sym_table[sym_conut-1].level>level))
        sym_conut--;
}


void next_level(void)
{
    if(now_level < INT_MAX)
        now_level++;
}


void exit_level(void)
{
    if(Opt_D)
    {
        printf("------------------------------\n");
        for(int i=0; i<sym_conut; i++)
        {
            struct base_node *p = sym_table[i].data;
            printf("%-10s level: %4d\n", p->name, sym_table[i].level);
        }
        printf("------------------------------\n");
    }

    if(now_level > 0)
        now_level--;

    pop_symbol(now_level);
}


void tree_print(int is_last, char *fmt, ...);
void add_tree_level(int is_last);
void del_tree_level(void);
void dump_scalar(enum scalar_type type, int is_last);
void dump_type_node(struct type_node *type, int is_last);
void dump_const_val(struct const_node *cont, int is_last);
void dump_vari_node(struct variable_node *head, int is_last);
void dump_varr_node(struct varirefe_node *varr, int is_last);
void dump_expr_node(struct expr_node *expr, int is_last);
void dump_simp_node(struct simp_node *simp, int is_last);
void dump_cond_node(struct cond_node *cond, int is_last);
void dump_whil_node(struct whil_node *whil, int is_last);
void dump_for__node(struct for__node *for_, int is_last);
void dump_finv_node(struct finv_node *finv, int is_last);
void dump_ret__node(struct ret__node *ret_, int is_last);
void dump_stat_node(struct statment_node *head, int is_last);
void dump_comp_node(struct compound_node *comp, int is_last);
void dump_func_node(struct function_node *head, int is_last);
void dump_ast(void);


#define DUMP_BEGIN(name, type, str_info)        \
void dump_##name##_node(struct type *p, int is_last)   \
{                                               \
    tree_print(is_last, str_info);              \
    add_tree_level(is_last);

#define DUMP_END        \
    del_tree_level();   \
}


void tree_print(int is_last, char *fmt, ...)
{
    va_list arg_ptr;

    if(is_last)
        printf("%s\\--", tree_lead);
    else
        printf("%s+--", tree_lead);
    va_start(arg_ptr, fmt);
    vprintf(fmt, arg_ptr);
    va_end(arg_ptr);
    printf("\n");
}


void add_tree_level(int is_last)
{
    if(is_last)
        strcat(tree_lead, "   ");
    else
        strcat(tree_lead, "|  ");
}


void del_tree_level(void)
{
    int i = strlen(tree_lead);
    tree_lead[i-3] = 0;
}


void dump_scalar(enum scalar_type type, int is_last)
{
    switch(type)
    {
        case VOID_TYPE:
            tree_print(is_last, "void");
            break;
        case INTE_TYPE:
            tree_print(is_last, "integer");
            break;
        case REAL_TYPE:
            tree_print(is_last, "real");
            break;
        case BOOL_TYPE:
            tree_print(is_last, "boolean");
            break;
        case TEXT_TYPE:
            tree_print(is_last, "string");
            break;
        default:
            tree_print(is_last, "unknow");
            break;
    }
}


void dump_type_node(struct type_node *type, int is_last)
{
    tree_print(is_last, "type");
    add_tree_level(is_last);
    
    dump_scalar(type->type, (type->dim==0)? 1:0);
    struct dim_list *temp = type->dim;
    while(temp != 0)
    {
        int is_last = (temp->next==0)? 1:0;
        tree_print(is_last, "dim %d to %d", temp->lower, temp->upper);
        temp = temp->next;
    }
DUMP_END


void dump_const_val(struct const_node *cont, int is_last)
{
    tree_print(is_last, "constant");
    add_tree_level(is_last);

    dump_scalar(cont->type, 1);
DUMP_END


DUMP_BEGIN(vari, variable_node, "variable and constant declartion")
    while(p != 0)
    {
        push_vari(p);

        int is_last = (p->sibling==0)? 1:0;
        tree_print(0, "%s", p->name);
        if(p->type != 0)
            dump_type_node(p->type, is_last);
        else if(p->const_val != 0)
            dump_const_val(p->const_val, is_last);
        p = p->sibling;
    }
DUMP_END


DUMP_BEGIN(varr, varirefe_node, "variable reference")
    tree_print(0, "%s", p->name);
    dump_expr_node(p->ref, 0);
    dump_type_node(p->type, 1);
DUMP_END


DUMP_BEGIN(expr, expr_node, "expression")
    const char *opt[] = {"unknow", "+", "-", "*", "/", "\%",
                            "-", "<", "<=", ">", ">=", "==",
                            "!=", "or", "and", "not"};
    while(p != 0)
    {
        int is_last = (p->sibling==0)? 1:0;
    
        switch(p->mode)
        {
            case CONST_DATA:
                dump_const_val(p->cont, 0);
                break;
            case VARIA_REFE:
                dump_varr_node(p->vref, 0);
                break;
            case FUNCT_INVO:
                dump_finv_node(p->finv, 0);
                break;
            case EXPRESSION:
                dump_expr_node(p->lsite, 0);
                dump_expr_node(p->rsite, 0);
                tree_print(0, "opt: %s", opt[p->opt]);
                break;
            default:
                tree_print(0, "unknow");
                break;
        }

        dump_type_node(p->type, is_last);
        p = p->sibling;
    }
DUMP_END


DUMP_BEGIN(simp, simp_node, "simple")
    if(p->lhs == 0)
        dump_expr_node(p->rhs, 1);
    else if(p->rhs == 0)
        dump_varr_node(p->lhs, 1);
    else
    {
        dump_varr_node(p->lhs, 0);
        dump_expr_node(p->rhs, 1);
    }
DUMP_END


DUMP_BEGIN(cond, cond_node, "condition")
    dump_expr_node(p->condition, 0);
    dump_stat_node(p->tpath, 0);
    dump_stat_node(p->fpath, 1);
DUMP_END


DUMP_BEGIN(whil, whil_node, "while loop")
    dump_expr_node(p->condition, 0);
    dump_stat_node(p->stat, 1);
DUMP_END


DUMP_BEGIN(for_, for__node, "for loop")
    next_level();
    push_vari(p->i);

    tree_print(0, "loop variable: %s", p->i->name);
    tree_print(0, "%d to %d", p->start, p->end);
    dump_stat_node(p->stat, 1);

    exit_level();
DUMP_END


DUMP_BEGIN(finv, finv_node, "function invocation")
    tree_print(0, "function name: %s", p->name);
    dump_expr_node(p->exprs, 0);
    dump_type_node(p->ret_type, 1);     // FIXME: Need apply function return type.
DUMP_END


struct type_node *find_lastrettype(void)
{
    struct type_node *ret = 0;
    if(in_progcomp == 0)
    {
        for(int i=sym_conut-1; i>=0; i--)
        {
            if(sym_table[i].whitch_struct == STRUCT_FUNC)
            {
                ret = ((struct function_node *)sym_table[i].data)->ret_type;
                break;
            }
        }
    }
    
    if((ret==0)&&(in_progcomp==0))
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> can not find return type, function have not push to symbol table ?\n");
        fprintf(outerr, "Replace with void type.\n");
        fprintf(outerr, "\033[0m");
    }
    if(ret == 0)
        ret = ast->type;
    return ret;
}


DUMP_BEGIN(ret_, ret__node, "return")
    struct type_node *now_rettype = find_lastrettype();
    check_rettype(now_rettype, p->expr->type, &p->loc);
    dump_expr_node(p->expr, 1);
DUMP_END


DUMP_BEGIN(stat, statment_node, "statement declartion")
    while(p != 0)
    {
        int is_last = (p->sibling==0)? 1:0;
    
        switch(p->mode)
        {
            case COMP_STAT:
                dump_comp_node(p->comp, is_last);
                break;
            case SIMP_STAT:
                dump_simp_node(p->simp, is_last);
                break;
            case COND_STAT:
                dump_cond_node(p->cond, is_last);
                break;
            case WHIL_STAT:
                dump_whil_node(p->whil, is_last);
                break;
            case FOR__STAT:
                dump_for__node(p->for_, is_last);
                break;
            case FINV_STAT:
                dump_finv_node(p->finv, is_last);
                break;
            case RET__STAT:
                dump_ret__node(p->ret_, is_last);
                break;
            default:
                tree_print(is_last, "unknow");
                break;
        }

        p = p->sibling;
    }
DUMP_END


int comp_set_level = 1;
DUMP_BEGIN(comp, compound_node, "compound statement")
    if(comp_set_level)
        next_level();

    dump_vari_node(p->loc_var, 0);
	dump_stat_node(p->stat, 1);

    if(comp_set_level)
        exit_level();
DUMP_END


DUMP_BEGIN(func, function_node, "function declartion")
    while(p != 0)
    {
        push_func(p);
        next_level();

        int is_last = (p->sibling==0)? 1:0;

        tree_print(is_last, "%s", p->name);
        add_tree_level(is_last);

        dump_vari_node(p->arg, 0);
        dump_type_node(p->ret_type, 0);

        comp_set_level = 0;
        dump_comp_node(p->comp, 1);
        comp_set_level = 1;

        del_tree_level();
        exit_level();
        p = p->sibling;
    }
DUMP_END


void dump_ast(void)
{
    push_prog(ast);

    tree_lead[0] = 0;
    printf("file name: %s.p\n", prog_name);
	printf("%s\n", ast->name);

    check_progname(prog_name, ast);

    dump_vari_node(ast->vacd, 0);
    dump_func_node(ast->func, 0);
    in_progcomp = 1;
    dump_comp_node(ast->comp, 1);
/*
extern int linenum;
    for(int i; i<linenum; i++)
        printf("%s", prog_line[i]);
*/
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

    strcpy(prog_name, argv[1]);
    int i;
    for(i=strlen(prog_name); prog_name[i]!='.';i--);
    prog_name[i] = 0;

    yyin = fp;

    yyparse();

    dump_ast();
/*
    fprintf( stdout, "\n" );
    fprintf( stdout, "|--------------------------------|\n" );
    fprintf( stdout, "|  There is no syntactic error!  |\n" );
    fprintf( stdout, "|--------------------------------|\n" );
*/

    exit(0);
}

