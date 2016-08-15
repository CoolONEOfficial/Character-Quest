#include "gmapobject.h"

GMapObject::GMapObject(chtype oType, float oLuck, int oColor)
{
    // Type
    type = oType;

    // Luck
    luck = oLuck;

    // Color
    setColor(oColor);
}

void GMapObject::setColor(int sColor)
{
    // Set pair
    type = type | COLOR_PAIR(sColor);
}

void GMapObject::setRealLuck(float allLuck)
{
    // Set real luck
    realLuck = luck * (100.0f / allLuck);
}

