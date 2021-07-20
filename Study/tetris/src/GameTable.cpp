#include "GameTable.h"
#include <windows.h>

using namespace std;

GameTable::GameTable(){
	positionMAX.X= 30;
	positionMAX.Y = 30;
	position = {15, 15};
	newfigure = new Figure;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int x = 10; x < positionMAX.X; x++){
		for(int y = 0; y < positionMAX.Y; y++){
			if(x == 10 || x == (positionMAX.X)-1 || y == (positionMAX.Y) - 1){
				cell[{x,y}] = 1;
			}else
			{
				cell[{x,y}] = 0;
			}
		}
	}
	DWORD l;
	COORD timeposition;

	for(auto it = cell.begin(); it != cell.end(); ++it){
			if(it->second == true){
//				cout << "{" << it->first.first << "," << it->first.second << "}," << it->second << endl;
				timeposition.X = it->first.first;
				timeposition.Y = it->first.second;
				SetConsoleCursorPosition(hStdout, timeposition);
				FillConsoleOutputAttribute(hStdout, BACKGROUND_RED, 1, timeposition, &l);
				FillConsoleOutputAttribute(hStdout, BACKGROUND_INTENSITY, 1, timeposition, &l);
				FillConsoleOutputCharacterA(hStdout, TEXT(' '), 1, timeposition, &l);

			}
	}
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

void GameTable::SetPositionFigure(COORD shiftcoord){
	position.X = position.X + shiftcoord.X;
	position.Y = position.Y + shiftcoord.Y;
}

void GameTable::ClearFigure(COORD& pos){
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
				FillConsoleOutputAttribute(hStdout, FOREGROUND_RED |
						FOREGROUND_GREEN | FOREGROUND_INTENSITY, 1, timeposition, &l);
				FillConsoleOutputCharacterA(hStdout, TEXT(' '), 1, timeposition, &l);

			}
		}
}
