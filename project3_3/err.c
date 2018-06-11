#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "main.h"

#define outerr stdout

#define eprintf(loc, msg)   printf("<Error> found in Line %d: ", loc.first_line);   \
                            printf("%s\n", msg);

void print_tagline(const YYLTYPE *loc)
{
    int i;
    int c;
    fprintf(outerr, "    %s", prog_line[loc->first_line-1]);
    fprintf(outerr, "    ");
    for(i=0; i<loc->first_column; i++)
        fprintf(outerr, " ");
    if(loc->first_line == loc->last_line)
        c = loc->last_column;
    else
        c = strlen(prog_line[loc->first_line-1]);
    for(; (i<c)&&(i<loc->first_column+32); i++)
        fprintf(outerr, "^");
    
    fprintf(outerr, "\n");
}


int check_redeclar(const char *n1, const char *n2, const YYLTYPE *l1, const YYLTYPE *l2)
{
    if(strcmp(n1, n2) == 0)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> symbol '%s' is redeclared\n", n1);
        fprintf(outerr, "First declared at line %d:\n", l1->first_line);
        print_tagline(l1);
        fprintf(outerr, "New declared at line %d:\n", l2->last_line);
        print_tagline(l2);
        fprintf(outerr, "\033[0m");

        return 1;
    }

    return 0;
}
