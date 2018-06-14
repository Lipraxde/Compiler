#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codegen.h"
#include "main.h"

static int limit_stack = 15;
extern struct program_node *ast;

static int code_expr(struct expr_node *expr);
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
    static int warn_dim = 0;

    if(type->dim != 0)
    {
        if(warn_dim == 0)
            fprintf(stdout, "<Warning> variable dimension is not support\n");
        warn_dim = 1;
    }

    return (type->type == INTE_TYPE) ? "I":
            (type->type == REAL_TYPE) ? "F":
            (type->type == BOOL_TYPE) ? "Z":
            (type->type == TEXT_TYPE) ? "Ljava/lang/String;":
            (type->type == VOID_TYPE) ? "V":"";
}


static const char *type_tolower(struct type_node *type)
{

    return (type->type == INTE_TYPE) ? "i":
            (type->type == REAL_TYPE) ? "f":
            (type->type == BOOL_TYPE) ? "i":"a";
}


static int code_globalvari(struct variable_node *vacd)
{
    int ret = 0;
    int wrote = 0;
    static int warn_str = 0;

    for(; vacd!=0; vacd=vacd->sibling)
    {
        if(vacd->var_mode == 1)
            continue;
        // if vacd is variable declaration, not constant
        if(vacd->type->type == TEXT_TYPE)
        {
            if(warn_str == 0)
                fprintf(stdout, "<Warning> string variable is not support\n");
            ret = 1;
            warn_str = 1;
            continue;
        }

        write_code(".field public static %s ", vacd->name);
        write_code("%s\n", type_tostring(vacd->type));
        wrote = 1;
    }

    if(wrote == 1)
        write_code("\n");
    return ret;
}


static int code_loadconst(struct const_node *cont)
{
    int ret = 0;
    static int load_type = 0;

    if(cont->type == INTE_TYPE)
        write_code("\tsipush %d\n", cont->int_val);
    else if(cont->type == REAL_TYPE)
        write_code("\tldc %f\n", cont->real_val);
    else if(cont->type == BOOL_TYPE)
        write_code("\ticonst_%s\n", (cont->bool_val == true) ? "1":"0");
    else if(cont->type == TEXT_TYPE)
        write_code("\tldc \"%s\"\n", cont->text_val);
    else if(load_type == 0)
    {
        fprintf(stdout, "<Warning> load constant type error\n");
        load_type = 1;
        ret = 1;
    }
    else
        ret = 1;

    return ret;
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
            if(convert_to_real == 0)
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


static int code_expr(struct expr_node *expr)
{
    int ret = 0;
    static int expr_unknow = 0;

    while(expr != 0)
    {
        switch(expr->mode)
        {
            case CONST_DATA:
                ret |= code_loadconst(expr->cont);
                break;
            case VARIA_REFE:
                ret |= code_loadvref(expr->vref);
                break;
            case FUNCT_INVO:
                ret |= code_finv(expr->finv);
                break;
            case EXPRESSION:
                ret |= code_opt(expr);
                break;
            default:
                if(expr_unknow == 0)
                {
                    fprintf(stdout, "<Warning> unknow expression\n");
                    expr_unknow = 1;
                }
                ret = 1;
                break;
        }

        expr = expr->sibling;
    }

    return ret;
}


static int code_simple(struct simp_node *simp)
{
    int ret = 0;

    if(simp->lhs == 0)         // print
    {
        write_code("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        ret |= code_expr(simp->rhs);
        write_code("\tinvokevirtual java/io/PrintStream/print(%s)V\n",
                    type_tostring(simp->rhs->type));
    }
    else if(simp->rhs == 0)    // read
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
        ret |= code_storevref(simp->lhs);
    }

    return 0;
}


static int code_condition(struct cond_node *cond)
{
    int ret = 0;
    int uniq_id = uniq_number();

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
    int uniq_id = uniq_number();

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
    int uniq_id = uniq_number();

    write_code("\tsipush %d\n", for_->start);
    write_code("\tistore %d\n", for_->i->var_addr-1);

    write_code("LBEGIN_%ld:\n", uniq_id);
    write_code("\tiload %d\n", for_->i->var_addr-1);
    write_code("\tsipush %d\n", for_->end);
    write_code("\tisub\n");
    write_code("\tifge LEXIT_%ld\n", uniq_id);
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
                ret |= code_compound(stat->comp);
                break;
            case SIMP_STAT:
                ret |= code_simple(stat->simp);
                break;
            case COND_STAT:
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
                break;
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
        write_code(".limit locals %d\n", func->loc_varcount+1);

        ret |= code_compound(func->comp);

        if(func->ret_type->type == VOID_TYPE)
            write_code("\treturn\n");
        write_code(".end method\n\n");
    }

    return ret;
}


int code_gen(struct program_node *ast)
{
    int ret = 0;

    write_code("; %s.j\n", ast->name);
    write_code(".class public %s\n", ast->name);
    write_code(".super java/lang/Object\n\n");

    write_code(".field public static _sc Ljava/util/Scanner;\n");
    ret |= code_globalvari(ast->vacd);
    ret |= code_function(ast->func);

    write_code(".method public static main([Ljava/lang/String;)V\n");
    write_code(".limit stack %d\n", limit_stack);
    write_code(".limit locals %d\n", ast->loc_varcount+1);
    
    // init read stream
    write_code("\tnew java/util/Scanner\n");
    write_code("\tdup\n");
    write_code("\tgetstatic java/lang/System/in Ljava/io/InputStream;\n");
    write_code("\tinvokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V\n");
    write_code("\tputstatic %s/_sc Ljava/util/Scanner;\n", ast->name);

    ret |= code_compound(ast->comp);

    write_code("\treturn\n");
    write_code(".end method\n");
    return 0;
}

