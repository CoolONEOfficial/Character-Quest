#include "gmap.h"

GMap::GMap(Biome *biome_, WINDOW *screen_)
{
    // Screen
    initScreen(screen_);

    // Player

    // Coords
    setPlayerX(0);
    setPlayerY(0);

    // Map

    // Biome
    biome = biome_;

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

int GMap::cameraX(int gameWidth_)
{
    return playerX - gameWidth_/2;
}

int GMap::cameraY(int gameHeight_)
{
    return playerY - gameHeight_/2;
}

// From map to screen coords

int GMap::toScreenX(int x_, int gameWidth_, int indentX_)
{
    return indentX_ - cameraX(gameWidth_) + x_;
}
int GMap::toScreenY(int y_, int gameHeight_, int indentY_)
{
    return indentY_ - cameraY(gameHeight_) + y_;
}

// From screen to map coord

Coord GMap::toMapCoord(Coord coord_, Rect<Coord> gameRect_ )
{
    return Coord(toMapX(coord_.getX(), gameRect_.coordFirst.getX(), gameRect_.width()),
                        toMapY(coord_.getY(), gameRect_.coordFirst.getY(), gameRect_.height()));
}

int GMap::toMapX(int x_, int gameX_, int gameWidth_)
{
    // X

    return x_ - gameX_ + cameraX(gameWidth_);
}
int GMap::toMapY(int y_, int gameY_, int gameHeight_)
{
    // Y

    return y_ - gameY_ + cameraY(gameHeight_);
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

float GMap::alignX(float x_)
{
    // Align X

    return ::alignX(x_, screen);
}

float GMap::alignY(float y_)
{
    // Align Y

    return ::alignY(y_, screen);
}

void GMap::initScreen(WINDOW *screen_)
{
    // Init screen

    if(screen_ != new WINDOW())
    {
        screen_ = screen_;
    }
}

void GMap::draw(Rect<ScreenCoord> drawRect_, bool generate_)
{
    // Draw

    // Generate
    if(generate_)
        generate(drawRect_);

    // Draw

    // Map
    for(int mX = 0; mX < drawRect_.width(); mX++)
    {
        // X
        int x = cameraX(drawRect_.width()) + mX;

        for(int mY = 0; mY < drawRect_.height(); mY++)
        {
            // Y
            int y = cameraY(drawRect_.height()) + mY;

            // Draw
            move(drawRect_.coordFirst.getY() + mY,
                 drawRect_.coordFirst.getY() + mX);
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
    move(toScreenY(playerY, drawRect_.height(), drawRect_.coordFirst.getY()),
         toScreenX(playerX, drawRect_.width(), drawRect_.coordFirst.getX()));
    printw("T");
}

void GMap::generate(Rect<ScreenCoord> genRect_)
{
    // Generate slots

    for(int mX = 0; mX < genRect_.width(); mX++)
    {
        // X
        int gX = cameraX(genRect_.width()) + mX;

        for(int mY = 0; mY < genRect_.height(); mY++)
        {
            // Y
            int gY = cameraY(genRect_.height()) + mY;

            // Generate
            if( slot.find(gX) == slot.end() ||
                    slot[gX].find(gY) == slot[gX].end() )
            {
                slot[gX][gY] = generateSlot();
            }
        }
    }
}

pair<bool, GMapSlot *> GMap::movePlayer(int changeX_, int changeY_)
{
    // Move player

    GMapSlot *gotoSlot = slot[playerX + changeX_][playerY + changeY_];

    pair<bool, GMapSlot *> returnPair = { gotoSlot->is_free(), gotoSlot };

    if(gotoSlot->is_free())
    {
        // Move
        playerX += changeX_;
        playerY += changeY_;

        saved = false;
    }

    return returnPair;
}

pair<bool, GMapSlot *> GMap::movePlayerUp()
{
    // Move Player Up

    return movePlayer(0, -1);
}

pair<bool, GMapSlot *> GMap::movePlayerDown()
{
    // Move player down

    return movePlayer(0, 1);
}

pair<bool, GMapSlot *> GMap::movePlayerLeft()
{
    // Move player left

    return movePlayer(-1, 0);
}

pair<bool, GMapSlot *> GMap::movePlayerRight()
{
    // Move player right

    return movePlayer(1, 0);
}

// --------------------------- Encapsulation ---------------------------

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
