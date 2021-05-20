#pragma once

#include <stdbool.h>

#include "../game_head.h"
#include "../event/event.h"
#include "../vector/vector.h"

extern Event *event_set_exp;

typedef struct _character_private {
    char *name;
    CHARACTER_T type;
    CHARACTER_RACE_T race;
    int level;
    int exp;
    int max_exp;
    int hp;
    int max_hp;
    int atk;
    int def;
    int spd;
    // int str;    // +1atk
    // int dex;    // +1spd
    // int wis;    // +5mp
    // int vit;    // +5hp
    // int sta;    // +5sp +inv_size
    // int chr;    // event
} _CharacterPrivate;

static _CharacterPrivate *new_character_private();

static const void *character_get_attr(const void *v, const void *t);
static void character_set_attr(const void *v, const void *t, const void *attr);
static bool character_is_alive(Character *c);
static void character_gain_exp(Character *c, int exp);