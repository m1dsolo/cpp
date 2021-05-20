#pragma once

#include "al_head.h"

typedef enum sort_type {
    ST_BUBBLE, 
    ST_SELECT, 
    ST_INSERTION, 
    ST_QUICK
} SORT_TYPE;

void sort(Vector *v, SORT_TYPE st);
void print_vector(Vector *v);
void print_vector_vector(Vector *v);

Vector *full_permutation(Vector *v);

static void sort_bubble(Vector *v);
static void sort_select(Vector *v);
static void sort_insertion(Vector *v);
static void sort_quick(Vector *v);

static void swap_by_index(Vector *v, int i, int j);
static void swap_by_pointer(void *i, void *j, size_t size);

static void sort_quick_helper(Vector *v, int left, int right);

static void full_permutation_helper(Vector *v, Vector *tmp, Vector *rst);