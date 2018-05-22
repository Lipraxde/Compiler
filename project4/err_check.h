#ifndef __ERR_CHECK_H__
#define __ERR_CHECK_H__

#include "stack.h"
#include "symbol.h"
#include "type.h"

int check_redeclared(struct stack *stack, const char *ident);

int check_progname(const char *prog_name, const char *str);
int check_funcname(struct stack *stack, const char *func_name);
int check_funcrettype(struct type *t);
int check_rettype(struct stack *stack, struct type *ret_t);

int check_type(struct type *t1, struct type *t2);
int check_assign(struct type *l, struct type *r);

int check_arraydim(struct symbol *s);
int check_arrayref(struct symbol *s, int dim);

int check_declared(struct symbol *s, const char *name);

int check_lhs(struct symbol *s, int dim);

int type_coercion(struct type *t1, struct type *t2, struct type **to_t);

#endif /* __ERR_CHECK_H__ */

