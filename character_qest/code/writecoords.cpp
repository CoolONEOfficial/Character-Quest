#include <writecoords.h>

HANDLE hConsole;

void setCursorPosition(int x, int y)
{
    COORD cursorCoord;
    cursorCoord.X = x;
    cursorCoord.Y = y;
    setCursorPosition(cursorCoord);
}

void setCursorPosition(COORD cursorCoord)
{
    SetConsoleCursorPosition(hConsole, cursorCoord);
}

void write(string text, int x, int y)
{
    setCursorPosition(x, y);
    cout<<text;
}

void write(string text, COORD coord)
{
    write(text, coord.X, coord.Y);
}

void write(char symbol, int x, int y)
{
    write(string(1,symbol), x, y);
}

void write(char symbol, COORD coord)
{
    write(symbol, coord.X, coord.Y);
}

void setColorText(char nColor)
{
    SetConsoleTextAttribute(hConsole, nColor);
}

void setDekryptor()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}
