#pragma once

#include "../game_head.h"


typedef struct event {
    Vector *v;
    Vector *args;
    void (*add)(Event *e, func_t func, void *args);
    void (*exe)(Event *e);
} Event;

void init_event();
