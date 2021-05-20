#pragma once

#define debug

#include "../head.h"

typedef struct list_node ListNode;

typedef struct list_node {
    void *val;
    ListNode *prev;
    ListNode *next;
} ListNode;

typedef struct _list_private {
    size_t num;
    ListNode *dummy_node;
    ListNode *final_node;
    size_t val_size;
} _ListPrivate;

typedef struct _list_iterator_private {
    ListNode *node;
} _ListIteratorPrivate;

static _ListPrivate *new_list_private(void *vals, int num, size_t val_size);
static ListIterator *new_list_iterator(ListNode *node);
static _ListIteratorPrivate *new_list_iterator_private(ListNode *node);
ListNode *new_list_node(void *val, ListNode *prev, ListNode *next, size_t val_size);
void delete_list_node(ListNode *node);

// 增
static void list_push_front(List *list, void *obj);
static void list_push_back(List *list, void *obj);
// 删
static void list_pop_front(List *list);
static void list_pop_back(List *list);
static ListIterator *list_erase(List *l, ListIterator *li);
// 改
static void *list_front(List *list);
static void *list_back(List *list);
// 查
static size_t list_size(List *list);
static bool list_empty(List *list);
// iterator
static ListIterator *list_begin(List *l);
static ListIterator *list_end(List *l);
static ListIterator *list_rbegin(List *l);
static ListIterator *list_rend(List *l);
static void list_iterator_pp(ListIterator *li);
static void list_iterator_mm(ListIterator *li);
static void *list_iterator_get_val(ListIterator *li);

#ifdef debug
static void my_error(char *s);
#endif