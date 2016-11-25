#include "timer.h"

clock_t timer(int time_)
{
    // Get timer

    return clock() + toClocks(time_);
}

clock_t toClocks(int mSecs_)
{
    // Tp clocks

    return mSecs_ * CLOCKS_PER_MSEC;
}

clock_t toMSecs(int clocks_)
{
    // To mSecs

    return clocks_ / CLOCKS_PER_MSEC;
}

Timer::Timer(int duration_, bool started_)
{
    // Times

    // Start
    setStartTime(clock());

    // Past
    setPastTime(0);

    // End
    setEndTime(timer(duration_));

    // Remaining
    setRemTime(duration_);

    // Duration
    setDuration(duration_);

    // Start / Stop
    setStarted(started_);
}

bool Timer::finished()
{
    // Finished

    return clock() > getEndTime();
}

void Timer::start()
{
    // Start

    if(!started)
    {
        // Start
        setStarted(true);
        setStartTime(clock() - pastTime);
        setEndTime(timer(remTime));
    }
    else
        // Restart
        Timer(time);
}

void Timer::pause()
{
    // Pause

    setStarted(false);
    setRemTime(endTime - clock());
    setPastTime(clock() - startTime);
}

void Timer::stop()
{
    // Stop

    Timer(duration, false);
}

// --------------------------- Encapsulation ---------------------------

// Times

// Start

clock_t Timer::getStartTime()
{
    // Get
    return startTime;
}
void Timer::setStartTime(clock_t startTime_)
{
    // Set
    startTime = startTime_;
}

// End

clock_t Timer::getEndTime()
{
    // Get
    return endTime;
}
void Timer::setEndTime(clock_t endTime_)
{
    // Set
    endTime = endTime_;
}

// Past

clock_t Timer::getPastTime()
{
    // Get
    return pastTime;
}
void Timer::setPastTime(clock_t pastTime_)
{
    // Set
    pastTime = pastTime_;
}

// Remaining

clock_t Timer::getRemTime()
{
    // Get
    return remTime;
}
void Timer::setRemTime(clock_t remTime_)
{
    // Set
    remTime = remTime_;
}

// Duration

clock_t Timer::getDuration()
{
    // Get
    return duration;
}
void Timer::setDuration(clock_t duration_)
{
    // Set
    duration = duration_;
}

// Started

bool Timer::getStarted()
{
    // Get
    return started;
}
void Timer::setStarted(bool started_)
{
    // Set
    started = started_;
}
