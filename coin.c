#include "coin.h"
#include "raylib.h"

void add_coins_to_inventory(int *coin,int count)
{
    *coin = *coin + count;
}

void draw_coin(struct Coin *coins,const int size)
{
    for(int o = 0;o < size;o++){
        if(coins[o].active){
            DrawTexture(coins[o].texture,coins[o].pos.x,coins[o].pos.y,WHITE);
        }

    }
}
