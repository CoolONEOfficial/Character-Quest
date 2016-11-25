#ifndef _FILE_TIMER_
#define _FILE_TIMER_

#define CLOCKS_PER_MSEC (CLOCKS_PER_SEC/1000)

#include <ctime>

// --------------------------- Timer ---------------------------

clock_t timer(int time_);

clock_t toClocks(int mSecs_);
clock_t toMSecs(int clocks_);

class Timer
{
public:
    explicit Timer(int duration_ = 2000, bool started_ = false);

private:
    // Times
    clock_t startTime;
    clock_t endTime;
    clock_t pastTime;
    clock_t remTime;

    // Duration
    clock_t duration;

    // Started
    bool started;
public:

    // Finished
    bool finished();

    // Control
    void start();
    void pause();
    void stop();

    // --------------------------- Encapsulation ---------------------------

    // Times

    // Start
    clock_t getStartTime();
    void setStartTime(clock_t startTime_);

    // Out
    clock_t getEndTime();
    void setEndTime(clock_t endTime_);

    // Past time
    clock_t getPastTime();
    void setPastTime(clock_t pastTime_);

    // Remaining time
    clock_t getRemTime();
    void setRemTime(clock_t remTime_);

    // Duration
    clock_t getDuration();
    void setDuration(clock_t duration_);

    // Started
    bool getStarted();
    void setStarted(bool started_);
};

#endif // _FILE_TIMER_
