#include "vector.h"
#include "_vector.h"

typedef struct {
    char *name;
    int age;
} Person;

Vector *new_vector(void *vals, int num, int val_size)
{
    Vector *v = malloc(sizeof(Vector));

    v->_private = new_vector_private(vals, num, val_size);
    v->size = vector_size;
    v->max_size = vector_max_size;
    v->empty = vector_empty;
    v->pop_back = vector_pop_back;
    v->push_back = vector_push_back;
    v->front = vector_front;
    v->back = vector_back;
    v->clear = vector_clear;
    v->at = vector_at;
    v->erase = vector_erase;

    return v;
}

static _VectorPrivate *new_vector_private(void *vals, int num, int val_size)
{
    _VectorPrivate *vp = malloc(sizeof(_VectorPrivate));

    vp->max_num = num < 7 ? 10 : (int)(num * 1.5);
    vp->buf_begin = malloc(val_size * vp->max_num);
    memcpy(vp->buf_begin, vals, val_size * num);
    vp->last_num = num;
    vp->obj_size = val_size;

    return vp;
}

void del_vector(Vector *v)
{
    _VectorPrivate *vp = v->_private;

    free(vp->buf_begin);
    vp->buf_begin = NULL;
    free(v->_private);
    v->_private = NULL;

    v->size = NULL;
    v->max_size = NULL;
    v->empty = NULL;
    v->pop_back = NULL;
    v->push_back = NULL;
    v->front = NULL;
    v->back = NULL;
    v->clear = NULL;
    v->at = NULL;
    v->erase = NULL;
}

static size_t vector_size(Vector *v)
{
    _VectorPrivate *vp = v->_private;

    return vp->last_num;
}

static size_t vector_max_size(Vector *v)
{
    _VectorPrivate *vp = v->_private;

    return vp->max_num;
}

static bool vector_empty(Vector *v)
{
    _VectorPrivate *vp = v->_private;

    return vp->last_num == 0;
}

static void vector_pop_back(Vector *v)
{
    _VectorPrivate *vp = v->_private;

    if (vp->last_num == 0)
        return;
    
    vp->last_num--;
}

static void vector_push_back(Vector *v, void *val)
{
    _VectorPrivate *vp = v->_private;

    if (vp->last_num == vp->max_num) {
        vp->max_num *= 1.5;
        vp->buf_begin = realloc(vp->buf_begin, (size_t)(vp->max_num));
    }

    void *src = &((void **)vp->buf_begin)[vp->last_num * vp->obj_size / sizeof(void *)];
    memcpy(src, val, vp->obj_size);

    vp->last_num++;
}

static void *vector_front(Vector *v)
{
    _VectorPrivate *vp = v->_private;

    return vp->buf_begin;
}

static void *vector_back(Vector *v)
{
    _VectorPrivate *vp = v->_private;

    void **ptr = vp->buf_begin;
    return &ptr[(vp->last_num - 1) * vp->obj_size / sizeof(void *)];
}

static void vector_clear(Vector *v)
{
    _VectorPrivate *vp = v->_private;

    vp->last_num = 0;
}

static void *vector_at(Vector *v, int index)
{
    _VectorPrivate *vp = v->_private;

    if (index >= 0 && index < vp->last_num) {
        return &((void **)vp->buf_begin)[index * vp->obj_size / sizeof(void *)];
    }
    else
        return NULL;
}

static void vector_erase(Vector *v, int index)
{
    _VectorPrivate *vp = v->_private;

    if (index >= 0 && index < vp->last_num) {
        void *dest = (void *)(&((char *)vp->buf_begin)[vp->obj_size * index]);
        void *rst = (void *)(&((char *)vp->buf_begin)[vp->obj_size * (index + 1)]);
        vp->last_num -= 1;
        memcpy(dest, rst, vp->obj_size * (vp->last_num - index));
    }
    else {
        perror("vector set");
        exit(EXIT_FAILURE);
    }
}