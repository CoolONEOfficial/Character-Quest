#include "button.h"

Button::Button(string name_, float x_, float y_,
               float indent_, bool align_)
{
    // Name
    setName(name_);

    // Coords
    setX(x_);
    setY(y_);

    // Deselect
    setSelected(false);

    // Indent
    setIndent(indent_);

    // Align
    setAlign(align_);
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
    drawHorizontalBorder(scrW);

    // Angle
    move(dY, dX + width(scrW)-1);
    printw("\\");

    // Middle

    if(selected)
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
    drawHorizontalBorder(scrW);

    // Angle
    move(dY + height(scrH)-1, dX + width(scrW)-1);
    printw("/");

    // Name
    move(dY+1 + indentH(scrH), dX+1 + indentW(scrW));
    printw("%s", name.c_str());
}

void Button::drawHorizontalBorder(int scrW)
{
    // Draw up/down border
    if(selected)
    {
        for(unsigned int f = 0; f < width(scrW)-2; f++)
        {
            printw("-");
        }
    }
}

float Button::width(int scrW)
{
    // Width

    return 2 + name.size() + indentW(scrW)*2.0;
}

float Button::height(int scrH)
{
    // Height

    return 2 + indentH(scrH)*2 + 1;
}

int Button::indentW(int scrW)
{
    // Width indent

    return alignW(indent * 2.0, scrW);
}

int Button::indentH(int scrH)
{
    // Height indent

    return alignH(indent * (scrH / 24.0), scrH);
}

// --------------------------- Values ---------------------------

// Name

string Button::getName()
{
    // Get
    return name;
}
void Button::setName(string name_)
{
    // Set
    name = name_;
}

// X

float Button::getX()
{
    // Get
    return x;
}
void Button::setX(float x_)
{
    // Set
    x = x_;
}

// Y

float Button::getY()
{
    // Get
    return y;
}
void Button::setY(float y_)
{
    // Set
    y = y_;
}

// Indent

float Button::getIndent()
{
    // Get
    return indent;
}
void Button::setIndent(float indent_)
{
    // Set
    indent = indent_;
}

// Selected

bool Button::getSelected()
{
    // Get
    return selected;
}
void Button::setSelected(bool selected_)
{
    // Set
    selected = selected_;
}

// Align

bool Button::getAlign()
{
    // Get
    return align;
}
void Button::setAlign(bool align_)
{
    // Set
    align = align_;
}
