#ifndef _FILE_FONT_
#define _FILE_FONT_

#include "savedelete.h"
#include "character.h"

#include <map>

using namespace std;

// --------------------------- Font ---------------------------

class Font
{
public:
    explicit Font(map <char, Character*> image_ = {}, int indent_ = 2);
    Font(const Font *&font_);
    ~Font();

    // Images
    map <char, Character*> image;

    // Indent
private:
    int indent;
public:

    // --------------------------- Encapsulation ---------------------------

    // Indent
    int getIndent();
    void setIndent(int indent_);
};

#endif // _FILE_FONT_
