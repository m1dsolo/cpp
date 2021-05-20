#pragma once

#include "../game_head.h"

typedef enum game_db_data_type {
    GD_CHARACTER
} GameDBDataType;

typedef struct game_db {
    void *_private;
    DATA_BASE_STATE (*save)(GameDB *db, GameDBDataType type, void *data);
} GameDB;

GameDB *new_game_db();
void init_game_db();

