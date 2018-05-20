/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
extern int Opt_D;
extern struct program_node *ast;

#define STRUCT_PROG 1
#define STRUCT_VARI 2
#define STRUCT_FUNC 3

struct symbol
{
	void *data;
	int level;
	int  whitch_struct;
};

struct symbol sym_table[200] = {0};
int sym_conut = 0;
int now_level = 0;

char prog_name[256];
char tree_lead[1024];

void push_symbol(void *data, int whitch_struct)
{
    sym_table[sym_conut].data = data;
    sym_table[sym_conut].level = now_level;
    sym_table[sym_conut].whitch_struct = whitch_struct;

    sym_conut++;
}


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
    if(now_level > 0)
        now_level--;

    pop_symbol(now_level);
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
    add_tree_level(is_last);

    dump_scalar(type->type, (type->dim==0)? 1:0);
    struct dim_list *temp = type->dim;
    while(temp != 0)
    {
        int is_last = (temp->next==0)? 1:0;
        tree_print(is_last, "dim %d to %d", temp->lower, temp->upper);
        temp = temp->next;
    }

    del_tree_level();
}


void dump_const_val(struct const_node *cont, int is_last)
{
    add_tree_level(is_last);

    tree_print(0, "constant");
    dump_scalar(cont->type, 1);

    del_tree_level();
}

void dump_vari_node(struct variable_node *head, int is_last)
{
    tree_print(is_last, "variable and constant declartion");
    add_tree_level(is_last);

    while(head != 0)
    {
        int is_last = (head->sibling==0)? 1:0;
        tree_print(is_last, "%s", head->name);
        if(head->type != 0)
            dump_type_node(head->type, is_last);
        else if(head->const_val != 0)
            dump_const_val(head->const_val, is_last);
        head = head->sibling;
    }

    del_tree_level();
}


void dump_comp_node(struct compound_node *comp, int is_last)
{
    tree_print(is_last, "compound statement");
    add_tree_level(is_last);

    dump_vari_node(comp->loc_var, 0);
    tree_print(1, "statement declartion");

    del_tree_level();
}


void dump_func_node(struct function_node *head, int is_last)
{
    tree_print(is_last, "function declartion");
    add_tree_level(is_last);

    while(head != 0)
    {
        int is_last = (head->sibling==0)? 1:0;

        tree_print(is_last, "%s", head->name);
        add_tree_level(is_last);

        dump_vari_node(head->arg, 0);
        tree_print(0, "function return type");
        dump_type_node(head->ret_type, 0);

        dump_comp_node(head->comp, 1);

        del_tree_level();
        head = head->sibling;
    }

    del_tree_level();
}


void dump_ast(void)
{
    tree_lead[0] = 0;
    printf("file name: %s.p\n", prog_name);
	printf("%s\n", ast->name);
    dump_vari_node(ast->vacd, 0);
    dump_func_node(ast->func, 0);
    dump_comp_node(ast->comp, 1);
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

