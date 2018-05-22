/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "attribute.h"
#include "err_check.h"
#include "stack.h"
#include "string.h"
#include "symbol.h"

extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
extern int Opt_D;

int is_error = 0;
struct symbol *default_symbol;
struct type *default_type;

struct stack *s;
struct type *t;
struct attr *a;
int now_level = 0;
char prog_name[256];

static void print_symbol(struct symbol *symbol)
{
    int level;
    const char *name;
    const char *kind;
    const char *type;
    const char *attr;
    static const char invalid[] = "";

    level = symbol->get_level(symbol);
    name = symbol->get_name(symbol);
    name = (name==0) ? invalid:name;
    kind = symbol->get_kind(symbol);
    kind = (kind==0) ? invalid:kind;
    type = symbol->get_type(symbol);
    type = (type==0) ? invalid:type;
    attr = symbol->get_attr(symbol);
    attr = (attr==0) ? invalid:attr;

    if(name[0] != 0)
    {
        printf("%-33s", name);
        printf("%-11s", kind);
        printf("%d%-10s", level, (level==0) ? "(global)":"(local)");
        printf("%-17s", type);
        printf("%-s", attr);    // Because want to match output example.
        // printf("%-11s", attr);
        printf("\n");
    }
}


int push_ident(const char *name)
{
    extern int linenum;
    int _is_error;
    struct symbol *now;

    now = symbol_create();
    now->set_level(now, now_level);
    _is_error = check_redeclared(s, name);
    is_error |= _is_error;
    if(_is_error == 0)
        now->set_name(now, name);
    else
        now->set_name(now, "");
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


int construct_attr(void)
{
    a = attr_create();

    return 0;
}


static int add_attr(void *target, int type)
{
    if(a != 0)
        a->add_attr(a, target, type);

    return 0;
}


int add_cons_attr(void *target, const char *type, int is_negative)
{
    void *temp = 0;
    int at = 0;

    if(type == type_inte)
    {
        temp = malloc(sizeof(int));
        *(int *)temp = *(int *)target;
        if(is_negative)
            *(int *)temp = -*(int *)temp;
        at = attr_inte;
    }
    else if(type == type_real)
    {
        temp = malloc(sizeof(double));
        *(double *)temp = *(double *)target;
        if(is_negative)
            *(double *)temp = -*(double *)temp;
        at = attr_real;
    }
    else if(type == type_stri)
    {
        unsigned long len = strlen(target);
        temp = malloc(len+1);
        strcpy(temp, *(const char **)target);
        at = attr_stri;
    }
    else if(type == type_bool)
    {
        temp = malloc(sizeof(int));
        *(int *)temp = *(int *)target;
        at = attr_bool;
    }

    add_attr(temp, at);

    return 0;
}

int supply_cons_attr(void)
{
    struct symbol *temp;

    s->init_iter(s, -1);
    for(temp=s->iterator(s);
        (temp!=0)&&(temp->get_attr(temp)==0)&&(temp->get_kind(temp)==kind_cons);
        temp=s->iterator(s))
        temp->set_attr(temp, a);
    a = 0;

    return 0;
}


int supply_func_attr(void)
{
    struct symbol *temp;

    s->init_iter(s, -1);
    for(temp=s->iterator(s); (temp!=0)&&(temp->get_kind(temp)!=kind_func); temp=s->iterator(s));
    if(temp != 0)
        temp->set_attr(temp, a);
    a = 0;

    return 0;
}


int construct_type(void)
{
    t = type_create();

    return 0;
}


int add_type(const char *str)
{
    if(t != 0)
        t->add_type(t, str);

    return 0;
}


int add_dim(int upper, int lower)
{
    if(t != 0)
        t->add_dime(t, upper, lower);

    return 0;
}


int supply_type(void)
{
    struct symbol *temp;
    const char *supply_kind;

    s->init_iter(s, -1);
    for(temp=s->iterator(s); (temp!=0)&&(temp->get_type(temp)!=0); temp=s->iterator(s));
    supply_kind = temp->get_kind(temp);


    for(; (temp!=0)&&(temp->get_type(temp)==0)&&(temp->get_kind(temp)==supply_kind);
        temp=s->iterator(s))
    {
        temp->set_type(temp, t);
        if(temp->get_kind(temp) == kind_para)
            add_attr(t, attr_type);

        if(supply_kind == kind_func)
            is_error |= check_funcrettype(t);
        else
            is_error |= check_arraydim(temp);
    }
    t = 0;

    return 0;
}


int next_level(void)
{
    if(now_level < INT_MAX)
        now_level++;

    return 0;
}


int exit_level(void)
{
    if(now_level > 0)
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

        struct stack *stemp;    // for inverse output order
        stemp = stack_create();
        for(temp=s->pop(s); (temp!=0)&&(temp->get_level(temp)==now_level); temp=s->pop(s))
            stemp->push(stemp, temp);
        s->push(s, temp);

        for(temp=stemp->pop(stemp); (temp!=0); temp=stemp->pop(stemp))
        {
            print_symbol(temp);
            symbol_delete(temp);
        }
        stack_delete(stemp, 0);

        for(i=0;i< 110;i++)
            printf("-");
        printf("\n");
    }
    else
    {   // Pop symbol
        for(temp=s->pop(s); (temp!=0)&&(temp->get_level(temp)==now_level); temp=s->pop(s));
        s->push(s, temp);
    }
}


struct symbol *find_variable(const char *name)
{
    struct symbol *ret = 0;

    s->init_iter(s, -1);
    for(ret=s->iterator(s);
        (ret!=0)&&(strcmp(name, ret->get_name(ret))!=0);
        ret=s->iterator(s));

    if((ret!=0)&&
        ((strcmp(name, ret->get_name(ret))!=0)||
        (ret->get_kind(ret)==kind_func)||
        (ret->get_kind(ret)==kind_prog)))
        return 0;
    return ret;
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

    s = stack_create();

    default_symbol = symbol_create();
    default_type = type_create();
    default_type->add_type(default_type, type_inte);
    default_symbol->set_type(default_symbol, default_type);

    yyparse();

    /* FIXME Should release attribute and type information. */
    stack_delete(s, symbol_delete);

    if(is_error == 0)
    {
        fprintf( stdout, "\n" );
        fprintf( stdout, "|-------------------------------------------|\n" );
        fprintf( stdout, "| There is no syntactic and semantic error! |\n" );
        fprintf( stdout, "|-------------------------------------------|\n" );
    }

    exit(0);
}

