#include "event.h"
#include "_event.h"


Event *event_set_exp;

void init_event()
{
    event_set_exp = new_event();
}

static Event *new_event()
{
    Event *e = malloc(sizeof(Event));

    e->v = new_vector(NULL, 0, sizeof(func_t));
    e->args = new_vector(NULL, 0, sizeof(void *));

    e->add = event_add;
    e->exe = event_exe;

    return e;
}

static void event_add(Event *e, func_t func, void *args)
{
    e->v->push_back(e->v, &func);
    e->args->push_back(e->args, &args);
}

static void event_exe(Event *e)
{
    for (int i = 0; i < e->v->size(e->v); i++) {
        func_t func = *(func_t *)e->v->at(e->v, i);
        void *args = *(void **)e->args->at(e->args, i);

        func(args);
    }
}