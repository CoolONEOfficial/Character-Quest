#ifndef _FILE_BOBJ_
#define _FILE_BOBJ_

#include <ncursesall.h>

// --------------------------- Biome Object ---------------------------

class BObj
{
public:
    BObj(float luck_ = 20.0f, chtype type_ = ' ');

    // --------------------------- Values ---------------------------

    // Type
    chtype getType();
    void setType(chtype type_);

    // Luck
    float getLuck();
    void setLuck(float luck_);

private:
    // Type
    chtype type;

    // Luck
    float luck;
};

#endif // _FILE_BOBJ_
