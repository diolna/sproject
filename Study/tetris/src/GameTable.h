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
	void ClearFigure(COORD& position);
	COORD GetPositionMAX(){return positionMAX;};
	bool GetCell(COORD& position);
	COORD& GetPositionFigure();
	void SetPositionFigure(COORD shiftcoord);
	Figure* GetFigure() {return newfigure;};



private:
	Figure* newfigure;
	COORD positionMAX;
	COORD position;
	map<pair<int,int>, bool> cell;
	HANDLE hStdout;
};
