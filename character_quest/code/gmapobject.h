#ifndef _FILE_GMAPOBJECT_
#define _FILE_GMAPOBJECT_

#include <ncursesall.h>

// --------------------------- Game map object ---------------------------

class GMapObject
{
public:
    GMapObject(chtype oType = ' ', float oLuck = 100, int oColor = 0);

    // Type
    chtype type;

    // Luck
    float luck;
    float realLuck;

    void setColor(int sColor);
    void setRealLuck(float allLuck);
};

#endif // _FILE_GMAPOBJECT_
