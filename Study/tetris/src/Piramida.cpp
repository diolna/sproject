#include "Piramida.h"
#include <map>

using namespace std;

void  Piramida::DisplayFigure(COORD& position) {

	cout << name;

}

Piramida::Piramida(){
	color = YELLOW;
	angle = 0;
	name = "piramida";
	this->position = {0,0};
	this->element ={
			{{-1,0},{1,color}},
			{{0,0},{1,color}},
			{{1,0},{1,color}},
			{{0,-1},{1,color}}};
}

Piramida::Piramida(int an){
			color = YELLOW;
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
									{{-1,0},{1,color}},
									{{0,0},{1,color}},
									{{1,0},{1,color}},
									{{0,-1},{1,color}}};
							break;
						}
						case 90:{
							element = {
									{{0,-1},{1,color}},
									{{0,0},{1,color}},
									{{0,1},{1,color}},
									{{1,0},{1,color}}};
						break;
						}
						case 180:{
							element = {
									{{-1,0},{1,color}},
									{{0,0},{1,color}},
									{{1,0},{1,color}},
									{{0,1},{1,color}}};

							break;
						}
						case 270:{
							element = {
									{{0,-1},{1,color}},
									{{0,0},{1,color}},
									{{0,1},{1,color}},
									{{-1,0},{1,color}}};
							break;

						}

						default: {
							element = {
									{{-1,0},{1,color}},
									{{0,0},{1,color}},
									{{1,0},{1,color}},
									{{0,-1},{1,color}}};
										break;
						}
						}
}

