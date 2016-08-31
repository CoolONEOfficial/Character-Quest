#ifndef _FILE_RANDS_
#define _FILE_RANDS_

#include <stdlib.h>
#include <cassert>

// --------------------------- Randoms ---------------------------

// Float
float randf(int limit, float minPart = 0.01);

// Integer
int randi(int limit);

// Luck
bool luck(float chance, float limit = 100.0);

#endif // _FILE_RANDS_

