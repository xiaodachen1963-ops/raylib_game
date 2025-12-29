#include "blue_ball.h"
#include "global.h"
#include "raylib.h"

void start_trading(enum game_screen *current_scr)
{
    *current_scr = trade;
}

void draw_blueball(struct Blue_ball blue_ball)
{
    Texture2D t = blue_ball.texture;
    Vector2 p = blue_ball.pos;
    DrawTexture(t,p.x,p.y,WHITE);
}

void collide_blue_ball(struct Blue_ball blue_ball,Rectangle player_rec,void(*to_do)(enum game_screen *current_scr,\
struct Player_inventory *inventory),struct Player_inventory *inventory,enum game_screen *current_scr)
{
    Rectangle blue_ball_rec;
    blue_ball_rec.x = blue_ball.pos.x;
    blue_ball_rec.y = blue_ball.pos.y;
    blue_ball_rec.width = blue_ball.texture.width;
    blue_ball_rec.height = blue_ball.texture.height;
    if(CheckCollisionRecs(player_rec,blue_ball_rec)){
        to_do(current_scr,inventory);
	}
}
