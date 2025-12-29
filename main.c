#include "raylib.h"
#include "raymath.h"
#include "enemy.h"
#include "blue_ball.h"
#include "green_ball.h"
#include "coin.h"
#include "ui.h"
#include "global.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void to_do(struct Player_inventory *inventory,enum game_screen *current_scr)
{
    if(!inventory->have_sword){
        inventory->health -= 3;
	    inventory->experience++;
    }else if(inventory->have_sword && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        inventory->experience++;
    }else{
        inventory->health -= 3;
    }
    if(inventory->health <= 0){
        *current_scr = die;
    }
}

void trade_do(enum game_screen *current_scr,struct Player_inventory *inventory)
{
    *current_scr = trade;
}

void view_tasks_do(enum game_screen *current_scr)
{
    *current_scr = view_tasks;
}

int main()
{
    enum game_screen current_scr = logo;
    enum game_screen next_scr;
    const register unsigned int window_w = 370;
    const register unsigned int window_h = 370;
    Texture2D player_texture;
    Texture2D enemy_texture;
    Texture2D coin_texture;
    Vector2 player_pos = {window_w/2,window_h/2};
    Vector2 player_direction = {0,0};
    Vector2 target_pos;
    Vector2 respawn_pos = {window_w/2,window_h/2};
    Rectangle player_rec;
    struct Player_inventory inventory = {0,false,"hand",false,"hand",0,20};
    bool moved;
    moved = false;
    float speed;
    float length;
    speed = 0.03;
    Texture2D grid;
    struct Enemy enemies[6];
    // a variable for counting the quantity of enemies
    int i;
    i = 0;
    // a variable for counting the quantity of coins
    int h;
    h = 0;
    int sleep_time;
    sleep_time = 0;
    struct Blue_ball blue_ball;
    blue_ball.pos = (Vector2){130,230};
    struct Green_ball green_ball;
    green_ball.pos = (Vector2){210,50};
    struct Coin coins[max_coin_quantity];

    InitWindow(window_w,window_h,"Raylib Disappeared keys");
    player_texture = LoadTexture("images\\player.png");
    enemy_texture = LoadTexture("images\\enemy.png");
    coin_texture = LoadTexture("images\\coin.png");
    grid = LoadTexture("images\\grid.png");
    blue_ball.texture = LoadTexture("images\\blue_ball.png");
    green_ball.texture = LoadTexture("images\\green_ball.png");
    Rectangle rebirth_button = create_button(130.0,75.0,(float)(window_w-130)/2,130.0);
    Rectangle stop_button = create_button(130.0,75.0,(float)(window_w-130)/2,35.0);
	struct Coin coin;
    char tasks[10][100];
    srand(time(NULL));
    init_tasks(tasks);
    for(int u = 0;u < 30;u++){
        coins[u].active = false;
    }
    while(!WindowShouldClose()){
        next_scr = current_scr;
        player_rec = (Rectangle){player_pos.x,player_pos.y,(float)player_texture.width,(float)player_texture.height};
	  switch(current_scr){
	    case logo : {
		    BeginDrawing();
	        DrawText("Powered by Raylib,GCC",36,160,26,LIGHTGRAY);
		    EndDrawing();
		    sleep_time++;
		    if(sleep_time > 6000){
		        next_scr = game;
		    }
	    }break;
	    case trade : {
	        BeginDrawing();
	        ClearBackground(RAYWHITE);
	        DrawRectangleRec(stop_button,LIGHTGRAY);
	        if(button_pressed(stop_button)){
	            player_rec = (Rectangle){player_pos.x,player_pos.y,(float)player_texture.width,(float)player_texture.height};
	            next_scr = game;
	            player_pos.x -= 30;
	            target_pos = player_pos;
	        }
	        EndDrawing();
	    }break;
	    case view_tasks : {
	        BeginDrawing();
	        DrawRectangleRec(stop_button,LIGHTGRAY);
	        if(button_pressed(stop_button)){
	            player_rec = (Rectangle){player_pos.x,player_pos.y,(float)player_texture.width,(float)player_texture.height};
	            next_scr = game;
	            player_pos.x -= 30;
	            target_pos = player_pos;
	        }
	        EndDrawing();
	    }break;
	    case game : {
	        // generate enemies
            if(rand() % 10000 == 0){
	           if(i >= 6){
	               printf("full");
	            }
	            else{
		            struct Enemy enemy;
					do{
						enemy.pos = (Vector2){(float)(rand() % window_w),(float)(rand() % window_h)};
						enemy.active = true;
						enemy.texture = enemy_texture;
						enemies[i++] = enemy;
					}while(Vector2Distance(enemy.pos,player_pos) < ENEMY_SAFE_DISTANCE);
	            }
	        }
	        // generate coins for player
	        if(rand() % 1000 == 0){
	            if(h < max_coin_quantity){
	                printf("s");
	                coin.pos = (Vector2){(float)(rand() % window_w),(float)(rand() % window_h)};
	                coin.active = true;
	                coin.texture = coin_texture;
	                coins[h] = coin;
	                h++;
	            }
	        }
        
	        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
	            target_pos = GetMousePosition();
	            player_direction.x = target_pos.x - player_pos.x;
	            player_direction.y = target_pos.y - player_pos.y;
	            length = sqrt(player_direction.x * player_direction.x + player_direction.y * player_direction.y);
	            if(length){
	    	        moved = true;
	                player_direction.x /= length;
		            player_direction.y /= length;
	            }else{
	                moved = false;
	            }
	        }
	        if(moved){
	            player_pos.x += player_direction.x * speed;
	            player_pos.y += player_direction.y * speed;
	            if(Vector2Distance(player_pos,target_pos) < speed){
	                player_pos = target_pos;
		              moved = false;
		        }
	        }
            BeginDrawing();
	        ClearBackground(RAYWHITE);
	        // DrawTexture(grid,0,0,WHITE);
            DrawTexture(player_texture,player_pos.x,player_pos.y,WHITE);
	        draw(enemies,6);
	        draw_blueball(blue_ball);
	        draw_greenball(green_ball);
	        draw_coin(coins,max_coin_quantity);
	        collide(enemies,player_pos,player_texture,6,to_do,&inventory,&next_scr);
	        collide_blue_ball(blue_ball,player_rec,trade_do,&inventory,&next_scr);
	        collide_green_ball(green_ball,player_rec,view_tasks_do,&next_scr);
	        EndDrawing();
	    }break;	
	    case die : {
	        BeginDrawing();
	        ClearBackground(RAYWHITE);
	        DrawRectangleRec(rebirth_button,LIGHTGRAY);
	        DrawText("Rebirth",rebirth_button.x + 20,rebirth_button.y + rebirth_button.height/2 - 10,20,BLACK);
	        if(button_pressed(rebirth_button)){
	            reset_player(&inventory,&player_pos,&target_pos,window_w,window_h);
	            next_scr = game;
	        }
	        EndDrawing();
	     }break;
	   }
	   current_scr = next_scr; 
    }
    CloseWindow();
    return 0;
}
