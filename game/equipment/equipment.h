#pragma once

#include "../game_head.h"

typedef enum equipment_id {
    EIW_WOOD_DAGGER, 
    EIW_WOOD_SWORD, 
    EIW_WOOD_HAMMER, 
    EIA_WOOD_ARMOR, 
    EIH_WOOD_HELMET, 
    EIP_WOOD_PANTS, 
    EIS_WOOD_SHOES, 
} EQUIPMENT_ID;

typedef enum equipment_t {
    ET_WEAPON_LIGHT, 
    ET_WEAPON_MEDIUM, 
    ET_WEAPON_HEAVY, 
    ET_WEAPON_GLOVE, 
    ET_WEAPON_BOW, 
    ET_WEAPON_STAFF, 
    ET_ARMOR_LIGHT, 
    ET_ARMOR_MEDIUM, 
    ET_ARMOR_HEAVY, 
    ET_HELMET, 
    ET_PANTS, 
    ET_SHOES, 
    ET_ORNAMENT, 
    ET_RING
} EQUIPMENT_T;

typedef enum equipment_attr_t {
    EA_NAME, 
    EA_VALUE, 
    EA_NUM, 
    EA_OWNER, 
    EA_TYPE, 
    EA_HP, 
    EA_ATK, 
    EA_DEF, 
    EA_SPD, 
    EA_HIT_RATE, 
    EA_DUR, 
    EA_MAX_DUR, 
    EA_WP
} EQUIPMENT_ATTR_T;

typedef struct equipment {
    void *_private;
    struct object_table;
    struct equipement_table;
} Equipment;