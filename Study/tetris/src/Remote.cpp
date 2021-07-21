#include "Remote.h"
#include <map>
#include <windows.h>

using namespace std;




bool Remote::Start(){



	char key;
	for(int i = 0; i <100; i++) {
		cin >> key;
	if(key == 'a' || key == 'A'){

		table->ClearFigure(table->GetPositionFigure());

		this->Left();

		this->ShowObject();
	} else if( key == 'd' || key == 'D'){
		table->ClearFigure(table->GetPositionFigure());

				this->Right();

				this->ShowObject();
	}else if( key == 's' || key == 'S'){
//		cout << table->GetPositionFigure().Y;

		table->ClearFigure(table->GetPositionFigure());
			if(this->Down() == false) {
				this->ShowObject();
				table->ZeroPositionFigure();
				break;
			}


				this->ShowObject();

	}
	}


	return false;
}

void Remote::ShowObject(){

	table->Display(table->GetPositionFigure());
}

bool Remote::Left(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // êàðòà ôèãóð³

	// ïðîâåðêà íà äîñòèæåíèå êîíöà ÷àøè ÏÅÐÅÄÅËÀÒÜ ÑÄÅËÀÒÜ ÈÍÈÖÈÀËËÈÇÀÖÈÞ ×ÀØÈ ÊÀÊ ÇÀÏÎËÍÅÍÍÛÅ ß×ÅÉÊÈ
//	if(table->GetPositionMAX().X - 1 == position.X){
//		return false;
//	}

			COORD timeposition;
	for(auto it= figuremap.begin(); it != figuremap.end(); ++it){
		if( it->second == 1){
			timeposition.X = table->GetPositionFigure().X + it->first.first - 1;
//			cout << " coordinate X = " << timeposition.X << endl;;
			timeposition.Y = table->GetPositionFigure().Y;
			if(table->GetCell(timeposition) == 1) return false;

		}
	}
	// ÍÀÄÎ ÎÁÍÎÂÈÒÜ ÊÎÎÐÄÈÍÀÒÓ
	table->SetPositionFigure({-1,0});
	return true;

}

bool Remote::Right(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // êàðòà ôèãóð³

	// òàê êàê ñìåùàåì â ïðàâî è ôèãóðà èìååò ñïðàâà åëåìåíòû, òî íóæíî íàéòè ýëåìåíò ñî çíà÷åíèåì 1 ìàêñèìàëüíî ñïðàâà

	//const auto p = minmax_element(figuremap)

	// ïðîâåðêà íà äîñòèæåíèå êîíöà ÷àøè ÏÅÐÅÄÅËÀÒÜ ÑÄÅËÀÒÜ ÈÍÈÖÈÀËËÈÇÀÖÈÞ ×ÀØÈ ÊÀÊ ÇÀÏÎËÍÅÍÍÛÅ ß×ÅÉÊÈ
//	if(table->GetPositionMAX().X + 1 == position.X){
//		return false;
//	}

			COORD timeposition;
	for(auto it= figuremap.rbegin() ; it != figuremap.rend(); ++it){
		if( it->second == 1){
			timeposition.X = table->GetPositionFigure().X + it->first.first + 1;
//			cout << " coordinate X = " << timeposition.X << endl;;
			timeposition.Y = table->GetPositionFigure().Y;
			if(table->GetCell(timeposition) == 1) return false;

		}
	}
	// ÍÀÄÎ ÎÁÍÎÂÈÒÜ ÊÎÎÐÄÈÍÀÒÓ
	table->SetPositionFigure({1,0});

	return true;

}
bool Remote::Down(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // êàðòà ôèãóð³
	COORD timeposition;
		for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
			if( it->second == 1){
				timeposition.Y = table->GetPositionFigure().Y + it->first.second + 1;
	//			cout << " coordinate X = " << timeposition.X << endl;;
				timeposition.X = table->GetPositionFigure().X + it->first.first + 1;
				if(table->GetCell(timeposition) == 1) {
					COORD pos;

					for(auto it = figuremap.begin(); it != figuremap.end(); ++it){
						if(it->second == 1){
							pos.X = table->GetPositionFigure().X + it->first.first;
							pos.Y = table->GetPositionFigure().Y + it->first.second;
							table->SetCell(pos);
						}
					}
					table->DeleteLine();
					return false;
				}

			}
		}
		// ÍÀÄÎ ÎÁÍÎÂÈÒÜ ÊÎÎÐÄÈÍÀÒÓ
			table->SetPositionFigure({0,1});
			return true;
}
