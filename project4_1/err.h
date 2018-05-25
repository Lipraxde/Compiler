#ifndef __ERR_H__
#define __ERR_H__

#include "main.h"
#include "y.tab.h"

#define outerr stdout

int check_redeclar(const char *n1, const char *n2, const YYLTYPE *l1, const YYLTYPE *l2);
int check_progname(const char *file_name, struct program_node *ast);
int check_rettype(struct type_node *ret_type, struct type_node *expr_type, const YYLTYPE *lic);
int check_funcrettypeisscalar(struct type_node *ret_type);
int check_typematch(struct type_node *type, enum scalar_type scalar[], int n);
int check_variavailable(struct varirefe_node *varr);
int check_variwriteable(struct varirefe_node *varr);
int check_finv(struct finv_node *expr);
int check_exprtypeandtypemakeup(struct expr_node *expr);
int check_foriinit(struct for__node *for_);
int check_lhsandrhstype(struct simp_node *p);

#endif /* __ERR_H__ */
