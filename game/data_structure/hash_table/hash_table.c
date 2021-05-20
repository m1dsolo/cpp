#include "hash_table.h"
#include "_hash_table.h"

static const int hash_table_primes[HASH_TABLE_PRIMES_NUM] = {11, 23, 53, 97, 193, 
                                                            389, 769, 1543, 3079, 6151, 
                                                            12289, 24593};

HashTable *new_hash_table(Vector *pairs, size_t n, HASH_TABLE_KEY_T type)
{
    HashTable *ht = malloc(sizeof(HashTable));

    ht->_private = new_hash_table_private(n, type);
    ht->insert = hash_table_insert;
    ht->at = hash_table_at;
    ht->erase = hash_table_erase;
    ht->size = hash_table_size;

    if (pairs == NULL && n == 0)
        return ht;

    // 插入
    _HashTablePrivate *htp = ht->_private;
    for (int i = 0; i < pairs->size(pairs); i++) {
        Pair *p = *(Pair **)pairs->at(pairs, i);
        hash_table_insert(ht, p);
    }

    return ht;
}

static _HashTablePrivate *new_hash_table_private(size_t n, HASH_TABLE_KEY_T type)
{
    _HashTablePrivate *htp = malloc(sizeof(_HashTablePrivate));

    int buckets_num = hash_table_next_prime(n);
    List *lists[buckets_num];
    for (int i = 0; i < buckets_num; i++) {
        lists[i] = new_list(NULL, 0, sizeof(Pair *));
    }

    htp->buckets = new_vector(lists, buckets_num, sizeof(List *));
    htp->kt = type;
    htp->num = 0;
    htp->dummy_node = new_list_node(NULL, NULL, NULL, sizeof(Pair *));
    htp->final_node = htp->dummy_node;

    return htp;
}

// 先用最简单的遍历
static size_t hash_table_next_prime(size_t n)
{
    size_t a = hash_table_primes[0];
    size_t i = 1;
    while (n > a) {
        a = hash_table_primes[i++];
    }

    return a;
}

static size_t hash_func(HashTable *ht, size_t n)
{
    _HashTablePrivate *htp = ht->_private;

    return n % htp->buckets->size(htp->buckets);
}

static size_t hash_table_str2index(char *key)
{
    size_t rst;
    char *p;
    
    for (rst = 0, p = key; *p; p++) {
        rst = 31 * rst + *p;
    }

    return rst;
}

// key_t == str时 key为char *, key_t == int时 key为int *
static List *get_bucket(HashTable *ht, void *key)
{
    _HashTablePrivate *htp = ht->_private;

    size_t index;
    switch (htp->kt) {
        case HK_INT:
            index = hash_func(ht, *(int *)key);
            break;
        case HK_STRING:
            index = hash_func(ht, hash_table_str2index(key));
            break;
    }

    return *(List **)htp->buckets->at(htp->buckets, index);
}

// 若key为char *，必须传入char *，而不是char **
static bool is_equal(HashTable *ht, void *key0, void *key1)
{
    _HashTablePrivate *htp = ht->_private;

    switch (htp->kt) {
        case HK_INT: {
            int k0 = *(int *)key0;
            int k1 = *(int *)key1;
            if (k0 == k1)
                return true;
            break;
        }
        case HK_STRING: {
            char *k0 = key0;
            char *k1 = key1;
            if (!strcmp(k0, k1))
                return true;
            break;
        }
    }

    return false;
}

// 如果一个桶内超过7个元素应该将链表改为红黑树，等学会再说吧
// 这是没管是否key重复
// insert若key为char *，必须传入char *，而不是char **
static void hash_table_insert(HashTable *ht, Pair *p)
{
    _HashTablePrivate *htp = ht->_private;
    List *l = get_bucket(ht, p->first(p));

    l->push_back(l, &p);
    
    // 实现迭代器
    _ListPrivate *lp = l->_private;

    htp->final_node->prev = lp->final_node;    // 充分利用了双向链表的prev来连接成迭代器
    lp->final_node->prev = htp->dummy_node;
    htp->final_node = lp->final_node;

    htp->num++;
}

// 第一个key相等的val
static void *hash_table_at(HashTable *ht, void *key)
{
    _HashTablePrivate *htp = ht->_private;
    List *l = get_bucket(ht, key);

    ListIterator *end = l->end(l);
    for (ListIterator *li = l->begin(l); li->get_val(li) != end->get_val(end); li->pp(li)) {
        Pair *p = *(Pair **)li->get_val(li);
        if (is_equal(ht, key, p->first(p)))
            return p->second(p);
    }

    return NULL;
}

// 迭代器也得改
// 遍历迭代器链表(伪链表)
static void hash_table_erase(HashTable *ht, void *key)
{
    _HashTablePrivate *htp = ht->_private;
    List *l = get_bucket(ht, key);

    // 迭代器修改
    ListNode *node = htp->dummy_node;
    while (node->prev != htp->dummy_node) {
        Pair *p = *(Pair **)node->prev->val;
        if (is_equal(ht, key, p->first(p))) {
            ListNode *tmp = node->prev->prev;
            delete_list_node(node->prev);
            node->prev = tmp;
            break;
        }
        else
            node = node->prev;
    }

    htp->num--;
}

static size_t hash_table_size(HashTable *ht)
{
    _HashTablePrivate *htp = ht->_private;

    return htp->num;
}

