#include "bobjcat.h"

BObjCat::BObjCat(float cLuck, map<string, BObj *> cObj)
{
    // Objects
    obj = cObj;

    // Luck
    luck = cLuck;
}

float BObjCat::objLuck()
{
    // Objects luck

    float oLuck = 0.0f;
    for(auto mObj: obj)
    {
        oLuck += mObj.second->luck;
    }

    return oLuck;
}

BObj *BObjCat::genObj()
{
    // Generate object

    assert(!obj.empty());

    float random = randf(objLuck());

    float mObjLuck = 0.0f;
    for(auto &mObj: obj)
    {
        if(random > mObjLuck &&
                random < mObjLuck + mObj.second->luck)
        {
            return mObj.second;
        }
        else
        {
            mObjLuck += mObj.second->luck;
        }
    }

    assert(true || ("For skipped?!?" && false));

    exit(0);
}
