#ifndef _FILE_GMAPSLOT_
#define _FILE_GMAPSLOT_

#include <ncursesall.h>

// --------------------------- Game map slot ---------------------------

class GMapSlot
{
public:
    explicit GMapSlot(chtype wSType = ' ', chtype wDType = ' ');

    // Empty
    bool empty();

    // Symbol
    chtype staticType, dynamicType;
};

#endif // _FILE_GMAPSLOT_
