#pragma once

#include <iostream>
#include "Figure.h"
#include <windows.h>
#include <map>
#include <vector>



using namespace std;

class GameTable  {
public:
	GameTable();
	GameTable& operator+(Figure& f);
	void Display(COORD& position);
	void DisplayLine(int y);
	void ClearFigure(COORD& position);
	COORD GetPositionMAX(){return positionMAX;};
	COORD GetPositionMIN() {return positionMIN;};
	bool GetCell(COORD& position);
	void SetCell(COORD& position, bool val);
	COORD& GetPositionFigure();
	void SetPositionFigure(COORD shiftcoord);
	void ZeroPositionFigure(){ position = {15,15};};
	Figure* GetFigure() {return newfigure;};
	vector<int> FindFullLines();
	vector<int> FindEmptyLines();
	void ClearLine(int y);
	void PullFigure(COORD pos);
	bool ShiftDown();


private:
	Figure* newfigure;
	COORD positionMAX;
	COORD positionMIN;
	COORD position;
	map<pair<int,int>, bool> cell;
	HANDLE hStdout;

};
