#ifndef BLUE_BALL_H
#define BLUE_BALL_H

#include "raylib.h"
#include "global.h"

struct Blue_ball
{
    Texture2D texture;
    Vector2 pos;
    bool is_trading;
};

void start_trading(enum game_screen *current_scr);
void draw_blueball(struct Blue_ball blue_ball);
void collide_blue_ball(struct Blue_ball blue_ball,Rectangle player_rec,void(*to_do)(enum game_screen *current_scr,\
struct Player_inventory *inventory),struct Player_inventory *inventory,enum game_screen *current_scr);

#endif
