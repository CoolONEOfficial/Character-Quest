#include "keycodes.h"

bool keyEng(char engChar_, int keyStroke_)
{
    // English keys

    // To small keyChar
    if(keyStroke_ >= FIRST_ENG_BIG_CHAR &&
            keyStroke_ <= LAST_ENG_BIG_CHAR)
    {
        keyStroke_ += DIFFERENT_ENG_CHARS;
    }

    if(keyStroke_ == engChar_)
        return true;
    return false;
}

bool keyArrowUp(int keyStroke_)
{
    if(keyStroke_ == 65)
        return true;
    return false;
}

bool keyArrowDown(int keyStroke_)
{
    if(keyStroke_ == 66)
        return true;
    return false;
}

bool keyArrowRight(int keyStroke_)
{
    if(keyStroke_ == 100)
        return true;
    return false;
}

bool keyFunc(int keyStroke_, int kNum)
{
    if(kNum < 5 && kNum > 0)
        if(keyStroke_ == 80 + kNum - 1)
            return true;
    return false;
}

bool keyEnter(int keyStroke_)
{
    if(keyStroke_ ==
        #if LINUX
            10
        #elif WINDOWS
            13
        #endif
            )
        return true;
    return false;
}

bool keyEsc(int keyStroke_)
{
    if(keyStroke_ == 27)
        return true;
    return false;
}

bool keyNum(int keyStroke_, int kNum)
{
    if(kNum < 10)
        if(keyStroke_ == 48 + kNum)
            return true;
    return false;
}

bool keyBackspace(int keyStroke_)
{
    if(keyStroke_ ==
        #if LINUX
            263
        #elif WINDOWS
            8
        #endif
            )
        return true;
    return false;
}

bool keySpace(int keyStroke_)
{
    if(keyStroke_ == 32)
        return true;
    return false;
}

bool keyArrowLeft(int keyStroke_)
{
    if(keyStroke_ == 68)
        return true;
    return false;
}
