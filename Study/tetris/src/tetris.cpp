//============================================================================
// Name        : tetris.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Figure.h"
#include "FigureSquare.h"

#include <iostream>

using namespace std;

int main() {

	Figure *f1 =  new FigureSquare;
	f1->DisplayFigure();
	return 0;
}
