#ifndef GLOBAL_H
#define GLOBAL_H
#define max_task_quantity 10
#define max_coin_quantity 30

#include "raylib.h"

struct Player_inventory
{
    int coins;
    bool have_sword;
    char sword_type[20];
    bool have_pickaxe;
    char pickaxe_type[20];
    int experience;
    int health;
};
enum game_screen{logo = 0,game,trade,view_tasks,die,end};

extern char tasks[10][100];

void reset_player(struct Player_inventory *inventory,Vector2 *player_pos,Vector2 *target,const int window_w,const int window_h);
void init_tasks(char tasks[][100]);

#endif
