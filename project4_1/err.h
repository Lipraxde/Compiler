#ifndef __ERR_H__
#define __ERR_H__

#include "y.tab.h"

#define outerr stdout

int check_redeclar(const char *n1, const char *n2, const YYLTYPE *l1, const YYLTYPE *l2);
int check_progname(const char *file_name, struct program_node *ast);
int check_rettype(struct type_node *ret_type, struct type_node *expr_type, const YYLTYPE *lic);
int check_funcrettypeisscalar(struct type_node *ret_type);

#endif /* __ERR_H__ */
