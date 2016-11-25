#ifndef _FILE_LABEL_
#define _FILE_LABEL_

#include "rect.h"
#include "screencoord.h"
#include "font.h"

#include "ncursesall.h"
#include <string>

using namespace std;

// --------------------------- Label ---------------------------

class Label
{
public:
    explicit Label(string text_ = "NoName", Font* font_ = new Font(), Rect<ScreenCoord> rect_ = Rect<ScreenCoord>(), WINDOW* screen_ = new WINDOW());

    // Text
private:
    string text;
public:

    // Rect
    Rect<ScreenCoord> rect;

    // Font
    Font* font;

    // Draw
    bool draw();
    bool drawText(string size_, string text_);

    // Screen
    WINDOW* screen;
    float alignX(float x_);
    float alignY(float y_);
    void initScreen(WINDOW* screen_);

    // Size
    int textWidth(string size_, string text_);
    int textHeight(string size_, string text_);

    // Coords
    int textX(string size_, string text_);
    int textY(string size_, string text_);
    Coord textCoord(string size_, string text_);

    // --------------------------- Encapsulation ---------------------------

    virtual string getText();
    virtual void setText(string text_);
};

#endif // _FILE_LABEL_
