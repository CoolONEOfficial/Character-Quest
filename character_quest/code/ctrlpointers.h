#ifndef _FILE_CONTROL_POINTERS_
#define _FILE_CONTROL_POINTERS_

#include <stdlib.h>
#include <vector>

// --------------------------- Control of pointers ---------------------------

// Save Delete pointer
#define SAVE_DEL(dPointer) \
    if(dPointer != NULL) \
{ \
    delete &dPointer; \
    dPointer = NULL; \
}

// Save Delete mas pointers
#define SAVE_DEL_MAS(dVector) \
    for(auto &mVector: dVector) \
    { \
        SAVE_DEL(mVector); \
    }

// Save Delete map pointers
#define SAVE_DEL_MAP(dMap) \
    for(auto &mMap: dMap) \
    { \
        SAVE_DEL(mMap.second); \
    }

#endif // _FILE_CONTROL_POINTERS_

