#include "Line.h"
#include <windows.h>
#include <iostream>

using namespace std;

void  Line::DisplayFigure(COORD& position) {

	cout << name;

}


	Line::Line(){
	name = "line";
	angle = 0;
	position = {0,0};
	element = {
			{{0,0}, 1},
			{{1,0}, 1},
			{{2,0}, 1},
			{{3,0}, 1},


	};

}

	void Line::SelectElement(int increment){
			angle = angle + increment;
			if(angle >= 360 ) angle = 0;

			switch (angle){
					case 0:{
						element = {
									{{-1,0}, 1},
									{{0,0}, 1},
									{{1,0}, 1},
									{{2,0}, 1},


							};
						break;
					}
					case 90:{
						element = {
									{{0,-1}, 1},
									{{0,0}, 1},
									{{0,1}, 1},
									{{0,2}, 1},	};
					break;
					}
					case 180:{
						element = {
									{{1,0}, 1},
									{{0,0}, 1},
									{{-1,0}, 1},
									{{-2,0}, 1},};

						break;
					}
					case 270:{
						element = {
									{{0,1}, 1},
									{{0,0}, 1},
									{{0,-1}, 1},
									{{0,-2}, 1},};
						break;

					}

					default: {
						element = {
									{{-1,0}, 1},
									{{0,0}, 1},
									{{1,0}, 1},
									{{2,0}, 1},	};
									break;
					}
					}

		}




	Line::Line(int an){
		angle = an;
		name = "line";
		position = {0,0};
		this->SelectElement(0);
		}

