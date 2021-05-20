#include "_main.h"


void init()
{
    init_event();
    init_game_db();
}

int main()
{
    init();
    Character *hero = new_character();

    GameDB *db = new_game_db();

    DATA_BASE_STATE s = db->save(db, GD_CHARACTER, hero);
    
}