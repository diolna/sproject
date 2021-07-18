#include "Remote.h"
#include <map>
#include <windows.h>

using namespace std;




bool Remote::Start(){

	this->ShowObject();
	cout << "Start";
	return false;
}

void Remote::ShowObject(){

	table->Display(position);
}

bool Remote::Left(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // карта фигурі

	// проверка на достижение конца чаши ПЕРЕДЕЛАТЬ СДЕЛАТЬ ИНИЦИАЛЛИЗАЦИЮ ЧАШИ КАК ЗАПОЛНЕННЫЕ ЯЧЕЙКИ
	if(table->GetPositionMAX().X - 1 == position.X){
		return false;
	}

			COORD timeposition;
	for(auto it= figuremap.begin(); it != figuremap.end(); ++it){
		if( it->second == 1){
			timeposition.X = position.X - it->first.first;
			timeposition.Y = position.Y;
			if(table->GetCell(timeposition) == 1) return false;

		}
	}
	// НАДО ОБНОВИТЬ КООРДИНАТУ
	position.X -=1;

	return true;

}

bool Remote::Right(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // карта фигурі

	// проверка на достижение конца чаши ПЕРЕДЕЛАТЬ СДЕЛАТЬ ИНИЦИАЛЛИЗАЦИЮ ЧАШИ КАК ЗАПОЛНЕННЫЕ ЯЧЕЙКИ
	if(table->GetPositionMAX().X + 1 == position.X){
		return false;
	}

			COORD timeposition;
	for(auto it= figuremap.begin(); it != figuremap.end(); ++it){
		if( it->second == 1){
			timeposition.X = position.X + it->first.first;
			timeposition.Y = position.Y;
			if(table->GetCell(timeposition) == 1) return false;

		}
	}
	// НАДО ОБНОВИТЬ КООРДИНАТУ
	position.X +=1;

	return true;

}
