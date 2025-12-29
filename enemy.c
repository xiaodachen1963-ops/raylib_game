#include "raylib.h"
#include "enemy.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void draw(struct Enemy enemies[],const int register size)
{
    Texture2D t;
    Vector2 p;
    for(int o = 0;o < size;o++){
        if(enemies[o].active){
	    t = enemies[o].texture;
	    p = enemies[o].pos;
	    DrawTexture(t,p.x,p.y,WHITE);
	}
    }
}

void collide(struct Enemy enemies[],Vector2 player_pos,Texture2D player_texture,\
const int register size,void(*to_do)(struct Player_inventory *inventory,\
enum game_screen *current_scr),struct Player_inventory *inventory,\
enum game_screen *current_scr)
{
    Rectangle enemy_rec;
    Rectangle player_rec;
    for(int o = 0;o < size;o++){
        if(enemies[o].active){
	        player_rec.x = player_pos.x;
	        player_rec.y = player_pos.y;
	        player_rec.width = player_texture.width;
	        player_rec.height = player_texture.height;
	        enemy_rec.x = enemies[o].pos.x;
	        enemy_rec.y = enemies[o].pos.y;
	        enemy_rec.width = enemies[o].texture.width;
	        enemy_rec.height = enemies[o].texture.height;
	        if(CheckCollisionRecs(player_rec,enemy_rec)){
		        to_do(inventory,current_scr);
	        }
	    }
    }
}

void move_enemy(struct Enemy enemies[],const int register size,const float speed)
{
    srand(time(NULL));
    for(int o = 0;o < size;o++){
        if(enemies[o].active){
            enemies[o].pos.x += (rand() % 3 - 1) * speed;
            enemies[o].pos.y += (rand() % 3 - 1) * speed;
        }
    }
}
