#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type.h"
#include "stack.h"

#define STRING_LEN 256

const char *type_void = "void";
const char *type_inte = "integer";
const char *type_real = "real";
const char *type_bool = "boolean";
const char *type_stri = "string";

struct dim_element
{
    int upper;
    int lower;
};

struct type_instance
{
    struct stack *type_s;
    const char *type;
    char string[STRING_LEN];
    int dim_count;
    int is_dimerr;
};


static int add_type(struct type *type, const char *type_str)
{
    type->_inst->type = type_str;

    return 0;
}


static int add_dime(struct type *type, int upper, int lower)
{
    struct stack *ts;
    struct dim_element *de;

    de = malloc(sizeof(struct dim_element));
    assert(de != 0);
    de->upper = upper;
    de->lower = lower;
    ts = type->_inst->type_s;
    ts->push(ts, de);

    if((lower>=upper)||(lower<0)||(upper<0))
        type->_inst->is_dimerr = 1;

    type->_inst->dim_count++;
    return 0;
}


static const char * get_type(struct type *type)
{
    struct stack *ts;
    char *dis;
    struct dim_element *de;
    int size = STRING_LEN;
    int c = 0;

    ts = type->_inst->type_s;
    dis = type->_inst->string;

    if(type->_inst->type == 0)
        return 0;

    if(size > 0)
        snprintf(dis, size, "%s%n", type->_inst->type, &c);
    size = size - c;
    dis = dis+c;

    ts->init_iter(ts, 0);
    de = ts->iterator(ts);
    if((size>0)&&(de!=0))
    {
        snprintf(dis, size, " ");
        size--;
        dis = dis+1;
    }

    for(; (size>0)&&(de!=0); de=ts->iterator(ts))
    {
        snprintf(dis, size, "[%d]%n", de->upper-de->lower+1, &c);
        size = size-c;
        dis = dis+c;
    }

    return type->_inst->string;
}


static int get_dims(struct type *type)
{
    return type->_inst->dim_count;
}


static int is_dimerr(struct type *type)
{
    return type->_inst->is_dimerr;
}


static int dim_element_delete(void *de)
{
    struct dim_element *dim_element = de;

    free(dim_element);

    return 0;
}


struct type * type_create(void)
{
    struct type *ret;

    ret = malloc(sizeof(struct type));
    assert(ret != 0);
    ret->_inst = malloc(sizeof(struct type_instance));
    assert(ret->_inst != 0);
    ret->_inst->type_s = stack_create();
    assert(ret->_inst->type_s != 0);

    ret->_inst->type = 0;
    ret->_inst->string[0] = 0;
    ret->_inst->dim_count = 0;
    ret->_inst->is_dimerr = 0;

    ret->add_type = add_type;
    ret->add_dime = add_dime;
    ret->get_type = get_type;
    ret->get_dims = get_dims;
    ret->is_dimerr = is_dimerr;

    return ret;
}


int type_delete(void *t)
{
    struct type *type = t;

    stack_delete(type->_inst->type_s, dim_element_delete);
    free(type->_inst);
    free(type);

    return 0;
}

