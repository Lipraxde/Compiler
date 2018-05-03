#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__

#define attr_type 0
#define attr_code 1
#define attr_inte 2
#define attr_real 3
#define attr_bool 4
#define attr_stri 5

struct attr_instance;

struct attr
{
    struct attr_instance *_inst;
    int             (*add_attr)(struct attr *self, void *target, int type);
    const char *    (*get_attr)(struct attr *self);
};

struct attr * attr_create(void);
int attr_delete(void *self);

#endif /* __ATTRIBUTE_H__ */
