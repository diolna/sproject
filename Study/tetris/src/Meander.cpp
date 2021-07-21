#include "Meander.h"
#include <windows.h>
#include <iostream>


using namespace std;

void  Meander::DisplayFigure(COORD& position) {

	cout << name;

}


	Meander::Meander(){
	name = "Meander";
	position = {0,0};
	element = {
			//{{0,0}, 0},
			{{1,0}, 1},
			{{2,0}, 1},
			{{0,1}, 1},
			{{1,1}, 1},
			//{{2,1}, 0},


	};
}


