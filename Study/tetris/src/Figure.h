#pragma once
#include <iostream>
#include <windows.h>
#include <map>


using namespace std;

class Figure {
public:
	virtual void DisplayFigure(COORD& position){};
	Figure(){};
	virtual map<pair<int,int>, bool>& GetViewFigure(){};


private:


};
