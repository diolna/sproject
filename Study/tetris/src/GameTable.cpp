#include "GameTable.h"
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;

void GameTable::DisplayCount(int c){


		COORD timeposition = {35, 15};
		SetConsoleCursorPosition(hStdout, timeposition);
		cout << "LINES = " <<  c/18;


}

GameTable::GameTable(){
	countline =0;
	positionMAX.X= 30;
	positionMAX.Y = 30;
	positionMIN.X = 10;
	positionMIN.Y = 0;
	position = {15, 0};
	//newfigure = new Figure;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int x = positionMIN.X; x < positionMAX.X; x++){
		for(int y = positionMIN.Y; y < positionMAX.Y; y++){
			if(x == positionMIN.X || x == (positionMAX.X)-1 || y == (positionMAX.Y) - 1){
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

void GameTable::SetCell(COORD& pos, bool val){
	pair<int, int> position;
			position.first = pos.X;
			position.second = pos.Y;
	cell[position] = val;
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

vector<int> GameTable::FindFullLines(){
//	cout << "DeleteLine " << endl;
	int langth;
	COORD pos;
	vector<int> arrY;


	for(int y = positionMIN.Y; y < positionMAX.Y - 1; ++y){
		pos.Y = y;
		langth = 0;
		for(int x = positionMIN.X +1; x < positionMAX.X - 1; ++x){

			pos.X = x;

			if(this->GetCell(pos)) {

				langth++;

			}

		}


		if(langth == positionMAX.X - positionMIN.X - 2) {
			//cout << "y = " << y <<  endl;
//			for( int x = positionMIN.X +1 ; x < positionMAX.X -1 ; ++x){
//
//				cell[{x,y }] = 0;
//			}
//			ClearLine(y);
			arrY.push_back(y);

		}

	}
	return arrY;
}
void GameTable::ClearLine(int y){

	DWORD l;
	COORD pos;
	pos.Y = y;
	for(int x = positionMIN.X + 1; x < positionMAX.X - 1; ++x){
		pos.X = x;

	SetConsoleCursorPosition(hStdout, pos);
	FillConsoleOutputAttribute(hStdout, FOREGROUND_RED |
							FOREGROUND_GREEN | FOREGROUND_INTENSITY, 1, pos, &l);
	FillConsoleOutputCharacterA(hStdout, TEXT(' '), 1, pos, &l);

	}
}

void GameTable::PullFigure(COORD pos){
	for(auto it= newfigure->GetViewFigure().begin(); it != newfigure->GetViewFigure().end(); ++it){
		COORD time;
		time.X = position.X + it->first.first;
		time.Y = position.Y + it->first.second;
		this->SetCell(time, 1);
	}
}

bool GameTable::ShiftDown(){
	vector<int> emptylines;
	emptylines = this->FindEmptyLines();
	sort(emptylines.begin(), emptylines.end());


	for(auto it = emptylines.begin(); it != emptylines.end(); ++it){
		for(int x = positionMIN.X + 1; x < positionMAX.X -1; ++x){

			if(cell[{x, *it-1}] == 1 && *it -1 >= 0) {
				for(int x = positionMIN.X + 1; x < positionMAX.X -1; ++x){
					cell[{x, *it}] = cell[{x, *it -1}];
					cell[{x,*it-1}] = 0;
				}

				this->ClearLine(*it-1);
				this->DisplayLine(*it);
//				countline++;
//				this->DisplayCount(countline);

				return true;
			}

		}

		}
	return false;
	}


void GameTable::DisplayLine(int y){
	COORD timeposition;
	DWORD l;

	for(int x = positionMIN.X +1; x < positionMAX.X -1 ; ++x){

				timeposition.X = x;
				timeposition.Y = y;
				if(cell[{x,y}] == 1){

				SetConsoleCursorPosition(hStdout, timeposition);
				FillConsoleOutputAttribute(hStdout, BACKGROUND_RED, 1, timeposition, &l);
				FillConsoleOutputAttribute(hStdout, BACKGROUND_INTENSITY, 1, timeposition, &l);
				FillConsoleOutputCharacterA(hStdout, TEXT(' '), 1, timeposition, &l);
				}

			}
}
vector<int> GameTable::FindEmptyLines(){
	vector<int> res;
	int count;
	for(int y = positionMIN.Y; y < positionMAX.Y -1; ++y){
		count = 0;
		for(int x = positionMIN.X +1; x < positionMAX.X; ++x){
			if(cell[{x,y}] == 0) count++;
		}
		//cout << "emptyline count= "<< count << endl;
		if(count == (positionMAX.X - positionMIN.X - 2)) res.push_back(y);
	}

	return res;
}
