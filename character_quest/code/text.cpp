#include "text.h"

bool drawText(int dX, int dY, string dText, string size, Font *tFont, int dSX, int dSY, int dSW, int dSH, int dIndent)
{
    // Draw text

    if(dX >= dSX &&
       dY >= dSY &&
       dX + textWidth(dText, size, tFont, dIndent) <= dSX + dSW &&
       dY + textHeight(dText, size, tFont) <= dSY + dSH)
    {
        // Draw
        int charX = dX;
        for(size_t f = 0; f < dText.size(); f++)
        {
            // Draw
            tFont->getImage()[dText[f]]->draw(charX, dY, size);

            // Add character X
            charX += tFont->getImage()[dText[f]]->width(size) + dIndent;
        }
    }
    else
    {
        return false;
    }

    return true;
}

int textWidth(string eText, string tSize, Font *tFont, int dIndent)
{
    // Get text width

    int tWidth = 0;
    for(size_t mChar = 0; mChar < eText.size(); mChar++)
    {
        // Current character width
        int charWidth = tFont->getImage()[eText[mChar]]->width(tSize);

        // Add character width
        tWidth += charWidth;
    }
    // Add all indents
    tWidth += dIndent * (eText.size()-1);

    return tWidth;
}

int textHeight(string eText, string tSize, Font *tFont)
{
    // Get text height

    int tHeight = 0;
    for(size_t mChar = 0; mChar < eText.size(); mChar++)
    {
        // Current character height
        int charHeight = tFont->getImage()[eText[mChar]]->height(tSize);

        // Set text height
        if(charHeight > tHeight)
        {
            tHeight = charHeight;
        }
    }

    return tHeight;
}
