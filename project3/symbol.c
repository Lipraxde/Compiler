#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "symbol.h"
#include "attribute.h"
#include "type.h"

const char *kind_prog = "program";
const char *kind_func = "function";
const char *kind_para = "parameter";
const char *kind_vari = "variable";
const char *kind_forv = "loop_var";
const char *kind_cons = "constant";

struct symbol_instance
{
    char name[IDENT_EFFECTIVE_LEN+1];
    int level;
    const char *kind;
    struct type *type;
    struct attr *attr;
};


static int set_name(struct symbol *symbol, const char *name)
{
    strncpy(symbol->_inst->name, name, IDENT_EFFECTIVE_LEN);

    return 0;
}


static const char * get_name(struct symbol *symbol)
{
    return symbol->_inst->name;
}


static int set_level(struct symbol *symbol, int n)
{
    symbol->_inst->level = n;

    return 0;
}


static int get_level(struct symbol *symbol)
{
    return symbol->_inst->level;
}


static int set_kind(struct symbol *symbol, const char *kind)
{
    symbol->_inst->kind = kind;

    return 0;
}


static const char * get_kind(struct symbol *symbol)
{
    return symbol->_inst->kind;
}


static int set_type(struct symbol *symbol, struct type *type)
{
    symbol->_inst->type = type;

    return 0;
}


static const char * get_type(struct symbol *symbol)
{
    struct type *type;
    const char *ret = 0;

    type = symbol->_inst->type;

    if(type != 0)
        ret = type->get_type(type);

    return ret;
}


static int set_attr(struct symbol *symbol, struct attr *attr)
{
    symbol->_inst->attr = attr;

    return 0;
}


static const char * get_attr(struct symbol *symbol)
{
    struct attr *attr;
    const char *ret = 0;

    attr = symbol->_inst->attr;

    if(attr != 0)
    {
        const char *k = symbol->get_kind(symbol);
        if(k==kind_func)
            ret = attr->get_attr(attr, attr_field_arg);
        else if(k==kind_cons)
            ret = attr->get_attr(attr, attr_field_val);
    }

    return ret;
}


struct symbol * symbol_create(void)
{
    struct symbol *ret;

    ret = malloc(sizeof(struct symbol));
    assert(ret != 0);
    ret->_inst = malloc(sizeof(struct symbol_instance));
    assert(ret->_inst != 0);

    ret->_inst->name[0] = 0;
    ret->_inst->level = 0;
    ret->_inst->kind = 0;
    ret->_inst->type = 0;
    ret->_inst->attr = 0;

    ret->set_name = set_name;
    ret->get_name = get_name;
    ret->set_level = set_level;
    ret->get_level = get_level;
    ret->set_kind = set_kind;
    ret->get_kind = get_kind;
    ret->set_type = set_type;
    ret->get_type = get_type;
    ret->set_attr = set_attr;
    ret->get_attr = get_attr;

    return ret;
}


int symbol_delete(void *s)
{
    struct symbol *symbol = s;

    free(symbol->_inst);
    free(symbol);

    return 0;
}

