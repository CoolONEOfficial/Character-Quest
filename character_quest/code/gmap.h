#ifndef _FILE_GMAP_
#define _FILE_GMAP_

#include "savedelete.h"
#include "gmapslot.h"
#include "screen.h"
#include "biome.h"
#include "rect.h"
#include "screencoord.h"

#include "ncursesall.h"
#include <map>
#include <string>

using namespace std;

// --------------------------- Game Map ---------------------------

class GMap
{
public:
    explicit GMap(Biome* biome_ = new Biome(), WINDOW* screen_ = new WINDOW());
    ~GMap();

private:
    // Player coords
    int playerX;
    int playerY;

    // Saved
    bool saved;
public:

    // Biome
    Biome* biome;

    // Slots
    map < int, map< int, GMapSlot*> > slot;

    // Draw
    virtual void draw(Rect<ScreenCoord> drawRect_, bool generate_ = true);

    // Generate
    virtual void generate(Rect<ScreenCoord> genRect_);
    GMapSlot* generateSlot();

    // Screen
    WINDOW* screen;
    float alignX(float x_);
    float alignY(float y_);
    void initScreen(WINDOW* screen_);

    // Camera coords
    int cameraX(int gameWidth_);
    int cameraY(int gameHeight_);

    // From map to screen coords
    int toScreenX(int x_, int gameWidth_, int indentX_);
    int toScreenY(int y_, int gameHeight_, int indentY_);

    // From screen to map coords
    Coord toMapCoord(Coord coord_, Rect<Coord> gameRect_);
    int toMapX(int x_, int gameX_, int gameWidth_);
    int toMapY(int y_, int gameY_, int gameHeight_);

    // Move player
    virtual pair<bool, GMapSlot*> movePlayer(int changeX_, int changeY_);
    pair<bool, GMapSlot*> movePlayerUp();
    pair<bool, GMapSlot*> movePlayerDown();
    pair<bool, GMapSlot*> movePlayerLeft();
    pair<bool, GMapSlot*> movePlayerRight();

    // Empty
    bool is_empty();

    // --------------------------- Encapsulation ---------------------------

    // Player coords

    // X
    int getPlayerX();
    void setPlayerX(int playerX_);

    // Y
    int getPlayerY();
    void setPlayerY(int playerY_);

    // Saved
    bool getSaved();
    void setSaved(bool saved_);
};

#endif // _FILE_GMAP_
