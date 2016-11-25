#ifndef _FILE_ANIMATION_
#define _FILE_ANIMATION_

#include "timer.h"

// --------------------------- Animaion ---------------------------

class Animation
{
public:
    Animation(float startValue_, float endValue_, float speed_);

private:
    // Values
    float startValue;
    float value;
    float endValue;

    // Speed
    float speed;

    // Paused
    bool paused;
public:

    // Timer
    Timer timer;

    // Control
    void start();
    void pause();
    void stop();

    // Tact
    void tact();

    // Started / Finished
    bool started();
    bool finished();

    // --------------------------- Encapsulation ---------------------------

    // Values

    // Start
    float getStartValue();
    void setStartValue(float startValue_);

    // Value
    float getValue();
    void setValue(float value_);

    // End
    float getEndValue();
    void setEndValue(float endValue_);

    // Speed
    float getSpeed();
    void setSpeed(float speed_);

    // Paused
    bool getPaused();
    void setPaused(bool paused_);
};

#endif // _FILE_ANIMATION_
