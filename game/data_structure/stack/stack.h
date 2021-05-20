#pragma once

#include "../head.h"

typedef struct stack {
    void *_private;
    int (*size)(Stack *s);
    bool (*is_empty)(Stack *s);
    void (*pop)(Stack *s);
    void (*push)(Stack *s, void *val);
    void *(*top)(Stack *s);
} Stack;

Stack *new_stack(void *vals, int num, size_t val_size);