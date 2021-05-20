#pragma once

#include "../head.h"
#include "../hash_table/hash_table.h"
#include "../list/_list.h"
#include "../hash_table/_hash_table.h"

typedef struct _unordered_map_private {
    HashTable *ht;
} _UnorderedMapPrivate;

typedef struct _unordered_map_iterator_private {
    ListNode *node;
} _UnorderedMapIteratorPrivate;

static _UnorderedMapPrivate *new_unordered_map_private(Vector *pairs, size_t n, UNORDERED_MAP_KEY_T type);
static UnorderedMapIterator *new_unordered_map_iterator(ListNode *node);
static _UnorderedMapIteratorPrivate *new_unordered_map_iterator_private(ListNode *node);

static void unordered_map_insert(UnorderedMap *um, Pair *p);
static void *unordered_map_at(UnorderedMap *um, void *key);
static void unordered_map_erase(UnorderedMap *um, void *key);
static size_t unordered_map_size(UnorderedMap *um);

static UnorderedMapIterator *unordered_map_begin(UnorderedMap *um);
static UnorderedMapIterator *unordered_map_end(UnorderedMap *um);

static void unordered_map_iterator_pp(UnorderedMapIterator *umi);
static Pair *unordered_map_iterator_get_val(UnorderedMapIterator *umi);