#include <stdio.h>
#include <stdlib.h>
#include "vector/my_vector.h"

typedef struct nums {
    int a;
    int b;
} Nums;

typedef void *(*func_t)(void *, void *);

static void print_nums(Nums *n);
void *add(void *lh, void *rh);
void *sub(void *lh, void *rh);

typedef struct event {
    Vector *v;
    Vector *args0;
    Vector *args1;
    void (*add)(struct event *e, void *arg0, void *arg1, func_t call_back);
    void (*exe)(struct event *e);
} Event;

static void event_add(Event *e, void *arg0, void *arg1, func_t call_back)
{
    e->v->push_back(e->v, &call_back);
    e->args0->push_back(e->args0, arg0);
    e->args1->push_back(e->args1, arg1);
}

static void event_exe(Event *e)
{
    for (int i = 0; i < e->v->size(e->v); i++) {
        func_t call_back = *(func_t *)e->v->at(e->v, i);
        Nums *a = e->args0->at(e->args0, i);
        Nums *b = e->args1->at(e->args1, i);
        Nums *e = call_back(a, b);
        print_nums(e);
    }
}

Nums *new_nums(int a, int b)
{
    Nums *n = malloc(sizeof(Nums));

    n->a = a;
    n->b = b;

    return n;
}

Event *new_event()
{
    Event *e = malloc(sizeof(Event));

    e->v = new_vector(NULL, 0, sizeof(func_t *));
    e->args0 = new_vector(NULL, 0, sizeof(Nums));
    e->args1 = new_vector(NULL, 0, sizeof(Nums));
    
    e->add = event_add;
    e->exe = event_exe;

    return e;
}

void *add(void *lh, void *rh)
{
    Nums *lhn = lh;
    Nums *rhn = rh;

    lhn->a += rhn->a;
    lhn->b += rhn->b;

    return lhn;
}

void *sub(void *lh, void *rh)
{
    Nums *lhn = lh;
    Nums *rhn = rh;

    lhn->a -= rhn->a;
    lhn->b -= rhn->b;

    return lhn;
}

static void print_nums(Nums *n)
{
    printf("a->a:%d, a->b:%d\n", n->a, n->b);
}

// int main()
// {
//     Nums *n0 = new_nums(3, 4);
//     Nums *n1 = new_nums(5, 6);

//     Event *e = new_event();
//     e->add(e, n0, n1, add);
//     e->add(e, n0, n1, sub);
//     e->exe(e);
// }