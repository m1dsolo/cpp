#pragma once

#include "../game_head.h"

typedef struct _item_private {
    char *name;
    int value;
    int num;
    Character *owner;
} _ItemPrivate;