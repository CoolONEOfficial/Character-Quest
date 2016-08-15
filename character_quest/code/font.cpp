#include "font.h"

Font::Font(map<char, Character *> fImage)
{
    // Image
    image = fImage;
}

Font::Font(const Font *&cFont)
{
    // Image
    image = cFont->image;
}

Font::~Font()
{
    // Image
    SAVE_DEL_MAP(image);
}

