#include "CurvedLine.h"
#include <windows.h>
#include <iostream>


using namespace std;

void  CurvedLine::DisplayFigure(COORD& position) {

	cout << name;

}


	CurvedLine::CurvedLine(){
		color = RED;
	angle = 0;
	name = "Meander";
	position = {0,0};
	element = {
			{{0,0}, 1},
			{{1,0}, 1},
			{{2,0}, 1},
			//{{0,1}, 0},
			//{{1,1}, 0},
			{{2,1}, 1}


	};
}

	CurvedLine::CurvedLine(int an){
		color = GREEN;
		angle = an;
		name = "line";
		position = {0,0};
		this->SelectElement(0);
	}

	void CurvedLine::SelectElement(int increment){
			angle = angle + increment;
			if(angle >= 360 ) angle = 0;

			switch (angle){
					case 0:{
						element = {
								{{-1,0}, 1},
								{{0,0}, 1},
								{{1,0}, 1},
								{{1,1}, 1}};
						break;
					}
					case 90:{
						element = {
									{{0,-1}, 1},
									{{0,0}, 1},
									{{0,1}, 1},
									{{-1,1}, 1}};
					break;
					}
					case 180:{
						element = {
									{{1,0}, 1},
									{{0,0}, 1},
									{{-1,0}, 1},
									{{-1,-1}, 1}};

						break;
					}
					case 270:{
						element = {
									{{0,1}, 1},
									{{0,0}, 1},
									{{0,-1}, 1},
									{{1,-1}, 1},};
						break;

					}

					default: {
						element = {
								{{-1,0}, 1},
								{{0,0}, 1},
								{{1,0}, 1},
								{{1,1}, 1}};
									break;
					}
					}

		}



