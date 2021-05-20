#include "show.h"
#include "_show.h"


void show_fight_begin(FightContext *fc)
{
    for (int i = 0; i < fc->fs0->size(fc->fs0); i++) {
        Fighter *f = *(Fighter **)fc->fs0->at(fc->fs0, i);

        printf("%s level:%d hp:%d/%d atk:%d def:%d spd:%d\n", f->c->get_attr(f->c, ))
    }
}