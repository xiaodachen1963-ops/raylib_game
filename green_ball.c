#include "raylib.h"
#include "green_ball.h"
#include "global.h"

void draw_greenball(struct Green_ball green_ball)
{
    DrawTexture(green_ball.texture,green_ball.pos.x,green_ball.pos.y,RAYWHITE);
}

void collide_green_ball(struct Green_ball green_ball,Rectangle player_rec,void(*to_do)(enum game_screen *current_scr),enum game_screen *current_scr)
{
    Rectangle green_ball_rec = {green_ball.pos.x,green_ball.pos.y,green_ball.texture.width,green_ball.texture.height};
    if(CheckCollisionRecs(green_ball_rec,player_rec)){
        to_do(current_scr);
    }
}
