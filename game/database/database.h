#pragma once

#include "../game_head.h"

typedef enum data_base_val_type {
    DV_STRING, 
    DV_INT
} DATA_BASE_VAL_TYPE;

typedef enum data_base_state {
    DB_OK, 
    DB_ERROR
} DATA_BASE_STATE;

typedef struct data_base {
    void *_private;
    DATA_BASE_STATE (*open)(DataBase *db, char *file_name);
    DATA_BASE_STATE (*close)(DataBase *db);
    // DatabaseState (*create)(DataBase *db, char *tb_name, char *s);
    // DatabaseState (*drop)(DataBase *db, char *tb_name);
    DATA_BASE_STATE (*insert)(DataBase *db, char *table_name, Vector *pairs, Vector *types);
    // DatabaseState (*delete)(DataBase *db, char *tb_name, Pair *p);
    // DatabaseState (*update)(DataBase *db, char *tb_name, Pair *old, Pair *new);
    // DatabaseState (*select)(DataBase )
} DataBase;

DataBase *new_database();