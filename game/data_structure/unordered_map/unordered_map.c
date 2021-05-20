#include "unordered_map.h"
#include "_unordered_map.h"


UnorderedMap *new_unordered_map(Vector *pairs, size_t n, UNORDERED_MAP_KEY_T type)
{
    UnorderedMap *um = malloc(sizeof(UnorderedMap));

    um->_private = new_unordered_map_private(pairs, n, type);
    um->insert = unordered_map_insert;
    um->at = unordered_map_at;
    um->erase = unordered_map_erase;
    um->size = unordered_map_size;

    um->begin = unordered_map_begin;
    um->end = unordered_map_end;

    return um;
}

static _UnorderedMapPrivate *new_unordered_map_private(Vector *pairs, size_t n, UNORDERED_MAP_KEY_T type)
{
    _UnorderedMapPrivate *ump = malloc(sizeof(_UnorderedMapPrivate));

    HASH_TABLE_KEY_T hk;
    switch (type) {
        case UK_INT:
            hk = HK_INT;
            break;
        case UK_STRING:
            hk = HK_STRING;
            break;
    }

    ump->ht = new_hash_table(pairs, n, hk);

    return ump;
}

static UnorderedMapIterator *new_unordered_map_iterator(ListNode *node)
{
    UnorderedMapIterator *umi = malloc(sizeof(UnorderedMapIterator));

    umi->_private = new_unordered_map_iterator_private(node);
    umi->pp = unordered_map_iterator_pp;
    umi->get_val = unordered_map_iterator_get_val;

    return umi;
}

static _UnorderedMapIteratorPrivate *new_unordered_map_iterator_private(ListNode *node)
{
    _UnorderedMapIteratorPrivate *umip = malloc(sizeof(_UnorderedMapIteratorPrivate));

    umip->node = node;

    return umip;
}

static void unordered_map_insert(UnorderedMap *um, Pair *p)
{
    _UnorderedMapPrivate *ump = um->_private;

    ump->ht->insert(ump->ht, p);
}

static void *unordered_map_at(UnorderedMap *um, void *key)
{
    _UnorderedMapPrivate *ump = um->_private;

    return ump->ht->at(ump->ht, key);
}

static void unordered_map_erase(UnorderedMap *um, void *key)
{
    _UnorderedMapPrivate *ump = um->_private;

    ump->ht->erase(ump->ht, key);
}

static size_t unordered_map_size(UnorderedMap *um)
{
    _UnorderedMapPrivate *ump = um->_private;

    return ump->ht->size(ump->ht);
}

static UnorderedMapIterator *unordered_map_begin(UnorderedMap *um)
{
    _UnorderedMapPrivate *ump = um->_private;
    _HashTablePrivate *htp = ump->ht->_private;
    
    UnorderedMapIterator *umi = new_unordered_map_iterator(htp->dummy_node->prev);

    return umi;
}

static UnorderedMapIterator *unordered_map_end(UnorderedMap *um)
{
    _UnorderedMapPrivate *ump = um->_private;
    _HashTablePrivate *htp = ump->ht->_private;
    
    UnorderedMapIterator *umi = new_unordered_map_iterator(htp->dummy_node);

    return umi;
}

static void unordered_map_iterator_pp(UnorderedMapIterator *umi)
{
    _UnorderedMapIteratorPrivate *umip = umi->_private;

    umip->node = umip->node->prev;
}

static Pair *unordered_map_iterator_get_val(UnorderedMapIterator *umi)
{
    _UnorderedMapIteratorPrivate *umip = umi->_private;

    return umip->node->val;
}