#ifndef _FILE_LABEL_
#define _FILE_LABEL_

#include "screen.h"
#include "text.h"
#include "timer.h"
#include "font.h"
#include "character.h"

#include <ncursesall.h>
#include <vector>
#include <string>

using namespace std;

// --------------------------- Label ---------------------------

class Label
{
public:
    Label(string lText, int lX, int lY, int lW, int lH, const Font *lFont,
          bool lAnimation = true, float lAnimationSpeedMSecs = 0.01f, int lIndent = 2, bool lAlign = true);

    // Coords
    int x, y;

    // Width / Height
    int width, height;

    // Text
    string text;

    // Indent
    int indent;

    // Align
    bool align;

    // Font
    Font *font;

    // Draw
    bool draw(int scrW, int scrH);

    // --------------------------- Animation ---------------------------

    string animationText();

    // View size
    float animationValue;

    // Bool
    bool animation;

    // Started / Finished Bools
    bool animationStarted;
    bool animationFinished();

    Timer *animationTimer;

    // Tact
    void animationTact();

    // Speed
    float animationSpeed;

    // Control
    void animationStart();
    void animationStop();
    void animationOn();
    void animationOff();
};

#endif // _FILE_LABEL_
