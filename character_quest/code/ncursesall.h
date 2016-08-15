#ifndef _FILE_NCURSES_
#define _FILE_NCURSES_

#include "systems.h"

// --------------------------- NCurses for Windows / Linux ---------------------------

#if UNIX
    #include <ncurses.h>
#elif WINDOWS
    #include <curses.h>
#endif

#endif // _FILE_NCURSES_
