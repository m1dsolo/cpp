#pragma once

#include "../game_head.h"

typedef enum skill_id {
    SI_CUT, 
    SI_SLASH, 
    SI_SMASH
} SKILL_ID;

typedef enum skill_attr_t {
    SA_NAME, 
    SA_CD, 
    SA_NOW_CD, 
    SA_OWNER, 
    SA_PROPERTIES, 
    SA_GET_DAMAGE
} SKILL_ATTR_T;

typedef enum skill_property_t {
    SP_CRIT, 
    SP_BLEED, 
    SP_REPEL
} SKILL_PROPERTY_T;

typedef enum skill_consume_t {
    SC_MP, 
    SC_LWP, 
    SC_MWP, 
    SC_HWP
} SKILL_CONSUME_T;

typedef struct skill_table {
    void (*exe)(Skill *s, void *objs);
} SkillTable;

typedef struct skill {
    void *_private;
    struct object_table;
    struct skill_table;
} Skill;

Skill *new_skill(SKILL_ID id, Character *owner);