#include "GameTable.h"
#include <windows.h>

using namespace std;

GameTable::GameTable(){
	positionMAX.X= 50;
	positionMAX.Y = 50;
	newfigure = new Figure;
}

GameTable& GameTable::operator+(Figure& f){


	newfigure = &f;


	return *this;
}


void GameTable::Display(COORD& pos){
	//

	position = pos;
	newfigure->DisplayFigure(position);
}

bool GameTable::GetCell(COORD& pos){
		pair<int, int> position;
		position.first = pos.X;
		position.second = pos.Y;
		if(cell[position] == 1) return true;
		return false;
}

