#ifndef _FILE_BUTTON_
#define _FILE_BUTTON_

#include "screen.h"
#include "rect.h"
#include "screencoord.h"

#include <string>
#include <cassert>
#include "ncursesall.h"

using namespace std;

// --------------------------- Button ---------------------------

class Button
{
public:
    explicit Button(string name_ = "button", ScreenCoord coord_ = ScreenCoord(),
                    float indent_ = 1, WINDOW* screen_ = new WINDOW());

private:
    // Name
    string name;
public:

    // Coords
    ScreenCoord coord;

    // Size
    float width();
    float height();

    // Indent
private:
    float indent;
public:
    int indentWidth();
    int indentHeight();

    // Screen
    WINDOW* screen;
    float alignX(float x_);
    float alignY(float y_);
    void initScreen(WINDOW* screen_);

    // Draw
    void draw();
    void drawHorizontalBorder();

private:
    // Selected
    bool selected;
public:

    // --------------------------- Encapsulation ---------------------------

    // Name
    string getName();
    void setName(string name_);

    // Indent
    float getIndent();
    void setIndent(float indent_);

    // Setlected
    bool getSelected();
    void setSelected(bool selected_);
};

#endif // _FILE_BUTTON_
