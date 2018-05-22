#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err_check.h"
#include "attribute.h"
#include "main.h"
#include "stack.h"
#include "symbol.h"
#include "type.h"

extern int linenum;             /* declared in lex.l */
extern int now_level;           /* declared in main.c */

const char *err_redeclared = "symbol '%s' is redeclared\n";
const char *err_progname = "program ID is inconsistent with filename\n";
const char *err_funcname = "function name of declaration is inconsistent\n";
const char *err_funcrettype = "return type of a function cannot be array type\n";
const char *err_progret = "program cannot be returned\n";
const char *err_dimerr = "wrong dimension declaration for array %s\n";
const char *err_dimref = "'%s' is %d dimension(s), but reference in %d dimension(s)\n";
const char *err_declared = "'%s' is not declared\n";
const char *err_assigarr = "array assignment is not allowed\n";
const char *err_constlhs = "constant '%s' cannot be assigned\n";

int check_redeclared(struct stack *s, const char *ident)
{
    struct symbol *b;

    s->init_iter(s, -1);
    for(b=s->iterator(s); (b!=0)&&(b->get_level(b)==now_level); b=s->iterator(s))
    {
        if(strcmp(ident, b->get_name(b)) == 0)
        {
            fprintf(stdout, "<Error> found in Line %d: ", linenum);
            fprintf(stdout, err_redeclared, ident);
            return 1;
        }
    }

    return 0;
}


int check_progname(const char *prog_name, const char *str)
{
    int is_error;

    is_error = (strcmp(prog_name, str)==0)? 0:1;
    if(is_error != 0)
    {
        fprintf(stdout, "<Error> found in Line %d: ", linenum);
        fprintf(stdout, "%s", err_progname);
    }

    return is_error;
}


int check_funcname(struct stack *s, const char *func_name)
{
    int is_error;
    struct symbol *b;

    s->init_iter(s, -1);
    for(b=s->iterator(s);
        (b!=0)&&(b->get_kind(b)!=kind_func);
        b=s->iterator(s));

    is_error = (strcmp(b->get_name(b), func_name)==0)? 0:1;
    if(is_error)
    {
        fprintf(stdout, "<Error> found in Line %d: ", linenum);
        fprintf(stdout, "%s", err_funcname);
    }

    return is_error;
}


int check_funcrettype(struct type *t)
{
    if(t->get_dims(t) != 0)
    {
        fprintf(stdout, "<Error> found in Line %d: ", linenum);
        fprintf(stdout, "%s", err_funcrettype);
        return 1;
    }
    return 0;
}


int check_rettype(struct stack *s, struct type *t)
{
    extern int is_progcompound;
    struct symbol *b;
    
    if(is_progcompound)
    {
        fprintf(stdout, "<Error> found in Line %d: ", linenum);
        fprintf(stdout, "%s", err_progret);
        return 1;
    }
    else
    {
        s->init_iter(s, -1);
        for(b=s->iterator(s);
            (b!=0)&&(b->get_kind(b)!=kind_func);
            b=s->iterator(s));
        if(b != 0)
            printf("~~~~~~~~~~%s, %d\n", b->get_type(b), linenum);
    }

    return 0;
}


int check_arraydim(struct symbol *s)
{
    int is_error;
    struct type *t = s->get_typeinst(s);

    is_error = t->is_dimerr(t);
    if(is_error)
    {
        fprintf(stdout, "<Error> found in Line %d: ", linenum);
        fprintf(stdout, err_dimerr, s->get_name(s));
    }

    return is_error;
}


int check_arrayref(struct symbol *s, int dim)
{
    if(s != 0)
    {
        struct type *t = s->get_typeinst(s);

        if(t->get_dims(t) < dim)
        {
            fprintf(stdout, "<Error> found in Line %d: ", linenum);
            fprintf(stdout, err_dimref, s->get_name(s), t->get_dims(t), dim);
            return 1;
        }
    }

    return 0;
}


int check_declared(struct symbol *s, const char *name)
{
    if(s == 0)
    {
        fprintf(stdout, "<Error> found in Line %d: ", linenum);
        fprintf(stdout, err_declared, name);
        return 1;
    }

    return 0;
}


int check_lhs(struct symbol *s, int dim)
{
    int s_dim = 0;

    if(s!=0)
    {
        struct type *t = s->get_typeinst(s);

        if(t->get_dims(t) > dim)
        {
            fprintf(stdout, "<Error> found in Line %d: ", linenum);
            fprintf(stdout, "%s", err_assigarr);
            return 1;
        }
    }

    if((s!=0)&&(s->get_kind(s)==kind_cons))
    {
        fprintf(stdout, "<Error> found in Line %d: ", linenum);
        fprintf(stdout, err_constlhs, s->get_name(s));
        return 1;
    }

    return 0;
}

