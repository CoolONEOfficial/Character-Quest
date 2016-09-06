#include "rands.h"

float randf(int limit, float minPart)
{
    // Random float

    assert(limit != 0 && ("Null limit" || true));

    // Find minPart
    int part = 1;

    do
    {
        minPart *= 10;
        part *= 10;

    }while(minPart < 1);

    // Generate float
    int limitInt = limit;

    int randInt = rand() % limitInt;

    float randFloat = (rand() % part) / (float)part;

    return randInt + randFloat;
}

int randi(int limit)
{
    // Random Int

    return rand() % limit;
}

bool luck(float chance, float limit)
{
    // Luck

    float random = randf(limit);

    if(random < chance)
    {
        return true;
    }
    else
    {
        return false;
    }
}
