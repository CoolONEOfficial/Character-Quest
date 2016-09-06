#ifndef _FILE_PUSHMESSAGE_
#define _FILE_PUSHMESSAGE_

#include "timer.h"

#include <string>

using namespace std;

// --------------------------- Message ---------------------------

class PushMessage
{
public:
    PushMessage(string text_ = "Text...", Timer deleteTimer_ = Timer(2000));

    // --------------------------- Values ---------------------------

    // Text
    string getText();
    void setText(string text_);

    // Timer
    Timer getDeleteTimer();
    void setDeleteTimer(Timer deleteTimer_);

private:
    // Text
    string text;

    // Timer
    Timer deleteTimer;
};

#endif // _FILE_PUSHMESSAGE_
