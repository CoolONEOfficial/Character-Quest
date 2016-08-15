#ifndef _FILE_TEXT_
#define _FILE_TEXT_

#include "screen.h"
#include "font.h"

#include <string>

using namespace std;

// --------------------------- Text ---------------------------

// Draw
bool drawText(int dX, int dY, string dText, string size, Font *tFont,
              int dSX = 0, int dSY = 0, int dSW = scrWidth(), int dSH = scrHeight(), int dIndent = 2);

// Width / Height
int textWidth(string eText, string tSize, Font *tFont, int dIndent = 2);
int textHeight(string eText, string tSize, Font *tFont);

#endif // _FILE_TEXT_

