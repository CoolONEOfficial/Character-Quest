#ifndef _FILE_RECT_
#define _FILE_RECT_

#include "coord.h"
#include "savedelete.h"

#include <stdlib.h>
#include <QDebug>
#include <cassert>

using namespace std;

// --------------------------- Values ---------------------------

template<class T>
class Rect
{
public:
    explicit Rect(T coordFirst_ = T(), T coordSecond_ = T())
    {
        // Coords
        coordFirst = coordFirst_;
        coordSecond = coordSecond_;
    }

    // Coords
    T coordFirst;
    T coordSecond;

    // Size
    int width()
    {
        // Width

        return coordSecond.getX() - coordFirst.getX();
    }

    int height()
    {
        // Height

        return coordSecond.getY() - coordFirst.getY();
    }

    // Center
    int centerX()
    {
        // Center X

        return coordFirst.getX() + width()/2;
    }
    int centerY()
    {
        // Center Y

        return coordFirst.getY() + height()/2;
    }
};

#endif // _FILE_RECT_
