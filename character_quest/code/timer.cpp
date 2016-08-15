#include "timer.h"

clock_t timer(int mSecs)
{
    // Get timer

    return clock() + (mSecs * CLOCKS_PER_MSEC);
}

Timer::Timer(int tMSecs)
{
    // Start
    start(tMSecs);
}

bool Timer::started()
{
    // Started

    if(clock() > startTime)
    {
        return true;
    }
    return false;
}

bool Timer::finished()
{
    // Finished

    if(clock() >= outTime)
    {
        return true;
    }
    return false;
}

void Timer::start(int sMSecs)
{
    // Start

    // Set

    // Start time
    startTime = clock();

    // MSecs
    mSecs = sMSecs;

    // Out time
    outTime = timer(sMSecs);
}

void Timer::restart()
{
    // Restart

    start(mSecs);
}

void Timer::stop()
{
    // Stop

    // Set

    // Out time
    outTime = clock();
}
