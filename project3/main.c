/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Transforms/Scalar.h>

extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
extern int Opt_D;

int now_level = 0;

LLVMModuleRef ir_obj;

static void print_symbol(struct symbol *symbol)
{
    int level;
}


int push_ident(const char *name)
{
    struct symbol *now;

    return 0;
}


int supply_kind(const char *kind)
{
    struct symbol *temp;

    return 0;
}


int construct_attr(void)
{
    return 0;
}


static int add_attr(void *target, int type)
{
    return 0;
}


int add_cons_attr(void *target, const char *type, int is_negative)
{
    return 0;
}

int supply_cons_attr(void)
{
    return 0;
}


int supply_func_attr(void)
{
    return 0;
}


int construct_type(void)
{
    return 0;
}


int add_type(const char *str)
{
    return 0;
}


int add_dim(int upper, int lower)
{
    return 0;
}


int supply_type(void)
{
    return 0;
}


int next_level(void)
{
    return 0;
}


int exit_level(void)
{
    return 0;
}


void dump_symbol(void)
{
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

//    ir_obj = LLVMModuleCreateWithName("top_module");

    yyparse();

/*
    fprintf( stdout, "\n" );
    fprintf( stdout, "|--------------------------------|\n" );
    fprintf( stdout, "|  There is no syntactic error!  |\n" );
    fprintf( stdout, "|--------------------------------|\n" );
*/

    exit(0);
}

