#include "button.h"

Button::Button(string bName, float bX, float bY,
               float bIndent, bool bAlign)
{
    // Name
    name = bName;

    // Coords
    x = bX;
    y = bY;

    // Deselect
    select = false;

    // Indent
    indent = bIndent;

    // Align
    align = bAlign;
}

float Button::width(int scrW)
{
    return 2 + name.size() + indentW(scrW)*2.0;
}

float Button::height(int scrH)
{
    return 2 + indentH(scrH)*2 + 1;
}

int Button::indentW(int scrW)
{
    return alignW(indent * 2.0, scrW);
}

int Button::indentH(int scrH)
{
    return alignH(indent * (scrH / 24.0), scrH);
}

void Button::draw(int scrW, int scrH)
{
    // Draw

    int dX;
    int dY;

    if(align)
    {
        dX = alignW(x, scrW);
        dY = alignH(y, scrH);
    }
    else
    {
        dX = x;
        dY = y;
    }

    dX -= width(scrW)/2.0;
    dY -= height(scrH)/2.0;

    // Borders

    // Up

    // Angle
    move(dY, dX);
    printw("/");

    // Border
    drawUpDownBorder(scrW);

    // Angle
    move(dY, dX + width(scrW)-1);
    printw("\\");

    // Middle

    if(select)
    {
        for(int f = 0; f<1 + indentH(scrH)*2; f++)
        {
            // Left
            move(dY+1 + f, dX);
            printw("|");

            // Right
            move(dY+1 + f, dX + width(scrW)-1);
            printw("|");
        }
    }

    // Down

    // Angle
    move(dY + height(scrH)-1, dX);
    printw("\\");

    // Border
    drawUpDownBorder(scrW);

    // Angle
    move(dY + height(scrH)-1, dX + width(scrW)-1);
    printw("/");

    // Name
    move(dY+1 + indentH(scrH), dX+1 + indentW(scrW));
    printw("%s", name.c_str());
}

void Button::drawUpDownBorder(int scrW)
{
    // Draw up/down border
    if(select)
    {
        for(unsigned int f = 0; f < width(scrW)-2; f++)
        {
            printw("-");
        }
    }
}
