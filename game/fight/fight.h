#pragma once

#include "../game_head.h"

typedef enum fight_state {
    FS_BEGIN, 
    FS_ROUND_BEGIN, 
    FS_ROUND_ACT, 
    FS_ROUND_END, 
    FS_TIMING, 
    FS_WIN, 
    FS_LOST
} FIGHT_STATE;

typedef struct fight_context {
    Vector *fs0;
    Vector *fs1;
    Fighter *acter;
    FIGHT_STATE s;
    bool is_over;
} FightContext;

typedef struct fighter {
    Character *c;
    int act_slot;
} Fighter;