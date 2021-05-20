#pragma once

#include "../game_head.h"
#include "../database/database.h"
#include "../vector/vector.h"
#include "../pair/pair.h"
#include "../character/character.h"
#include "../character/_character.h"

typedef struct _game_db_private {
    DataBase *db;
} _GameDBPrivate;

static _GameDBPrivate *new_game_db_private();
static DATA_BASE_STATE game_db_save(GameDB *db, GameDBDataType type, void *v);