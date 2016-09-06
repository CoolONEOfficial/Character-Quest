#include "font.h"

Font::Font(map<char, Character *> image_)
{
    // Image
    setImage(image_);
}

Font::Font(const Font *&font_)
{
    // Image
    setImage(font_->image);
}

Font::~Font()
{
    // Image
    SAVE_DEL_MAP(image);
}

// --------------------------- Values ---------------------------

// Image

map<char, Character *> Font::getImage()
{
    // Get
    return image;
}
void Font::setImage(map<char, Character *> image_)
{
    // Set
    image = image_;
}

