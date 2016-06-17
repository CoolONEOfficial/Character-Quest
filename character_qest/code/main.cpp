// --------------------------- Headers ---------------------------

#include "slot.h"
#include "button.h"
#include "writecoords.h"

// --------------------------- Includes ---------------------------

#include <conio.h>
#include <stdio.h>
#include <map>
#include <windows.h>
#include <vector>

// --------------------------- Defines ---------------------------

#define WIDTH 80
#define HEIGHT 25

#define UP_ARROW 119
#define LEFT_ARROW 97
#define DOWN_ARROW 115
#define RIGHT_ARROW 100
#define ENTER 13
#define ESCAPE 27
#define SPACE 32

using namespace std;

// --------------------------- Values ---------------------------

// Player Coords
COORD player;

const int indentX = 0,
          indentY = 0;

// View size
const int viewWidth = WIDTH,
          viewHeight = HEIGHT;

// Command
string writeCommand;

// Scene
int scene;

// Maps

    // Scenes
    map <string, int> scenes;

    // Dirs
    map <string, int> directions;

    // Buttons
    map <string, int> buttons;

// X of frame in game
int gameFrameX();

// Selected button
int selectedButton;

// GameMap
Slot gameMap[viewWidth][viewHeight];

// Buttons
vector < vector <Button> > button;

// Log
string help[viewHeight];

// --------------------------- Voids ---------------------------

void command(string command);
void keysCommand(int keyStroke);
void setScene(int nScene);
void drawScene();
void drawPlayer();
void drawMap();
void drawHelp();
void drawFrame();
void drawButton(Button dButton);
void drawSlot(Slot dSlot, int dX, int dY);
void movePlayer(int direction);
void getCommand();
void pushLog(string message);
void addButton(int bScene, Button nButton);
void clear(int x1, int y1, int x2, int y2);

int main(int argc, char** argv)
{
    // Set english
    PostMessage(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 2, 0);

    // --------------------------- Maps ---------------------------

    // Scenes
    scenes["main"] = 0;
    scenes["game"] = 1;

    // Dirs
    directions["up"] = 0;
    directions["down"] = 1;
    directions["left"] = 2;
    directions["right"] = 3;

    // --------------------------- Set default values ---------------------------

    // Set console dekryptor
    setDekryptor();

    // Clear log
    for(int f = 0; f<viewHeight; f++)
    {
        help[f] = "";
    }

    // Scene
    setScene(scenes["main"]);

    // Select first button
    selectedButton = 0;

    // Add wall
    gameMap[1][2].symbol = '|';
    gameMap[1][2].solid = true;

    gameMap[1][3].symbol = '|';
    gameMap[1][3].solid = true;

    gameMap[2][1].symbol = '-';
    gameMap[2][1].solid = true;

    // Player Coords
    player.X = viewWidth / 2;
    player.Y = viewHeight / 2;

    // Add branches buttons

    for(int f = 0; f<scenes.size(); f++)
    {
        vector <Button> pushVector;
        button.push_back(pushVector);
    }

    addButton(scenes["main"], Button("Play", 1, HEIGHT - 4));
    addButton(scenes["main"], Button("Exit", WIDTH - 7, HEIGHT - 4));

    // --------------------------- Game ---------------------------

    do
    {
        // --------------------------- Draw ---------------------------

        // Draw buttons
        if(button[scene].size() > 0)
        {
            for(int f = 0; f<button[scene].size(); f++)
            {
                button[scene][f].select = false;
            }

            button[scene][selectedButton].select = true;

            for(int f = 0; f<button[scene].size(); f++)
            {
                drawButton(button[scene][f]);
            }
        }

        // --------------------------- Commands ---------------------------

        // Read
        int keyStroke = getch();

        // Do
        keysCommand(keyStroke);
    }
    while(true);

    return 0;
}

void command(string command)
{
    // --------------------------- Commands ---------------------------

    // --------------------------- General ---------------------------

    // Exit applicaton
    if(command == "exit")
    {
        // Exit
        exit(0);
    }

    // Go to scene
    else if(command == "goto")
    {
        // Read scene
        string gotostr;
        cin>>gotostr;

        // Set scene
        setScene( scenes[gotostr] );

        // Add log message
        pushLog("You go to "+gotostr);
    }

    // --------------------------- Game ---------------------------

    if(scene == scenes["game"])
    {
        // Moves

        // Left
        if(command == "left" ||
           command == "a")
        {
            movePlayer(directions["left"]);

            // Add log message
            pushLog("You move left");
        }

        // Right
        else if(command == "right" ||
                command == "d")
        {
            movePlayer(directions["right"]);

            // Add log message
            pushLog("You move right");
        }

        // Up
        else if(command == "up" ||
                command == "w")
        {
            movePlayer(directions["up"]);

            // Add log message
            pushLog("You move up");
        }

        // Down
        else if(command == "down" ||
                command == "s")
        {
            movePlayer(directions["down"]);

            // Add log message
            pushLog("You move down");
        }
    }

    clear(gameFrameX() + indentX, 0, 80, viewHeight);
}

void keysCommand(int keyStroke)
{
    // --------------------------- Keys Command ---------------------------

    // Game
    if(scene == scenes["game"])
    {
        // Up
        if(keyStroke == UP_ARROW)
        {
            command("up");
        }

        // Down
        else if(keyStroke == DOWN_ARROW)
        {
            command("down");
        }

        // Left
        else if(keyStroke == LEFT_ARROW)
        {
            command("left");
        }

        // Right
        else if(keyStroke == RIGHT_ARROW)
        {
            command("right");
        }

        // Go to main
        else if(keyStroke == ESCAPE)
        {
            setScene(scenes["main"]);
        }
    }

    // Main
    else if(scene == scenes["main"])
    {
        // Select left button
        if(keyStroke == LEFT_ARROW)
        {
            if(selectedButton > 0)
            {
                selectedButton--;
            }
        }

        // Select right button
        else if(keyStroke == RIGHT_ARROW)
        {
            if(selectedButton < button[scene].size()-1)
            {
                selectedButton++;
            }
        }

        // Click select button
        else if(keyStroke == SPACE)
        {
            for(int f = 0; f<button[scene].size(); f++)
            {
                if(button[scene][f].select)
                {
                    // Play
                    if(button[scene][f].name == "Play")
                    {
                        setScene(scenes["game"]);
                    }

                    // Exit
                    else if(button[scene][f].name == "Exit")
                    {
                        exit(0);
                    }
                }
            }
        }

        // Escape
        else if(keyStroke == ESCAPE)
        {
            command("exit");
        }
    }

    // Get Command
    if(keyStroke == ENTER)
    {
        getCommand();
    }
}

void setScene(int nScene)
{
    scene = nScene;
    system("cls");
    drawScene();
}

int gameFrameX()
{
    return viewWidth + indentX*2;
}

void getCommand()
{
    // Get command

    // Create
    string readCommand;

    // Draw label

    // Game
    if(scene == scenes["game"])
    {
        setCursorPosition(0, HEIGHT-1);
    }

    // Main
    else if(scene == scenes["main"])
    {
        setCursorPosition(0, HEIGHT-1);
    }
    cout<<"Command: ";

    // Get
    cin>>readCommand;

    // Do
    command(readCommand);
}

void drawScene()
{
    // Draw

    // Game
    if(scene == scenes["game"])
    {
        drawMap();
    }

    else if(scene == scenes["main"])
    {
//		cout<<"main";
    }
}

void drawPlayer()
{
    // Draw player
    write('i', player.X + indentX, player.Y + indentY);
}

void drawMap()
{
    // Draw map
    for(int moveX = 0; moveX < viewWidth; moveX++)
    {
        for(int moveY = 0; moveY < viewHeight; moveY++)
        {
            drawSlot(gameMap[moveX][moveY], moveX + indentX, moveY + indentY);
        }
    }

    // Go to start
    setCursorPosition(0, 0);

    // Draw Player
    drawPlayer();
}

void drawHelp()
{
    // Draw log
    clear(gameFrameX() + indentX, 0, WIDTH+10, viewHeight + indentY*2);

    for(int f = 0; f<viewHeight; f++)
    {
        write(help[f], gameFrameX() + indentX, f + indentY);
    }
}

void drawFrame()
{
    // Draw frame
    for(int f = 0; f<viewHeight + indentY*2; f++)
    {
        write('|', gameFrameX(), f);
    }
}

void drawButton(Button dButton)
{
    // Up frame
    setCursorPosition(dButton.x, dButton.y);
    dButton.drawFrame();

    // Middle
    setCursorPosition(dButton.x, dButton.y+1);
    dButton.draw();

    // Down frame
    setCursorPosition(dButton.x, dButton.y+2);
    dButton.drawFrame();
}

void drawSlot(Slot dSlot, int dX, int dY)
{
    setColorText(dSlot.color);
    write(dSlot.symbol, dX, dY);
}

void movePlayer(int direction)
{
    // Move player

    // Fill old coord
    write(gameMap[player.X][player.Y].symbol, player.X + indentX, player.Y + indentY);

    // Up
    if(direction == directions["up"])
    {
        if(player.Y > 0 &&
           !gameMap[player.X][player.Y-1].solid)
        {
            // Move Y
            player.Y--;
        }
    }

    // Down
    else if(direction == directions["down"])
    {
        if(player.Y < viewHeight-1 &&
           !gameMap[player.X][player.Y+1].solid)
        {
            // Move Y
            player.Y++;
        }
    }

    // Left
    else if(direction == directions["left"])
    {
        if(player.X > 0 &&
           !gameMap[player.X-1][player.Y].solid)
        {
            // Move X
            player.X--;
        }
    }

    // Right
    else if(direction == directions["right"])
    {
        if(player.X < viewWidth-1 &&
           !gameMap[player.X+1][player.Y].solid)
        {
            // Move X
            player.X++;
        }
    }

    // Draw player
    drawPlayer();
}

void pushLog(string message)
{
    for(int f = 0; f<viewHeight-1; f++)
    {
        help[f] = help[f+1];
    }

    help[viewHeight - 1] = message;

//	drawHelp();
}

void addButton(int bScene, Button nButton)
{
    button[bScene].push_back(nButton);
    buttons[nButton.name] = button[bScene].size();
}

void clear(int x1, int y1, int x2, int y2)
{
    if(x1>x2)
        swap(x1, x2);

    if(y1>y2)
        swap(y1, y2);

    for(int x = x1; x<x2-x1; x++)
    {
        for(int y = y1; y<y2 - y1; y++)
        {
            write(' ', x, y);
        }
    }

    setCursorPosition(0,0);
}
