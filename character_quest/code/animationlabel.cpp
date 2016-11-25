#include "animationlabel.h"

AnimationLabel::AnimationLabel(string text_, Font* font_, Rect<ScreenCoord> rect_, WINDOW *screen_)
    : Label(text_, font_, rect_, screen_)
{
    // Animation
    animation = AnimationString(text_);
}

// Text

string AnimationLabel::getText()
{
    // Get
    return animation.getEndText();
}

void AnimationLabel::setText(string text_)
{
    // Set
    animation.setEndText(text_);
}
