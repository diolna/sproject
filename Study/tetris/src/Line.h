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
//	Line(GameTable* tab) : table(tab){}
	void DisplayFigure(COORD& pos);
	virtual ~Line(){};
	map<pair<int,int>, bool>& GetViewFigure(){ return element;}
//	int GetAngle() { return angle;}
//	void SetAngle(int an) { angle = an;}
	void SelectElement(int n );
private:
	string name;
	//GameTable* table;
	COORD position;
	map<pair<int,int>, bool> element;
	int angle;

};
