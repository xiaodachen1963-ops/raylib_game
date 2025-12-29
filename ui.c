#include "ui.h"
#include "raylib.h"

Rectangle create_button(const float width,const float height,const float x,const float y)
{
    Rectangle button = {x,y,width,height};
    return button;
}

bool button_pressed(Rectangle button)
{
    if(CheckCollisionPointRec(GetMousePosition(),button)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            return true;
        }
    }
    return false;
}
