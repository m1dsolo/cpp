#pragma once

#include "../game_head.h"

typedef struct vector Vector;

typedef enum character_attr_t {
    CA_NAME, 
    CA_TYPE, 
    CA_RACE, 
    CA_LEVEL, 
    CA_EXP, 
    CA_MAX_EXP, 
    CA_HP, 
    CA_MAX_HP, 
    CA_ATK, 
    CA_DEF, 
    CA_SPD
    // CA_STR, 
    // CA_DEX, 
    // CA_WIS, 
    // CA_VIT, 
    // CA_STA, 
    // CA_CHR
} CHARACTER_ATTR_T;

typedef enum character_t {
    CT_HERO, 
    CT_MONSTER
} CHARACTER_T;

typedef enum character_race_t {
    CR_HUMAN
} CHARACTER_RACE_T;

typedef struct character_table {
    bool (*is_alive)(Character *c);
    void (*gain_exp)(Character *c, int exp);
} CharacterTable;

typedef struct character {
    void *_private;
    struct object_table;
    struct character_table;
} Character;


Character *new_character();

void event_factor_update_level(void *v);