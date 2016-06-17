#include "button.h"

Button::Button(string bName, int bX, int bY)
{
	// Name
	name = bName;
	
	// Coords
	x = bX;
	y = bY;
	
	select = false;
}

void Button::draw(bool selected)
{
	char border = ' ';
	
	if(select)
	{
		border = '|';
	}
	
	cout<<border<<name<<border;
}

void Button::drawFrame()
{
	char border = ' ';
	
	if(select)
	{
		border = '-';
	}
	
	cout<<' ';
	for(int f = 0; f<name.length(); f++)
	{
		cout<<border;
	}
	cout<<' ';
}
