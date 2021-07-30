#include "Remote.h"
#include <map>
#include <windows.h>
#include <conio.h>

using namespace std;




bool Remote::Start(){


	char key1=0;
	    while(table->GetPositionFigure().Y < table->GetPositionMAX().Y)//for exit
	    {
	        if(kbhit())//buffer keyboard not empty?
	        {
	        while(table->ShiftDown()){};
	        key1=getch();
	            switch (key1)
	            {
	            case 75:
	            	table->ClearFigure(table->GetPositionFigure());
           			this->Left();
           			this->ShowObject();
	                break;
	            case 77:
	            	table->ClearFigure(table->GetPositionFigure());
   					this->Right();
   					this->ShowObject();
	                break;
	            case 80:
	            	table->ClearFigure(table->GetPositionFigure());
	            	if(this->Down() == false) {
	            		this->ShowObject();
	            		table->PullFigure(position);
	            		table->ZeroPositionFigure();
	            		vector<int > lines;

	            		lines = table->FindFullLines();
	            		for(auto it = lines.begin(); it != lines.end(); ++it){
	            			for(int x = table->GetPositionMIN().X + 1; x < table->GetPositionMAX().X -1 ; ++x){
	            				COORD t;
	            				t.X = x;
	            				t.Y = *it;
	            				table->SetCell(t, 0);
	            				table->ClearLine(*it);

	            			}

	            		}
	            		return false;
	            	}
       				this->ShowObject();
	                break;

	            }
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
	for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
		if( it->second == 1){
			timeposition.X = table->GetPositionFigure().X + it->first.first + 1;
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
				timeposition.X = table->GetPositionFigure().X + it->first.first;
				if(table->GetCell(timeposition) == 1 ) {
					table->SetPositionFigure({0,0});
					return false;
				}

			}

		}


		// ÍÀÄÎ ÎÁÍÎÂÈÒÜ ÊÎÎÐÄÈÍÀÒÓ
			table->SetPositionFigure({0,1});

			return true;
}
