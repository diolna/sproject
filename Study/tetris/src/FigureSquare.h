#pragma once

#include "Figure.h"
#include <iostream>

using namespace std;

class FigureSquare: public Figure {
public:
	void DisplayFigure();
private:
	int width;
	int color;



};

