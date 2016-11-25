#include "screen.h"

int screenWidth(WINDOW *screen_)
{
    // Screen width

    return getmaxx(screen_);
}

int screenHeight(WINDOW *screen_)
{
    // Screen height

    return getmaxy(screen_);
}

Rect<Coord> screenRect(WINDOW *screen_)
{
    // Screen rect

    return Rect<Coord>(Coord(0, 0), Coord(screenWidth(screen_), screenHeight(screen_)));
}

float alignX(float x_, WINDOW *screen_)
{
    // Align X

    return (x_ * screenWidth(screen_)) / screenWidthDefault;
}

float alignY(float y_, WINDOW *screen_)
{
    // Align Y

    return (y_ * screenHeight(screen_)) / screenHeightDefault;
}
