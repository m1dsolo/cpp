#include "character.h"
#include "_character.h"


CHARACTER_ATTR_T cas[CHARACTER_ATTR_NUM];

Character *new_character()
{
    Character *c = malloc(sizeof(Character));

    c->_private = new_character_private();

    c->get_attr = character_get_attr;
    c->set_attr = character_set_attr;
    c->is_alive = character_is_alive;
    c->gain_exp = character_gain_exp;

    event_set_exp->add(event_set_exp, event_factor_update_level, c);

    return c;
}

void init_character()
{
    cas = {CA_NAME, CA_}
}

static _CharacterPrivate *new_character_private()
{
    _CharacterPrivate *cp = malloc(sizeof(_CharacterPrivate));

    cp->name = "yang";
    cp->type = CT_HERO;
    cp->race = CR_HUMAN;
    cp->level = 1;
    cp->exp = 0;
    cp->max_exp = level_table[cp->level];
    cp->hp = 50;
    cp->max_hp = 50;
    cp->atk = 5;
    cp->def = 2;
    cp->spd = 10;

    return cp;
}

static bool character_is_alive(Character *c)
{
    _CharacterPrivate *cp = c->_private;

    return cp->hp > 0;
}

static const void *character_get_attr(const void *v, const void *t)
{
    const Character *c = v;
    const type = *(CHARACTER_ATTR_T *)t;
    const _CharacterPrivate *cp = c->_private;

    switch (type) {
        case CA_NAME:
            return &cp->name;
        case CA_TYPE:
            return &cp->type;
        case CA_RACE:
            return &cp->race;
        case CA_LEVEL:
            return &cp->level;
        case CA_EXP:
            return &cp->exp;
        case CA_MAX_EXP:
            return &cp->max_exp;
        case CA_HP:
            return &cp->hp;
        case CA_MAX_HP:
            return &cp->max_hp;
        case CA_ATK:
            return &cp->atk;
        case CA_DEF:
            return &cp->def;
        case CA_SPD:
            return &cp->spd;
    }
}

static void character_set_attr(const void *v, const void *t, const void *attr)
{
    const Character *c = v;
    const type = *(CHARACTER_ATTR_T *)t;
    _CharacterPrivate *cp = c->_private;

    switch (type) {
        case CA_NAME:
            cp->name = *(char **)attr;
            break;
        case CA_TYPE:
            cp->type = *(CHARACTER_T *)attr;
            break;
        case CA_RACE:
            cp->race = *(CHARACTER_RACE_T *)attr;
            break;
        case CA_LEVEL:
            cp->level = *(int *)attr;
            break;
        case CA_EXP:
            cp->exp = *(int *)attr;
            event_set_exp->exe(event_set_exp);
            break;
        case CA_MAX_EXP:
            cp->max_exp = *(int *)attr;
            break;
        case CA_HP:
            cp->hp = *(int *)attr;
            break;
        case CA_MAX_HP:
            cp->max_hp = *(int *)attr;
            break;
        case CA_ATK:
            cp->atk = *(int *)attr;
            break;
        case CA_DEF:
            cp->def = *(int *)attr;
            break;
        case CA_SPD:
            cp->spd = *(int *)attr;
            break;
    }
}

static void character_gain_exp(Character *c, int exp)
{
    assert(exp > 0);
    
    _CharacterPrivate *cp = c->_private;

    cp->exp += exp;
    while (1) {
        if (cp->level >= MAX_LEVEL)
            break;
        else if (cp->exp >= level_table[cp->level]) {
            cp->exp -= level_table[cp->level];
            cp->level += 1;
            cp->max_exp = level_table[cp->level];
        }
        else 
            break;
    }
}


void event_factor_update_level(void *v)
{
    Character *c = (Character *)v;
    _CharacterPrivate *cp = c->_private;

    while (1) {
        if (cp->level >= MAX_LEVEL)
            break;
        else if (cp->exp >= level_table[cp->level]) {
            cp->exp -= level_table[cp->level];
            cp->level += 1;
            cp->max_exp = level_table[cp->level];
        }
        else 
            break;
    }
}