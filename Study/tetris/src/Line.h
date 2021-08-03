#pragma once

#include <iostream>
#include "Figure.h"
#include <string>
#include "GameTable.h"

using namespace std;

class Line : public Figure {
public:
	Line();
	Line(int angle);
	void DisplayFigure(COORD& pos);
	virtual ~Line(){};
	map<pair<int,int>, pair<bool, COLORFIGURE>>& GetViewFigure(){ return element;}
	void SelectElement(int n );
	COLORFIGURE GetColor(){return color;}
private:
	string name;
	COLORFIGURE color;
	COORD position;
	map<pair<int,int>, pair<bool, COLORFIGURE>> element;
	int angle;

};
