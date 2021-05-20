#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "../pair/pair.h"
#include "../vector/vector.h"

// static void my_error(char *s)
// {
//     perror(s);
//     exit(EXIT_FAILURE);
// }

// int main()
// {
//     DataBase *db = new_database();

//     db->open(db, "game_sqlite3.db");

//     char *keys[] = {"name", "age"};
//     char *vals0[] = {"yang", "zou"};
//     int vals1[] = {20, 21};

//     Pair *p0 = new_pair(&keys[0], sizeof(char *), &vals0[0], sizeof(char *));
//     Pair *p1 = new_pair(&keys[1], sizeof(char *), &vals0[1], sizeof(char *));
//     Vector *pairs = new_vector(NULL, 0, sizeof(Pair));
//     pairs->push_back(pairs, p0);
//     pairs->push_back(pairs, p1);
//     Vector *types = new_vector(NULL, 0, sizeof(DATA_BASE_VAL_TYPE));
//     DATA_BASE_VAL_TYPE type0 = DV_STRING;
//     DATA_BASE_VAL_TYPE type1 = DV_STRING;
//     types->push_back(types, &type0);
//     types->push_back(types, &type1);

//     db->insert(db, "person", pairs, types);

//     db->close(db);
// }