#ifndef _FILE_MAIN_
#define _FILE_MAIN_

#include "ctrlpointers.h"
#include "systems.h"
#include "rands.h"
#include "screen.h"
#include "mydebug.h"
#include "keycodes.h"
#include "timer.h"
#include "gmapcategory.h"
#include "gmapobject.h"
#include "gmapslot.h"
#include "gmap.h"
#include "font.h"
#include "scene.h"
#include "pushmessage.h"

#include <ncursesall.h>
#include <time.h>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// --------------------------- Main ---------------------------

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

// Generate
GMapSlot *generateSlot();
void generateViewMap(GMap *gGMap);

// Selected
int selectedGMap;

// View size
const int indentX = 0,
          indentY = 0;
const int viewWidth = 80,
          viewHeight = 24;

// --------------------------- Categories ---------------------------

map <string, GMapCategory*> gMapCategoriesDynamic;
map <string, GMapCategory*> gMapCategoriesStatic;

// Luck
float allGMapCategoriesLuck(map<string, GMapCategory *> gMapCategories);
void setGMapCategoriesRealLuck(map<string, GMapCategory *> &sMapCategories);

// Generate
GMapCategory *generateCategory(map<string, GMapCategory *> gMapCategories);
GMapCategory *generateCategoryStatic();
GMapCategory *generateCategoryDynamic();

// Luck find dynamic object
float gMapObjectDynamicLuck;

#endif // _FILE_MAIN_

