#pragma once

#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#include "../pair/pair.h"
#include "../vector/vector.h"

typedef struct _sqlite_private {
    sqlite3 *db;
} _SqlitePrivate;

static _SqlitePrivate *new_sqlite_private();
static DATA_BASE_STATE sqlite_open(DataBase *db, char *file_name);
static DATA_BASE_STATE sqlite_close(DataBase *db);
static DATA_BASE_STATE sqlite_insert(DataBase *db, char *table_name, Vector *pairs, Vector *types);