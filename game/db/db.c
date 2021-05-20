#include "db.h"
#include "_db.h"

// 可以改为const
Vector *db_character_types;

// 这个全局变量看能不能去掉
char **db_character_keys;

GameDB *new_game_db()
{
    GameDB *db = malloc(sizeof(GameDB));

    db->_private = new_game_db_private();
    db->save = game_db_save;

    return db;
}

void init_game_db()
{
    DATA_BASE_VAL_TYPE types[] = {DV_STRING, DV_INT, DV_INT, DV_INT, DV_INT,    // name, type, race, level, exp, 
                                    DV_INT, DV_INT, DV_INT, DV_INT, DV_INT,     // max_exp, hp, max_hp, atk, def, 
                                    DV_INT};                                    // spd;
    db_character_types = new_vector(NULL, 0, sizeof(DATA_BASE_VAL_TYPE));
    for (int i = 0; i < CHARACTER_ATTR_NUM; i++) {
        db_character_types->push_back(db_character_types, &types[i]);
    }
    
    static char *keys[] = {"name", "type", "race", "level", "exp", 
                    "max_exp", "hp", "max_hp", "atk", "def", 
                    "spd"};
    for (int i = 0; i < CHARACTER_ATTR_NUM; i++) {
        db_character_keys = keys;
    }
}

static _GameDBPrivate *new_game_db_private()
{
    _GameDBPrivate *gp = malloc(sizeof(_GameDBPrivate));

    gp->db = new_database();

    // open
    gp->db->open(gp->db, DB_FILE_NAME);

    return gp;
}

static DATA_BASE_STATE game_db_save(GameDB *db, GameDBDataType type, void *v)
{
    _GameDBPrivate *gp = db->_private;

    switch (type) {
        case GD_CHARACTER: {
            // 一堆new的还没free
            // 可以给pair初始个大小，增加vector效率
            Vector *pairs = new_vector(NULL, 0, sizeof(Pair));
            Character *c = v;
            _CharacterPrivate *cp = c->_private;

            int datas[11] = {0, cp->type, cp->race, cp->level, cp->exp, 
                            cp->max_exp, cp->hp, cp->max_hp, cp->atk, cp->def, 
                            cp->spd};

            pairs->push_back(pairs, new_pair(&db_character_keys[0], sizeof(char *), &cp->name, sizeof(char *)));
            for (int i = 1; i < CHARACTER_ATTR_NUM; i++) {
                Pair *p = new_pair(&db_character_keys[i], sizeof(char *), &datas[i], sizeof(int));
                pairs->push_back(pairs, p);
            }

            gp->db->insert(gp->db, GD_CHARACTER_TB_NAME, pairs, db_character_types);
            break;
        }
        default:
            break;
    }
}