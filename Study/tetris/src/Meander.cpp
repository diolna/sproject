#include "Meander.h"
#include <windows.h>
#include <iostream>


using namespace std;

void  Meander::DisplayFigure(COORD& position) {

	cout << name;

}


	Meander::Meander(){
		color = RED;
	angle = 0;
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

	Meander::Meander(int an){
			color = RED;
			angle = an;
			name = "line";
			position = {0,0};
			this->SelectElement(0);
		}

		void Meander::SelectElement(int increment){
				angle = angle + increment;
				if(angle >= 360 ) angle = 0;

				switch (angle){
						case 0:{
							element = {
									{{-1,0}, 1},
									{{0,0}, 1},
									{{0,-1}, 1},
									{{1,-1}, 1}};
							break;
						}
						case 90:{
							element = {
										{{0,-1}, 1},
										{{0,0}, 1},
										{{1,0}, 1},
										{{1,1}, 1}};
						break;
						}
						case 180:{
							element = {
									{{-1,0}, 1},
									{{0,0}, 1},
									{{0,-1}, 1},
									{{1,-1}, 1}};

							break;
						}
						case 270:{
							element = {
									{{0,-1}, 1},
									{{0,0}, 1},
									{{1,0}, 1},
									{{1,1}, 1}};
							break;

						}

						default: {
							element = {
									{{-1,0}, 1},
									{{0,0}, 1},
									{{0,-1}, 1},
									{{1,-1}, 1}};
										break;
						}
						}

			}





