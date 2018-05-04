#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include "attribute.h"
#include "type.h"

#define IDENT_EFFECTIVE_LEN 32

const char *kind_prog;
const char *kind_func;
const char *kind_para;
const char *kind_vari;
const char *kind_forv;
const char *kind_cons;

struct symbol_instance;

struct symbol
{
    struct symbol_instance *_inst;
    int             (*set_name)(struct symbol *self, const char *name); // Max length = 32
    const char *    (*get_name)(struct symbol *self);
    int             (*set_level)(struct symbol *self, int n);
    int             (*get_level)(struct symbol *self);
    int             (*set_kind)(struct symbol *self, const char *kind);
    const char *    (*get_kind)(struct symbol *self);
    int             (*set_type)(struct symbol *self, struct type *type);
    const char *    (*get_type)(struct symbol *self);
    int             (*set_attr)(struct symbol *self, struct attr *attr);
    const char *    (*get_attr)(struct symbol *self);
};

struct symbol * symbol_create(void);
int symbol_delete(void *self);

#endif /* __SYMBOL_H__ */

