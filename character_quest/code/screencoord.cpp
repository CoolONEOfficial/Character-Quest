#include "screencoord.h"

ScreenCoord::ScreenCoord(int x_, int y_, WINDOW *screen_)
{
    // Coord
    setX(x_);
    setY(y_);

    // Screen
    initScreen(screen_);
}

void ScreenCoord::initScreen(WINDOW *screen_)
{
    // Init screen

    screen = screen_;
}

float ScreenCoord::alignX(float x_)
{
    // Align X

    return ::alignX(x_, screen);
}

float ScreenCoord::alignY(float y_)
{
    // Align Y

    return ::alignY(y_, screen);
}

int ScreenCoord::getX()
{
    // Get X

    return alignX(Coord::getX());
}

int ScreenCoord::getY()
{
    // Get Y

    return alignY(Coord::getY());
}
