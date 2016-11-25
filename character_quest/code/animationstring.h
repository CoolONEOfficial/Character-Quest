#ifndef _FILE_ANIMATIONSTRING_
#define _FILE_ANIMATIONSTRING_

#include "animation.h"
#include "string"

using namespace std;

// --------------------------- Animation String ---------------------------

class AnimationString : public Animation
{
public:
    AnimationString(string text_ = "NoName", float animationSpeed_ = 0.01f);

    // Texts

    string text();
private:
    string endText;
public:

    // --------------------------- Encapsulation ---------------------------

    // End Text
    string getEndText();
    void setEndText(string endText_);
};

#endif // _FILE_ANIMATIONSTRING_
