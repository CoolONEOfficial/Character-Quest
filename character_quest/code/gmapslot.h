#ifndef _FILE_GMAPSLOT_
#define _FILE_GMAPSLOT_

#include <ncursesall.h>

// --------------------------- Game map slot ---------------------------

class GMapSlot
{
public:
    explicit GMapSlot(chtype wSType = ' ', chtype wDType = ' ');

    // Symbol
    chtype staticType, dynamicType;

    // Free
    bool free();

    // Empty
    bool empty();
};

#endif // _FILE_GMAPSLOT_
