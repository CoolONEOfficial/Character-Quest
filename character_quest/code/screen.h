#ifndef _FILE_SCREEN_
#define _FILE_SCREEN_

#include "rect.h"
#include "coord.h"

#include "ncursesall.h"

// --------------------------- Screen ---------------------------

// Screen
int screenWidth(WINDOW* screen_);
int screenHeight(WINDOW* screen_);
Rect<Coord> screenRect(WINDOW* screen_);

// Default Screen

const int screenWidthDefault = 80;
const int screenHeightDefault = 24;
const Rect<Coord> screenDefault = Rect<Coord>(Coord(0, 0), Coord(screenWidthDefault, screenHeightDefault));

// --------------------------- Align ---------------------------

float alignX(float x_, WINDOW* screen_);
float alignY(float y_, WINDOW *screen_);

#endif // _FILE_SCREEN_

