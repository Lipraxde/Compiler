 #include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "attribute.h"
#include "stack.h"
#include "type.h"

#define STRING_LEN 256

struct attr_element
{
    void *target;
    int type;
};

struct attr_instance
{
    struct stack *attr_s;
    char string[STRING_LEN];
};


static int add_attr(struct attr *attr, void *target, int type)
{
    struct stack *as;
    struct attr_element *ae;

    if(target != 0)
    {
        ae = malloc(sizeof(struct attr_element));
        assert(ae != 0);
        ae->target = target;
        ae->type = type;
        as = attr->_inst->attr_s;
        as->push(as, ae);
    }

    return 0;
}


static const char * get_attr(struct attr *attr, int field)
{
    struct stack *as;
    char *dis;
    struct attr_element *ae;
    int size = STRING_LEN;
    int c = 0;

    as = attr->_inst->attr_s;
    dis = attr->_inst->string;

    as->init_iter(as, 0);
    for(ae=as->iterator(as); (size>0)&&(ae!=0); ae=as->iterator(as))
    {
        c = 0;
        if((ae->type==attr_type)&&(field&attr_field_arg))
        {
            struct type *te = ae->target;
            snprintf(dis, size, "%s, %n", te->get_type(te), &c);
        }
        else if((ae->type==attr_inte)&&(field&attr_field_val))
        {
            snprintf(dis, size, "%d, %n", *(int *)ae->target, &c);
        }
        else if((ae->type==attr_real)&&(field&attr_field_val))
        {
            snprintf(dis, size, "%lf, %n", *(double *)ae->target, &c);
        }
        else if((ae->type==attr_stri)&&(field&attr_field_val))
        {
            snprintf(dis, size, "\"%s\", %n", (const char *)ae->target, &c);
        }
        else if((ae->type==attr_bool)&&(field&attr_field_val))
        {
            snprintf(dis, size, "%s, %n", (*(int *)ae->target==1) ? "true":"false", &c);
        }

        size = size-c;
        dis = dis+c;
    }

    *(dis-2) = 0;   // eliminat ", "

    return attr->_inst->string;
}


static int attr_element_delete(void *ae)
{
    struct attr_element *attr_element = ae;

    free(attr_element);

    return 0;
}


struct attr * attr_create(void)
{
    struct attr *ret;

    ret = malloc(sizeof(struct attr));
    assert(ret != 0);
    ret->_inst = malloc(sizeof(struct attr_instance));
    assert(ret->_inst != 0);
    ret->_inst->attr_s = stack_create();
    assert(ret->_inst->attr_s != 0);

    ret->_inst->string[0] = 0;

    ret->add_attr = add_attr;
    ret->get_attr = get_attr;

    return ret;
}


int attr_delete(void *a)
{
    struct attr *attr = a;

    stack_delete(attr->_inst->attr_s, attr_element_delete);
    free(attr->_inst);
    free(attr);

    return 0;
}
