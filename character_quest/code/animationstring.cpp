#include "animationstring.h"

AnimationString::AnimationString(string text_, float animationSpeed_)
    : Animation(0.0f, text_.size(), animationSpeed_)
{
    // End text
    setEndText(text_);
}

string AnimationString::text()
{
    // Text

    string text_;

    size_t length_ = getEndText().length();

    for(size_t mChar = 0; mChar < length_; mChar++)
    {
        if(getValue() > mChar)
            text_.push_back(endText[mChar]);
    }

    return text_;
}

// --------------------------- Encapsulation ---------------------------

// Text

string AnimationString::getEndText()
{
    // Get
    return endText;
}
void AnimationString::setEndText(string endText_)
{
    // Set
    endText = endText_;
}
