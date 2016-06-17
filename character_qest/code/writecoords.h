#ifndef WRITECOORDS_H
#define WRITECOORDS_H

#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

extern HANDLE hConsole;

void setDekryptor();

void setCursorPosition(COORD cursorCoord);

void setCursorPosition(int x, int y);

void write(string text, int x, int y);

void write(string text, COORD coord);

void write(char symbol, int x, int y);

void write(char symbol, COORD coord);

void setColorText(char nColor);

#endif
