#ifndef __CODEGEN_H__
#define __CODEGEN_H__

#include "main.h"

extern FILE *outfile;

int code_gen(struct program_node *ast);

#endif /* __CODEGEN_H__ */
