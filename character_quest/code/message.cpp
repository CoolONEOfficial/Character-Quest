#include "pushmessage.h"

PushMessage::PushMessage(string mText, int mMSecs)
{
    // Text
    text = mText;

    // Time
    deleteTimer = new Timer(mMSecs);
}
