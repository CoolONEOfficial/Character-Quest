#ifndef _FILE_MAIN_
#define _FILE_MAIN_

#include "savedelete.h"
#include "rands.h"
#include "screen.h"
#include "keycodes.h"
#include "timer.h"
#include "gmapslot.h"
#include "gmap.h"
#include "biome.h"
#include "bobj.h"
#include "bobjcat.h"
#include "font.h"
#include "scene.h"
#include "pushmessage.h"
#include "ncursesall.h"

#ifdef WINDOWS
    #include "windows.h"
#endif

#ifdef DEBUG
    #include <qcoreapplication.h>
#endif
#include <time.h>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// --------------------------- Main ---------------------------

// Inits
void initAll();

// Update screen
void update();

// Clocks per update
float cpu;

// Clear screen
void cls(int x = 0, int y = 0, int w = scrWidth(), int h = scrHeight());

// Old Width / Height
int scrOldWidth;
int scrOldHeight;

// Key stroke / char
int keyStroke;
char keyChar;

// Commands
void keysCommand(int keyStroke);

// --------------------------- Scenes ---------------------------

#include "scenes.h"

Scene *selectedScene;

// Set
void setScene(Scene *sScene);

// Draw
void drawScene(Scene *dScene = selectedScene);

// --------------------------- Scenes values / voids ---------------------------

// Timer screensaver (screensaver)
int timerScreensaver;

// Delete save mode (saves)
bool deleteSave;

// Move player (game)
void movePlayer(int direction);

// Save / Read saves (saves, game)
void saveSaves(string sFileName = "save.txt");
void readSaves(string rFileName = "save.txt");

// --------------------------- Messages ---------------------------

vector <PushMessage*> message;

// Draw
void drawMessages();

// --------------------------- Buttons ---------------------------

// Click
void buttonClick();

// Selected button
size_t selectedButton;

// --------------------------- Fonts ---------------------------

#include "fonts.h"

// --------------------------- Characters ---------------------------

// Set pairs
void initCharPairs();

// --------------------------- GMaps ---------------------------

GMap *gMap[4];

// Selected
int selectedGMap;

// View size
const int gMapX = 0,
          gMapY = 0;
const int gMapWidth = 80,
          gMapHeight = 24;

// --------------------------- Biomes ---------------------------

#include "biomes.h"

#endif // _FILE_MAIN_

