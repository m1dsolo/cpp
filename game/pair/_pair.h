#pragma once

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct _pair_private {
    void *v0;
    void *v1;
} _PairPrivate;

static _PairPrivate *new_pair_private(void *v0, size_t v0_size, void *v1, size_t v1_size);
static void *pair_first(Pair *p);
static void *pair_second(Pair *p);