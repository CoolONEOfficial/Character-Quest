#ifndef _FILE_PUSHMESSAGE_
#define _FILE_PUSHMESSAGE_

#include "timer.h"

#include <string>

using namespace std;

// --------------------------- Message ---------------------------

class PushMessage
{
public:
    PushMessage(string mText = "Text...", int mMSecs = 2000);

    // Text
    string text;

    // Timer
    Timer *deleteTimer;

};

#endif // _FILE_PUSHMESSAGE_
