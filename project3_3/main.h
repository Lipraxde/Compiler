#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdbool.h>
#include "y.tab.h"

enum scalar_type
{
    VOID_TYPE = 1,
    INTE_TYPE,
    REAL_TYPE,
    BOOL_TYPE,
    TEXT_TYPE
};

struct const_node
{
    union
    {
        int     int_val;
        double  real_val;
        bool    bool_val;
        char   *text_val;
    };
    enum scalar_type type;
    YYLTYPE loc;
};

struct dim_list
{
    int lower;
    int upper;
    struct dim_list *next;
    YYLTYPE loc;
};

struct type_node
{
    enum scalar_type type;
    struct dim_list *dim;
    YYLTYPE loc;
};

struct varirefe_node
{
    const char *name;
    struct type_node *type;
    struct expr_node *ref;
    YYLTYPE loc;
};

enum expr_opt
{
    opt_add = 1, opt_del, opt_mul, opt_div, opt_mod, opt_nega,
    cmp_less, cmp_leq, cmp_gt, cmp_geq, cmp_eq, cmp_neq,
    bool_or, bool_and, bool_not
};

enum expr_mode
{
    CONST_DATA = 1,
    VARIA_REFE,
    FUNCT_INVO,
    EXPRESSION
};

struct expr_node
{
    union
    {
        struct const_node    *cont;
        struct varirefe_node *vref;
        struct finv_node     *finv;
        struct
        {
            struct expr_node *lsite;
            struct expr_node *rsite;
            enum expr_opt     opt;
        };
    };
    struct type_node *type;
    enum expr_mode mode;
    struct expr_node *sibling;
    YYLTYPE loc;
};

enum state_mode
{
    COMP_STAT = 1,
    SIMP_STAT,
    COND_STAT,
    WHIL_STAT,
    FOR__STAT,
    FINV_STAT,
    RET__STAT
};

struct simp_node
{
    struct varirefe_node *lhs;
    struct expr_node     *rhs;
    YYLTYPE loc;
};

struct cond_node
{
    struct expr_node         *condition;
    struct statment_node     *tpath;
    struct statment_node     *fpath;
    YYLTYPE loc;
};

struct whil_node
{
    struct expr_node         *condition;
    struct statment_node     *stat;
    YYLTYPE loc;
};

struct for__node
{
    struct variable_node     *i;
    int start;
    int end;
    struct statment_node     *stat;
    YYLTYPE loc;
};

struct finv_node
{
    const char               *name;
    struct expr_node         *exprs;
    struct type_node         *ret_type;
    YYLTYPE loc;
};

struct ret__node
{
    struct expr_node         *expr;
    YYLTYPE loc;
};

struct statment_node
{
    union
    {
        struct compound_node *comp;
        struct simp_node     *simp;
        struct cond_node     *cond;
        struct whil_node     *whil;
        struct for__node     *for_;
        struct finv_node     *finv;
        struct ret__node     *ret_;
    };
    enum state_mode       mode;
    struct statment_node *sibling;
    YYLTYPE loc;
};

struct variable_node
{
    const char *name;
    struct type_node     *type;
    struct const_node    *const_val;
    struct variable_node *sibling;
    YYLTYPE loc;
};

struct function_node
{
    const char *name;
    struct variable_node *arg;
    struct type_node     *ret_type;
    struct compound_node *comp;
    struct function_node *sibling;
    YYLTYPE loc;
};

struct compound_node
{
    struct variable_node *loc_var;
    struct statment_node *stat;
    YYLTYPE loc;
};

struct program_node
{
    const char *name;
    struct variable_node *vacd;
    struct function_node *func;
    struct compound_node *comp;
    YYLTYPE loc;
};

#endif /* __MAIN_H__ */

