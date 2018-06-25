#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdbool.h>
#include <stdio.h>
#include "y.tab.h"

struct symbol
{
	void *data;
	int level;
	int  whitch_struct;
};

#define STRUCT_PROG 1
#define STRUCT_VARI 2
#define STRUCT_FUNC 3

extern char *prog_line[];
extern struct symbol sym_table[];
extern int sym_count;
FILE *outfile;

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
    YYLTYPE loc;
    union
    {
        int     int_val;
        double  real_val;
        bool    bool_val;
        char   *text_val;
    };
    enum scalar_type type;
};

struct dim_list
{
    YYLTYPE loc;
    int lower;
    int upper;
    struct dim_list *next;
};

struct type_node
{
    YYLTYPE loc;
    enum scalar_type type;
    struct dim_list *dim;
};

struct varirefe_node
{
    YYLTYPE loc;
    const char *name;
    struct expr_node         *ref;
    struct type_node         *type;
    struct variable_node     *var;
    int allow_arrayaccess;
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
    YYLTYPE loc;
    int is_checked;
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
    YYLTYPE loc;
    struct varirefe_node *lhs;
    struct expr_node     *rhs;
};

struct cond_node
{
    YYLTYPE loc;
    struct expr_node         *condition;
    struct statment_node     *tpath;
    struct statment_node     *fpath;
};

struct whil_node
{
    YYLTYPE loc;
    struct expr_node         *condition;
    struct statment_node     *stat;
};

struct for__node
{
    YYLTYPE loc;
    struct variable_node     *i;
    int start;
    int end;
    YYLTYPE ploc;
    struct statment_node     *stat;
};

struct finv_node
{
    YYLTYPE loc;
    const char               *name;
    int is_checked;
    struct expr_node         *exprs;
    struct type_node     *ret_type;
    struct function_node     *func;
};

struct ret__node
{
    YYLTYPE loc;
    struct expr_node         *expr;
};

struct statment_node
{
    YYLTYPE loc;
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
};

struct variable_node
{
    YYLTYPE loc;
    const char *name;
    struct type_node     *type;
    struct const_node    *const_val;
    struct variable_node *sibling;
    int var_addr; // -1 = global, n = %n
    int var_mode; // 0 = variable, 1 = constant, 2 = loop parameter
};

struct function_node
{
    YYLTYPE loc;
    const char *name;
    YYLTYPE end_loc;
    const char *end_name;
    struct variable_node *arg;
    struct type_node     *ret_type;
    struct compound_node *comp;
    struct function_node *sibling;
    int loc_varcount;
};

struct compound_node
{
    YYLTYPE loc;
    struct variable_node *loc_var;
    struct statment_node *stat;
};

struct program_node
{
    YYLTYPE loc;
    const char *name;
    YYLTYPE end_loc;
    const char *end_name;
    struct type_node     *type;
    struct variable_node *vacd;
    struct function_node *func;
    struct compound_node *comp;
    int loc_varcount;
};

struct base_node
{
    YYLTYPE loc;
    const char *name;   // Node may not have name information.
};

#endif /* __MAIN_H__ */

