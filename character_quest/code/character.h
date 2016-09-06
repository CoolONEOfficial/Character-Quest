#ifndef _FILE_CHARACTER_
#define _FILE_CHARACTER_

#include <map>
#include <vector>
#include <string>
#include <ncursesall.h>
#include <cassert>

using namespace std;

// --------------------------- Character ---------------------------

class Character
{
public:
    Character(char imageNatural_ = '.',
              int widthSmall_ = 4, int heightSmall_ = 5, vector<string> imageSmall_ = {""},
              int widthNormal_ = 6, int heightNormal_ = 8, vector<string> imageNormal_ = {""},
              int widthBig_ = 8, int heightBig_ = 10, vector<string> imageBig_ = {""});

    // Draw
    void draw(int dX, int dY, string size);

    // Size
    int width(string cSize);
    int height(string cSize);

    // --------------------------- Values ---------------------------

    // -------------------------- Images --------------------------

    // Small
    vector<string> getImageSmall();
    void setImageSmall(vector<string> imageSmall_);

    // Normal
    vector<string> getImageNormal();
    void setImageNormal(vector<string> imageNormal_);

    // Big
    vector<string> getImageBig();
    void setImageBig(vector<string> imageBig_);

    // Natural
    char getImageNatural();
    void setImageNatural(char imageNatural_);

    // -------------------------- Sizes --------------------------

    // Small
    int getWidthSmall();
    void setWidthSmall(int widthSmall_);
    int getHeightSmall();
    void setHeightSmall(int heightSmall_);

    // Normal
    int getWidthNormal();
    void setWidthNormal(int widthNormal_);
    int getHeightNormal();
    void setHeightNormal(int heightNormal_);

    // Big
    int getWidthBig();
    void setWidthBig(int widthBig_);
    int getHeightBig();
    void setHeightBig(int heightBig_);

private:
    // -------------------------- Images --------------------------

    // Small
    vector<string> imageSmall;

    // Normal
    vector<string> imageNormal;

    // Big
    vector<string> imageBig;

    // Natural
    char imageNatural;

    // -------------------------- Sizes --------------------------

    // Small
    int widthSmall;
    int heightSmall;

    // Normal
    int widthNormal;
    int heightNormal;

    // Big
    int widthBig;
    int heightBig;
};

#endif // _FILE_CHARACTER_
