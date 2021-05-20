#pragma once

#include "../game_head.h"
#include "../vector/vector.h"


static Event *new_event();
static void event_add(Event *e, func_t func, void *args);
static void event_exe(Event *e);