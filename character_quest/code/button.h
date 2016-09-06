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
    Button(string name_ = "button", float x_ = 0, float y_ = 0,
           float indent_ = 1, bool align_ = true);

    // Draw
    void draw(int scrW, int scrH);
    void drawHorizontalBorder(int scrW);

    // Size
    float width(int scrW);
    float height(int scrH);

    // Indent
    int indentW(int scrW);
    int indentH(int scrH);

    // --------------------------- Values ---------------------------

    // Name
    string getName();
    void setName(string name_);

    // Coords
    float getX();
    void setX(float x_);
    float getY();
    void setY(float y_);

    // Indent
    float getIndent();
    void setIndent(float indent_);

    // Setlected
    bool getSelected();
    void setSelected(bool selected_);

    // Align
    bool getAlign();
    void setAlign(bool align_);

private:
    // Name
    string name;

    // Coords
    float x, y;

    // Indent
    float indent;

    // Selected
    bool selected;

    // Align
    bool align;
};

#endif // _FILE_BUTTON_
