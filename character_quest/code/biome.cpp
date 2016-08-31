#include "biome.h"

Biome::Biome(float bDynamiclLuck, map<string, BObjCat *> bCatStatic, map<string, BObjCat *> bCatDynamic)
{
    // Categories
    catStatic = bCatStatic;
    catDynamic = bCatDynamic;

    // Luck find dynamic object
    dynamicLuck = bDynamiclLuck;
}

float Biome::catsLuck(map<string, BObjCat *> &mapCats)
{
    // Categories luck

    assert(!mapCats.empty() || ( "Categories map is empty" && false ));

    float cLuck = 0.0f;
    for(auto mCat: mapCats)
    {
        cLuck += mCat.second->luck;
    }

    return cLuck;
}

BObjCat *Biome::genCat(map<string, BObjCat *> &mapCats)
{
    // Generate category

    assert(!mapCats.empty() || ( "Categories map is empty" && false ));

    float random = randf(catsLuck(mapCats));

    float mCatLuck = 0.0f;
    for(auto &mCat: mapCats)
    {
        if(random > mCatLuck &&
                random < mCatLuck + mCat.second->luck)
        {
            return mCat.second;
        }
        else
        {
            mCatLuck += mCat.second->luck;
        }
    }

    assert(true || ("For skipped?!?" && false));

    exit(0);
}

BObjCat *Biome::genCatStatic()
{
    // Generate category static

    return genCat(catStatic);
}

BObjCat *Biome::genCatDynamic()
{
    // Generate category dynamic

    return genCat(catDynamic);
}
