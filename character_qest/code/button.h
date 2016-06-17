#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>

using namespace std;

class Button
{
	public:
		Button(string bName = "button", int bX = 0, int bY = 0);
	
	// Name	
	string name;
	
	// Coords
	int x, y;
	
	bool select;
	
	void draw(bool selected = false);
    void drawFrame();
	
	protected:
};

#endif
