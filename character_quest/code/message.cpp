#include "pushmessage.h"

PushMessage::PushMessage(string text_, Timer deleteTimer_)
{
    // Text
    text = text_;

    // Delete timer
    deleteTimer = deleteTimer_;
}

// --------------------------- Values ---------------------------

// Text

string PushMessage::getText()
{
    // Get
    return text;
}
void PushMessage::setText(string text_)
{
    // Set
    text = text_;
}

// Delete Timer

Timer PushMessage::getDeleteTimer()
{
    // Get
    return deleteTimer;
}
void PushMessage::setDeleteTimer(Timer deleteTimer_)
{
    // Set
    deleteTimer = deleteTimer_;
}
