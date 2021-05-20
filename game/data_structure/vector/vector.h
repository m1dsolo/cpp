#pragma once

#include "../head.h"

typedef struct vector {
    void *_private;
    size_t (*size)(Vector *v);
    size_t (*max_size)(Vector *v);
    bool (*empty)(Vector *v);
    void (*pop_back)(Vector *v);
    void (*push_back)(Vector *v, void *val);
    void *(*front)(Vector *v);
    void *(*back)(Vector *v);
    void (*clear)(Vector *v);
    void *(*at)(Vector *v, int index);
    void (*erase)(Vector *v, int index);
} Vector;

Vector *new_vector(void *vals, int num, int val_size);
void del_vector(Vector *v);