#ifndef __MAIN_H__
#define __MAIN_H__

int push_ident(const char *name);
int supply_kind(const char *kind);
int construct_type(void);
int add_type(const char *str);
int add_dim(int upper, int lower);
int supply_type(void);
int next_level(void);
int exit_level(void);
void dump_symbol(void);

#endif /* __MAIN_H__ */

