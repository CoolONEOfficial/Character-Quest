#include "button.h"

Button::Button(string name_, ScreenCoord coord_,
               float indent_, WINDOW *screen_)
{
    // Screen
    initScreen(screen_);

    // Name
    setName(name_);

    // Coords
    coord = coord_;

    // Deselect
    setSelected(false);

    // Indent
    setIndent(indent_);
}

void Button::draw()
{
    // Draw

    assert(screen != new WINDOW());

    // Set draw coords

    Coord drawCoord(coord.getX() - width()/2,
                    coord.getY() - height()/2);

    move(0,0);
    printw("scrW:%i scrH:%i", screenWidth(screen), screenHeight(screen));

    // Borders

    // Up

    // Angle
    move(drawCoord.getY(), drawCoord.getX());
    printw("/");

    // Border
    drawHorizontalBorder();

    // Angle
    move(drawCoord.getY(), drawCoord.getX() + width()-1);
    printw("\\");

    // Middle

    if(selected)
    {
        for(int f = 0; f < height()-2; f++)
        {
            // Left
            move(drawCoord.getY()+1 + f, drawCoord.getX());
            printw("|");

            // Right
            move(drawCoord.getY()+1 + f, drawCoord.getX() + width()-1);
            printw("|");
        }
    }

    // Down

    // Angle
    move(drawCoord.getY() + height()-1, drawCoord.getX());
    printw("\\");

    // Border
    drawHorizontalBorder();

    // Angle
    move(drawCoord.getY() + height()-1, drawCoord.getX() + width()-1);
    printw("/");

    // Name
    move(drawCoord.getY()+1 + indentHeight(), drawCoord.getX()+1 + indentWidth());
    printw("%s", name.c_str());
}

void Button::drawHorizontalBorder()
{
    // Draw up/down border
    if(selected)
    {
        for(unsigned int f = 0; f < width()-2; f++)
        {
            printw("-");
        }
    }
}

float Button::width()
{
    // Width

    return 2.0f + name.size() + indentWidth()*2.0f;
}

float Button::height()
{
    // Height

    return 2.0f + indentHeight()*2.0f + 1.0f;
}

int Button::indentWidth()
{
    // Width indent

    return alignX(indent*2);
}

int Button::indentHeight()
{
    // Height indent

    return alignY(indent);
}

float Button::alignX(float x_)
{
    // Align X

    return ::alignX(x_, screen);
}

float Button::alignY(float y_)
{
    // Align Y

    return ::alignY(y_, screen);
}

void Button::initScreen(WINDOW *screen_)
{
    // Set screen

    if(screen_ != new WINDOW())
    {
        screen = screen_;

        // Coord
        coord.initScreen(screen_);
    }
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
