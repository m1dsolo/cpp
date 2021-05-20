#pragma once

#include "../head.h"

// 注意：若key为char *，则只需传char *为参，若key为int，则需传int *
typedef enum hash_table_key_t {
    HK_INT, 
    HK_STRING
} HASH_TABLE_KEY_T;

typedef struct hash_table {
    void *_private;
    void (*insert)(HashTable *ht, Pair *p);
    void *(*at)(HashTable *ht, void *key);
    void (*erase)(HashTable *ht, void *key);
    size_t (*size)(HashTable *ht);
} HashTable;

HashTable *new_hash_table(Vector *pairs, size_t n, HASH_TABLE_KEY_T type);
