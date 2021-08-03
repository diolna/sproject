#pragma once

#include <iostream>
#include "Figure.h"
#include <string>
#include "GameTable.h"

using namespace std;

class Meander : public Figure {
public:
	Meander();
	Meander(int angle);
//	Line(GameTable* tab) : table(tab){}
	void DisplayFigure(COORD& pos);
	virtual ~Meander(){};
	map<pair<int,int>, bool>& GetViewFigure(){ return element;}
	void SelectElement(int increment);
	COLORFIGURE GetColor(){return color;}
private:
	int angle;
	string name;
	COLORFIGURE color;
	//GameTable* table;
	COORD position;
	map<pair<int,int>, bool> element;
};
