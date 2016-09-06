#include "saveslot.h"

SaveSlot::SaveSlot(GMapWorld *sGMap, string sPlayerName)
{
    // GMap
    gMap = *sGMap;

    // Player name
    playerName = sPlayerName;
}

bool SaveSlot::saved()
{
    // Saved

    return gMap.getSaved();
}

bool SaveSlot::is_empty()
{
    // Empty

    return gMap.is_empty();
}
