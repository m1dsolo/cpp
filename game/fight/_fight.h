#pragma once

#include "../game_head.h"
#include "../vector/vector.h"


static FightContext *new_fight_context(Vector *cs0, Vector *cs1);
static Fighter *new_fighter(Character *c);

static void fight_begin(FightContext *fc);
static void fight_round_begin(FightContext *fc);
static void fight_round_act(FightContext *fc);
static void fight_round_end(FightContext *fc);
static void fight_timing(FightContext *fc);
static void fight_win(FightContext *fc);
static void fight_lost(FightContext *fc);