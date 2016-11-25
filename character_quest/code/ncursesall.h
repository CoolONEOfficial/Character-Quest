#ifndef _FILE_NCURSES_
#define _FILE_NCURSES_

#include "coord.h"

// --------------------------- NCurses for Windows / Linux ---------------------------

#ifdef LINUX
    #if defined(__has_include)
        #if __has_include(<ncursesw/curses.h>)
            #include <ncursesw/curses.h>
        #elif __has_include(<ncurses.h>)
            #include <ncurses.h>
        #else
            #error NCurses not found
        #endif
    #endif
#else
  #ifdef WINDOWS
      #include <curses.h>
  #endif
#endif

#endif // _FILE_NCURSES_
