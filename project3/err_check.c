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

const char *err_redeclared = "symbol ’%s’ is redeclared\n";

int check_redeclared(struct stack *s, const char *ident)
{
    struct symbol *b;

    s->init_iter(s, -1);
    for(b=s->iterator(s); (b!=0)&&(b->get_level(b)==now_level); b=s->iterator(s))
    {
        if(strcmp(ident, b->get_name(b)) == 0)
        {
            printf("<Error> found in Line %d: ", linenum);
            printf(err_redeclared, ident);
            return 1;
        }
    }

    return 0;
}

