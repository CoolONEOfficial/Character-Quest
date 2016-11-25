#include "label.h"

Label::Label(string text_, Font *font_, Rect<ScreenCoord> rect_, WINDOW *screen_)
{
    // Screen
    initScreen(screen_);

    // Text
    setText(text_);

    // Font
    font = font_;

    // Rect
    rect = rect_;
}

bool Label::draw()
{
    // Draw

    assert(screen != new WINDOW());

    if(!drawText("big", getText()))
        if(!drawText("normal", getText()))
            if(!drawText("small", getText()))
                if(!drawText("natural", getText()))
                    return false;

    return true;
}

bool Label::drawText(string size_, string text_)
{
    // Draw text

    if( textX(size_, text_) > rect.coordFirst.getX() &&
            textX(size_, text_) + textWidth(size_, text_) < rect.coordSecond.getX() &&
            textY(size_, text_) > rect.coordFirst.getY() &&
            textY(size_, text_) + textHeight(size_, text_) < rect.coordSecond.getY() )
    {
        // Draw
        int mCharX = textX(size_, text_);
        for(auto mChar: getText())
        {
            // Draw char
            font->image[mChar]->draw(mCharX,
                                     textY(size_, text_), size_);

            // Add x
            mCharX += font->image[mChar]->width(size_) + font->getIndent();
        }

//#ifdef DEBUG

//        move(textY(size_), textX(size_));
//        printw("s");

//        move(textY(size_) + textHeight(size_), textX(size_) + textWidth(size_));
//        printw("e");

//        move(rect.coordLeftUp->getY(), rect.coordLeftUp->getX());
//        printw("rs");

//        move(rect.coordLeftUp->getY() + rect.height(), rect.coordLeftUp->getX() + rect.width());
//        printw("re");

//#endif

        return true;
    }

    return false;
}

float Label::alignX(float x_)
{
    // Align X

    return ::alignX(x_, screen);
}

float Label::alignY(float y_)
{
    // Align Y

    return ::alignY(y_, screen);
}

void Label::initScreen(WINDOW *screen_)
{
    // Set screen

    screen = screen_;

    // Rect
    rect.coordFirst.initScreen(screen_);
    rect.coordSecond.initScreen(screen_);
}

int Label::textWidth(string size_, string text_)
{
    // Width

    int width_ = 0;

    // Add

    // Chars Widths
    for(auto mChar: text_)
    {
        width_ += font->image[mChar]->width(size_);
    }

    // Indents
    size_t length_ = text_.length();
    if(length_ > 0)
    {
        for(size_t mCharNum = 0; mCharNum < length_ - 1; mCharNum++)
        {
            width_ += font->getIndent();
        }
    }

    return width_;
}

int Label::textHeight(string size_, string text_)
{
    // Height

    int height_ = 0;
    for(auto mChar: text_)
    {
        int charHeight = font->image[mChar]->height(size_);

        if(charHeight > height_)
            height_ = charHeight;
    }

    return height_;
}

int Label::textX(string size_, string text_)
{
    // Text X

    return rect.centerX() - textWidth(size_, text_)/2;
}

int Label::textY(string size_, string text_)
{
    // Text Y

    return rect.centerY() - textHeight(size_, text_)/2;
}

Coord Label::textCoord(string size_, string text_)
{
    // Text coord

    return Coord(textX(size_, text_), textY(size_, text_));
}

// --------------------------- Encapsulation ---------------------------

// Text

string Label::getText()
{
    // Get
    return text;
}

void Label::setText(string text_)
{
    // Set
    text = text_;
}

