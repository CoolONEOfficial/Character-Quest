#ifndef _FILE_GMAP_
#define _FILE_GMAP_

#include "ctrlpointers.h"
#include "gmapslot.h"
#include "screen.h"

#include <ncursesall.h>
#include <map>
#include <string>

using namespace std;

// --------------------------- Game Map ---------------------------

class GMap
{
public:
    GMap(string pName = "Empty");
    ~GMap();

    // Player Name
    string playerName;

    // Slots
    map < int, map< int, GMapSlot*> > slot;

    // Player coords
    int playerX;
    int playerY;

    // Camera coords
    int cameraX(int viewW);
    int cameraY(int viewH);

    // From map to screen coords
    int toScrX(int mX, int viewW, int indentX);
    int toScrY(int mY, int viewH, int indentY);

    // From screen to map coords
    int toMapX(int sX, int viewW, int indentX);
    int toMapY(int sY, int viewH, int indentY);

    // Saved
    bool saved;

    // Empty
    bool empty();

    // Move player
    bool movePlayer(string dir);

    void draw(int dX, int dY, int dW, int dH);
    void clear();
};

#endif // _FILE_GMAP_
