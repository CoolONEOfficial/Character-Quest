#ifndef _FILE_ANIMATIONLABEL_
#define _FILE_ANIMATIONLABEL_

#include "rect.h"
#include "screencoord.h"
#include "label.h"
#include "animationstring.h"

#include <string>

using namespace std;

// --------------------------- Label ---------------------------

class AnimationLabel : public Label
{
public:
    explicit AnimationLabel(string text_ = "NoName", Font* font_ = new Font(), Rect<ScreenCoord> rect_ = Rect<ScreenCoord>(), WINDOW* screen_ = new WINDOW());

    // Animation
    AnimationString animation;

    // Text
    string getText();
    void setText(string text_);
};

#endif // _FILE_ANIMATIONLABEL_
