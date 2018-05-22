#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "main.h"

#define eprintf(loc, msg)   printf("<Error> found in Line %d: ", loc.first_line);   \
                            printf("%s\n", msg);

void print_tagline(const YYLTYPE *loc)
{
    int i;
    int c;
    char *tag_line = strdup(prog_line[loc->first_line-1]);
    int elim = 0;
    int begin_col;
    int end_col;
    for(; (tag_line[0]!=0)&&
        ((tag_line[0]==' ')||(tag_line[0]=='\t'));
        elim++)
        tag_line = &tag_line[1];

    begin_col = loc->first_column - elim;
    end_col = loc->last_column - elim;

    fprintf(outerr, "    %s", tag_line);
    fprintf(outerr, "    ");
    for(i=0; i<begin_col; i++)
        fprintf(outerr, " ");
    if(loc->first_line == loc->last_line)
        c = end_col;
    else
        c = strlen(tag_line);
    for(; (i<c)&&(i<begin_col+31); i++)
        fprintf(outerr, "^");
    if(i == begin_col+32)
        fprintf(outerr, "~");
    
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


int check_progname(const char *file_name, struct program_node *ast)
{
    const char *head_name = ast->name;
    const char *tail_name = ast->end_name;

    if(strcmp(file_name, head_name) != 0)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> program ID is inconsistent with filename\n");
        fprintf(outerr, "Filename: %s\n", file_name);
        fprintf(outerr, "Beginning at line %d:\n", ast->loc.first_line);
        print_tagline(&ast->loc);
        fprintf(outerr, "\033[0m");
        return 1;
    }

    if(strcmp(head_name, tail_name) != 0)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> program ID is inconsistent with beginning\n");
        fprintf(outerr, "Beginning at line %d:\n", ast->loc.first_line);
        print_tagline(&ast->loc);
        fprintf(outerr, "Ending at line %d:\n", ast->end_loc.first_line);
        print_tagline(&ast->end_loc);
        fprintf(outerr, "\033[0m");
        return 1;
    }

    return 0;
}


// FIXME: Not comparesion two type.
int check_rettype(struct type_node *ret_type, struct type_node *expr_type, const YYLTYPE *loc)
{
    if(ret_type->type == VOID_TYPE)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> current return type is void\n");
        fprintf(outerr, "Should not return value at:\n");
        print_tagline(loc);
        fprintf(outerr, "\033[0m");
        return 1;
    }

    return 0;
}

