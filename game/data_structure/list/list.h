#pragma once

#include "../head.h"

typedef struct list {
    void *_private;
    size_t (*size)(List *l);
    bool (*empty)(List *l);
    void (*pop_back)(List *l);
    void (*pop_front)(List *l);
    void (*push_back)(List *l, void *val);
    void (*push_front)(List *l, void *val);
    void *(*front)(List *l);
    void *(*back)(List *l);
    ListIterator *(*erase)(List *l, ListIterator *li);
    // iterator

    ListIterator *(*begin)(List *l);
    ListIterator *(*end)(List *l);
    ListIterator *(*rbegin)(List *l);
    ListIterator *(*rend)(List *l);
} List;

typedef struct list_iterator {
    void *_private;
    void (*pp)(ListIterator *li);
    void (*mm)(ListIterator *li);
    void *(*get_val)(ListIterator *li);
} ListIterator;

List *new_list(void *vals, int num, size_t val_size);
