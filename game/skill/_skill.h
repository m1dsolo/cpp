#pragma once


#include "../game_head.h"
#include "../vector/vector.h"

typedef struct _skill_private {
    char *name;
    int cd;
    int now_cd;
    Character *owner; 
    Vector *properties;
    SKILL_GET_DAMAGE_T get_damage;
} _SkillPrivate;

static _SkillPrivate *new_skill_private(SKILL_ID id, Character *owner);

static SKILL_GET_DAMAGE_T new_skill_get_damage(SKILL_ID id);
static int skill_get_damage_normal(Skill *s, void *objs);

static SKILL_EXE_T new_skill_exe(SKILL_ID id);
static void skill_exe_cut(Skill *s, void *objs);
static void skill_exe_slash(Skill *s, void *objs);
static void skill_exe_smash(Skill *s, void *objs);

static const void *skill_get_attr(const void *v, const void *t);
static void skill_set_attr(const void *v, const void *t, void *attr);