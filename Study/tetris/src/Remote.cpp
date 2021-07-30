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
	            case 32:
	            	table->ClearFigure(table->GetPositionFigure());
	            	this->Rotation();
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
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // карта фигурі

	// проверка на достижение конца чаши ПЕРЕДЕЛАТЬ СДЕЛАТЬ ИНИЦИАЛЛИЗАЦИЮ ЧАШИ КАК ЗАПОЛНЕННЫЕ ЯЧЕЙКИ
//	if(table->GetPositionMAX().X - 1 == position.X){
//		return false;
//	}

			COORD timeposition;
	for(auto it= figuremap.begin(); it != figuremap.end(); ++it){
		if( it->second == 1){
<<<<<<< HEAD
			timeposition.X = table->GetPositionFigure().X -( it->first.first)-1;
			cout << " coordinate X = " << timeposition.X << endl;;
=======
			timeposition.X = table->GetPositionFigure().X + it->first.first - 1;
>>>>>>> de3cbbe5dd855f41033d2aaff26a6a689e9c8bb4
			timeposition.Y = table->GetPositionFigure().Y;
			if(table->GetCell(timeposition) == 1) return false;

		}
	}
	// НАДО ОБНОВИТЬ КООРДИНАТУ
	table->SetPositionFigure({-1,0});
	return true;

}

bool Remote::Right(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // карта фигурі

	// так как смещаем в право и фигура имеет справа елементы, то нужно найти элемент со значением 1 максимально справа

	//const auto p = minmax_element(figuremap)

	// проверка на достижение конца чаши ПЕРЕДЕЛАТЬ СДЕЛАТЬ ИНИЦИАЛЛИЗАЦИЮ ЧАШИ КАК ЗАПОЛНЕННЫЕ ЯЧЕЙКИ
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
	// НАДО ОБНОВИТЬ КООРДИНАТУ
	table->SetPositionFigure({1,0});

	return true;

}
bool Remote::Down(){
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // карта фигурі
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


		// НАДО ОБНОВИТЬ КООРДИНАТУ
			table->SetPositionFigure({0,1});

			return true;
}

bool Remote::Rotation(){
	// временно удаляем текущее значение фигуры
	map<pair<int,int>,bool> figuremap = table->GetFigure() ->GetViewFigure(); // карта фигурі
	COORD timeposition;
		for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
				if( it->second == 1){
					timeposition.X = table->GetPositionFigure().X + it->first.first;
					timeposition.Y = table->GetPositionFigure().Y;
					table->SetCell(timeposition, 0);

				}
		}
// переворачиваем
	table->GetFigure()->SelectElement(90);
	figuremap = table->GetFigure() ->GetViewFigure(); // карта фигурі

	// ставим фигуру

	//COORD timeposition;
	for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
			if( it->second == 1){
				timeposition.X = table->GetPositionFigure().X + it->first.first;
				timeposition.Y = table->GetPositionFigure().Y;
	// если есть наложения то надо все вернуть назад.
				if(table->GetCell(timeposition) == 1) {

					table->GetFigure()->SelectElement(-90);
					figuremap = table->GetFigure() ->GetViewFigure(); // карта фигурі
					//COORD timeposition;

					for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
						if( it->second == 1){
							timeposition.X = table->GetPositionFigure().X + it->first.first;
							timeposition.Y = table->GetPositionFigure().Y;
							table->SetCell(timeposition, 1);

									}
							}

					return false;

			}
		}
	}


	return true;
}
