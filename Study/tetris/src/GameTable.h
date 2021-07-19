#pragma once

#include <iostream>
#include "Figure.h"
#include <windows.h>
#include <map>



using namespace std;

class GameTable  {
public:
	GameTable();
	GameTable& operator+(Figure& f);
	void Display(COORD& position);
	COORD GetPositionMAX(){return positionMAX;};
	bool GetCell(COORD& position);
	Figure* GetFigure() {return newfigure;};



private:
	Figure* newfigure;
	COORD positionMAX;
	COORD position;
	map<pair<int,int>, bool> cell;
};
