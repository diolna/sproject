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
	void DisplayCount(int count);
	void ClearFigure(COORD& position);
	COORD GetPositionMAX(){return positionMAX;};
	COORD GetPositionMIN() {return positionMIN;};
	pair<bool, COLORFIGURE> GetCell(COORD& position);
	void SetCell(COORD& position, pair<bool, COLORFIGURE> val);
	COORD& GetPositionFigure();
	void SetPositionFigure(COORD shiftcoord);
	void ZeroPositionFigure(){ position = {15,0};};
	Figure* GetFigure() {return newfigure;};
	vector<int> FindFullLines();
	vector<int> FindEmptyLines();
	void ClearLine(int y);
	void PullFigure(COORD pos);
	bool ShiftDown();
	int GetCountLines(){return countline;}
	void SetCountLines(){countline++;}


private:
	Figure* newfigure;
	COORD positionMAX;
	COORD positionMIN;
	COORD position;
	map<pair<int,int>, pair<bool, COLORFIGURE>> cell;
	HANDLE hStdout;
	int countline;

};
