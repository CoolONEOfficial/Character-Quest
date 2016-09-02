#ifndef _FILE_BIOME_
#define _FILE_BIOME_

#include "savedelete.h"
#include "rands.h"
#include "bobjcat.h"

#include <map>
#include <string>
#include <cassert>

using namespace std;

class Biome
{
public:
    Biome(float bDynamiclLuck = 20.0f,
          map <string, BObjCat*> bCatStatic = {},
          map <string, BObjCat*> bCatDynamic = {});

    // Categories
    map <string, BObjCat*> catStatic, catDynamic;

    // Luck find dynamic object
    float dynamicLuck;

    // Categories luck
    float catsLuck(map<string, BObjCat *> &mapCats);

    // Generate category
    BObjCat *genCat(map<string, BObjCat*> &mapCats);
    BObjCat *genCatStatic();
    BObjCat *genCatDynamic();
};

#endif // _FILE_BIOME_
