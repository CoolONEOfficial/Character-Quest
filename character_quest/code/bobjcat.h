#ifndef _FILE_BOBJCAT_
#define _FILE_BOBJCAT_

#include "savedelete.h"
#include "rands.h"
#include "bobj.h"

#include <map>
#include <string>
#include <cassert>

using namespace std;

class BObjCat
{
public:
    BObjCat(float cLuck, map <string, BObj*> cObj);

    // Objects
    map <string, BObj*> obj;

    // Luck
    float luck;
    float objLuck();

    // Generate object
    BObj *genObj();
};

#endif // _FILE_BOBJCAT_
