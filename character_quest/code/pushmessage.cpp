#include "pushmessage.h"

PushMessage::PushMessage(string text_, Timer deleteTimer_)
{
    // Text
    text = text_;

    // Delete timer
    deleteTimer = deleteTimer_;
}

// --------------------------- Encapsulation ---------------------------

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
