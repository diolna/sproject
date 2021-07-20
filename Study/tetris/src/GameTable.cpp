#include "GameTable.h"
#include <windows.h>

using namespace std;

GameTable::GameTable(){
	positionMAX.X= 50;
	positionMAX.Y = 50;
	position = {5, 5};
	newfigure = new Figure;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
}

GameTable& GameTable::operator+(Figure& f){


	newfigure = &f;


	return *this;
}


void GameTable::Display(COORD& pos){
	//
	DWORD l;

	COORD timeposition = pos;


	map<pair<int,int>, bool> figuremap = newfigure->GetViewFigure();
	for(auto it = figuremap.begin(); it != figuremap.end(); ++it){
		if(it->second == true){
			timeposition.X = position.X + it->first.first;
			timeposition.Y = position.Y + it->first.second;
//			cout << "coordinate x,y basic = " << position.X << " , " << position.Y << endl;
//			cout << "coordinate x,y = " << timeposition.X << " , " << timeposition.Y << endl;
			SetConsoleCursorPosition(hStdout, timeposition);
			FillConsoleOutputAttribute(hStdout, BACKGROUND_RED, 1, timeposition, &l);
			FillConsoleOutputAttribute(hStdout, BACKGROUND_INTENSITY, 1, timeposition, &l);
			FillConsoleOutputCharacterA(hStdout, TEXT(' '), 1, timeposition, &l);

		}
	}

}

bool GameTable::GetCell(COORD& pos){
		pair<int, int> position;
		position.first = pos.X;
		position.second = pos.Y;
		if(cell[position] == 1) return true;
		return false;
}

COORD& GameTable::GetPositionFigure(){
		return position;
}

