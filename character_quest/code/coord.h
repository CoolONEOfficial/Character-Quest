#ifndef _FILE_COORD_
#define _FILE_COORD_

#include "ncursesall.h"

// --------------------------- Coord ---------------------------

class Coord
{
public:
    explicit Coord(int x_ = 0, int y_ = 0);

    // Coords
private:
    // X
    int x;

    // Y
    int y;
public:

    // --------------------------- Encapsulation ---------------------------

    // X
    virtual int getX();
    void setX(int x_);

    // Y
    virtual int getY();
    void setY(int y_);
};

#endif // _FILE_COORD_
