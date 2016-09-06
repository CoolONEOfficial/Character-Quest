#ifndef _FILE_SCENE_
#define _FILE_SCENE_

#include "savedelete.h"
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

    // Buttons
    void drawButtons(int dSelectedButton, int scrW = scrWidth(), int scrH = scrHeight());

    // Labels
    void drawLabels(int scrW = scrWidth(), int scrH = scrHeight());

    // Add button
    void addButton(Button *aButton);

    // Align
    void alignButtonsX(int bY);
    void alignButtonsY(int bX);

    // --------------------------- Values ---------------------------

    // Buttons
    vector <Button*> getButton();
    void setButtonVector(vector<Button*> button_);
    void setButton(int key_, Button* value_);

    // Id's
    map <string, int> getButtonId();
    void setButtonIdMap(map <string, int> buttonId_);
    void setButtonId(string key_, int value_);

    // Labels
    vector <Label*> getLabel();
    void setLabelVector(vector <Label*> label_);
    void setLabel(int key_, Label* value_);

private:

    // Buttons
    vector <Button*> button;
    map <string, int> buttonId;

    // Labels
    vector <Label*> label;
};

#endif // _FILE_SCENE_
