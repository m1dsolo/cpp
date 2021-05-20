#pragma once

#include "../head.h"
#include "../list/list.h"
#include "../list/_list.h"
#include "../vector/vector.h"
#include "../pair/pair.h"

#define HASH_TABLE_PRIMES_NUM 12

typedef struct _hash_table_private {
    Vector *buckets;
    HASH_TABLE_KEY_T kt;
    int num;        // 元素个数

    // 用来实现迭代器
    ListNode *dummy_node;
    ListNode *final_node;
} _HashTablePrivate;

static _HashTablePrivate *new_hash_table_private(size_t n, HASH_TABLE_KEY_T type);
static size_t hash_table_next_prime(size_t n);
static size_t hash_func(HashTable *ht, size_t n);
static size_t hash_table_str2index(char *key);
static List *get_bucket(HashTable *ht, void *key);
static bool is_equal(HashTable *ht, void *key0, void *key1);

static void hash_table_insert(HashTable *ht, Pair *p);
static void *hash_table_at(HashTable *ht, void *key);
static void hash_table_erase(HashTable *ht, void *key);
static size_t hash_table_size(HashTable *ht);