#include "FigureSquare.h"
#include <windows.h>

#include <iostream>

using namespace std;

void  FigureSquare::DisplayFigure(COORD& position) {

	cout << name;
	cout << "number array elements = " << element.size() << endl;

}

FigureSquare::FigureSquare(){
	name = "square";
	position = {0,0};
	element = {
			{{0,0}, 1},
			{{0,1}, 1},
			{{0,2}, 0},
			{{1,0}, 1},
			{{1,1}, 1},
			{{1,2}, 0},
			{{2,0}, 0},
			{{2,1}, 0},
			{{2,2}, 0}


	};
}

