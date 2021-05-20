#include "equipment.h"
#include "_equipment.h"


Equipment *new_equipment(EQUIPMENT_ID id, Character *owner)
{
    Equipment *e = malloc(sizeof(Equipment));

    e->_private = new_equipment_private(id, owner);
    e->get_attr = equipment_get_attr;
    e->set_attr = equipment_set_attr;

    return e;
}

static _EquipmentPrivate *new_equipment_private(EQUIPMENT_ID id, Character *owner)
{
    _EquipmentPrivate *ep = malloc(sizeof(_EquipmentPrivate));

    switch (id) {
        case EIW_WOOD_DAGGER: {
            ep->name = "wood_dagger";
            ep->type = ET_WEAPON_LIGHT;
            ep->value = 10;
            ep->hp = 0;
            ep->atk = 3;
            ep->def = 0;
            ep->spd = 2;
            ep->hit_rate = 90;
            ep->dur = 20;
            ep->max_dur = 20;
            ep->wp = 2;
            break;
        }
        case EIW_WOOD_SWORD: {
            ep->name = "wood_sword";
            ep->type = ET_WEAPON_MEDIUM;
            ep->value = 10;
            ep->hp = 0;
            ep->atk = 5;
            ep->def = 0;
            ep->spd = 0;
            ep->hit_rate = 90;
            ep->dur = 25;
            ep->max_dur = 25;
            ep->wp = 2;
            break;
        }
        case EIW_WOOD_HAMMER: {
            ep->name = "wood_hammer";
            ep->type = ET_WEAPON_HEAVY;
            ep->value = 10;
            ep->hp = 0;
            ep->atk = 7;
            ep->def = 0;
            ep->spd = -2;
            ep->hit_rate = 90;
            ep->dur = 30;
            ep->max_dur = 30;
            ep->wp = 2;
            break;
        }
    }
    ep->num = 1;
    ep->owner = owner;

    return ep;
}

static const void *equipment_get_attr(const void *v, const void *t)
{
    const Equipment *e = v;
    const EQUIPMENT_ATTR_T type = *(EQUIPMENT_ATTR_T *)t;
    const _EquipmentPrivate *ep = e->_private;

    switch (type) {
        case EA_NAME:
            return &ep->name;
        case EA_VALUE:
            return &ep->value;
        case EA_NUM:
            return &ep->num;
        case EA_OWNER:
            return &ep->owner;
        case EA_TYPE:
            return &ep->type;
        case EA_HP:
            return &ep->hp;
        case EA_ATK:
            return &ep->atk;
        case EA_DEF:
            return &ep->def;
        case EA_SPD:
            return &ep->spd;
        case EA_HIT_RATE:
            return &ep->hit_rate;
        case EA_DUR:
            return &ep->dur;
        case EA_MAX_DUR:
            return &ep->max_dur;
        case EA_WP:
            return &ep->wp;
    }
}

static void equipment_set_attr(const void *v, const void *t, const void *attr)
{
    const Equipment *e = v;
    const EQUIPMENT_ATTR_T type = *(EQUIPMENT_ATTR_T *)t;
    _EquipmentPrivate *ep = e->_private;

    switch (type) {
        case EA_NAME:
            ep->name = *(char **)attr;
            break;
        case EA_VALUE:
            ep->value = *(int *)attr;
            break;
        case EA_NUM:
            ep->num = *(int *)attr;
            break;
        case EA_OWNER:
            ep->owner = *(Character **)attr;
            break;
        case EA_TYPE:
            ep->type = *(EQUIPMENT_T *)attr;
            break;
        case EA_HP:
            ep->hp = *(int *)attr;
            break;
        case EA_ATK:
            ep->atk = *(int *)attr;
            break;
        case EA_DEF:
            ep->def = *(int *)attr;
            break;
        case EA_SPD:
            ep->spd = *(int *)attr;
            break;
        case EA_HIT_RATE:
            ep->hit_rate = *(int *)attr;
            break;
        case EA_DUR:
            ep->dur = *(int *)attr;
            break;
        case EA_MAX_DUR:
            ep->max_dur = *(int *)attr;
            break;
        case EA_WP:
            ep->wp = *(int *)attr;
            break;
}