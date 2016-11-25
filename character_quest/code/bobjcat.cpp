#include "bobjcat.h"

BObjCat::BObjCat(float luck_, map<string, BObj *> object_)
{
    // Objects
    object = object_;

    // Luck
    setLuck(luck_);
}

float BObjCat::objectsLuck()
{
    // Objects luck

    float oLuck = 0.0f;
    for(auto mObj: object)
    {
        oLuck += mObj.second->getLuck();
    }

    return oLuck;
}

BObj *BObjCat::genObject()
{
    // Generate object

    assert(!object.empty());

    float random = randf(objectsLuck());

    float mObjLuck = 0.0f;
    for(auto &mObj: object)
    {
        if(random >= mObjLuck &&
                random <= mObjLuck + mObj.second->getLuck())
        {
            return mObj.second;
        }
        else
        {
            mObjLuck += mObj.second->getLuck();
        }
    }

    assert("For skipped?!?" && false);

    exit(EXIT_FAILURE);
}

// --------------------------- Encapsulation ---------------------------

// Luck

float BObjCat::getLuck()
{
    // Get
    return luck;
}
void BObjCat::setLuck(float luck_)
{
    // Set
    luck = luck_;
}
