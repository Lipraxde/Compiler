/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "symbol.h"

extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
extern int Opt_D;

struct stack *s;
struct type *t;
int now_level = 0;

static void print_symbol(struct symbol *symbol)
{
    int level;
    const char *name;
    const char *kind;
    const char *type;
    const char *attr;
    static const char invalid[] = "invalid";

    level = symbol->get_level(symbol);
    name = symbol->get_name(symbol);
    name = (name==0) ? invalid:name;
    kind = symbol->get_kind(symbol);
    kind = (kind==0) ? invalid:kind;
    type = symbol->get_type(symbol);
    type = (type==0) ? invalid:type;
    attr = symbol->get_attr(symbol);
    attr = (attr==0) ? invalid:attr;

    printf("%-33s", name);
    printf("%-11s", kind);
    printf("%d%-10s", level, (level==0) ? "(global)":"(local)");
    printf("%-17s", type);
    printf("%-11s", attr);
    printf("\n");
}


int push_ident(const char *name)
{
    struct symbol *now;

    now = symbol_create();
    now->set_level(now, now_level);
    now->set_name(now, name);
    s->push(s, now);

    return 0;
}


int supply_kind(const char *kind)
{
    struct symbol *temp;

    s->init_iter(s, -1);
    for(temp=s->iterator(s); (temp!=0)&&(temp->get_kind(temp)==0); temp=s->iterator(s))
        temp->set_kind(temp, kind);

    return 0;
}


int construct_type(void)
{
    t = type_create();

    return 0;
}


int add_type(const char *str)
{
    t->add_type(t, str);

    return 0;
}


int add_dim(int upper, int lower)
{
    t->add_dime(t, upper, lower);

    return 0;
}


int supply_type(void)
{
    struct symbol *temp;

    s->init_iter(s, -1);
    for(temp=s->iterator(s); (temp!=0)&&(temp->get_type(temp)==0); temp=s->iterator(s))
        temp->set_type(temp, t);
    t = 0;

    return 0;
}

int next_level(void)
{
    if(now_level<INT_MAX)
        now_level++;

    return 0;
}


int exit_level(void)
{
    if(now_level>0)
        now_level--;

    return 0;
}


void dump_symbol(void)
{
    int i;
    struct symbol *temp;

    if(Opt_D)
    {
        for(i=0;i< 110;i++)
            printf("=");
        printf("\n");
        printf("%-33s%-11s%-11s%-17s%-11s\n","Name","Kind","Level","Type","Attribute");
        for(i=0;i< 110;i++)
            printf("-");
        printf("\n");

        for(temp=s->pop(s); (temp!=0)&&(temp->get_level(temp)==now_level); temp=s->pop(s))
            print_symbol(temp);
        s->push(s, temp);

        for(i=0;i< 110;i++)
            printf("=");
        printf("\n");
    }
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

    s = stack_create();

    yyparse();

    stack_delete(s, symbol_delete);

    fprintf( stdout, "\n" );
    fprintf( stdout, "|--------------------------------|\n" );
    fprintf( stdout, "|  There is no syntactic error!  |\n" );
    fprintf( stdout, "|--------------------------------|\n" );
    exit(0);
}

