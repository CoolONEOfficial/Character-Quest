#ifndef _FILE_SCREENRECT_
#define _FILE_SCREENRECT_

#include "rect.h"
#include "screen.h"
#include "screencoord.h"

#include <stdlib.h>
#include <cassert>

// --------------------------- Screen rect ---------------------------

class ScreenRect : public Rect
{
public:
    explicit ScreenRect(pair<Coord*, Coord*> coord_ = make_pair(new ScreenCoord(), new ScreenCoord()), WINDOW* screen_ = new WINDOW());
    explicit ScreenRect(Coord* coordFirst_, Coord* coordSecond_, WINDOW* screen_ = new WINDOW());

    // Screen coords
private:
    ScreenCoord coordFirst;
    ScreenCoord coordSecond;
public:

    // Screen
    void initScreen(WINDOW* screen_);

    // --------------------------- Encapsulation ---------------------------

    void getCoordFirst();
    void getCoordSecond();
};

#endif // _FILE_SCREENRECT_
