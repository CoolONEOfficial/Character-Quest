#include "main.h"

int main()//int argc, char *argv[])
{
    // Init screen
    initscr();

    // ?
    raw();

    // Active all keys
    keypad(stdscr, TRUE);

    // Off cursor
    curs_set(0);

    // Off echos
    noecho();

    // Init colors
    start_color();

    // Set pairs
    initCharPairs();

    // No delay getch
    nodelay(stdscr, TRUE);

    // Shake Random
    srand(time(0));

    // --------------------------- Set Default Vals ---------------------------

    setScenes();

    // Set time of out screensaver
    timerScreensaver = timer(5000);

    // Init GMaps
    for(int mGMap = 0; mGMap < 4; mGMap++)
    {
        gMap[mGMap] = new GMap();
    }

    // Off deleting saves mode
    deleteSave = false;

    // Clear selectedGMap
    selectedGMap = -1;

    // Add Map Objects

    // Dynamic

    // Luck
    gMapObjectDynamicLuck = 10.0;

    // Create
    gMapCategoriesDynamic["home"] = new GMapCategory(0.25);
    gMapCategoriesDynamic["nature"] = new GMapCategory(100.0);

    // Set

    // Dynamic

    gMapCategoriesDynamic["home"]->addObject(new GMapObject('H', 100, COLOR_YELLOW), "home");

    gMapCategoriesDynamic["nature"]->addObject(new GMapObject('P', 100, COLOR_GREEN), "tree");

    // Static

    gMapCategoriesStatic["nature"] = new GMapCategory(100.0);

    gMapCategoriesStatic["nature"]->addObject(new GMapObject('m', 90, COLOR_GREEN), "grass");
    gMapCategoriesStatic["nature"]->addObject(new GMapObject('v', 10, COLOR_CYAN), "flower");

    // Read save
    readSaves();

    // Start Game

    // Set Scene
    setScene(scene["screensaver"]);

    cpu = clock();
    do
    {
        // Enum CPU
        cpu = clock() - cpu;

        if(selectedScene == scene["screensaver"])
        {
            if(clock() > timerScreensaver)
            {
                setScene(scene["main"]);
            }
        }

        // Set old Width / Height
        scrOldWidth = scrWidth();
        scrOldHeight = scrHeight();

        // Draw
        update();

        // Set CPU
        cpu = clock();

        // Get char
        keyStroke = getch();
        keyChar = char(keyStroke);

        // Keys Commands
        if(selectedScene != scene["savesNew"])
        {
            keysCommand(keyStroke);
        }
        else
        {
            if(keyStroke != -1)
            {
                if(keyBackspace(keyStroke))
                {
                    if(!selectedScene->label[1]->text.empty())
                    {
                        // Backspace
                        selectedScene->label[1]->text.pop_back();
                    }
                }
                else if(keyEnter(keyStroke))
                {
                    // Create save
                    gMap[selectedGMap] = new GMap(selectedScene->label[1]->text);

                    // To game
                    setScene(scene["game"]);
                }
                else
                {
                    // Valid keyChar?
                    if(selectedScene->label[1]->font->image.find(keyChar) !=
                       selectedScene->label[1]->font->image.end())
                    {
                        // Add keyChar
                        selectedScene->label[1]->text.push_back(keyChar);
                    }
                }
            }
        }
    }
    while(true);

    endwin();

    // Delete all

    // Cats
    SAVE_DEL_MAP(gMapCategoriesStatic);
    SAVE_DEL_MAP(gMapCategoriesDynamic);

    // GMaps
    SAVE_DEL_MAS(gMap);

    // Messages
    SAVE_DEL_MAS(message);

    return 0;
}

void keysCommand(int keyStroke)
{
    // --------------------------- Keys Command ---------------------------

    // Game
    if(selectedScene == scene["game"])
    {
        // Up
        if(keyEng('w', keyStroke))
        {
           if(!gMap[selectedGMap]->movePlayer("up"))
           {
               message.push_back(new PushMessage("You don't move up"));
           }
        }

        // Down
        else if(keyEng('s', keyStroke))
        {
            if(!gMap[selectedGMap]->movePlayer("down"))
            {
                message.push_back(new PushMessage("You don't move down"));
            }
        }

        // Left
        else if(keyEng('a', keyStroke))
        {
            if(!gMap[selectedGMap]->movePlayer("left"))
            {
                message.push_back(new PushMessage("You don't move left"));
            }
        }

        // Right
        else if(keyEng('d', keyStroke))
        {
            if(!gMap[selectedGMap]->movePlayer("right"))
            {
                message.push_back(new PushMessage("You don't move right"));
            }
        }

        // Pause
        else if(keyEsc(keyStroke))
        {
            setScene(scene["gamePause"]);
        }
    }

    // Main
    else if(selectedScene == scene["main"])
    {
        // Escape
        if(keyEsc(keyStroke))
        {
            setScene(scene["mainExit"]);
        }
    }

    // Main
    else if(selectedScene == scene["gamePause"])
    {
        // Escape
        if(keyEsc(keyStroke))
        {
            setScene(scene["game"]);
        }
    }

    // Main
    else if(selectedScene == scene["gameExit"])
    {
        // Escape
        if(keyEsc(keyStroke))
        {
            setScene(scene["pause"]);
        }
    }

    // Saves
    else if(selectedScene == scene["saves"])
    {
        // Escape
        if(keyEsc(keyStroke))
        {
            setScene(scene["main"]);
        }
    }

    // Saves
    else if(selectedScene == scene["exit"])
    {
        // Escape
        if(keyEsc(keyStroke))
        {
            setScene(scene["main"]);
        }
    }

    // Buttons
    if(!selectedScene->button.empty())
    {
        // Select left button
        if(keyEng('a', keyStroke))
        {
            if(selectedButton > 0)
            {
                selectedButton--;
            }
        }

        // Select right button
        else if(keyEng('d',  keyStroke))
        {
            if(selectedButton < selectedScene->button.size()-1)
            {
                selectedButton++;
            }
        }

        // Click select button
        else if(keyEnter(keyStroke))
        {
            buttonClick();
        }
    }
}

void update()
{
    // Tact animations texts
    if(!selectedScene->label.empty())
    {
        for(auto mLabel: selectedScene->label)
        {
            mLabel->animationTact();
        }
    }

    // Clear screen
    cls();

    // Draw

    // Scene
    drawScene();

    // Messages
    drawMessages();

//    // Debug texts
//    move(0,5);
//    printw("w:%f h:%f", scrWidth(), scrHeight());
//    move(1,5);
//    printw("selectedGMap: %i", selectedGMap);
//    move(2,5);
//    if(selectedGMap != -1)
//    {
//        printw("pX:%i pY:%i pName:%s",
//               gMap[selectedGMap]->playerX,
//               gMap[selectedGMap]->playerY,
//               gMap[selectedGMap]->playerName.c_str());
//    }
//    move(4,5);
//    printw("animText:%s", scene["savesNew"]->label[1]->text.c_str());

    refresh();
}

void cls(int x, int y, int w, int h)
{
    // Clear screen

    for(int mY = y; mY < y + h; mY++)
    {
        for(int mX = x; mX < x + w; mX++)
        {
            move(mY, mX);
            printw(" ");
        }
    }
}

void drawScene(Scene *dScene)
{
    // Draw Scene

    // Main

    if(dScene == scene["main"])
    {

    }

    // Main Exit

    else if(dScene == scene["mainExit"])
    {

    }

    // Saves

    else if(dScene == scene["saves"])
    {

    }

    // First game

    else if(dScene == scene["savesNew"])
    {

    }

    // Game

    else if(dScene == scene["game"])
    {
        // Generate GMap
        generateViewMap(gMap[selectedGMap]);

        // Draw
        gMap[selectedGMap]->draw(indentX, indentY, viewWidth, viewHeight);
    }

    // Pause

    else if(dScene == scene["gamePause"])
    {
        // Draw game (background)
        drawScene(scene["game"]);

        // Label "Pause"
        cls(0, 0, scrWidth(), scrHeight() / 3.0);
        cls(0, scrHeight() / 3.0 * 2.0, scrWidth(), scrHeight());
    }

    // Exit Pause

    else if(dScene == scene["gamePauseExit"])
    {
        drawScene(scene["gamePause"]);
    }

    // Draw other scene
    if(dScene == selectedScene)
    {
        dScene->draw(selectedButton);
    }
}

void initCharPairs()
{
    // Set pairs
    for(int mPair = 1; mPair <= COLORS; mPair++)
    {
        init_pair(mPair, mPair, COLOR_BLACK);
    }
}

void setScene(Scene *sScene)
{
    // Text animation
    if(!sScene->label.empty())
    {
        // Stop all texts animations
        for(auto &mLabel: sScene->label)
        {
            mLabel->animationStop();
        }

        // Start first text animation
        sScene->label[0]->animationStart();
    }

    // Select button
    selectedButton = 0;

    // Set
    selectedScene = sScene;
}

GMapCategory *generateCategory(map <string, GMapCategory *> gMapCategories)
{
    // Generate category

    GMapCategory *gCategory = new GMapCategory();

    // Set real luck
    setGMapCategoriesRealLuck(gMapCategories);

    float random = randf(100);

    // Select category

    float saveLuck = 0;
    for(auto mCat: gMapCategories)
    {
        if(random > saveLuck &&
                random < saveLuck + mCat.second->realLuck)
        {
            // Return category
            gCategory = mCat.second;
            break;
        }
        else
        {
            // Next category
            saveLuck += mCat.second->realLuck;
        }
    }

    return gCategory;
}

GMapSlot *generateSlot()
{
    // Generate slot

    GMapSlot *randSlot = new GMapSlot();

    // Set dynamic
    if(luck(gMapObjectDynamicLuck))
    {
        randSlot->dynamicType = generateCategoryDynamic()->generateObject()->type;
    }

    // Set static
    randSlot->staticType = generateCategoryStatic()->generateObject()->type;

    return randSlot;
}

void setGMapCategoriesRealLuck(map <string, GMapCategory *> &sMapCategories)
{
    // Set categories realLuck
    for(auto &mCat: sMapCategories)
    {
        mCat.second->setRealLuck(allGMapCategoriesLuck(sMapCategories));
    }
}

float allGMapCategoriesLuck(map <string, GMapCategory *> gMapCategories)
{
    // All categories dynamic luck
    float allLuck = 0;
    for(auto mCat: gMapCategories)
    {
        allLuck += mCat.second->luck;
    }

    return allLuck;
}

GMapCategory *generateCategoryStatic()
{
    // Generate static category
    return generateCategory(gMapCategoriesStatic);
}

GMapCategory *generateCategoryDynamic()
{
    // Generate dynamic category
    return generateCategory(gMapCategoriesDynamic);
}

void drawMessages()
{
    // Messages

    for(size_t mMsg = 0; mMsg < message.size(); mMsg++)
    {
        if(!message[mMsg]->deleteTimer->finished())
        {
            move(scrHeight() - 1 - mMsg, 0);
            printw("%s",message[mMsg]->text.c_str());
        }
        else
        {
            message.pop_back();
        }
    }
}

void buttonClick()
{
    // Button click

    // --------------------------- Main ---------------------------

    if(selectedScene == scene["main"])
    {
        // Play
        if(selectedScene->button[selectedButton]->name == "Play")
        {
            setScene(scene["saves"]);
            readSaves();
        }

        // Continue
        else if(selectedScene->button[selectedButton]->name == "Continue")
        {
            if(selectedGMap != -1 &&
                    !gMap[selectedGMap]->empty())
            {
                // Continue game
                readSaves();
                setScene(scene["game"]);
            }
            else
            {
                message.push_back(new PushMessage("No saves!"));
            }
        }
    }

    // --------------------------- Pause ---------------------------

    else if(selectedScene == scene["gamePause"])
    {
        // Exit to main
        if(selectedScene->button[selectedButton]->name == "Main")
        {
            // To main
            if(gMap[selectedGMap]->saved)
            {
                setScene(scene["main"]);
            }
            else
            {
                setScene(scene["gamePauseExit"]);
            }
        }

        // Save
        else if(selectedScene->button[selectedButton]->name == "Save")
        {
            saveSaves("save.txt");
        }
    }

    // --------------------------- Exit ---------------------------

    else if(selectedScene == scene["mainExit"])
    {
        // No
        if(selectedScene->button[selectedButton]->name == "No")
        {
            setScene(scene["main"]);
        }

        // Yes
        else if(selectedScene->button[selectedButton]->name == "Yes")
        {
            exit(0);
        }
    }

    // --------------------------- Game exit ---------------------------

    else if(selectedScene == scene["gamePauseExit"])
    {
        // Save and exit
        if(selectedScene->button[selectedButton]->name == "Save and exit")
        {
            saveSaves("save.txt");
            setScene(scene["main"]);
        }

        // Exit unsaved
        else if(selectedScene->button[selectedButton]->name == "Exit unsaved")
        {
            setScene(scene["main"]);
        }
    }

    // --------------------------- Maps ---------------------------

    else if(selectedScene == scene["saves"])
    {
        if(selectedScene->button[selectedButton]->name == "Delete" ||
                selectedScene->button[selectedButton]->name == "Cancel")
        {
            // To delete/load save
            deleteSave = !deleteSave;

            if(deleteSave)
            {
                // Set this button name "Cancel"
                selectedScene->button[selectedButton]->name = "Cancel";
            }
            else
            {
                // Set this button name "Delete"
                selectedScene->button[selectedButton]->name = "Delete";
            }
        }
        else
        {
            // Select GMap
            selectedGMap = selectedButton;

            if(!gMap[selectedButton]->empty())
            {
                if(deleteSave)
                {
                    // Delete
                    gMap[selectedButton]->clear();

                    // Message
                    message.push_back(new PushMessage("Deleted"));

                    // Button Cancel
                    selectedButton = selectedScene->buttonId["Delete"];
                    buttonClick();

                    // Update saves/buttons
                    saveSaves();
                    readSaves();
                }
                else
                {
                    // To game
                    setScene(scene["game"]);
                }
            }
            else
            {
                if(deleteSave)
                {
                    // Message "This is empty slot"
                    message.push_back(new PushMessage("This is empty slot"));
                }
                else
                {
                    // First game
                    scene["savesNew"]->label[1]->text.clear();
                    setScene(scene["savesNew"]);
                }
            }
        }
    }
}

void generateViewMap(GMap *gGMap)
{
    // Generate view map

    for(int mX = gGMap->cameraX(alignW(viewWidth)); mX < gGMap->cameraX(alignW(viewWidth)) + alignW(viewWidth); mX++)
    {
        for(int mY = gGMap->cameraY(alignH(viewHeight)); mY < gGMap->cameraY(alignH(viewHeight)) + alignH(viewHeight); mY++)
        {
            if(gGMap->slot.find(mX) == gGMap->slot.end() ||
               gGMap->slot[mX].find(mY) == gGMap->slot[mX].end())
            {
                // Generate
                gGMap->slot[mX][mY] = generateSlot();
            }
        }
    }
}

void saveSaves(string sFileName)
{
    // Save

    ofstream file(sFileName.c_str());

    // Old selected gMap
    file<<"oldGMap "<<selectedGMap<<endl;

    // GMaps
    for(int mGMap = 0; mGMap < 4; mGMap++)
    {
        file<<"gMap "<<mGMap<<endl;

        // Player coords
        file<<" player"<<endl;
        file<<"  name "<<gMap[mGMap]->playerName<<endl;
        file<<"  x "<<gMap[mGMap]->playerX<<endl;
        file<<"  y "<<gMap[mGMap]->playerY<<endl;
        file<<" /player"<<endl;

        // GMap
        for(auto& f1: gMap[mGMap]->slot)
        {
            for(auto& f2: f1.second)
            {
                file<<" slot"<<endl;

                file<<"  x "<<f1.first<<endl;
                file<<"  y "<<f2.first<<endl;

                file<<"  sType "<<f2.second->staticType<<endl;
                file<<"  dType "<<f2.second->dynamicType<<endl;

                file<<" /slot"<<endl;
            }
        }

        file<<"/gMap"<<endl;

        gMap[mGMap]->saved = true;
    }

    file.close();

    message.push_back(new PushMessage("Saved"));
}

void readSaves(string rFileName)
{
    // Read Saves

    ifstream file(rFileName.c_str());

    bool rGMapB = false;
    GMap *rGMap = new GMap;
    int rGMapNum = 0;
    bool rPlayerB = false;
    bool rSlotB = false;
    GMapSlot *rSlot = new GMapSlot;
    int rSlotX;
    int rSlotY;

    if(file.is_open())
    {
        while(!file.fail())
        {
            // Get command
            string command;
            file>>command;

            // SaveSlot

            if(command == "gMap")
            {
                rGMapB = true;
                rGMap = new GMap;

                // Num
                int num;
                file>>num;

                rGMapNum = num;
            }

            else if(command == "/gMap")
            {
                rGMapB = false;
                gMap[rGMapNum] = rGMap;

                // Set button name
                scene["saves"]->button[rGMapNum]->name = rGMap->playerName;
            }

            // Old GMap
            else if(command == "oldGMap")
            {
                int oldGMap;
                file>>oldGMap;

                // Select old GMap
                selectedGMap = oldGMap;
            }

            // SaveSlot commands

            if(rGMapB)
            {
                // Player

                if(command == "player")
                {
                    rPlayerB = true;
                }

                else if( command == "/player")
                {
                    rPlayerB = false;
                }

                // Player commands

                if(rPlayerB)
                {
                    if(command == "name")
                    {
                        string pName;
                        file>>pName;

                        rGMap->playerName = pName;
                    }

                    // X
                    else if(command == "x")
                    {
                        int pX;
                        file>>pX;

                        rGMap->playerX = pX;
                    }

                    // Y
                    else if(command == "y")
                    {
                        int pY;
                        file>>pY;

                        rGMap->playerY = pY;
                    }
                }

                // Slot

                if(command == "slot")
                {
                    rSlotB = true;
                    rSlot = new GMapSlot();
                }

                else if(command == "/slot")
                {
                    rSlotB = false;
                    rGMap->slot[rSlotX][rSlotY] = rSlot;
                }

                // Slot commands

                if(rSlotB)
                {
                    // X
                    if(command == "x")
                    {
                        int sX;
                        file>>sX;

                        rSlotX = sX;
                    }

                    // Y
                    else if(command == "y")
                    {
                        int sY;
                        file>>sY;

                        rSlotY = sY;
                    }

                    // Static type
                    else if(command == "sType")
                    {
                        chtype sSType;
                        file>>sSType;

                        rSlot->staticType = sSType;
                    }

                    // Dynamic type
                    else if(command == "dType")
                    {
                        chtype sDType;
                        file>>sDType;

                        rSlot->dynamicType = sDType;
                    }
                }
            }
        }
    }

    file.close();
}
