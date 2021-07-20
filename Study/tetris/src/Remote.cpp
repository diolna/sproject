#include "Remote.h"
#include <map>
#include <windows.h>

using namespace std;




bool Remote::Start(){

	char key;
	for(int i = 0; i <5; i++) {
		cin >> key;
	if(key == 'a' ){

		this->Left();

		this->ShowObject();
	}

	}


	return false;
}

void Remote::ShowObject(){

	table->Display(table->GetPositionFigure());
}

bool Remote::Left(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // êàğòà ôèãóğ³

	// ïğîâåğêà íà äîñòèæåíèå êîíöà ÷àøè ÏÅĞÅÄÅËÀÒÜ ÑÄÅËÀÒÜ ÈÍÈÖÈÀËËÈÇÀÖÈŞ ×ÀØÈ ÊÀÊ ÇÀÏÎËÍÅÍÍÛÅ ß×ÅÉÊÈ
//	if(table->GetPositionMAX().X - 1 == position.X){
//		return false;
//	}

			COORD timeposition;
	for(auto it= figuremap.begin(); it != figuremap.end(); ++it){
		if( it->second == 1){
			timeposition.X = table->GetPositionFigure().X - it->first.first;
			timeposition.Y = table->GetPositionFigure().Y;
			if(table->GetCell(timeposition) == 1) return false;

		}
	}
	// ÍÀÄÎ ÎÁÍÎÂÈÒÜ ÊÎÎĞÄÈÍÀÒÓ
	position.X -=1;

	return true;

}

bool Remote::Right(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // êàğòà ôèãóğ³

	// ïğîâåğêà íà äîñòèæåíèå êîíöà ÷àøè ÏÅĞÅÄÅËÀÒÜ ÑÄÅËÀÒÜ ÈÍÈÖÈÀËËÈÇÀÖÈŞ ×ÀØÈ ÊÀÊ ÇÀÏÎËÍÅÍÍÛÅ ß×ÅÉÊÈ
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
	// ÍÀÄÎ ÎÁÍÎÂÈÒÜ ÊÎÎĞÄÈÍÀÒÓ
	position.X +=1;

	return true;

}
