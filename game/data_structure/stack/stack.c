#include "stack.h"
#include "_stack.h"

Stack *new_stack(void *vals, int num, size_t val_size)
{
    Stack *stack = malloc(sizeof(Stack));
    stack->_private = new_list(vals, num, val_size);

    stack->size = stack_size;
    stack->is_empty = stack_is_empty;
    stack->pop = stack_pop;
    stack->push = stack_push;
    stack->top = stack_top;
}

static int stack_size(Stack *s)
{
    List *l = s->_private;

    return l->size(l);
}

static bool stack_is_empty(Stack *s)
{
    List *l = s->_private;

    return l->empty(l);
}

static void stack_pop(Stack *s)
{
    List *l = s->_private;

    l->pop_back(l);
}

static void stack_push(Stack *s, void *val)
{
    List *l = s->_private;

    l->push_back(l, val);
}

static void *stack_top(Stack *s)
{
    List *l = s->_private;
    
    return l->back(l);
}