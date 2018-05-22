#ifndef __ERR_H__
#define __ERR_H__

#include "y.tab.h"

int check_redeclar(const char *n1, const char *n2, const YYLTYPE *l1, const YYLTYPE *l2);

#endif /* __ERR_H__ */
