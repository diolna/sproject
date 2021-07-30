#pragma once
#include <iostream>
#include <windows.h>
#include <map>


using namespace std;

class Figure {
public:
	virtual void DisplayFigure(COORD& position){};
	Figure(){};
	virtual ~Figure(){};
	virtual map<pair<int,int>, bool>& GetViewFigure(){};
//	virtual int GetAngle();
//	virtual void SetAngle(int an);
	virtual void SelectElement(int increment){};




};
