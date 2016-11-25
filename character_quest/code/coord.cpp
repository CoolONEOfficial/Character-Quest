#include "coord.h"

Coord::Coord(int x_, int y_)
{
    // X
    setX(x_);

    // Y
    setY(y_);
}

// --------------------------- Values ---------------------------

// X

int Coord::getX()
{
    // Get
    return x;
}
void Coord::setX(int x_)
{
    // Set
    x = x_;
}

// Y

int Coord::getY()
{
    // Get
    return y;
}
void Coord::setY(int y_)
{
    // Set
    y = y_;
}
