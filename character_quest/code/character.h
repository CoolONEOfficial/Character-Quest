#ifndef _FILE_CHARACTER_
#define _FILE_CHARACTER_

#include <map>
#include <vector>
#include <string>
#include <ncursesall.h>

using namespace std;

// --------------------------- Character ---------------------------

class Character
{
public:
    Character(char cNaturalImage = '.',
              int cSmallWidth = 4, int cSmallHeight = 5, vector<string> cSmallImage = {""},
              int cNormalWidth = 6, int cNormalHeight = 8, vector<string> cNormalImage = {""},
              int cBigWidth = 8, int cBigHeight = 10, vector<string> cBigImage = {""});

    // Widths / Heights
    int widthSmall, heightSmall;
    int widthNormal, heightNormal;
    int widthBig, heightBig;

    int width(string cSize);
    int height(string cSize);

    // Images
    vector< string > imageSmall;
    vector< string > imageNormal;
    vector< string > imageBig;
    char imageNatural;

    void draw(int dX, int dY, string size);
};

#endif // _FILE_CHARACTER_
