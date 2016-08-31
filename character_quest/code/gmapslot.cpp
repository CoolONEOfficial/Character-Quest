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
    return dynamicType == ' ' &&
            staticType == ' ';
}

bool GMapSlot::free()
{
    return dynamicType == ' ';
}

