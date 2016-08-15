#ifndef _FILE_SCREEN_
#define _FILE_SCREEN_

#include <ncursesall.h>

// --------------------------- Screen ---------------------------

// Start Width / Height
const int scrDWidth = 80;
const int scrDHeight = 24;

// Width / Height
float scrWidth();
float scrHeight();

// Align
int alignW(int val, int scrW = scrWidth());
int alignH(int val, int scrH = scrHeight());

#endif // _FILE_SCREEN_

