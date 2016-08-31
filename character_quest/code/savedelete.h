#ifndef _FILE_SAVE_DELETE_POINTERS_
#define _FILE_SAVE_DELETE_POINTERS_

#include <stdlib.h>
#include <vector>

// --------------------------- Save delete ---------------------------

// Save delete
#define SAVE_DEL(dPointer) \
    if(dPointer != NULL) \
{ \
    delete &dPointer; \
    dPointer = NULL; \
}

// Save delete mas
#define SAVE_DEL_MAS(dVector) \
    for(auto &mVector: dVector) \
    { \
        SAVE_DEL(mVector); \
    }

// Save delete map
#define SAVE_DEL_MAP(dMap) \
    for(auto &mMap: dMap) \
    { \
        SAVE_DEL(mMap.second); \
    }

#endif // _FILE_SAVE_DELETE_POINTERS_

