#ifndef _FILE_GMAPWORLD_
#define _FILE_GMAPWORLD_

#include "gmap.h"
#include "gmaphome.h"

// --------------------------- Game Map World ---------------------------

class GMapWorld : public GMap
{
public:
    GMapWorld(Biome *gBiome = new Biome(), GMapHome *gMapHome =  new GMapHome());

    // Draw
    void draw(int dX, int dY, int dW, int dH, bool gen = true);

    // Move player
    GMapSlot* movePlayer(int mX, int mY);

    // Find home
    bool findGMapHome(int sX, int sY);

    // --------------------------- Values ---------------------------

    // Map Homes
    map<int, map<int, GMapHome*>> getGMapHome();
    void setGMapHome(map<int, map<int, GMapHome*>> gMapHome_);
    void setGMapHomeX(int x_, map<int, GMapHome*> gMapHome_);
    void setGMapHomeY(int x_, int y_, GMapHome* gMapHome_);

    // Empty Home
    GMapHome* getEmptyGMapHome();
    void setEmptyGMapHome(GMapHome* emptyGMapHome_);

private:
    // Map Homes
    map<int, map<int, GMapHome*>> gMapHome;

    // Empty Home
    GMapHome* emptyGMapHome;
};

#endif // _FILE_GMAPWORLD_
