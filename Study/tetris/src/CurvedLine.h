#pragma once

#include <iostream>
#include "Figure.h"
#include <string>
#include "GameTable.h"

using namespace std;

class CurvedLine : public Figure {
public:
	CurvedLine();
//	Line(GameTable* tab) : table(tab){}
	void DisplayFigure(COORD& pos);
	virtual ~CurvedLine(){};
	map<pair<int,int>, bool>& GetViewFigure(){ return element;}
private:
	string name;
	GameTable* table;
	COORD position;
	map<pair<int,int>, bool> element;
};
