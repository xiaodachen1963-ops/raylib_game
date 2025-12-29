#ifndef GREEN_BALL_H
#define GREEN_BALL_H

#include "raylib.h"
#include "global.h"

struct Green_ball
{
    Texture2D texture;
    Vector2 pos;
};

void draw_greenball(struct Green_ball green_ball);
void collide_green_ball(struct Green_ball green_ball,Rectangle player_rec,void(*to_do)(enum game_screen *current_scr),enum game_screen *current_scr);

#endif
