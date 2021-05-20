#pragma once

#include "../head.h"

typedef enum unordered_map_key_t {
    UK_INT, 
    UK_STRING
} UNORDERED_MAP_KEY_T;

typedef struct unordered_map {
    void *_private;
    void (*insert)(UnorderedMap *um, Pair *p);
    void *(*at)(UnorderedMap *um, void *key);
    void (*erase)(UnorderedMap *um, void *key);
    size_t (*size)(UnorderedMap *um);

    UnorderedMapIterator *(*begin)(UnorderedMap *um);
    UnorderedMapIterator *(*end)(UnorderedMap *um);
} UnorderedMap;

typedef struct unordered_map_iterator {
    void *_private;
    void (*pp)(UnorderedMapIterator *umi);
    Pair *(*get_val)(UnorderedMapIterator *umi);
} UnorderedMapIterator;

UnorderedMap *new_unordered_map(Vector *pairs, size_t n, UNORDERED_MAP_KEY_T type);