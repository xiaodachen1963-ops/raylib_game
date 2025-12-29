#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "global.h"

#define max_number_of_enemies 6
#define ENEMY_SAFE_DISTANCE 80.0f

struct Enemy
{
    Vector2 pos;
    Texture2D texture;
    bool active;
};

void draw(struct Enemy enemies[],const int register size);
void collide(struct Enemy enemies[],Vector2 player_pos,Texture2D player_texture,\
const int register size,void(*to_do)(struct Player_inventory *inventory,\
enum game_screen *current_scr),struct Player_inventory *inventory,\
enum game_screen *current_scr);
void move_enemy(struct Enemy enemies[],const int register size,const float speed);

#endif
