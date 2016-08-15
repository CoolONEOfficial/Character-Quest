#ifndef _FILE_BUTTON_
#define _FILE_BUTTON_

#include "screen.h"

#include <string>
#include <ncursesall.h>

using namespace std;

// --------------------------- Button ---------------------------

class Button
{
public:
    Button(string bName = "button", float bX = 0, float bY = 0,
           float bIndent = 1, bool bAlign = true);

    // Name
    string name;

    // Coords
    float x, y;

    // Indent
    float indent;

    // Selected
    bool select;

    // Align
    bool align;

    // Size
    float width(int scrW);
    float height(int scrH);

    // Indent
    int indentW(int scrW);
    int indentH(int scrH);

    void draw(int scrW, int scrH);

private:
    void drawUpDownBorder(int scrW);
};

#endif // _FILE_BUTTON_
