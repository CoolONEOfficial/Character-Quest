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
    Font(map <char, Character*> fImage = {});
    Font(const Font *&cFont);
    ~Font();

    // Images
    map <char, Character*> image;
};

#endif // _FILE_FONT_
