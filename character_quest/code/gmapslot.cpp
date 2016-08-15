#include "gmapslot.h"

GMapSlot::GMapSlot(chtype wSType, chtype wDType)
{
    // Static type
    staticType = wSType;

    // Dynamic type
    dynamicType = wDType;
}

bool GMapSlot::empty()
{
    if(dynamicType == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

