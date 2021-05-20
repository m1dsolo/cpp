#include "database.h"
#include "_database.h"


DataBase *new_database()
{
    DataBase *db = malloc(sizeof(DataBase));

    db->_private = new_sqlite_private();
    db->open = sqlite_open;
    db->close = sqlite_close;
    db->insert = sqlite_insert;

    return db;
}

static _SqlitePrivate *new_sqlite_private()
{
    _SqlitePrivate *sp = malloc(sizeof(_SqlitePrivate));

    sp->db = NULL;

    return sp;
}

static DATA_BASE_STATE sqlite_open(DataBase *db, char *file_name)
{
    _SqlitePrivate *sp = (_SqlitePrivate *)db->_private;

    int ret = sqlite3_open(file_name, &sp->db);

    switch (ret) {
        case SQLITE_OK:
            return DB_OK;
        default:
            return DB_ERROR;
    }
}

static DATA_BASE_STATE sqlite_close(DataBase *db)
{
    _SqlitePrivate *sp = (_SqlitePrivate *)db->_private;

    int ret = sqlite3_close(sp->db);

    switch (ret) {
        case SQLITE_OK:
            return DB_OK;
        default:
            return DB_ERROR;
    }
}

static DATA_BASE_STATE sqlite_insert(DataBase *db, char *table_name, Vector *pairs, Vector *types)
{
    _SqlitePrivate *sp = db->_private;
    char order[128] = {"insert into "};
    char *ptr = &order[12];

    sprintf(ptr, "%s(", table_name);
    ptr = &ptr[strlen(table_name) + 1];
    
    for (int i = 0; i < pairs->size(pairs); i++) {
        Pair *p = (Pair *)pairs->at(pairs, i);
        char *key = *(char **)p->first(p);
        sprintf(ptr, "%s, ", key);
        ptr = &ptr[strlen(key) + 2];
    }

    ptr--;
    ptr--;
    *ptr = ')';
    ptr++;
    sprintf(ptr, " values(");
    ptr = &ptr[8];

    for (int i = 0; i < pairs->size(pairs); i++) {
        Pair *p = (Pair *)pairs->at(pairs, i);
        DATA_BASE_VAL_TYPE type = *(DATA_BASE_VAL_TYPE *)types->at(types, i);
        char str[64];

        switch (type) {
            case DV_STRING: {
                char *val = *(char **)p->second(p);
                sprintf(str, "\"%s\"", val);
                break;
            }
            case DV_INT: {
                int val = *(int *)p->second(p);
                sprintf(str, "%d", val);
                break;
            }
        }
        sprintf(ptr, "%s, ", str);
        ptr = &ptr[strlen(str) + 2];
    }
    order[strlen(order) - 2] = ')';
    order[strlen(order) - 1] = ';';

    printf("%s\n", order);
    int ret = sqlite3_exec(sp->db, order, NULL, NULL, NULL);

    switch (ret) {
        case SQLITE_OK:
            return DB_OK;
        default:
            return DB_ERROR;
    }
}