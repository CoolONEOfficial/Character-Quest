#include "character.h"

Character::Character(char cNaturalImage, int cSmallWidth, int cSmallHeight, vector<string> cSmallImage,
                     int cNormalWidth, int cNormalHeight, vector<string> cNormalImage,
                     int cBigWidth, int cBigHeight, vector<string> cBigImage)
{
    // Set sizes
    widthSmall = cSmallWidth;
    heightSmall = cSmallHeight;

    widthNormal = cNormalWidth;
    heightNormal = cNormalHeight;

    widthBig = cBigWidth;
    heightBig = cBigHeight;

    // Images
    imageSmall = cSmallImage;
    imageNormal = cNormalImage;
    imageBig = cBigImage;
    imageNatural = cNaturalImage;
}

int Character::width(string cSize)
{
    // Width

    if(cSize == "small")
    {
        return widthSmall;
    }
    else if(cSize == "normal")
    {
        return widthNormal;
    }
    else if(cSize == "big")
    {
        return widthBig;
    }
    else if(cSize == "natural")
    {
        return 1;
    }
    else
    {
        exit(0);
    }
}

int Character::height(string cSize)
{
    // Height

    if(cSize == "small")
    {
        return heightSmall;
    }
    else if(cSize == "normal")
    {
        return heightNormal;
    }
    else if(cSize == "big")
    {
        return heightBig;
    }
    else if(cSize == "natural")
    {
        return 1;
    }
    else
    {
        exit(0);
    }
}

void Character::draw(int dX, int dY, string size)
{
    // Draw char

    if(size != "natural")
    {
        vector <string> cImage;

        if(size == "small")
        {
            cImage = imageSmall;
        }
        else if(size == "normal")
        {
            cImage = imageNormal;
        }
        else if(size == "big")
        {
            cImage = imageBig;
        }

        for(size_t mY = 0; mY < cImage.size(); mY++)
        {
            // for 0 to string size
            for(size_t f = 0; f < cImage[mY].size(); f++)
            {
                if(cImage[mY][f] != ' ')
                {
                    // Move
                    move(dY + mY, dX + f);

                    // Draw char
                    printw("%c",cImage[mY].c_str()[f]);
                }
            }
        }
    }
    else
    {
        move(dY, dX);
        printw("%c", imageNatural);
    }
}

