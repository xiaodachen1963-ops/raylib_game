#include "raylib.h"
#include "global.h"
#include <string.h>

void reset_player(struct Player_inventory *inventory,Vector2 *player_pos,Vector2 *target,const int window_w,const int window_h)
{
    inventory->coins = 0;
    inventory->have_sword = false;
    strcpy(inventory->sword_type,"hand");
    inventory->have_pickaxe = false;
    strcpy(inventory->pickaxe_type,"hand");
    inventory->experience = 0;
    inventory->health = 20;
    player_pos->x = (float)window_w / 2;
    player_pos->y = (float)window_h / 2;
    target->x = (float)window_w / 2;
    target->y = (float)window_h / 2;
}

void init_tasks(char tasks[][100])
{
    strcpy(tasks[0],"Get enough coins");
    strcpy(tasks[1],"Buy a steel sword,but don't kill me");
    strcpy(tasks[2],"Kill a monster");
    strcpy(tasks[3],"Cut down a tree");
}
