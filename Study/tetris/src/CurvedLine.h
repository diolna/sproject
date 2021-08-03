#pragma once

#include <iostream>
#include "Figure.h"
#include <string>
#include "GameTable.h"

using namespace std;

class CurvedLine : public Figure {
public:
	CurvedLine(int angle);
	CurvedLine();
//	Line(GameTable* tab) : table(tab){}
	void DisplayFigure(COORD& pos);
	virtual ~CurvedLine(){};
	map<pair<int,int>, pair<bool, COLORFIGURE>>& GetViewFigure(){ return element;}
	void SelectElement(int increment);
	COLORFIGURE GetColor(){return color;}

	private:
	string name;
	COLORFIGURE color;
	//GameTable* table;
	COORD position;
	map<pair<int,int>, pair<bool, COLORFIGURE>> element;
	int angle;
};
