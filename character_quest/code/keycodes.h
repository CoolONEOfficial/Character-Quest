#ifndef _FILE_KEY_CODES_
#define _FILE_KEY_CODES_

#include "systems.h"

#define DIFFERENT_ENG_CHARS 32
#define LENGTH_ENG_ALPHABET 26
#define FIRST_ENG_BIG_CHAR 65
#define LAST_ENG_BIG_CHAR (FIRST_ENG_BIG_CHAR + LENGTH_ENG_ALPHABET)
#define FIRST_ENG_SMALL_CHAR 97
#define LAST_ENG_SMALL_CHAR (FIRST_ENG_SMALL_CHAR + LENGTH_ENG_ALPHABET)

#define DIFFERENT_RUS_CHARS 32
#define LENGTH_RUS_ALPHABET 33
#define FIRST_RUS_BIG_CHAR 1152
#define LAST_RUS_BIG_CHAR (FIRST_RUS_BIG_CHAR + LENGTH_RUS_ALPHABET)
#define FIRST_RUS_SMALL_CHAR 1184
#define LAST_RUS_SMALL_CHAR (FIRST_RUS_SMALL_CHAR + LENGTH_RUS_ALPHABET)

// --------------------------- Key Codes ---------------------------

bool keyEng(char engChar, int keyStroke)
{
    // English keys

    // To small keyChar
    if(keyStroke >= FIRST_ENG_BIG_CHAR &&
            keyStroke <= LAST_ENG_BIG_CHAR)
    {
        keyStroke += DIFFERENT_ENG_CHARS;
    }

    if(keyStroke == engChar)
        return true;
    return false;
}

// Arrows

bool keyArrowUp(int keyStroke)
{
    if(keyStroke == 65)
        return true;
    return false;
}

bool keyArrowLeft(int keyStroke)
{
    if(keyStroke == 68)
        return true;
    return false;
}

bool keyArrowDown(int keyStroke)
{
    if(keyStroke == 66)
        return true;
    return false;
}

bool keyArrowRight(int keyStroke)
{
    if(keyStroke == 100)
        return true;
    return false;
}

// Func

bool keyFunc(int keyStroke, int kNum)
{
    if(kNum < 5 && kNum > 0)
        if(keyStroke == 80 + kNum - 1)
            return true;
    return false;
}

// Nums

bool keyNum(int keyStroke, int kNum)
{
    if(kNum < 10)
        if(keyStroke == 48 + kNum)
            return true;
    return false;
}

// Other

bool keyEsc(int keyStroke)
{
    if(keyStroke == 27)
        return true;
    return false;
}

bool keyEnter(int keyStroke)
{
    if(keyStroke ==
    #if LINUX
    10
    #elif WINDOWS
    13
    #endif
    )
        return true;
    return false;
}

bool keySpace(int keyStroke)
{
    if(keyStroke == 32)
        return true;
    return false;
}

bool keyBackspace(int keyStroke)
{
    if(keyStroke ==
    #if LINUX
    263
    #elif WINDOWS
    8
    #endif
    )
        return true;
    return false;
}

#endif // _FILE_KEY_CODES_
