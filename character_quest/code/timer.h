#ifndef _FILE_TIMER_
#define _FILE_TIMER_

#define CLOCKS_PER_MSEC (CLOCKS_PER_SEC/1000)

#include <ctime>

// --------------------------- Timer ---------------------------

clock_t timer(int mSecs);

class Timer
{
public:
    Timer(int tMSecs = 2000);

    bool started();
    bool finished();

    // Control
    void start(int sMSecs);
    void restart();
    void stop();

private:
    // Out time
    clock_t outTime;

    // MSecs
    int mSecs;

    // Start time
    clock_t startTime;
};

#endif // _FILE_TIMER_
