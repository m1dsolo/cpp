#include "fight.h"
#include "_fight.h"


void fight(Vector *cs0, Vector *cs1)
{
    FightContext *fc = new_fight_context(cs0, cs1);

    switch (fc->s) {
        case FS_BEGIN:
            fight_begin(fc);
            break;
        case FS_ROUND_BEGIN:
            fight_round_begin(fc);
            break;
        case FS_ROUND_ACT:
            fight_round_act(fc);
            break;
        case FS_ROUND_END:
            fight_round_end(fc);
            break;
        case FS_TIMING:
            fight_timing(fc);
            break;
        case FS_WIN:
            fight_win(fc);
            break;
        case FS_LoST:
            fight_lost(fc);
            break;
    }
}

static FightContext *new_fight_context(Vector *cs0, Vector *cs1)
{
    FightContext *fc = malloc(sizeof(FightContext));

    fc->fs0 = new_vector(NULL, 0, sizeof(Fighter *));
    fc->fs1 = new_vector(NULL, 0, sizeof(Fighter *));

    for (int i = 0; i < cs0->size(cs0); i++) {
        Character *c = *(Character **)cs0->at(cs0, i);
        Fighter *f = new_fighter(c);
        fc->fs0->push_back(fc->fs0, &f);
    }
    for (int i = 0; i < cs1->size(cs1); i++) {
        Character *c = *(Character **)cs1->at(cs1, i);
        Fighter *f = new_fighter(c);
        fc->fs1->push_back(fc->fs1, &f);
    }

    fc->acter = NULL;
    fc->s = FS_BEGIN;

    return fc;
}

static Fighter *new_fighter(Character *c)
{
    Fighter *f = malloc(sizeof(Fighter));

    f->c = c;
    f->act_slot = 0;

    return f;
}

static void fight_begin(FightContext *fc)
{
    show_fight_begin(fc);

    fc->s = FS_TIMING;
}

static void fight_round_begin(FightContext *fc)
{
    show_fight_round_begin(fc);

    fc->s = FS_ROUND_ACT;
}

static void fight_round_act(FightContext *fc)
{
    show_fight_round_act(fc);

    fc->s = FS_ROUND_END;
}

static void fight_round_end(FightContext *fc)
{
    show_fight_round_act(fc);

    
}

static void fight_timing(FightContext *fc)
{
    
}

static void fight_win(FightContext *fc)
{
    
}

static void fight_lost(FightContext *fc)
{
    
}