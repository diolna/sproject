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
	map<pair<int,int>, bool>& GetViewFigure(){ return element;}
	void SelectElement(int increment);
	private:
		int angle;
		string name;
		//GameTable* table;
		COORD position;
		map<pair<int,int>, bool> element;

};
