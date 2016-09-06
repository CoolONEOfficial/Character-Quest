#ifndef _FILE_BOBJCAT_
#define _FILE_BOBJCAT_

#include "savedelete.h"
#include "rands.h"
#include "bobj.h"

#include <map>
#include <string>
#include <cassert>

using namespace std;

// --------------------------- Biome Object Category ---------------------------

class BObjCat
{
public:
    BObjCat(float luck_ = 20.0f, map <string, BObj*> object_ = {});

    // Objects luck
    float objectsLuck();

    // Generate object
    BObj *genObject();

    // --------------------------- Values ---------------------------

    // Object
    map <string, BObj*> getObject();
    void setObjectMap(map <string, BObj*> object_);
    void setObject(string key_, BObj* value_);

    // Luck
    float getLuck();
    void setLuck(float luck_);

private:

    // Object
    map <string, BObj*> object;

    // Luck
    float luck;
};

#endif // _FILE_BOBJCAT_
