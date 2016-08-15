#include "screen.h"

float scrWidth()
{
    return getmaxx(stdscr);
}

float scrHeight()
{
    return getmaxy(stdscr);
}

int alignW(int val, int scrW)
{
    return (val * scrW) / scrDWidth;
}

int alignH(int val, int scrH)
{
    return (val * scrH) / scrDHeight;
}
