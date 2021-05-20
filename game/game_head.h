#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define DB_FILE_NAME "/home/yang/code/game/data"
#define GD_CHARACTER_TB_NAME "character"
#define DB_KEYS_MAX_SIZE 16
#define CHARACTER_ATTR_NUM 11
#define MAX_LEVEL 10

const static int level_table[MAX_LEVEL + 1] = {MAX_LEVEL, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

typedef struct character Character;
typedef enum character_t CHARACTER_T;
typedef enum character_attr_t CHARACTER_ATTR_T;
typedef enum character_race_t CHARACTER_RACE_T;

typedef struct euqipment Equipment;
typedef enum equipment_t EQUIPMENT_T;
typedef enum equipment_attr_t EQUIPMENT_ATTR_T;

typedef struct skill Skill;
typedef enum skill_t SKILL_T;
typedef enum skill_attr_t SKILL_ATTR_T;

typedef struct fighter Fighter;
typedef struct fight_context FightContext;

typedef struct event Event;
typedef struct vector Vector;
typedef struct pair Pair;
typedef struct data_base DataBase;
typedef enum data_base_val_type DATA_BASE_VAL_TYPE;
typedef enum data_base_state DATA_BASE_STATE;
typedef struct game_db GameDB;
typedef enum game_db_data_type GameDBDataType;

typedef void (*func_t)(void *args);
typedef int (*SKILL_GET_DAMAGE_T)(Skill *s, void *objs);
typedef void (*SKILL_EXE_T)(Skill *s, void *objs);

extern Event *event_set_exp;

typedef struct object_table {
    const void *(*get_attr)(const void *v, void *t);
    void (*set_attr)(void *v, const void *t, const void *attr);
} ObjectTable;

typedef struct item_table {
    
} ItemTable;

