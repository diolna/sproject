#pragma once

#include "Figure.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <map>

using namespace std;

class FigureSquare: public Figure {
public:
	FigureSquare();
//	FigureSquare(string& n) : name(n){};

 	void DisplayFigure(COORD& position);
	virtual ~FigureSquare(){};
	map<pair<int,int>, bool>& GetViewFigure(){ return element;}
	void SelectElement(int increment){};
	COLORFIGURE GetColor(){return color;}



private:
	//int width;
	COLORFIGURE color;
	//Figure* new_figure;
	string name;
	COORD position;
	map<pair<int,int>, bool> element;


};
