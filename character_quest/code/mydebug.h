#ifndef _FILE_MY_DEBUG_
#define _FILE_MY_DEBUG_

#include <ncursesall.h>
#include <stdlib.h>

using namespace std;

// --------------------------- Debug ---------------------------

// Text
void debugText(const char *text,...)
{
    // Debug text and exit

    // Text
    move(0,0);
    printw(text);

    // Exit
    getch();
    exit(0);
}

#endif // _FILE_MY_DEBUG_

