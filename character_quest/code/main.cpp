#include "main.h"

int main(int argc, char *argv[])
{
#ifdef DEBUG
    // Debugger
    QCoreApplication a(argc, argv);
#endif

    // Init
    initAll();

    // Shake Random
    srand(time(0));

#ifdef WINDOWS
    // Change lang
    PostMessage(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 2, 0);
#endif

    // Set time of out screensaver
    timerScreensaver = timer(5000);

    // Off deleting saves mode
    deleteSave = false;

    // Clear selectedGMap
    selectedSaveSlot = -1;

    // Read save
    loadSaves();

    // Set Scene
    setScene(scene["screensaver"]);

    // Start Game

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
                    if(!selectedScene->getLabel()[1]->getText().empty())
                    {
                        // Backspace
                        string newText = selectedScene->getLabel()[1]->getText();
                        newText.pop_back();

                        selectedScene->getLabel()[1]->setText(newText);
                    }
                }
                else if(keyEnter(keyStroke))
                {
                    // Create save
                    saveSlot[selectedSaveSlot] = new SaveSlot(new GMapWorld(biome["forest"]), selectedScene->getLabel()[1]->getText());
                    saveSlot[selectedSaveSlot]->gMap.setEmptyGMapHome(new GMapHome(biome["home"]));

                    // To game

                    setScene(scene["game"]);
                }
                else
                {
                    // Valid keyChar?
                    if(selectedScene->getLabel()[1]->getFont()->getImage().find(keyChar) !=
                       selectedScene->getLabel()[1]->getFont()->getImage().end())
                    {
                        // Add keyChar
                        string newText = selectedScene->getLabel()[1]->getText();
                        newText.push_back(keyChar);

                        selectedScene->getLabel()[1]->setText(newText);
                    }
                }
            }
        }
    }
    while(true);

    endwin();

    // Delete all

    // GMaps
    SAVE_DEL_MAS(saveSlot);

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
           if(!saveSlot[selectedSaveSlot]->gMap.movePlayerUp()->is_free())
           {
               message.push_back(new PushMessage("You don't move up"));
           }
        }

        // Down
        else if(keyEng('s', keyStroke))
        {
            if(!saveSlot[selectedSaveSlot]->gMap.movePlayerDown()->is_free())
            {
                message.push_back(new PushMessage("You don't move down"));
            }
        }

        // Left
        else if(keyEng('a', keyStroke))
        {
            if(!saveSlot[selectedSaveSlot]->gMap.movePlayerLeft()->is_free())
            {
                message.push_back(new PushMessage("You don't move left"));
            }
        }

        // Right
        else if(keyEng('d', keyStroke))
        {
            if(!saveSlot[selectedSaveSlot]->gMap.movePlayerRight()->is_free())
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
    if(!selectedScene->getButton().empty())
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
            if(selectedButton < selectedScene->getButton().size()-1)
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
    if(!selectedScene->getLabel().empty())
    {
        for(auto mLabel: selectedScene->getLabel())
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

    // Debug texts
#ifdef DEBUG
//    move(1,1);
//    if(selectedGMap != -1)
//    {
//        printw("%c", gMap[selectedGMap]->biome->genCatStatic()->genObj()->type);
//    }
#endif

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
        // Draw
        saveSlot[selectedSaveSlot]->gMap.draw(gMapX, gMapY, gMapWidth, gMapHeight);
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
    if(!sScene->getLabel().empty())
    {
        // Stop all texts animations
        for(auto &mLabel: sScene->getLabel())
        {
            mLabel->animationStop();
        }

        // Start first text animation
        sScene->getLabel()[0]->animationStart();
    }

    // Select button
    selectedButton = 0;

    // Set
    selectedScene = sScene;
}

void drawMessages()
{
    // Messages

    for(size_t mMsg = 0; mMsg < message.size(); mMsg++)
    {
        if(!message[mMsg]->getDeleteTimer().finished())
        {
            move(scrHeight() - 1 - mMsg, 0);
            printw("%s",message[mMsg]->getText().c_str());
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
        if(selectedScene->getButton()[selectedButton]->getName() == "Play")
        {
            setScene(scene["saves"]);
            loadSaves();
        }

        // Continue
        else if(selectedScene->getButton()[selectedButton]->getName() == "Continue")
        {
            if(selectedSaveSlot != -1 &&
                    !saveSlot[selectedSaveSlot]->is_empty())
            {
                // Continue game
                loadSaves();
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
        if(selectedScene->getButton()[selectedButton]->getName() == "Main")
        {
            // To main
            if(saveSlot[selectedSaveSlot]->saved())
            {
                setScene(scene["main"]);
            }
            else
            {
                setScene(scene["gamePauseExit"]);
            }
        }

        // Save
        else if(selectedScene->getButton()[selectedButton]->getName() == "Save")
        {
            saveSaves("save.txt");
        }
    }

    // --------------------------- Exit ---------------------------

    else if(selectedScene == scene["mainExit"])
    {
        // No
        if(selectedScene->getButton()[selectedButton]->getName() == "No")
        {
            setScene(scene["main"]);
        }

        // Yes
        else if(selectedScene->getButton()[selectedButton]->getName() == "Yes")
        {
            exit(EXIT_SUCCESS);
        }
    }

    // --------------------------- Game exit ---------------------------

    else if(selectedScene == scene["gamePauseExit"])
    {
        // Save and exit
        if(selectedScene->getButton()[selectedButton]->getName() == "Save and exit")
        {
            saveSaves("save.txt");
            setScene(scene["main"]);
        }

        // Exit unsaved
        else if(selectedScene->getButton()[selectedButton]->getName() == "Exit unsaved")
        {
            setScene(scene["main"]);
        }
    }

    // --------------------------- Maps ---------------------------

    else if(selectedScene == scene["saves"])
    {
        if(selectedScene->getButton()[selectedButton]->getName() == "Delete" ||
                selectedScene->getButton()[selectedButton]->getName() == "Cancel")
        {
            // To delete/load save
            deleteSave = !deleteSave;

            // Rename button

            // New button
            Button* newButton =  selectedScene->getButton()[selectedButton];

            if(deleteSave)
            {
                // Set name "Cancel"
                newButton->setName("Cancel");
            }
            else
            {
                // Set name "Delete"
                newButton->setName("Cancel");
            }

            // Set
            selectedScene->setButton(selectedButton, newButton);
        }
        else
        {
            // Select GMap
            selectedSaveSlot = selectedButton;

            if(!saveSlot[selectedButton]->is_empty())
            {
                if(deleteSave)
                {
                    // Delete
                    saveSlot[selectedButton] = new SaveSlot(new GMapWorld(biome["forest"], new GMapHome(biome["home"])));

                    // Message
                    message.push_back(new PushMessage("Deleted"));

                    // Button Cancel
                    selectedButton = selectedScene->getButtonId()["Delete"];
                    buttonClick();

                    // Update saves/buttons
                    saveSaves();
                    loadSaves();
                }
                else
                {
                    // To game
                    setScene(scene["game"]);
                    saveSlot[selectedSaveSlot]->gMap.setSaved(true);
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

                    // Clear label
                    Label *newLabel = scene["savesNew"]->getLabel()[1];
                    newLabel->setText(string());

                    scene["savesNew"]->setLabel(1, newLabel);

                    // Set scene
                    setScene(scene["savesNew"]);
                }
            }
        }
    }
}

void saveSaves(string sFileName)
{
    // Save

    ofstream file(sFileName.c_str());

    // Old selected gMap
    file<<"oldSaveSlot "<<selectedSaveSlot<<endl;

    // GMaps
    for(int mSave = 0; mSave < saveSlotNum; mSave++)
    {
        // SaveSlot number
        file<<"saveSlot "<<mSave<<endl;

            // Player name
            file<<" playerName "<<saveSlot[mSave]->playerName<<endl;

            file<<" gMapWorld"<<endl;

                // Biome name
                for(auto &mBiome: biome)
                {
                    if(saveSlot[mSave]->gMap.getBiome() == mBiome.second)
                    {
                        file<<"  biome "<<mBiome.first<<endl;
                        break;
                    }
                }

                // Player coords
                file<<"  player"<<endl;

                    file<<"   x "<<saveSlot[mSave]->gMap.getPlayerX()<<endl;
                    file<<"   y "<<saveSlot[mSave]->gMap.getPlayerY()<<endl;

                file<<"  /player"<<endl;

                // GMap slots
                for(auto mX: saveSlot[mSave]->gMap.getSlot())
                {
                    for(auto mY: mX.second)
                    {
                        file<<"  gMapSlot"<<endl;

                            file<<"   x "<<mX.first<<endl;
                            file<<"   y "<<mY.first<<endl;

                            file<<"   sType "<<mY.second->getStaticType()<<endl;
                            file<<"   dType "<<mY.second->getDynamicType()<<endl;

                        file<<"  /gMapSlot"<<endl;
                    }
                }

                // Home
                for(auto mHomeX: saveSlot[mSave]->gMap.getGMapHome())
                {
                    for(auto mHomeY: mHomeX.second)
                    {
                        file<<"  gMapHome"<<endl;

                            // Biome name
                            for(auto &mBiome: biome)
                            {
                                if(mHomeY.second->getBiome() == mBiome.second)
                                {
                                    file<<"  biome "<<mBiome.first<<endl;
                                    break;
                                }
                            }

                            // Coords
                            file<<"   x "<<mHomeX.first<<endl;
                            file<<"   y "<<mHomeY.first<<endl;

                            // Wall type
                            file<<"   wallType "<<mHomeY.second->getWallType().getDynamicType();

                            // Slots
                            for(auto mX: mHomeY.second->getSlot())
                            {
                                for(auto mY: mX.second)
                                {
                                    file<<"   gMapSlot"<<endl;

                                        file<<"    x "<<mX.first<<endl;
                                        file<<"    y "<<mY.first<<endl;

                                        file<<"    sType "<<mY.second->getStaticType()<<endl;
                                        file<<"    dType "<<mY.second->getDynamicType()<<endl;

                                    file<<"   /gMapSlot"<<endl;
                                }
                            }

                        file<<"  /gMapHome"<<endl;
                    }
                }

            file<<" /gMapWorld"<<endl;

        file<<"/saveSlot"<<endl;

        // Saved bool
        saveSlot[mSave]->gMap.setSaved(true);
    }

    file.close();

    // Message
    message.push_back(new PushMessage("Saved"));
}

void loadSaves(string rFileName)
{
    // Read Saves

    ifstream file(rFileName.c_str());

    if(file.is_open())
    {
        // Command
        string command;

        while(!file.fail())
        {
            // Get command
            file>>command;

            // Old SaveSlot Num
            if(command == "oldSaveSlot")
            {
                // Select old save
                file>>selectedSaveSlot;
            }

            // SaveSlot

            if(command == "saveSlot")
            {
                // Clear
                SaveSlot* rSaveSlot = new SaveSlot(new GMapWorld(biome["forest"], new GMapHome(biome["home"])));
                int rSaveSlotNum = 0;

                // Read num
                file>>rSaveSlotNum;

                // Read
                do
                {
                    file>>command;

                    // Player Name
                    if(command == "playerName")
                    {
                        // Set player name
                        file>>rSaveSlot->playerName;
                    }

                    // GMapWorld

                    else if(command == "gMapWorld")
                    {
                        // Clear
                        GMapWorld rGMapWorld = GMapWorld();

                        do
                        {
                            file>>command;

                            // Biome name
                            if(command == "biome")
                            {
                                string biomeName;
                                file>>biomeName;

                                rGMapWorld.setBiome(biome[biomeName]);
                            }

                            // Game Home

                            if(command == "gHome")
                            {
                                // Clear
                                GMapHome *rGMapHome = new GMapHome();
                                int rGMapHomeX;
                                bool rGMapHomeXB = false;
                                int rGMapHomeY;
                                bool rGMapHomeYB = false;

                                // Read
                                do
                                {
                                    file>>command;

                                    // Biome
                                    if(command == "biome")
                                    {
                                        string biomeName;
                                        file>>biomeName;

                                        rGMapHome->setBiome(biome[biomeName]);
                                    }

                                    // X
                                    else if(command == "x")
                                    {
                                        file>>rGMapHomeX;
                                        rGMapHomeXB = true;
                                    }

                                    // Y
                                    else if(command == "y")
                                    {
                                        file>>rGMapHomeY;
                                        rGMapHomeYB = true;
                                    }

                                    // Wall type
                                    else if(command == "wallType")
                                    {
                                        chtype wallType_;
                                        file>>wallType_;
                                        rGMapHome->setWallType(GMapSlot(' ', wallType_));
                                    }

                                    // Slot

                                    else if(command == "gMapSlot")
                                    {
                                        // Clear
                                        GMapSlot *rGMapSlot = new GMapSlot();
                                        int rGMapSlotX;
                                        bool rGMapSlotXB = false;
                                        int rGMapSlotY;
                                        bool rGMapSlotYB = false;

                                        // Read
                                        do
                                        {
                                            file>>command;

                                            // X
                                            if(command == "x")
                                            {
                                                file>>rGMapSlotX;
                                                rGMapSlotXB = true;
                                            }

                                            // Y
                                            else if(command == "Y")
                                            {
                                                file>>rGMapSlotY;
                                                rGMapSlotYB = true;
                                            }

                                            // Static type
                                            else if(command == "sType")
                                            {
                                                chtype staticType_;
                                                file>>staticType_;
                                                rGMapSlot->setStaticType(staticType_);
                                            }

                                            // Dynamic type
                                            else if(command == "dType")
                                            {
                                                chtype dynamicType_;
                                                file>>dynamicType_;
                                                rGMapSlot->setDynamicType(dynamicType_);
                                            }

                                        } while(command != "/gMapSlot");

                                        // X and Y initialized?
                                        assert(rGMapSlotXB && rGMapSlotYB && ("X or Y in gMapSlot uninitialized" || true));

                                        // Set
                                        rGMapHome->setSlot(rGMapSlotX, rGMapSlotY, rGMapSlot);
                                    }

                                } while(command != "/gHome");

                                // X and Y initialized?
                                assert(rGMapHomeXB && rGMapHomeYB && ("X or Y in GMapHome uninitialized" || true));

                                // Set
                                rGMapWorld.setGMapHomeY(rGMapHomeX, rGMapHomeY, rGMapHome);
                            }

                            // Player

                            else if(command == "player")
                            {
                                // Clear
                                bool rGMapWorldPlayerXB = false;
                                bool rGMapWorldPlayerYB = false;

                                // Read
                                do
                                {
                                    file>>command;

                                    // X
                                    if(command == "x")
                                    {
                                        int x_;
                                        file>>x_;
                                        rGMapWorld.setPlayerX(x_);
                                        rGMapWorldPlayerXB = true;
                                    }

                                    // Y
                                    else if(command == "y")
                                    {
                                        int y_;
                                        file>>y_;
                                        rGMapWorld.setPlayerY(y_);
                                        rGMapWorldPlayerYB = true;
                                    }

                                } while(command != "/player");

                                // X and Y initialized?
                                assert(rGMapWorldPlayerXB && rGMapWorldPlayerYB && ("X or Y in GMapWorld in player uninitialized" || true));
                            }

                            // Slot

                            else if(command == "gMapSlot")
                            {
                                // Clear
                                GMapSlot *rGMapSlot = new GMapSlot();
                                int rGMapSlotX;
                                bool rGMapSlotXB = false;
                                int rGMapSlotY;
                                bool rGMapSlotYB = false;

                                // Read
                                do
                                {
                                    file>>command;

                                    // X
                                    if(command == "x")
                                    {
                                        file>>rGMapSlotX;
                                        rGMapSlotXB = true;
                                    }

                                    // Y
                                    else if(command == "y")
                                    {
                                        file>>rGMapSlotY;
                                        rGMapSlotYB = true;
                                    }

                                    // Static type
                                    else if(command == "sType")
                                    {
                                        chtype staticType_;
                                        file>>staticType_;
                                        rGMapSlot->setStaticType(staticType_);
                                    }

                                    // Dynamic type
                                    else if(command == "dType")
                                    {
                                        chtype dynamicType_;
                                        file>>dynamicType_;
                                        rGMapSlot->setDynamicType(dynamicType_);
                                    }

                                } while(command != "/gMapSlot");

                                // X and Y initialized?
                                assert(rGMapSlotXB && rGMapSlotYB && ("X or Y uninitialized" || true));

                                // Set
                                rGMapWorld.setSlot(rGMapSlotX, rGMapSlotY, rGMapSlot);
                            }

                        } while(command != "/gMapWorld");

                        // Set
                        rSaveSlot->gMap = rGMapWorld;
                    }

                } while(command != "/saveSlot");

                // Set

                // SaveSlot
                saveSlot[rSaveSlotNum] = rSaveSlot;

                // Rename Button

                // New Button
                Button* newButton = scene["saves"]->getButton()[rSaveSlotNum];

                // Edit
                newButton->setName(rSaveSlot->playerName);

                // Set
                scene["saves"]->setButton(rSaveSlotNum, newButton);
            }
        }
    }

    file.close();
}

void initAll()
{
    // --------------------------- Init All ---------------------------

    // Init screen
    initscr();

    // Get keyboard control
    raw();

    // Active all keys
    keypad(stdscr, TRUE);

    // Off cursor
    curs_set(0);

    // Off echos
    noecho();

    // No delay getch
    nodelay(stdscr, TRUE);

    // Colors
    start_color();

    // Character pairs
    initCharPairs();

    // Scenes
    initScenes();

    // Biomes
    initBiomes();

    // GMaps
    for(auto &mSave: saveSlot)
    {
        mSave = new SaveSlot(new GMapWorld(biome["forest"], new GMapHome(biome["home"])));
    }
}
