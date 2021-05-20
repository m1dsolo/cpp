#pragma once

#include "../head.h"

typedef struct _vector_private {
    size_t max_num;        // 最大obj个数
    size_t last_num;       // 总共obj个数
    size_t cur_num;        // 当前obj下标
    size_t obj_size;
    void *buf_begin;
} _VectorPrivate;

static _VectorPrivate *new_vector_private(void *vals, int num, int val_size);

static size_t vector_size(Vector *v);
static size_t vector_max_size(Vector *v);
static bool vector_empty(Vector *v);
static void vector_pop_back(Vector *v);
static void vector_push_back(Vector *v, void *val);
static void *vector_front(Vector *v);
static void *vector_back(Vector *v);
static void vector_clear(Vector *v);
static void *vector_at(Vector *v, int index);
static void vector_erase(Vector *v, int index);