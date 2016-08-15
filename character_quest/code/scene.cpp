#include "scene.h"

Scene::Scene(vector<Label *> sLabel, vector<Button *> sButton, bool alBX, int bY, int alBY, int bX)
{
    // Button
    for(auto mButton: sButton)
    {
        addButton(mButton);
    }

    // Label
    label = sLabel;

    if(alBX)
    {
        alignButtonsX(bY);
    }
    else if(alBY)
    {
        alignButtonsY(bX);
    }
}

Scene::Scene(const Scene *&cScene)
{
    Scene(cScene->label, cScene->button);
}

Scene::~Scene()
{
    // Button
    SAVE_DEL_MAS(button)

    // Label
    SAVE_DEL_MAS(label)
}

void Scene::draw(int dSelectedButton, int scrW, int scrH)
{
    // Draw

    // Labels
    drawLabels(scrW, scrH);

    // Buttons
    drawButtons(dSelectedButton, scrW, scrH);
}

void Scene::addButton(Button *aButton)
{
    // Add button

    // Map
    size_t buttonsSize = button.size();
    buttonId[aButton->name] = buttonsSize;

    // Button
    button.push_back(aButton);
}

void Scene::alignButtonsX(int bY)
{
    // Align buttons width

    for(size_t mButton = 0; mButton < button.size(); mButton++)
    {
        button[mButton]->x = scrDWidth / (button.size()+1) * (mButton+1);
        button[mButton]->y = bY;
    }
}

void Scene::alignButtonsY(int bX)
{
    // Align buttons height

    for(size_t mButton = 0; mButton < button.size(); mButton++)
    {
        button[mButton]->x = bX;
        button[mButton]->y = scrDHeight / (button.size()+1) * (mButton+1);
    }
}

void Scene::drawButtons(int dSelectedButton, int scrW, int scrH)
{
    // Draw buttons

    if(!button.empty())
    {
        // Deselect all
        for(size_t mButton = 0; mButton < button.size(); mButton++)
        {
            button[mButton]->select = false;
        }

        // Select selected
        button[dSelectedButton]->select = true;

        // Draw
        for(size_t mButton = 0; mButton < button.size(); mButton++)
        {
            button[mButton]->draw(scrW, scrH);
        }
    }
}

void Scene::drawLabels(int scrW, int scrH)
{
    // Draw labels

    if(!label.empty())
    {        
        // Draw
        for(auto mLabel: label)
        {
            mLabel->draw(scrW, scrH);
        }

        // Start next if previous finished
        for(size_t mLabel = 0; mLabel < label.size()-1; mLabel++)
        {
            if(label[mLabel]->animationFinished() &&
               !label[mLabel+1]->animationStarted)
            {
                label[mLabel+1]->animationStart();
            }
        }
    }
}
