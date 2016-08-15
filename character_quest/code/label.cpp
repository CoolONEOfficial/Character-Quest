#include "label.h"

Label::Label(string lText, int lX, int lY, int lW, int lH, const Font *lFont, bool lAnimation, float lAnimationSpeedMSecs, int lIndent, bool lAlign)
{
    // Coords
    x = lX;
    y = lY;

    // Width / Height
    width = lW;
    height = lH;

    // Texts
    text = lText;

    // Indent
    indent = lIndent;

    // Animation
    animation = lAnimation;

    // Invisible
    animationValue = 0.0f;

    if(lAnimation)
    {
        // Speed
        animationSpeed = lAnimationSpeedMSecs;
    }
    else
    {
        // Speed
        animationSpeed = 0.0f;
    }

    // Align
    align = lAlign;

    // Font Id
    font = (Font*)lFont;

    // Timer
    animationTimer = new Timer(lAnimationSpeedMSecs);
}

string Label::animationText()
{
    // Animation text
    if(animation)
    {
        string aText;
        for(size_t mChar = 0; mChar < text.size() && mChar < animationValue; mChar++)
        {
            aText.push_back(text[mChar]);
        }
        return aText;
    }
    return text;
}

bool Label::animationFinished()
{
    if(animationValue > text.size())
    {
        return true;
    }
    return false;
}

void Label::animationTact()
{
    if(animation)
    {
        if(animationStarted)
        {
            if(animationTimer->finished())
            {
                animationValue += animationSpeed;

                if(!animationFinished())
                {
                    animationTimer->restart();
                }
            }
        }
    }
}

void Label::animationStart()
{
    if(animation)
    {
        // Stop
        animationStop();

        // Start
        animationStarted = true;
    }
}

void Label::animationStop()
{
    if(animation)
    {
        animationValue = 0;
    }
}

void Label::animationOn()
{
    // On animation
    animation = true;
}

void Label::animationOff()
{
    // Off animation
    animation = false;
}

bool Label::draw(int scrW, int scrH)
{
    // Draw label

    // Center coords
    int lCX = alignW(x + width/2, scrW);
    int lCY = alignH(y + height/2, scrH);

    // Try Big size
    if(!drawText(lCX - textWidth(text, "big", font) / 2,
                 lCY - textHeight(text, "big", font) / 2,
                 animationText(), "big", font,
                 alignW(x, scrW), alignH(y, scrH),
                 alignW(width, scrW), alignH(height, scrH), indent))
    {
        // Try Normal size
        if(!drawText(lCX - textWidth(text, "normal", font) / 2,
                     lCY - textHeight(text, "normal", font) / 2,
                     animationText(), "normal", font,
                     alignW(x, scrW), alignH(y, scrH),
                     alignW(width, scrW), alignH(height, scrH), indent))
        {
            // Try Small size
            if(!drawText(lCX - textWidth(text, "small", font) / 2,
                         lCY - textHeight(text, "small", font) / 2,
                         animationText(), "small", font,
                         alignW(x, scrW), alignH(y, scrH),
                         alignW(width, scrW), alignH(height, scrH), indent))
            {
                // Try Natural size
                return drawText(lCX - textWidth(text, "natural", font) / 2,
                                lCY - textHeight(text, "natural", font) / 2,
                                animationText(), "natural", font,
                                alignW(x, scrW), alignH(y, scrH),
                                alignW(width, scrW), alignH(height, scrH), indent);
            }
        }
    }

    return true;
}

