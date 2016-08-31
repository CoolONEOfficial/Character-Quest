#include "gmap.h"

GMap::GMap(Biome *gBiome, string gPlayerName)
{
    // Player

    // Name
    playerName = gPlayerName;

    // Coords
    playerX = 100;
    playerY = 100;

    // Map

    // Biome
    biome = gBiome;

    // Saved
    saved = false;

    // Slot
    slot = {};
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

bool GMap::empty()
{
    // Empty

    return playerName == "Empty";
}

GMapSlot *GMap::genSlot()
{
    // Generate slot

    GMapSlot *gSlot = new GMapSlot();

    // Set dynamic
    if(luck(biome->dynamicLuck))
    {
        gSlot->dynamicType = biome->genCatDynamic()->genObj()->type;
    }

    // Set static
    gSlot->staticType = biome->genCatStatic()->genObj()->type;

    return gSlot;
}

void GMap::draw(int dX, int dY, int dW, int dH)
{
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

            // Generate
            if( slot.find(x) == slot.end() ||
                    slot[x].find(y) == slot[x].end() )
            {
                slot[x][y] = genSlot();
            }

            // Draw
            move(alignH(dY) + mY, alignW(dX) + mX);
            if(slot[x][y]->dynamicType == ' ')
            {
                addch(slot[x][y]->staticType);
            }
            else
            {
                addch(slot[x][y]->dynamicType);
            }
        }
    }

    // Player
    move(toScrY(playerY, alignH(dH), alignH(dY)),
         toScrX(playerX, alignW(dW), alignW(dX)));
    printw("T");
}

bool GMap::movePlayer(string dir)
{
    // Move player

    // Up
    if(dir == "up")
    {
        if(slot[playerX][playerY-1]->free())
        {
            // Move Y
            playerY--;

            saved = false;

            return true;
        }
    }

    // Down
    else if(dir == "down")
    {
        if(slot[playerX][playerY+1]->free())
        {
            // Move Y
            playerY++;

            saved = false;

            return true;
        }
    }

    // Left
    else if(dir == "left")
    {
        if(slot[playerX-1][playerY]->free())
        {
            // Move X
            playerX--;

            saved = false;

            return true;
        }
    }

    // Right
    else if(dir == "right")
    {
        if(slot[playerX+1][playerY]->free())
        {
            // Move X
            playerX++;

            saved = false;

            return true;
        }
    }

    return false;
}

