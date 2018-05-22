#ifndef __STACK_H__
#define __STACK_H__

struct stack_instance;

struct stack
{
    struct stack_instance   *_inst;
    int    (*push)(struct stack *self, void *p);       // Push void *
    void * (*pop)(struct stack *self);                 // Pop void *
    int    (*init_iter)(struct stack *self, int n);    // Iterator initialize, negative mean iterate form tail to head
    void * (*iterator)(struct stack *self);            // Iterator will return void * and setup next iterate.
};

struct stack *stack_create(void);
int stack_delete(struct stack *self, int (*destroyer)(void *));

#endif /* __STACK_H__ */

