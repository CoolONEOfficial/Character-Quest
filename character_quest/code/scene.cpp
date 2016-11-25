#include "scene.h"

Scene::Scene(vector<AnimationLabel *> labels_, vector<Button *> buttons_, WINDOW *screen_, bool alignButtonsX_, int buttonY_, bool alignButtonsY_, int buttonX_)
{
    // Button
    for(auto mButton: buttons_)
    {
        addButton(mButton);
    }

    // Label
    label = labels_;

    // Align Buttons
    if(alignButtonsX_)
    {
        alignButtonsX(buttonY_);
    }
    else if(alignButtonsY_)
    {
        alignButtonsY(buttonX_);
    }

    // Screen
    initScreen(screen_);
}

Scene::Scene(const Scene *&scene_)
{
    Scene(scene_->label, scene_->button);
}

Scene::~Scene()
{
    // Button
    SAVE_DEL_MAS(button)

    // Label
    SAVE_DEL_MAS(label)
}

float Scene::alignX(float x_)
{
    // Align X

    return ::alignX(x_, screen);
}

float Scene::alignY(float y_)
{
    // Align Y

    return ::alignY(y_, screen);
}

void Scene::initScreen(WINDOW *screen_)
{
    // Set screen

    if(screen_ != new WINDOW())
    {
        screen = screen_;

        // Labels
        for(auto &mLabel: label)
        {
            mLabel->initScreen(screen_);
        }

        // Buttons
        for(auto &mButton: button)
        {
            mButton->initScreen(screen_);
        }
    }
}

void Scene::draw(int selectedButton_)
{
    // Draw

    assert(screen != new WINDOW());

    // Labels
    drawLabels();

    // Buttons
    drawButtons(selectedButton_);
}

void Scene::addButton(Button *button_)
{
    // Add button

    // Map
    size_t buttonsSize = button.size();
    buttonId[button_->getName()] = buttonsSize;

    // Button
    button.push_back(button_);
}

void Scene::alignButtonsX(int y_)
{
    // Align buttons width

    for(size_t mButton = 0; mButton < button.size(); mButton++)
    {
        button[mButton]->coord.setX(screenWidthDefault / (button.size()+1) * (mButton+1));
        button[mButton]->coord.setY(y_);
    }
}

void Scene::alignButtonsY(int x_)
{
    // Align buttons height

    for(size_t mButton = 0; mButton < button.size(); mButton++)
    {
        button[mButton]->coord.setX(x_);
        button[mButton]->coord.setY(screenHeightDefault / (button.size()+1) * (mButton+1));
    }
}

void Scene::drawButtons(int selectedButton_)
{
    // Draw buttons

    if(!button.empty())
    {
        // Deselect all
        for(auto &mButton: button)
        {
            mButton->setSelected(false);
        }

        // Select selected
        button[selectedButton_]->setSelected(true);

        // Draw
        for(auto mButton: button)
        {
            mButton->draw();
        }
    }
}

void Scene::drawLabels()
{
    // Draw labels

    if(!label.empty())
    {        
        // Draw
        for(auto mLabel: label)
        {
            mLabel->draw();
        }

        // Start next if previous finished
        for(size_t mLabel = 0; mLabel < label.size()-1; mLabel++)
        {
            if(label[mLabel]->animation.finished() &&
               !label[mLabel+1]->animation.started())
            {
                label[mLabel+1]->animation.start();
            }
        }
    }
}
