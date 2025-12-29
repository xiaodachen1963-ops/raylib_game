#ifndef COIN_H
#define COIN_H
#include "raylib.h"
#include "global.h"

struct Coin
{
    Texture2D texture;
    Vector2 pos;
    bool active;
};

void add_coin_to_inventory(int *coins,int count);
void draw_coin(struct Coin coins[],const int size);

#endif
