#ifndef _FILE_SAVESLOT_
#define _FILE_SAVESLOT_

#include "gmapworld.h"
#include "gmaphome.h"

#include <map>
#include <string>

using namespace std;

// --------------------------- Save Slot ---------------------------

class SaveSlot
{
public:
    SaveSlot(GMapWorld *sGMap = new GMapWorld(), string sPlayerName = "Empty");

    // Game Map
    GMapWorld gMap;

    // Player name
    string playerName;

    // Saved
    bool saved();

    // Emty
    bool is_empty();
};

#endif // _FILE_SAVESLOT_
