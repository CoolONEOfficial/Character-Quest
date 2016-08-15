#include "gmap.h"

GMap::GMap(string pName)
{
    // Player name
    playerName = pName;

    // Player coords
    playerX = 0;
    playerY = 0;

    // Saved
    saved = false;
}

GMap::~GMap()
{
    // Delete all GMapSlots
    for(auto &mMapSlots: slot)
    {
        SAVE_DEL_MAP(mMapSlots.second)
    }
}

int GMap::cameraX(int viewW)
{
    return playerX - viewW/2;
}

int GMap::cameraY(int viewH)
{
    return playerY - viewH/2;
}

int GMap::toScrX(int mX, int viewW, int indentX)
{
    return indentX - cameraX(viewW) + mX;
}

int GMap::toScrY(int mY, int viewH, int indentY)
{
    return indentY - cameraY(viewH) + mY;
}

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
    return playerName == "Empty";
}

void GMap::draw(int dX, int dY, int dW, int dH)
{
    // Draw

    // Map
    for(int mY = 0; mY < alignH(dH); mY++)
    {
        // Move y
        move(alignH(dY) + mY, alignW(dX));

        // Draw
        for(int mX = 0; mX < alignW(dW); mX++)
        {
            int x = cameraX(alignW(dW)) + mX;
            int y = cameraY(alignH(dH)) + mY;

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

void GMap::clear()
{
    // Clear

    // GMap
    slot.clear();

    // Player
    playerX = 0;
    playerY = 0;
    playerName = "Empty";
}

bool GMap::movePlayer(string dir)
{
    // Move player

    // Up
    if(dir == "up")
    {
        if(slot[playerX][playerY-1]->empty())
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
        if(slot[playerX][playerY+1]->empty())
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
        if(slot[playerX-1][playerY]->empty())
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
        if(slot[playerX+1][playerY]->empty())
        {
            // Move X
            playerX++;

            saved = false;

            return true;
        }
    }

    return false;
}

