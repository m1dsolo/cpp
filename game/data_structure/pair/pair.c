#include "pair.h"
#include "_pair.h"


Pair *new_pair(void *v0, size_t v0_size, void *v1, size_t v1_size)
{
    Pair *p = malloc(sizeof(Pair));

    p->_private = new_pair_private(v0, v0_size, v1, v1_size);
    p->first = pair_first;
    p->second = pair_second;

    return p;
}

static _PairPrivate *new_pair_private(void *v0, size_t v0_size, void *v1, size_t v1_size)
{
    _PairPrivate *pp = malloc(sizeof(_PairPrivate));

    pp->v0 = malloc(v0_size);
    pp->v1 = malloc(v1_size);

    if (v0)
        memcpy(pp->v0, v0, v0_size);
    else
        memset(pp->v0, 0, v0_size);
    if (v1)
        memcpy(pp->v1, v1, v1_size);
    else
        memset(pp->v1, 0, v1_size);

    return pp;
}

static void *pair_first(Pair *p)
{
    _PairPrivate *pp = p->_private;

    return pp->v0;
}

static void *pair_second(Pair *p)
{
    _PairPrivate *pp = p->_private;

    return pp->v1;
}