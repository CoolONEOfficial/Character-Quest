#ifndef _FILE_KEY_CODES_
#define _FILE_KEY_CODES_

#define DIFFERENT_ENG_CHARS 32
#define LENGTH_ENG_ALPHABET 26
#define FIRST_ENG_BIG_CHAR 65
#define LAST_ENG_BIG_CHAR (FIRST_ENG_BIG_CHAR + LENGTH_ENG_ALPHABET)
#define FIRST_ENG_SMALL_CHAR 97
#define LAST_ENG_SMALL_CHAR (FIRST_ENG_SMALL_CHAR + LENGTH_ENG_ALPHABET)

// --------------------------- Key Codes ---------------------------

// English
bool keyEng(char engChar_, int keyStroke_);

// Arrows
bool keyArrowUp(int keyStroke_);
bool keyArrowLeft(int keyStroke_);
bool keyArrowDown(int keyStroke_);
bool keyArrowRight(int keyStroke_);

// Func
bool keyFunc(int keyStroke_, int kNum);

// Nums
bool keyNum(int keyStroke_, int kNum);

// Other

bool keyEsc(int keyStroke_);
bool keyEnter(int keyStroke_);
bool keySpace(int keyStroke_);
bool keyBackspace(int keyStroke_);

#endif // _FILE_KEY_CODES_
