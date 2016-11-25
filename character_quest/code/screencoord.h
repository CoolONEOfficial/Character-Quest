#ifndef _FILE_SCREENCOORD_
#define _FILE_SCREENCOORD_

#include "screen.h"
#include "rect.h"
#include "coord.h"

// --------------------------- Screen coord ---------------------------

class ScreenCoord : public Coord
{
public:
    explicit ScreenCoord(int x_ = 0, int y_ = 0, WINDOW* screen_ = new WINDOW());

    // Screen
    WINDOW* screen;
    void initScreen(WINDOW* screen_);

    // Align
    float alignX(float x_);
    float alignY(float y_);

    // Aligned coord
    int getX();
    int getY();
};

#endif // _FILE_SCREENCOORD_
