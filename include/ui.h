#ifndef UI_H
#define UI_H

#include "raylib.h"
#include "global.h"

Rectangle create_button(const float width,const float height,const float x,const float y);
bool button_pressed(Rectangle button);

#endif
