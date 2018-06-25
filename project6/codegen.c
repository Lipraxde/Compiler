#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codegen.h"
#include "main.h"

#define TEXT_TYPE_LEN 256

static int limit_stack = 15;
extern struct program_node *ast;

static long code_expr(struct expr_node *expr);
static int code_finv(struct finv_node *finv);
static int code_statment(struct statment_node *stat);
static int code_compound(struct compound_node *comp);

static void write_code(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vfprintf(outfile, fmt, args);
    va_end(args);
}


static long uniq_number()
{
    static long count = 1;
    return count++;
}


static const char *type_tostring(struct type_node *type)
{
    int dim_conut = 0;
    static char type_string[512];
    char *string;

    string = type_string;
    *string = 0;

    for(struct dim_list *dim=type->dim; dim!=0; dim=dim->next)
    {
        sprintf(string, "[%d x ", dim->upper-dim->lower+1);
        for(; *string!=0; string++);
        dim_conut++;
    }

    switch(type->type)
    {
        case REAL_TYPE:
            sprintf(string, "float");
            break;
        case TEXT_TYPE:
            sprintf(string, "[%d x i8]", TEXT_TYPE_LEN);
            break;
        case INTE_TYPE:
        case BOOL_TYPE:
        default:
            sprintf(string, "i32");
            break;
    }
    for(; *string!=0; string++);

    while(dim_conut--!=0)
        sprintf(string++, "]");

    return type_string; 
}


static const char *type_tolower(struct type_node *type)
{

    return (type->type == INTE_TYPE) ? "i":
            (type->type == REAL_TYPE) ? "f":
            (type->type == BOOL_TYPE) ? "i":"a";
}


static const char *const_tostring(struct const_node *c)
{
    static char const_string[4*TEXT_TYPE_LEN+50];
    char *p = const_string;

    *p = 0;
    switch(c->type)
    {
        case REAL_TYPE:
            {
                double b = (double)(float)c->real_val;
                sprintf(p, "0x%lx", *(long *)&b);
            }
            break;
        case TEXT_TYPE:
            sprintf(const_string, "c\"%s", c->text_val);
            for(; *p!=0; p++);
            for(int i=0; i<TEXT_TYPE_LEN-strlen(c->text_val); i++)
            {
                sprintf(p, "\\00");
                for(; *p!=0; p++);
            }
            sprintf(p, "\"");
            break;
        case INTE_TYPE:
            sprintf(p, "%d", c->int_val);
            break;
        case BOOL_TYPE:
            sprintf(p, "%d", c->bool_val==true ? 1:0);
            break;
        default:
            break;
    }

    return const_string;
}

static int code_globalvari(struct variable_node *vacd)
{
    int ret = 0;
    int wrote = 0;

    for(; vacd!=0; vacd=vacd->sibling)
    {
        write_code("@%s = dso_local global ", vacd->name);
        write_code("%s ", type_tostring(vacd->type));

        int align = 4;
        if(vacd->var_mode == 0)
            write_code("zeroinitializer");
        else if(vacd->var_mode == 1)
            write_code("%s", const_tostring(vacd->const_val));
        /* gloabal could not have loop variable */

        write_code(", align %d\n", align);
        wrote = 1;
    }

    if(wrote == 1)
        write_code("\n");
    return ret;
}


static int code_localvari(struct variable_node *vacd)
{
    int ret = 0;
    int wrote = 0;

    for(; vacd!=0; vacd=vacd->sibling)
    {
        if(vacd->type->type == TEXT_TYPE)
        {
            fprintf(stdout, "<Warning> no string variable\n");
            break;
        }

        write_code("\t%%%s = alloca ", vacd->name);
        write_code("%s", type_tostring(vacd->type));
        write_code(", align 4\n");

        if(vacd->var_mode == 1)
        {
            write_code("\tstore ");
            write_code("%s ", type_tostring(vacd->type));
            write_code("%s, ", const_tostring(vacd->const_val));
            write_code("%s* ", type_tostring(vacd->type));
            write_code("%%%s", vacd->name);
            write_code(", align 4\n");
        }

        wrote = 1;
    }

    if(wrote == 1)
        write_code("\n");
    return ret;
}


static long code_loadconst(struct const_node *cont)
{
    int uniq_temp = 0;
    static int load_type = 0;

    uniq_temp = uniq_number();
    if(cont->type == INTE_TYPE)
    {
        write_code("\t%%.%ld = alloca i32, align 4\n", uniq_temp);
        write_code("\tstore i32 %d, i32* %%.%ld, align 4\n", cont->int_val, uniq_temp);
    }
    else if(cont->type == REAL_TYPE)
    {
        double b = (double)(float)cont->real_val;
        write_code("\t%%.%ld = alloca float, align 4\n", uniq_temp);
        write_code("\tstore float 0x%llx, float* %%.%ld, align 4\n",
                    *(long *)(&b), uniq_temp);
    }
    else if(cont->type == BOOL_TYPE)
    {
        write_code("\t%%.%ld = alloca i32, align 4\n", uniq_temp);
        write_code("\tstore i32 %d, i32* %%.%ld, align 4\n",
                    cont->bool_val==true ? 1:0, uniq_temp);
    }
/*    else if(cont->type == TEXT_TYPE)
    {
    }*/
    else if(load_type == 0)
    {
        fprintf(stdout, "<Warning> load constant type error\n");
        load_type = 1;
    }

    return uniq_temp;
}


static int code_loadvref(struct varirefe_node *vref)
{
    int ret = 0;

    if(vref->var->var_mode == 1)
        ret |= code_loadconst(vref->var->const_val);
    else
    {
        if(vref->var->var_addr == 0) // global variable
        {
            write_code("\tgetstatic %s/%s %s\n", ast->name, vref->var->name,
                                                    type_tostring(vref->var->type));
        }
        else
        {
            write_code("\t%sload %d\n", type_tolower(vref->var->type),
                                        vref->var->var_addr-1);
        }
    }

    return ret;
}


static int code_storevref(struct varirefe_node *vref)
{
    int ret = 0;

    if(vref->var->var_addr == 0) // global variable
    {
        write_code("\tputstatic %s/%s %s\n", ast->name, vref->name,
                                                type_tostring(vref->type));
    }
    else
    {
        write_code("\t%sstore %d\n", type_tolower(vref->type),
                                        vref->var->var_addr-1);
    }

    return ret;
}


static int code_opt(struct expr_node *expr)
{
    int ret = 0;
    int convert_to_real = 0;
    long uniq_trueid, uniq_falseid;
    const char *cmp_str;

    if(expr->lsite != 0)
    {
        ret |= code_expr(expr->lsite);
        if((expr->lsite->type->type==INTE_TYPE)&&
            (expr->rsite->type->type==REAL_TYPE))
        {
            write_code("\ti2f\n");
            convert_to_real = 1;
        }
    }

    ret |= code_expr(expr->rsite);
    if((expr->rsite->type->type==INTE_TYPE)&&
        (expr->lsite != 0)&&
        (expr->lsite->type->type==REAL_TYPE))
    {
        write_code("\ti2f\n");
        convert_to_real = 1;
    }

    switch(expr->opt)
    {
        case opt_add:
            write_code("\t%sadd\n", type_tolower(expr->type));
            break;
        case opt_del:
            write_code("\t%ssub\n", type_tolower(expr->type));
            break;
        case opt_mul:
            write_code("\t%smul\n", type_tolower(expr->type));
            break;
        case opt_div:
            write_code("\t%sdiv\n", type_tolower(expr->type));
            break;
        case opt_nega:
            write_code("\t%sneg\n", type_tolower(expr->type));
            break;
        case opt_mod:
            write_code("\t%srem\n", type_tolower(expr->type));
            break;
        case cmp_less:
            cmp_str = "iflt";
            goto CMP_COMMON;
        case cmp_leq:
            cmp_str = "ifle";
            goto CMP_COMMON;
        case cmp_gt:
            cmp_str = "ifgt";
            goto CMP_COMMON;
        case cmp_geq:
            cmp_str = "ifge";
            goto CMP_COMMON;
        case cmp_eq:
            cmp_str = "ifeq";
            goto CMP_COMMON;
        case cmp_neq:
            cmp_str = "ifne";
CMP_COMMON:
            if((convert_to_real==0)&&(expr->rsite->type->type==INTE_TYPE))
                write_code("\tisub\n");
            else
                write_code("\tfcmpl\n");
            
            uniq_trueid = uniq_number();
            uniq_falseid = uniq_number();

            write_code("\t%s LCMP_%ld\n", cmp_str, uniq_trueid);
            write_code("\ticonst_0\n");
            write_code("\tgoto LCMP_%ld\n", uniq_falseid);
            write_code("LCMP_%ld:\n", uniq_trueid);
            write_code("\ticonst_1\n");
            write_code("LCMP_%ld:\n", uniq_falseid);
            break;
        case bool_or:
            write_code("\tior\n");
            break;
        case bool_and:
            write_code("\tiand\n");
            break;
        case bool_not:
            write_code("\ticonst_1\n");
            write_code("\tixor\n");
            break;
        default:
            break;
    }

    return ret;
}


static long code_expr(struct expr_node *expr)
{
    long uniq_temp = 0;
    static int expr_unknow = 0;

    while(expr != 0)
    {
        switch(expr->mode)
        {
            case CONST_DATA:
                uniq_temp = code_loadconst(expr->cont);
                break;
/*            case VARIA_REFE:
                uniq_temp = code_loadvref(expr->vref);
                break;
            case FUNCT_INVO:
                uniq_temp = code_finv(expr->finv);
                break;
            case EXPRESSION:
                uniq_temp = code_opt(expr);
                break;*/
            default:
                if(expr_unknow == 0)
                {
                    fprintf(stdout, "<Warning> unknow expression\n");
                    expr_unknow = 1;
                }
                break;
        }

        expr = expr->sibling;
    }

    return uniq_temp;
}


static int code_simple(struct simp_node *simp)
{
    long uniq_temp = 0;
    long uniq_obj = 0;

    if(simp->lhs == 0)         // print
    {
        uniq_temp = code_expr(simp->rhs);
        uniq_obj = uniq_number();
        switch(simp->rhs->type->type)
        {
            case INTE_TYPE:
                write_code("\t%%.%ld = load i32, i32* %%.%ld, align 4", uniq_obj, uniq_temp);
                write_code("\tcall void @print_int(i32 signext %%.%ld)\n", uniq_obj);
                break;
            case REAL_TYPE:
                write_code("\t%%.%ld = load float, float* %%.%ld, align 4", uniq_obj, uniq_temp);
                write_code("\tcall void @print_real(float %%.%ld)\n", uniq_obj);
                break;
            case BOOL_TYPE:
                write_code("\t%%.%ld = load i32, i32* %%.%ld, align 4", uniq_obj, uniq_temp);
                write_code("\tcall void @print_bool(i32 signext %%.%ld)\n", uniq_obj);
                break;
/*            case TEXT_TYPE:
                // write_code("%%.%ld = load i32, i32* %%.%ld, align 4", uniq_obj, uniq_temp);
                write_code("\tcall void @print_text(i8* getelementptr inbounds");
                write_code("([%d x i8], [%d x i8]* %%.%ld, i32 0, i32 0))\n",
                            TEXT_TYPE_LEN, TEXT_TYPE_LEN, uniq_obj);
                break;*/
            default:
                fprintf(stdout, "<Warning> unknow type\n");
                break;
        }
    }
/*    else if(simp->rhs == 0)    // read
    {
        write_code("\tgetstatic %s/_sc Ljava/util/Scanner;\n", ast->name);
        write_code("\tinvokevirtual java/util/Scanner/next%s()%s\n", 
                    (simp->lhs->type->type == INTE_TYPE) ? "Int":
                    (simp->lhs->type->type == REAL_TYPE) ? "Float":
                    (simp->lhs->type->type == BOOL_TYPE) ? "Boolean":
                    (simp->lhs->type->type == TEXT_TYPE) ? "String":"", 
                    type_tostring(simp->lhs->type));
        ret |= code_storevref(simp->lhs);
    }
    else
    {
        ret |= code_expr(simp->rhs);
        if((simp->rhs->type->type==INTE_TYPE)&&
            (simp->lhs->type->type==REAL_TYPE))
            write_code("\ti2f\n");
        ret |= code_storevref(simp->lhs);
    }
*/
    return 0;
}


static int code_condition(struct cond_node *cond)
{
    int ret = 0;
    long uniq_id = uniq_number();

    ret |= code_expr(cond->condition);
    write_code("\tifeq LFALSE_%ld\n", uniq_id);
    ret |= code_statment(cond->tpath);
    write_code("\tgoto LEXIT_%ld\n", uniq_id);
    write_code("LFALSE_%ld:\n", uniq_id);
    ret |= code_statment(cond->fpath);
    write_code("LEXIT_%ld:\n", uniq_id);

    return ret;
}


static int code_while(struct whil_node *whil)
{
    int ret = 0;
    long uniq_id = uniq_number();

    write_code("LBEGIN_%ld:\n", uniq_id);
    ret |= code_expr(whil->condition);
    write_code("\tifeq LEXIT_%ld\n", uniq_id);
    ret |= code_statment(whil->stat);
    write_code("\tgoto LBEGIN_%ld\n", uniq_id);
    write_code("LEXIT_%ld:\n", uniq_id);

    return ret;
}


static int code_for(struct for__node *for_)
{
    int ret = 0;
    long uniq_id = uniq_number();

    write_code("\tsipush %d\n", for_->start);
    write_code("\tistore %d\n", for_->i->var_addr-1);

    write_code("LBEGIN_%ld:\n", uniq_id);
    write_code("\tiload %d\n", for_->i->var_addr-1);
    write_code("\tsipush %d\n", for_->end);
    write_code("\tisub\n");
    write_code("\tifgt LEXIT_%ld\n", uniq_id);
    ret |= code_statment(for_->stat);
    // loop variable add 1.
    write_code("\tiload %d\n", for_->i->var_addr-1);
    write_code("\tsipush 1\n");
    write_code("\tiadd\n");
    write_code("\tistore %d\n", for_->i->var_addr-1);
    write_code("\tgoto LBEGIN_%ld\n", uniq_id);
    write_code("LEXIT_%ld:\n", uniq_id);

    return ret;
}


static int code_finv(struct finv_node *finv)
{
    int ret = 0;

    ret |= code_expr(finv->exprs);
    //invokestatic test1/add(II)I"
    write_code("\tinvokestatic %s/%s(", ast->name, finv->name);
    for(struct variable_node *arg=finv->func->arg; arg!=0; arg=arg->sibling)
        write_code("%s", type_tostring(arg->type));
    write_code(")%s\n", type_tostring(finv->func->ret_type));

    return ret;
}


static int code_return(struct ret__node *ret_)
{
    struct type_node *type = ret_->expr->type;

    if(type->type != VOID_TYPE)
    {
        code_expr(ret_->expr);
        write_code("\t%sreturn\n", type_tolower(type));
        return 0;
    }
    else
        return 1;
}


static int code_statment(struct statment_node *stat)
{
    int ret = 0;
    static int stat_unknow = 0;

    while(stat != 0)
    {
        switch(stat->mode)
        {
            case COMP_STAT:
                // ret |= code_compound(stat->comp);
                fprintf(stdout, "<Warning> no inside compound\n");
                break;
            case SIMP_STAT:
                ret |= code_simple(stat->simp);
                break;
/*            case COND_STAT:
                ret |= code_condition(stat->cond);
                break;
            case WHIL_STAT:
                ret |= code_while(stat->whil);
                break;
            case FOR__STAT:
                ret |= code_for(stat->for_);
                break;
            case FINV_STAT:
                ret |= code_finv(stat->finv);
                break;
            case RET__STAT:
                ret |= code_return(stat->ret_);
                break;*/
            default:
                if(stat_unknow == 0)
                {
                    fprintf(stdout, "<Warning> unknow statement\n");
                    stat_unknow = 1;
                }
                ret = 1;
                break;
        }

        stat = stat->sibling;
    }

    return ret;
}


static int code_compound(struct compound_node *comp)
{
    int ret = 0;

    ret |= code_statment(comp->stat);

    return ret;
}


static int code_function(struct function_node *func)
{
    int ret = 0;

    for(; func!=0; func=func->sibling)
    {
        write_code(".method public static %s(", func->name);
        for(struct variable_node *arg=func->arg; arg!=0; arg=arg->sibling)
            write_code("%s", type_tostring(arg->type));
        write_code(")%s\n", type_tostring(func->ret_type));

        write_code(".limit stack %d\n", limit_stack);
        write_code(".limit locals %d\n", func->loc_varcount);

        ret |= code_compound(func->comp);

        if(func->ret_type->type == VOID_TYPE)
            write_code("\treturn\n");
        else    // Avoid label at last.
            write_code("\tnop\n");
        write_code(".end method\n\n");
    }

    return ret;
}


int code_gen(struct program_node *ast)
{
    int ret = 0;

    write_code("; ModuleID = '%s.p'\n", ast->name);
    write_code("source_filename = \"%s.p\"\n", ast->name);
    write_code("target datalayout = \"e-m:e-p:64:64-i64:64-i128:128-n64-S128\"\n\n");

    ret |= code_globalvari(ast->vacd);

    // declared at help.ll
    write_code("declare dso_local void @print_real(float)\n");
    write_code("declare dso_local void @print_int(i32 signext)\n");
    write_code("declare dso_local void @print_bool(i32 signext)\n");
    write_code("declare dso_local void @print_text(i8*)\n\n");

//     ret |= code_function(ast->func);

    write_code("define dso_local signext i32 @main(i32 signext, i8**) {\n");
    // No command line argument
    // write_code("\t%3 = alloca i32, align 4\n");
    // write_code("\t%4 = alloca i8**, align 8\n");
    // write_code("\tstore i32 %0, i32* %3, align 4\n");
    // write_code("\tstore i8** %1, i8*** %4, align 8\n");

    struct variable_node *loc_var = ast->comp->loc_var;
    code_localvari(loc_var);

    ret |= code_compound(ast->comp);

    write_code("\tret i32 0\n");
    write_code("}\n\n");
    return 0;
}

