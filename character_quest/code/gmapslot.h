#ifndef _FILE_GMAPSLOT_
#define _FILE_GMAPSLOT_

#include <ncursesall.h>

// --------------------------- Game Map Slot ---------------------------

class GMapSlot
{
public:
    explicit GMapSlot(chtype staticType_ = ' ', chtype dynamicType_ = ' ');

    // Free
    bool is_free();

    // Empty
    bool is_empty();

    // --------------------------- Values ---------------------------

    // Types

    // Static
    chtype getStaticType();
    void setStaticType(chtype staticType_);

    // Dynamic
    chtype getDynamicType();
    void setDynamicType(chtype dynamicType_);

private:
    // Types

    // Static
    chtype staticType;

    // Dynamic
    chtype dynamicType;
};

#endif // _FILE_GMAPSLOT_
