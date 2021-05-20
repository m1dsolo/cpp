#pragma once

#include "../game_head.h"
#include "../item/_item.h"

typedef struct _equipment_private {
    struct _item_private;
    EQUIPMENT_T type;
    int hp;
    int atk;
    int def;
    int spd;
    int hit_rate;
    int dur;
    int max_dur;
    int wp;
} _EquipmentPrivate;

static _EquipmentPrivate *new_equipment_private(EQUIPMENT_ID id, Character *owner);

static const void *equipment_get_attr(const void *v, const void *t);
static void equipment_set_attr(const void *v, const void *t, const void *attr);