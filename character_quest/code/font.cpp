#include "font.h"

Font::Font(map<char, Character *> image_, int indent_)
{
    // Image
    image = image_;

    // Indent
    indent = indent_;
}

Font::Font(const Font *&font_)
{
    // Image
    image = font_->image;
}

Font::~Font()
{
    // Image
    SAVE_DEL_MAP(image);
}

// Encapsulation

// Indent

int Font::getIndent()
{
    // Get
    return indent;
}
void Font::setIndent(int indent_)
{
    // Set
    indent = indent_;
}
