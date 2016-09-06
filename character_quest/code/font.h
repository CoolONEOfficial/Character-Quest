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
    Font(map <char, Character*> image_ = {});
    Font(const Font *&font_);
    ~Font();

    // --------------------------- Values ---------------------------

    // Images
    map <char, Character*> getImage();
    void setImage(map <char, Character*> image_);

private:
    // Images
    map <char, Character*> image;
};

#endif // _FILE_FONT_
