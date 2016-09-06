#include "gmapworld.h"

GMapWorld::GMapWorld(Biome *gBiome, GMapHome *gMapHome)
    : GMap(gBiome)
{
    // Emty home
    emptyGMapHome = gMapHome;
}

bool GMapWorld::findGMapHome(int sX, int sY)
{
    // Find

    return gMapHome.find(sX) != gMapHome.end() &&
            gMapHome[sX].find(sY) != gMapHome[sX].end();
}

void GMapWorld::draw(int dX, int dY, int dW, int dH, bool gen)
{
    // Draw

    if(findGMapHome(getPlayerX(), getPlayerY()))
    {
        // Home
        gMapHome[getPlayerX()][getPlayerY()]->draw(dX, dY, dW, dH, gen);
    }
    else
    {
        // World
        GMap::draw(dX, dY, dW, dH, gen);
    }
}

GMapSlot *GMapWorld::movePlayer(int mX, int mY)
{
    // Move player

    GMapSlot *gotoSlot;

    if(findGMapHome(getPlayerX(), getPlayerY()))
    {
        // In home

        gotoSlot = gMapHome[getPlayerX()][getPlayerY()]->movePlayer(mX, mY);
    }
    else
    {
        // In world

        gotoSlot = GMap::movePlayer(mX, mY);

        // Check home
        if(!gotoSlot->is_free())
        {
            if(!findGMapHome(getPlayerX() + mX, getPlayerY() + mY))
            {
                // Check
                for(auto mHomeType: getBiome()->getCatDynamic()["homes"]->getObject())
                {
                    if(gotoSlot->getDynamicType() == mHomeType.second->getType())
                    {
                        // Generate home
                        gMapHome[getPlayerX() + mX][getPlayerY() + mY] = emptyGMapHome;

                        // Set player coords to home
                        setPlayerX(getPlayerX() + mX);
                        setPlayerY(getPlayerY() + mY);
                    }
                }
            }
        }
    }

    return gotoSlot;
}

// --------------------------- Values ---------------------------

// Homes

map<int, map<int, GMapHome *> > GMapWorld::getGMapHome()
{
    // Get
    return gMapHome;
}
void GMapWorld::setGMapHome(map<int, map<int, GMapHome *> > gMapHome_)
{
    // Set map
    gMapHome = gMapHome_;
}
void GMapWorld::setGMapHomeX(int x_, map<int, GMapHome *> gMapHome_)
{
    // Set x map
    gMapHome[x_] = gMapHome_;
}
void GMapWorld::setGMapHomeY(int x_, int y_, GMapHome *gMapHome_)
{
    // Set GMapHome
    gMapHome[x_][y_] = gMapHome_;
}

// Empty GMapHome

GMapHome *GMapWorld::getEmptyGMapHome()
{
    // Get
    return emptyGMapHome;
}
void GMapWorld::setEmptyGMapHome(GMapHome *emptyGMapHome_)
{
    // Set
    emptyGMapHome = emptyGMapHome_;
}
