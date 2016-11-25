#include "biome.h"

Biome::Biome(float dynamiclLuck_, map<string, BObjCat *> catStatic_, map<string, BObjCat *> catDynamic_)
{
    // Categories

    // Static
    catStatic = catStatic_;

    // Dynamic
    catDynamic = catDynamic_;

    // Luck find dynamic object
    setDynamicLuck(dynamiclLuck_);
}

BObjCat *Biome::genCat(map<string, BObjCat *> mapCats)
{
    // Generate category

    assert(!mapCats.empty() && ( "Categories map is empty" || true ));

    float random = randf(catsLuck(mapCats));

    float mCatLuck = 0.0f;
    for(auto &mCat: mapCats)
    {
        if(random >= mCatLuck &&
                random <= mCatLuck + mCat.second->getLuck())
        {
            return mCat.second;
        }
        else
        {
            mCatLuck += mCat.second->getLuck();
        }
    }

    assert("For skipped?!?" && false);

    exit(EXIT_FAILURE);
}

float Biome::catsLuck(map<string, BObjCat *> mapCats)
{
    // Categories luck

    assert(!mapCats.empty() && ( "Categories map is empty" || true ));

    float cLuck = 0.0f;
    for(auto mCat: mapCats)
    {
        cLuck += mCat.second->getLuck();
    }

    return cLuck;
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

bool Biome::is_empty()
{
    // Empty

    return catDynamic.empty() && catStatic.empty();
}

// --------------------------- Encapsulation ---------------------------

// Dynamic luck

float Biome::getDynamicLuck()
{
    // Get
    return dynamicLuck;
}
void Biome::setDynamicLuck(float dynamicLuck_)
{
    // Set
    dynamicLuck = dynamicLuck_;
}
