#pragma once

#include <iostream>
#include "Figure.h"
#include <string>
#include "GameTable.h"

using namespace std;

class Line : public Figure {
public:
	Line(){ name = "line";}
	Line(GameTable* tab) : table(tab){}
	void DisplayFigure(COORD& pos){cout << name;};
private:
	string name;
	GameTable* table;
	COORD position;
};
