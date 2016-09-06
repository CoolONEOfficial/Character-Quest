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
    GMap(Biome* biome_ = new Biome());
    ~GMap();

    // Draw
    virtual void draw(int dX, int dY, int dW, int dH, bool gen = true);

    // Generate
    virtual void generate(int dW, int dH);
    GMapSlot* generateSlot();

    // From map to screen coords
    int toScrX(int mX, int viewW, int indentX);
    int toScrY(int mY, int viewH, int indentY);

    // From screen to map coords
    int toMapX(int sX, int viewW, int indentX);
    int toMapY(int sY, int viewH, int indentY);

    // Camera coords
    int cameraX(int viewW);
    int cameraY(int viewH);

    // Move player
    virtual GMapSlot* movePlayer(int mX, int mY);
    GMapSlot* movePlayerUp();
    GMapSlot* movePlayerDown();
    GMapSlot* movePlayerLeft();
    GMapSlot* movePlayerRight();

    // Empty
    bool is_empty();

    // --------------------------- Values ---------------------------

    // Slots
    map < int, map< int, GMapSlot*> > getSlot();
    void setSlotX(map < int, map< int, GMapSlot*> > slot_);
    void setSlotY(int x_, map< int, GMapSlot*> slot_);
    void setSlot(int x_, int y_, GMapSlot* slot_);

    // Player coords

    // X
    int getPlayerX();
    void setPlayerX(int playerX_);

    // Y
    int getPlayerY();
    void setPlayerY(int playerY_);

    // Biome
    Biome *getBiome();
    void setBiome(Biome* biome_);

    // Saved
    bool getSaved();
    void setSaved(bool saved_);

private:
    // Slots
    map < int, map< int, GMapSlot*> > slot;

    // Player coords

    // X
    int playerX;

    // Y
    int playerY;

    // Biome
    Biome* biome;

    // Saved
    bool saved;
};

#endif // _FILE_GMAP_
