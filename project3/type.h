#ifndef __TYPE_H__
#define __TYPE_H__

const char *type_void;
const char *type_inte;
const char *type_real;
const char *type_bool;
const char *type_stri;

struct type_instance;

struct type
{
    struct type_instance *_inst;
    int             (*add_type)(struct type *self, const char *type);
    int             (*add_dime)(struct type *self, int upper, int lower);
    const char *    (*get_type)(struct type *self);
};

struct type * type_create(void);
int type_delete(void *self);

#endif /* __TYPE_H__ */

