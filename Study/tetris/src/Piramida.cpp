#include "Piramida.h"
#include <map>

using namespace std;

void  Piramida::DisplayFigure(COORD& position) {

	cout << name;

}

Piramida::Piramida(){
	angle = 0;
	name = "piramida";
	this->position = {0,0};
	this->element ={
			{{-1,0},1},
			{{0,0},1},
			{{1,0},1},
			{{0,-1},1}};
}

Piramida::Piramida(int an){
			color = RED;
			angle = an;
			name = "piramida";
			position = {0,0};
			this->SelectElement(0);
}

void Piramida::SelectElement(int increment){
	angle = angle + increment;
				if(angle >= 360 ) angle = 0;

				switch (angle){
						case 0:{
							element = {
									{{-1,0},1},
									{{0,0},1},
									{{1,0},1},
									{{0,-1},1}};
							break;
						}
						case 90:{
							element = {
									{{0,-1},1},
									{{0,0},1},
									{{0,1},1},
									{{1,0},1}};
						break;
						}
						case 180:{
							element = {
									{{-1,0},1},
									{{0,0},1},
									{{1,0},1},
									{{0,1},1}};

							break;
						}
						case 270:{
							element = {
									{{0,-1},1},
									{{0,0},1},
									{{0,1},1},
									{{-1,0},1}};
							break;

						}

						default: {
							element = {
									{{-1,0},1},
									{{0,0},1},
									{{1,0},1},
									{{0,-1},1}};
										break;
						}
						}
}

