#ifndef _FILE_GMAPHOME_
#define _FILE_GMAPHOME_

#include "rands.h"
#include "gmap.h"
#include "gmapslot.h"

// --------------------------- Game Map Home ---------------------------

class GMapHome : public GMap
{
public:
    GMapHome(Biome* hBiome = new Biome(), GMapSlot hWallType = GMapSlot(' ', ACS_BLOCK));

    // Generate home
    void generate(int dW, int dH);

    // Draw
    void draw(int dX, int dY, int dW, int dH, bool gen = true);

    // Move player
    GMapSlot* movePlayer(int mX, int mY);

    // Empty
    bool is_empty();

    // --------------------------- Values ---------------------------

    // Wall type
    GMapSlot getWallType();
    void setWallType(GMapSlot wallType_);

    // Generated
    bool getGenerated();
    void setGenerated(bool generated_);

private:
    // Wall type
    GMapSlot wallType;

    // Generated
    bool generated;
};

#endif // _FILE_GMAPHOME_
