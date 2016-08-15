#ifndef _FILE_GMAPCATEGORY_
#define _FILE_GMAPCATEGORY_

#include "rands.h"
#include "gmapobject.h"

#include <map>
#include <vector>
#include <string>

using namespace std;

// --------------------------- Game map category

class GMapCategory
{
public:
    GMapCategory(float oLuck = 100.0);
    ~GMapCategory();

    // Luck
    float luck;
    float realLuck;

    // Objects
    vector<GMapObject*> objects;
    map<string, int> objectsId;

    GMapObject *generateObject();

    void setObjectsRealLuck();
    void addObject(GMapObject* aObject, string name);
    void setRealLuck(float allLuck);
};

#endif // _FILE_GMAPCATEGORY_
