#include "CurvedLine.h"
#include <windows.h>
#include <iostream>


using namespace std;

void  CurvedLine::DisplayFigure(COORD& position) {

	cout << name;

}


	CurvedLine::CurvedLine(){
	name = "Meander";
	position = {0,0};
	element = {
			{{0,0}, 1},
			{{1,0}, 1},
			{{2,0}, 1},
			{{0,1}, 0},
			{{1,1}, 0},
			{{2,1}, 1},


	};
}


