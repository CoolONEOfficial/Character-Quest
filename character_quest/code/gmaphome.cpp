#include "gmaphome.h"

GMapHome::GMapHome(Biome *hBiome, GMapSlot hWallType)
    : GMap(hBiome)
{
    // Biome
    setBiome(hBiome);

    // Wall type
    setWallType(hWallType);

    // Not Generated
    setGenerated(false);
}

void GMapHome::generate(int dW, int dH)
{
    // Generate home

    // Set

    // Width
    int hWidth = 14;

    int addChance = 100;
    while(luck(addChance))
    {
        // Add width
        hWidth++;

        // Reduce chance
        addChance -= 10;
    }

    // Height
    int hHeight = hWidth/2;

    // Create clear slots
    for(int mX = -hWidth; mX < alignW(dW) + hWidth*2; mX++)
    {
        // X
        int x = cameraX(alignW(dW)) + mX;

        for(int mY = -hHeight; mY < alignH(dH) + hHeight*2; mY++)
        {
            // Y
            int y = cameraY(alignH(dH)) + mY;

            // Create

            setSlot(x, y, new GMapSlot());
        }
    }

    // Generate

    // Home
    for(int mX = -hWidth/2; mX < hWidth/2; mX++)
    {
        for(int mY = -hHeight/2; mY < hHeight/2; mY++)
        {
            setSlot(mX, mY, generateSlot());
        }
    }

    // Walls

    // Up/Down
    for(int mX = -hWidth/2; mX <= hWidth/2; mX++)
    {
        setSlot(mX, -hHeight/2, &wallType);
        setSlot(mX, hHeight/2, &wallType);
    }

    // Left/Right
    for(int mY = -hHeight/2; mY <= hHeight/2; mY++)
    {
        setSlot(-hWidth/2, mY, &wallType);
        setSlot(hWidth/2, mY, &wallType);
    }

    // Generated
    generated = true;
}

void GMapHome::draw(int dX, int dY, int dW, int dH, bool gen)
{
    // Draw

    GMap::draw(dX, dY, dW, dH, gen && !getGenerated());
}

GMapSlot *GMapHome::movePlayer(int mX, int mY)
{
    // Move player

    GMapSlot *gotoSlot = getSlot()[getPlayerX() + mX][getPlayerY() + mY];

    // Move
    GMap::movePlayer(mX, mY);

    return gotoSlot;
}

bool GMapHome::is_empty()
{
    // Empty

    return getBiome()->is_empty();
}

// --------------------------- Values ---------------------------

// Wall type

GMapSlot GMapHome::getWallType()
{
    // Get
    return wallType;
}
void GMapHome::setWallType(GMapSlot wallType_)
{
    // Set
    wallType = wallType_;
}

// Generated

bool GMapHome::getGenerated()
{
    // Get
    return generated;
}
void GMapHome::setGenerated(bool generated_)
{
    // Set
    generated = generated_;
}
