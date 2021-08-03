#pragma once

#include <iostream>
#include <map>
#include "Figure.h"


using namespace std;

class Piramida : public Figure {

public:
	Piramida();
	Piramida(int angle);
	void DisplayFigure(COORD& pos);
	virtual ~Piramida(){};
	map<pair<int,int>, pair<bool, COLORFIGURE>>& GetViewFigure(){ return element;}
	void SelectElement(int increment);
	COLORFIGURE GetColor() {return color;}
	private:
		int angle;
		string name;
		COLORFIGURE color;
		//GameTable* table;
		COORD position;
		map<pair<int,int>, pair<bool, COLORFIGURE>> element;

};
