#pragma once

#include "../head.h"

typedef struct pair {
    void *_private;
    void *(*first)(Pair *p);
    void *(*second)(Pair *p);
} Pair;

Pair *new_pair(void *v0, size_t v0_size, void *v1, size_t v1_size);