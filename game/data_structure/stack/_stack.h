#pragma once

#include "../head.h"
#include "../list/list.h"

static int stack_size(Stack *s);
static bool stack_is_empty(Stack *s);
static void stack_pop(Stack *s);
static void stack_push(Stack *s, void *val);
static void *stack_top(Stack *s);