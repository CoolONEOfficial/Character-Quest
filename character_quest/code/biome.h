#ifndef _FILE_BIOME_
#define _FILE_BIOME_

#include "savedelete.h"
#include "rands.h"
#include "bobjcat.h"

#include <map>
#include <string>
#include <cassert>

using namespace std;

// --------------------------- Biome ---------------------------

class Biome
{
public:
    Biome(float dynamiclLuck_ = 20.0f,
          map <string, BObjCat*> catStatic_ = {},
          map <string, BObjCat*> catDynamic_ = {});

    // Categories luck
    float catsLuck(map<string, BObjCat *> mapCats);

    // Generate category
    BObjCat *genCat(map<string, BObjCat *> mapCats);
    BObjCat *genCatStatic();
    BObjCat *genCatDynamic();

    // Emty
    bool is_empty();

    // --------------------------- Values ---------------------------

    // Categories

    // Dynamic
    map<string,BObjCat*> getCatDynamic();
    void setCatDynamicMap(map<string,BObjCat*> catDynamic_);
    void setCatDynamic(string key_, BObjCat* value_);

    // Static
    map<string,BObjCat*> getCatStatic();
    void setCatStaticMap(map<string, BObjCat*> catStatic_);
    void setCatStatic(string key_, BObjCat* value_);

    // Dynamic luck
    float getDynamicLuck();
    void setDynamicLuck(float dynamicLuck_);

private:
    // Categories

    // Static
    map<string,BObjCat*> catStatic;

    // Dynamic
    map<string,BObjCat*> catDynamic;

    // Dynamic luck
    float dynamicLuck;
};

#endif // _FILE_BIOME_
