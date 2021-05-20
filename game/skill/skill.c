#include "skill.h"
#include "_skill.h"


Skill *new_skill(SKILL_ID id, Character *c)
{
    Skill *s = malloc(sizeof(Skill));

    s->_private = new_skill_private(id, c);
    
    s->get_attr = skill_get_attr;
    s->set_attr = skill_set_attr;
    s->exe = new_skill_exe(id);

    return s;
}

static _SkillPrivate *new_skill_private(SKILL_ID id, Character *owner)
{
    _SkillPrivate *sp = malloc(sizeof(_SkillPrivate));

    switch (id) {
        case SI_CUT: {
            sp->name = "cut";
            sp->cd = 3;
            sp->owner = owner;
            sp->properties = new_vector(NULL, 0, sizeof(SKILL_PROPERTY_T));
            SKILL_PROPERTY_T pt = SP_BLEED;
            sp->properties->push_back(sp->properties, &pt);
            break;
        }
        case SI_SLASH: {
            sp->name = "slash";
            sp->cd = 3;
            sp->owner = owner;
            sp->properties = new_vector(NULL, 0, sizeof(SKILL_PROPERTY_T));
            SKILL_PROPERTY_T pt = SP_CRIT;
            sp->properties->push_back(sp->properties, &pt);
            break;
        }
        case SI_SMASH: {
            sp->name = "smash";
            sp->cd = 3;
            sp->owner = owner;
            sp->properties = new_vector(NULL, 0, sizeof(SKILL_PROPERTY_T));
            SKILL_PROPERTY_T pt = SP_REPEL;
            sp->properties->push_back(sp->properties, &pt);
            break;
        }
    }
    sp->get_damage = new_skill_get_damage(id);
    sp->now_cd = 0;

    return sp;
}

static SKILL_EXE_T new_skill_exe(SKILL_ID id)
{
    switch (id) {
        case SI_CUT:
            return skill_exe_cut;
        case SI_SLASH:
            return skill_exe_slash;
        case SI_SMASH:
            return skill_exe_smash;
    }
}

static SKILL_GET_DAMAGE_T new_skill_get_damage(SKILL_ID id)
{
    switch (id) {
        case SI_CUT:
        case SI_SLASH:
        case SI_SMASH:
            return  skill_get_damage_normal;
    }
}

static void skill_exe_cut(Skill *s, void *objs)
{

}

static void skill_exe_slash(Skill *s, void *objs)
{

}
static void skill_exe_smash(Skill *s, void *objs)
{

}

static int skill_get_damage_normal(Skill *s, void *objs)
{
    // s->owner->atk
    // f->c->def
}

static const void *skill_get_attr(const void *v, const void *t)
{
    const Skill *s = v;
    const SKILL_ATTR_T type = *(SKILL_ATTR_T *)t;
    _SkillPrivate *sp = s->_private;

    switch (type) {
        case SA_NAME:
            return &sp->name;
        case SA_CD:
            return &sp->cd;
        case SA_NOW_CD:
            return &sp->now_cd;
        case SA_OWNER:
            return &sp->owner;
        case SA_PROPERTIES:
            return &sp->properties;
        case SA_GET_DAMAGE:
            return &sp->get_damage;
    }
}

static void skill_set_attr(const void *v, const void *t, void *attr)
{
    const Skill *s = v;
    const SKILL_ATTR_T type = *(SKILL_ATTR_T *)t;
    _SkillPrivate *sp = s->_private;

    switch (type) {
        case SA_NAME:
            sp->name = *(char **)attr;
            break;
        case SA_CD:
            sp->cd = *(int *)attr;
            break;
        case SA_NOW_CD:
            sp->now_cd = *(int *)attr;
            break;
        case SA_OWNER:
            sp->owner = *(Character **)attr;
            break;
        case SA_PROPERTIES:
            sp->properties = *(Vector **)attr;
            break;
        case SA_GET_DAMAGE:
            sp->get_damage = *(SKILL_GET_DAMAGE_T *)attr;
            break;
    }
}