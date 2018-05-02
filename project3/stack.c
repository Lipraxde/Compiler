#include <assert.h>
#include <stdlib.h>
#include "stack.h"

struct list
{
    void *data;
    struct list *next;
    struct list *perv;
};

struct stack_instance
{
    struct list *head;      // Stack head
    struct list *tail;      // Stack tail
    int count;              // How much element in stack
    struct list *now_iter;  // Now iterate element
    int iter_n;             // Iterate director
};


static int push(struct stack *stack, void *data)
{
    struct list *new;
    struct list *old_tail;

    new = malloc(sizeof(struct list));
    assert(new != 0);

    old_tail = stack->_inst->tail;
    old_tail->data = data;
    old_tail->next = new;
    new->data = 0;
    new->next = new;
    new->perv = old_tail;

    stack->_inst->tail = new;
    stack->_inst->count++;

    return 0;
}


static void *pop(struct stack *stack)
{
    void *ret = 0;
    struct list *new;
    struct list *old_tail;

    if(stack->_inst->count > 0)
    {
        old_tail = stack->_inst->tail;
        stack->_inst->tail = old_tail->perv;
        new = stack->_inst->tail;
        ret = new->data;

        free(old_tail);
        new->data = 0;
        new->next = new;

        stack->_inst->count--;
    }

    return ret;
}


static int init_iter(struct stack *stack, int n)
{
    struct list *target;

    stack->_inst->iter_n = n;

    if(n >= 0)
    {
        target = stack->_inst->head;
        for(; n!=0; n--)
            target = target->next;
    }
    else
    {
        target = stack->_inst->tail;
        for(; n!=0; n++)
            target = target->perv;
    }

    stack->_inst->now_iter = target;

    return 0;
}


static void *iterator(struct stack *stack)
{
    void *ret;

    ret = stack->_inst->now_iter->data;

    if(stack->_inst->iter_n >= 0)
        stack->_inst->now_iter = stack->_inst->now_iter->next;
    else
        stack->_inst->now_iter = stack->_inst->now_iter->perv;

    return ret;
}


struct stack *stack_create(void)
{
    struct stack *ret;
    struct list *i1;
    struct list *i2;

    ret = malloc(sizeof(struct stack));
    assert(ret != 0);
    ret->_inst = malloc(sizeof(struct stack_instance));
    assert(ret->_inst != 0);

    i1 = malloc(sizeof(struct list));
    assert(i1 != 0);
    i2 = malloc(sizeof(struct list));
    assert(i2 != 0);

    i1->data = 0;
    i1->next = i2;
    i1->perv = i1;

    i2->data = 0;
    i2->next = 0;
    i2->perv = i1;

    ret->_inst->head = i2;
    ret->_inst->tail = i2;
    ret->_inst->count = 0;
    ret->_inst->now_iter = i2;
    ret->_inst->iter_n = 0;

    ret->push = push;
    ret->pop = pop;
    ret->init_iter = init_iter;
    ret->iterator = iterator;

    return ret;
}


int stack_delete(struct stack * stack, int (*destroyer)(void *))
{
    int ret = 0;
    void *temp;

    while(1)
    {
        temp = stack->pop(stack);
        if(temp == 0)
            break;
        if(destroyer != 0)
            ret = destroyer(temp);
        if(ret != 0)
            return ret;
    }

    free(stack->_inst->head->perv);
    free(stack->_inst->head);
    free(stack->_inst);
    free(stack);

    return ret;
}

