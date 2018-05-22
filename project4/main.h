#ifndef __MAIN_H__
#define __MAIN_H__

int is_error;
char prog_name[256];
struct symbol *default_symbol;
struct type *default_type;

int push_ident(const char *name);
int supply_kind(const char *kind);

int construct_attr(void);
int add_cons_attr(void *target, const char *type, int is_negative);
int supply_cons_attr(void);
int supply_func_attr(void); /* Add parameter attribute to function in add_type. */

int construct_type(void);
int add_type(const char *str);
int add_dim(int upper, int lower);
int supply_type(void);

int next_level(void);
int exit_level(void);
void dump_symbol(void);

struct symbol * find_variable(const char *name);

#endif /* __MAIN_H__ */

