#ifndef _FILE_SCENE_
#define _FILE_SCENE_

#include "ctrlpointers.h"
#include "screen.h"
#include "button.h"
#include "label.h"

#include <string>
#include <vector>

using namespace std;

// --------------------------- Scene ---------------------------

class Scene
{
public:
    Scene(vector <Label*> sLabel = {}, vector <Button*> sButton = {},
          bool alBX = false, int bY = scrDHeight/2, int alBY = false, int bX = scrDWidth/2);
    Scene(const Scene *&cScene);
    ~Scene();

    // Draw
    void draw(int dSelectedButton, int scrW = scrWidth(), int scrH = scrHeight());

    // --------------------------- Buttons ---------------------------

    vector <Button*> button;
    map <string, int> buttonId;

    // Add
    void addButton(Button *aButton);

    // Align
    void alignButtonsX(int bY);
    void alignButtonsY(int bX);

    // Draw
    void drawButtons(int dSelectedButton, int scrW = scrWidth(), int scrH = scrHeight());

    // --------------------------- Labels ---------------------------

    vector <Label*> label;

    // Draw
    void drawLabels(int scrW = scrWidth(), int scrH = scrHeight());
};

#endif // _FILE_SCENE_
