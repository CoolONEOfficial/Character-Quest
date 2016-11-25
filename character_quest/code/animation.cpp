#include "animation.h"

Animation::Animation(float startValue_, float endValue_, float speed_)
{
    // Start value
    setStartValue(startValue_);

    // End value
    setEndValue(endValue_);

    // Speed
    setSpeed(speed_);

    // Stop
    setValue(startValue_);
    setPaused(false);

    // Timer
    timer = Timer(100);
}

void Animation::start()
{
    // Start

    timer.start();

    if(paused)
        // Continue
        setPaused(false);
    else if(!started())
        // Start
        setValue(getValue() + speed);
    else
        // Restart
        setValue(speed);
}

void Animation::pause()
{
    // Pause

    setPaused(true);
    timer.pause();
}

void Animation::stop()
{
    // Stop

    setValue(getStartValue());
    timer.stop();
}

void Animation::tact()
{
    // Tact

    if(!finished() && started() && !getPaused() &&
            timer.finished())
    {
        setValue(getValue() + speed);
        timer.start();
    }
}

bool Animation::started()
{
    // Started

    return getValue() > getStartValue();
}

bool Animation::finished()
{
    // Finished

    return getValue() > getEndValue();
}

// --------------------------- Encapsulation ---------------------------

// Values

// Start

float Animation::getStartValue()
{
    // Get
    return startValue;
}
void Animation::setStartValue(float startValue_)
{
    // Set
    startValue = startValue_;
}

// Value

float Animation::getValue()
{
    // Get
    return value;
}
void Animation::setValue(float value_)
{
    // Set
    value = value_;
}

// End

float Animation::getEndValue()
{
    // Get
    return endValue;
}
void Animation::setEndValue(float endValue_)
{
    // Set
    endValue = endValue_;
}

// Speed

float Animation::getSpeed()
{
    // Get
    return speed;
}
void Animation::setSpeed(float speed_)
{
    // Set
    speed = speed_;
}

// Paused

bool Animation::getPaused()
{
    // Get
    return paused;
}
void Animation::setPaused(bool paused_)
{
    // Set
    paused = paused_;
}
