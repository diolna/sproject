#pragma once
#include <iostream>
#include <windows.h>
#include <map>

enum COLORFIGURE{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	BROUN


};


using namespace std;

class Figure {
public:
	virtual void DisplayFigure(COORD& position){};
	Figure(){};
	virtual ~Figure(){};
	virtual map<pair<int,int>, pair<bool, COLORFIGURE>>& GetViewFigure() = 0;
//	virtual int GetAngle();
//	virtual void SetAngle(int an);
	virtual void SelectElement(int increment){};
	virtual COLORFIGURE GetColor() = 0;




};
