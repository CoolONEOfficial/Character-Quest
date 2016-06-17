#ifndef WALL_H
#define WALL_H

#include <vector>

using namespace std;

class Slot
{
	public:
		Slot(int wSymbol = '.', bool wSolid = false, char wColor = 0x2);
		
		// Symbol
		char symbol;
		
		// Solid
		bool solid;
		
		// Color
		char color;
		
	protected:
};

#endif
