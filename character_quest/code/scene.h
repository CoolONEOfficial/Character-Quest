#ifndef _FILE_SCENE_
#define _FILE_SCENE_

#include "savedelete.h"
#include "screen.h"
#include "button.h"
#include "animationlabel.h"
#include "rect.h"

#include <string>
#include <vector>

using namespace std;

// --------------------------- Scene ---------------------------

class Scene
{
public:
    explicit Scene(vector <AnimationLabel*> labels_ = {}, vector <Button*> buttons_ = {}, WINDOW* screen_ = new WINDOW(),
                         bool alignButtonsX_ = false, int buttonY_ = screenHeightDefault/2,
                         bool alignButtonsY_ = false, int buttonX_ = screenWidthDefault/2);
    Scene(const Scene *&scene_);
    virtual ~Scene();

    // Buttons
    vector <Button*> button;
    map <string, int> buttonId;

    // Labels
    vector <AnimationLabel*> label;

    // Screen
    WINDOW* screen;
    float alignX(float x_);
    float alignY(float y_);
    void initScreen(WINDOW *screen_);

    // Draw
    void draw(int selectedButton_);

    // Buttons
    void drawButtons(int selectedButton_);

    // Labels
    void drawLabels();

    // Add button
    void addButton(Button *button_);

    // Align
    void alignButtonsX(int y_);
    void alignButtonsY(int x_);
};

#endif // _FILE_SCENE_
