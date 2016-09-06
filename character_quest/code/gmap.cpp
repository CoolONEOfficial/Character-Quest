#include "gmap.h"

GMap::GMap(Biome *biome_)
{
    // Player

    // Coords
    setPlayerX(0);
    setPlayerY(0);

    // Map

    // Biome
    setBiome(biome_);

    // Saved
    setSaved(true);
}

GMap::~GMap()
{
    // Slots
    for(auto &mMapSlots: slot)
    {
        SAVE_DEL_MAP(mMapSlots.second)
    }
}

// Camera coords

int GMap::cameraX(int viewW)
{
    return playerX - viewW/2;
}

int GMap::cameraY(int viewH)
{
    return playerY - viewH/2;
}

// From map to screen coords

int GMap::toScrX(int mX, int viewW, int indentX)
{
    return indentX - cameraX(viewW) + mX;
}
int GMap::toScrY(int mY, int viewH, int indentY)
{
    return indentY - cameraY(viewH) + mY;
}

// From screen to map coords

int GMap::toMapX(int sX, int viewW, int indentX)
{
    return sX - indentX + cameraX(viewW);
}
int GMap::toMapY(int sY, int viewH, int indentY)
{
    return sY - indentY + cameraY(viewH);
}

bool GMap::is_empty()
{
    // Empty

    return slot.empty();
}

GMapSlot *GMap::generateSlot()
{
    // Generate slot

    GMapSlot *gSlot = new GMapSlot();

    // Set dynamic
    if(luck(biome->getDynamicLuck()))
    {
        gSlot->setDynamicType(biome->genCatDynamic()->genObject()->getType());
    }

    // Set static
    gSlot->setStaticType(biome->genCatStatic()->genObject()->getType());

    return gSlot;
}

void GMap::draw(int dX, int dY, int dW, int dH, bool gen)
{
    // Draw

    // Generate
    if(gen)
        generate(dW, dH);

    // Draw

    // Map
    for(int mX = 0; mX < alignW(dW); mX++)
    {
        // X
        int x = cameraX(alignW(dW)) + mX;

        for(int mY = 0; mY < alignH(dH); mY++)
        {
            // Y
            int y = cameraY(alignH(dH)) + mY;

            // Draw
            move(alignH(dY) + mY, alignW(dX) + mX);
            if(slot[x][y]->getDynamicType() == ' ')
            {
                addch(slot[x][y]->getStaticType());
            }
            else
            {
                addch(slot[x][y]->getDynamicType());
            }
        }
    }

    // Player
    move(toScrY(playerY, alignH(dH), alignH(dY)),
         toScrX(playerX, alignW(dW), alignW(dX)));
    printw("T");
}

void GMap::generate(int dW, int dH)
{
    // Generate slots

    for(int mX = 0; mX < alignW(dW); mX++)
    {
        // X
        int gX = cameraX(alignW(dW)) + mX;

        for(int mY = 0; mY < alignH(dH); mY++)
        {
            // Y
            int gY = cameraY(alignH(dH)) + mY;

            // Generate
            if( slot.find(gX) == slot.end() ||
                    slot[gX].find(gY) == slot[gX].end() )
            {
                slot[gX][gY] = generateSlot();
            }
        }
    }
}

GMapSlot *GMap::movePlayer(int mX, int mY)
{
    // Move player

    GMapSlot *gotoSlot = slot[playerX + mX][playerY + mY];

    if(gotoSlot->is_free())
    {
        // Move
        playerX += mX;
        playerY += mY;

        saved = false;
    }

    return gotoSlot;
}

GMapSlot *GMap::movePlayerUp()
{
    // Move Player Up

    return movePlayer(0, -1);
}

GMapSlot *GMap::movePlayerDown()
{
    // Move player down

    return movePlayer(0, 1);
}

GMapSlot *GMap::movePlayerLeft()
{
    // Move player left

    return movePlayer(-1, 0);
}

GMapSlot *GMap::movePlayerRight()
{
    // Move player right

    return movePlayer(1, 0);
}

// --------------------------- Values ---------------------------

// Slot

map<int, map<int, GMapSlot *> > GMap::getSlot()
{
    // Get
    return slot;
}
void GMap::setSlotX(map<int, map<int, GMapSlot *> > slot_)
{
    // Set Map X
    slot = slot_;
}
void GMap::setSlotY(int x_, map<int, GMapSlot *> slot_)
{
    // Set Map Y
    slot[x_] = slot_;
}
void GMap::setSlot(int x_, int y_, GMapSlot *slot_)
{
    // Set Slot
    slot[x_][y_] = slot_;
}

// Player

// X

int GMap::getPlayerX()
{
    // Get
    return playerX;
}
void GMap::setPlayerX(int playerX_)
{
    // Set
    playerX = playerX_;
}

// Y

int GMap::getPlayerY()
{
    // Get
    return playerY;
}
void GMap::setPlayerY(int playerY_)
{
    // Set
    playerY = playerY_;
}

// Biome

Biome *GMap::getBiome()
{
    // Get
    return biome;
}
void GMap::setBiome(Biome *biome_)
{
    // Set
    biome = biome_;
}

// Saved

bool GMap::getSaved()
{
    // Get
    return saved;
}
void GMap::setSaved(bool saved_)
{
    // Set
    saved = saved_;
}
