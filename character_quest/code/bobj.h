#ifndef _FILE_BOBJ_
#define _FILE_BOBJ_

#include <ncursesall.h>

class BObj
{
public:
    BObj(float oLuck = 20.0f, chtype oType = ' ');

    // Type
    chtype type;

    // Luck
    float luck;
};

#endif // _FILE_BOBJ_
