#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "main.h"

#define eprintf(loc, msg)   printf("<Error> found in Line %d: ", loc.first_line);   \
                            printf("%s\n", msg);

void print_tagline(const YYLTYPE *loc)
{
    int i, c, begin_col, end_col;
    char *tag_line = strdup(prog_line[loc->first_line-1]);
    int elim = 0;

    for(; (tag_line[0]!=0)&&
        ((tag_line[0]==' ')||(tag_line[0]=='\t'));
        elim++)
        tag_line = &tag_line[1];

    begin_col = loc->first_column - elim;
    if(loc->first_line == loc->last_line)
        end_col = loc->last_column - elim;
    else
        end_col = strlen(tag_line);

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
    if(i == begin_col+31)
        fprintf(outerr, "~");
    
    fprintf(outerr, "\n");
}


int check_redeclar(const char *n1, const char *n2, const YYLTYPE *l1, const YYLTYPE *l2)
{
    if(strcmp(n1, n2) == 0)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> symbol '%s' is redeclared\n", n1);
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "First declared at line %d:\n", l1->first_line);
        print_tagline(l1);
        fprintf(outerr, "New declared at line %d:\n", l2->last_line);
        print_tagline(l2);
        fprintf(outerr, "\n");

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
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Filename: %s\n", file_name);
        fprintf(outerr, "Beginning at line %d:\n", ast->loc.first_line);
        print_tagline(&ast->loc);
        fprintf(outerr, "\n");
        return 1;
    }

    if(strcmp(head_name, tail_name) != 0)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> program ID is inconsistent with beginning\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Beginning at line %d:\n", ast->loc.first_line);
        print_tagline(&ast->loc);
        fprintf(outerr, "Ending at line %d:\n", ast->end_loc.first_line);
        print_tagline(&ast->end_loc);
        fprintf(outerr, "\n");
        return 1;
    }

    return 0;
}


int check_rettype(struct type_node *ret_type, struct type_node *expr_type, const YYLTYPE *loc)
{
    if(ret_type->type == VOID_TYPE)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> current return type is void\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Should not return value at line %d:\n", loc->first_line);
        print_tagline(loc);
        fprintf(outerr, "\n");
        return 1;
    }

    if(ret_type->type != expr_type->type)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> return type mismatch\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Return type definition at line %d:\n", ret_type->loc.first_line);
        print_tagline(&ret_type->loc);
        fprintf(outerr, "Return statement at line %d:\n", loc->first_line);
        print_tagline(loc);
        fprintf(outerr, "\n");
    }

    return 0;
}


int check_funcrettypeisscalar(struct type_node *ret_type)
{
    if(ret_type->dim != 0)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> return type of function should not be array type\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Definition at line %d:\n", ret_type->dim->loc.first_line);
        YYLTYPE loc = ret_type->dim->loc;
        loc.last_column = ret_type->loc.last_column;
        loc.last_line = ret_type->loc.last_line;
        print_tagline(&loc);
        fprintf(outerr, "\n");
        return 1;
    }

    return 0;
}


static int check_varirefandassigntype(struct varirefe_node *varr)
{
    struct variable_node *var_ref;
    struct type_node *type_ref = 0;

    for(int i=sym_count-1; i>=0; i--)
    {
        if(sym_table[i].whitch_struct != STRUCT_VARI)
            continue;
        var_ref = ((struct variable_node *)sym_table[i].data);
        if(strcmp(var_ref->name, varr->name) == 0)
        {
            type_ref = var_ref->type;
            break;
        }
    }

    if(type_ref != 0)
    {
        varr->var = var_ref;
        varr->type->type = type_ref->type;
        varr->type->dim = type_ref->dim;
        varr->type->loc = type_ref->loc;
    }
    else
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> undefined reference\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Variable refernece at line %d:\n", varr->loc.first_line);
        print_tagline(&varr->loc);
        fprintf(outerr, "\n");

        return 1;
    }

    return 0;
}

static const char *text[] = {"unknown", "void", "integer", "real", "boolean", "string"};
int check_typematch(struct type_node *type, enum scalar_type scalar[], int n)
{
    int ret = 1;

    for(int i=0; i<n; i++)
    {
        if(type->type == scalar[i])
            ret = 0;
    }

    if(ret != 0)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> type mismatch\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Type must be %s", text[scalar[0]]);
        if(n > 1)
        {
            for(int i=1; i<n-1; i++)
                fprintf(outerr, ", %s", text[scalar[i]]);
            fprintf(outerr, " or %s type\n", text[scalar[n-1]]);
        }
        else
            fprintf(outerr, " type\n");
        fprintf(outerr, "But %s type at line %d:\n", text[type->type], type->loc.first_line);
        print_tagline(&type->loc);
        if(type->type == 0)
        {
            int sz;
            if(n > 0)   sz = n-1;
            else        sz = 0;
            fprintf(outerr, "Assume it %s type\n", text[scalar[sz]]);
            type->type = scalar[sz];
            fprintf(outerr, "\n");
        }
    }

    return ret;
}


static int check_varirefdim(struct varirefe_node *varr)
{
    int ret = 0;
    int n;
    enum scalar_type type_arr[4];
    int ref_dimconut = 0;
    int var_dimconut = 0;

    if(varr->var == 0)
        return 0;

    struct expr_node *expr_list = varr->ref;
    while(expr_list != 0)
    {
        ret |= check_exprtypeandtypemakeup(expr_list);
        type_arr[0] = INTE_TYPE;    n = 1;
        ret |= check_typematch(expr_list->type, type_arr, n);

        ref_dimconut++;
        expr_list = expr_list->sibling;
    }

    struct dim_list *dim_list = varr->type->dim;
    while(dim_list != 0)
    {
        var_dimconut++;
        dim_list = dim_list->next;
    }

    if(ref_dimconut > var_dimconut)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> dimension of declaration is greater than reference one\n");
        fprintf(outerr, "\033[0m");
        if(var_dimconut == 0)
        {
            fprintf(outerr, "Declaration type is scalar at line %d:\n",
                    varr->var->loc.first_line);
            print_tagline(&varr->var->loc);
        }
        else
        {
            fprintf(outerr, "Declaration dimension is %d at line %d:\n",
                    var_dimconut, varr->type->loc.first_line);
            print_tagline(&varr->type->loc);
        }
        fprintf(outerr, "Refernece dimension is %d at line %d:\n",
                ref_dimconut, varr->loc.first_line);
        print_tagline(&varr->loc);
        fprintf(outerr, "\n");

        ret = 1;
    }

    if((varr->allow_arrayaccess==0)&&(ref_dimconut<var_dimconut))
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> Access array is not allow here\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Access array at line %d:\n", varr->loc.first_line);
        print_tagline(&varr->loc);
        fprintf(outerr, "\n");

        ret = 1;
    }

    return ret;
}


int check_variavailable(struct varirefe_node *varr)
{
    int ret = 0;
    ret |= check_varirefandassigntype(varr);
    ret |= check_varirefdim(varr);
    return ret;
}


int check_variwriteable(struct varirefe_node *varr)
{
    if(varr->var == 0)
        return 1;

    if(varr->var->var_mode == 1)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> Assign constant variable is not allow\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Constant variable is declared at line %d:\n",
                varr->var->loc.first_line);
        print_tagline(&varr->var->loc);
        fprintf(outerr, "Assign constant variable at line %d:\n", varr->loc.first_line);
        print_tagline(&varr->loc);
        fprintf(outerr, "\n");
        return 1;
    }
    else if(varr->var->var_mode == 2)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> Assign loop variable is not allow\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Loop variable is declared at line %d:\n",
                varr->var->loc.first_line);
        print_tagline(&varr->var->loc);
        fprintf(outerr, "Assign loop variable at line %d:\n", varr->loc.first_line);
        print_tagline(&varr->loc);
        fprintf(outerr, "\n");
        return 1;
    }
    else if(varr->var->var_mode != 0)
    {
        printf("unknown error\n");
        return 1;
    }

    return 0;
}


static int expr_typemakeupandcheck(struct expr_node *expr)
{
    int n;
    int ret = 0;
    enum scalar_type type_arr[4];

    switch(expr->opt)
    {
        case opt_add:
        case opt_del:
        case opt_mul:
        case opt_div:
            ret |= check_exprtypeandtypemakeup(expr->lsite);

            if((expr->opt==opt_add)&&(expr->lsite->type->type==TEXT_TYPE))
            {
                ret |= check_exprtypeandtypemakeup(expr->rsite);

                type_arr[0] = TEXT_TYPE;    n = 1;
                ret |= check_typematch(expr->rsite->type, type_arr, n);
                
                expr->type->type = TEXT_TYPE;
                break;
            }

            type_arr[0] = INTE_TYPE;    type_arr[1] = REAL_TYPE;    n = 2;
            ret |= check_typematch(expr->lsite->type, type_arr, n);
        case opt_nega:
            ret |= check_exprtypeandtypemakeup(expr->rsite);

            type_arr[0] = INTE_TYPE;    type_arr[1] = REAL_TYPE;    n = 2;
            ret |= check_typematch(expr->rsite->type, type_arr, n);

            expr->type->type = INTE_TYPE;
            if(((expr->lsite!=0)&&(expr->lsite->type->type==REAL_TYPE))||
                ((expr->rsite!=0)&&(expr->rsite->type->type==REAL_TYPE)))
                expr->type->type = REAL_TYPE;
            break;
        case opt_mod:
            ret |= check_exprtypeandtypemakeup(expr->lsite);
            ret |= check_exprtypeandtypemakeup(expr->rsite);

            type_arr[0] = INTE_TYPE;    n = 1;
            ret |= check_typematch(expr->lsite->type, type_arr, n);
            ret |= check_typematch(expr->rsite->type, type_arr, n);

            expr->type->type = INTE_TYPE;
            break;
        case cmp_less:
        case cmp_leq:
        case cmp_gt:
        case cmp_geq:
        case cmp_eq:
        case cmp_neq:
            ret |= check_exprtypeandtypemakeup(expr->lsite);
            ret |= check_exprtypeandtypemakeup(expr->rsite);

            type_arr[0] = INTE_TYPE;    type_arr[1] = REAL_TYPE;    n = 2;
            ret |= check_typematch(expr->lsite->type, type_arr, n);
            ret |= check_typematch(expr->rsite->type, type_arr, n);

            expr->type->type = BOOL_TYPE;
            break;
        case bool_or:
        case bool_and:
            ret |= check_exprtypeandtypemakeup(expr->lsite);
            type_arr[0] = BOOL_TYPE;    n = 1;
            ret |= check_typematch(expr->lsite->type, type_arr, n);
        case bool_not:
            ret |= check_exprtypeandtypemakeup(expr->rsite);
            type_arr[0] = BOOL_TYPE;    n = 1;
            ret |= check_typematch(expr->rsite->type, type_arr, n);
            expr->type->type = BOOL_TYPE;
            break;
        default:
            break;
    }

    return ret;
}


static int check_finvrefandassigntype(struct finv_node *finv)
{
    struct function_node *func_ref;
    struct type_node *type_ref = 0;

    for(int i=sym_count-1; i>=0; i--)
    {
        if(sym_table[i].whitch_struct != STRUCT_FUNC)
            continue;
        func_ref = ((struct function_node *)sym_table[i].data);
        if(strcmp(func_ref->name, finv->name) == 0)
        {
            type_ref = func_ref->ret_type;
            break;
        }
    }

    if(type_ref != 0)
        finv->func = func_ref;
    else
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> undefined reference\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Function refernece at line %d:\n", finv->loc.first_line);
        print_tagline(&finv->loc);
        fprintf(outerr, "\n");
        return 1;
    }
    return 0;
}


static int finv_makeupandtypecheck(struct finv_node *finv)
{
    int ret = 0;
    struct expr_node *expr_list;
    struct expr_node *redunt_expr = 0;
    struct variable_node *arg_list = 0;

    expr_list = finv->exprs;
    if(finv->func != 0)
        arg_list = finv->func->arg;

    while(expr_list != 0)
    {
        if(expr_list->mode == VARIA_REFE)
            expr_list->vref->allow_arrayaccess = 1;
        // Makeup argument type
        ret |= check_exprtypeandtypemakeup(expr_list);
        // Type check
        if(arg_list != 0)
        {
            int n;
            enum scalar_type type_arr[4];
            if(arg_list->type->type == REAL_TYPE)
            {
                type_arr[0] = INTE_TYPE;
                type_arr[1] = REAL_TYPE;
                n = 2;
            }
            else
            {
                type_arr[0] = arg_list->type->type;
                n = 1;
            }
            check_typematch(expr_list->type, type_arr, n);
            // Dimension check
            if((expr_list->mode == VARIA_REFE)&&(expr_list->vref->var!=0))
            {
                int arg_dim, def_dim, ref_dim;
                struct dim_list *dim_list;
                struct expr_node *iexpr_list;

                dim_list = arg_list->type->dim;
                for(arg_dim=0; dim_list!=0; arg_dim++, dim_list=dim_list->next);
                dim_list = expr_list->vref->type->dim;
                for(def_dim=0; dim_list!=0; def_dim++, dim_list=dim_list->next);
                iexpr_list = expr_list->vref->ref;
                for(ref_dim=0; iexpr_list!=0; ref_dim++, iexpr_list=iexpr_list->sibling);

                if(def_dim-ref_dim!=arg_dim)
                {
                    fprintf(outerr, "\033[31m");
                    fprintf(outerr, "<Error> Dimension mismatch\n");
                    fprintf(outerr, "\033[0m");
                    fprintf(outerr, "Parameter dimension is %d at line %d:\n",
                            arg_dim, arg_list->type->loc.first_line);
                    print_tagline(&arg_list->type->loc);
                    fprintf(outerr, "Argument declared at line %d:\n",
                            expr_list->vref->var->loc.first_line);
                    print_tagline(&expr_list->vref->var->loc);
                    fprintf(outerr, "Argument pass is %d at line %d:\n",
                            def_dim-ref_dim, expr_list->vref->loc.first_line);
                    if(ref_dim == 0)
                        print_tagline(&expr_list->type->loc);
                    else
                        print_tagline(&expr_list->vref->ref->loc);
                    fprintf(outerr, "\n");
                }
                else
                {
                    // Check dimension size match
                    struct dim_list *par_dimlist = arg_list->type->dim;
                    struct dim_list *arg_dimlist = expr_list->vref->type->dim;

                    for(; ref_dim!=0; ref_dim--, arg_dimlist=arg_dimlist->next);

                    while((par_dimlist!=0)&&(arg_dimlist!=0))
                    {
                        int par, arg;
                        par = par_dimlist->upper - par_dimlist->lower;
                        arg = arg_dimlist->upper - arg_dimlist->lower;
                        if(par != arg)
                        {
                            fprintf(outerr, "\033[31m");
                            fprintf(outerr, "<Error> Dimension size mismatch\n");
                            fprintf(outerr, "\033[0m");
                            fprintf(outerr, "One of size at line %d:\n",
                                    par_dimlist->loc.first_line);
                            print_tagline(&par_dimlist->loc);
                            fprintf(outerr, "Anther ont size at line %d:\n",
                                    arg_dimlist->loc.first_line);
                            print_tagline(&arg_dimlist->loc);
                            fprintf(outerr, "\n");
                        }
                        par_dimlist = par_dimlist->next;
                        arg_dimlist = arg_dimlist->next;
                    }
                }
            }

            arg_list = arg_list->sibling;
        }

        expr_list = expr_list->sibling;

        // Argument declaration not enough
        if((expr_list!=0)&&(arg_list==0))
        {
            fprintf(outerr, "\033[31m");
            fprintf(outerr, "<Error> parameter are not enough\n");
            fprintf(outerr, "\033[0m");
            fprintf(outerr, "Redundant(?) argument at line %d:\n", expr_list->loc.first_line);
            print_tagline(&expr_list->loc);
            fprintf(outerr, "\n");
        }
    }

    // Expresstion(input arg) not enough
    if(arg_list!=0)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> argument are not enough\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Redundant(?) argument at line %d:\n",
                arg_list->loc.first_line);
        print_tagline(&arg_list->loc);
        fprintf(outerr, "Involved at line %d:\n", finv->loc.first_line);
        print_tagline(&finv->loc);
        fprintf(outerr, "\n");
    }

    if(finv->func != 0)
        finv->ret_type = finv->func->ret_type;
    return ret;
}


int check_finv(struct finv_node *finv)
{
    int ret = 0;

    if(finv->is_checked != 0)
        return 0;
    else
        finv->is_checked = 1;

    ret |= check_finvrefandassigntype(finv);
    ret |= finv_makeupandtypecheck(finv);

    return ret;
}


int check_exprtypeandtypemakeup(struct expr_node *expr)
{
    int ret = 0;

    if(expr->is_checked != 0)
        return 0;
    else
        expr->is_checked = 1;

    switch(expr->mode)
    {
        case CONST_DATA:
            expr->type->type = expr->cont->type;
            break;
        case VARIA_REFE:
            ret |= check_variavailable(expr->vref);
            expr->type->type = expr->vref->type->type;
            break;
        case FUNCT_INVO:
            ret |= check_finv(expr->finv);
            if(expr->finv->func != 0)
                expr->type->type = expr->finv->func->ret_type->type;
            break;
        case EXPRESSION:
            ret = expr_typemakeupandcheck(expr);
            break;
        default:
            break;
    }

    // print_tagline(&expr->type->loc);
    return ret;
}


int check_foriinit(struct for__node *for_)
{
    int from = for_->start;
    int to = for_->end;

    if(from > to)
    {
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> loop parameter lower bound is greater then upper bound\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "Loop parameter from %d to %d at line %d:\n",
                from, to, for_->ploc.first_line);
        print_tagline(&for_->ploc);
        fprintf(outerr, "\n");
    }

    return 0;
}


int check_lhsandrhstype(struct simp_node *p)
{
    struct varirefe_node *lhs = p->lhs;
    struct expr_node *rhs = p->rhs;

    if((lhs->var!=0)&&(lhs->var->type->type!=rhs->type->type))
    {
        if((lhs->var->type->type==REAL_TYPE)&&
            (rhs->type->type==INTE_TYPE))
            return 0;
        fprintf(outerr, "\033[31m");
        fprintf(outerr, "<Error> type mismatch LHS and RHS\n");
        fprintf(outerr, "\033[0m");
        fprintf(outerr, "At line %d:\n", p->loc.first_line);
        fprintf(outerr, "LHS is %s type\n", text[lhs->var->type->type]);
        fprintf(outerr, "RHS is %s type\n", text[rhs->type->type]);
        print_tagline(&p->loc);
        fprintf(outerr, "\n");
    }

    return 0;
}

