#ifndef _FILE_GMAP_
#define _FILE_GMAP_

#include "savedelete.h"
#include "gmapslot.h"
#include "screen.h"
#include "biome.h"

#include <ncursesall.h>
#include <map>
#include <string>

using namespace std;

// --------------------------- Game Map ---------------------------

class GMap
{
public:
    GMap(Biome *gBiome = new Biome(), string gPlayerName = "Empty");
    ~GMap();

    // Slots
    map < int, map< int, GMapSlot*> > slot;

    // Camera coords
    int cameraX(int viewW);
    int cameraY(int viewH);

    // Saved
    bool saved;

    // From map to screen coords
    int toScrX(int mX, int viewW, int indentX);
    int toScrY(int mY, int viewH, int indentY);

    // From screen to map coords
    int toMapX(int sX, int viewW, int indentX);
    int toMapY(int sY, int viewH, int indentY);

    // Draw
    void draw(int dX, int dY, int dW, int dH);

    // Biome
    Biome *biome;

    // Generate Slot
    GMapSlot *genSlot();

    // Empty
    bool empty();

    // --------------------------- Player ---------------------------

    // Player Name
    string playerName;

    // Player coords
    int playerX;
    int playerY;

    // Move player
    bool movePlayer(string dir);

};

#endif // _FILE_GMAP_
