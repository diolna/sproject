#include "Line.h"
#include <windows.h>
#include <iostream>

using namespace std;

void  Line::DisplayFigure(COORD& position) {

	cout << name;

}


	Line::Line(){
	name = "line";
	position = {0,0};
	element = {
			{{0,0}, 1},
			{{1,0}, 1},
			{{2,0}, 1},
			{{3,0}, 1},


	};
}


