#include "Remote.h"
#include <map>
#include <windows.h>
#include <conio.h>

using namespace std;


void Remote::KeyDown(){

	char key1=0;

		 while(kbhit()){
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
//				 this->ShowObject();
//				 table->PullFigure(position);
//				 table->ZeroPositionFigure();
//				 vector<int > lines;
//
//				 lines = table->FindFullLines();
//				 for(auto it = lines.begin(); it != lines.end(); ++it){
//					 for(int x = table->GetPositionMIN().X + 1; x < table->GetPositionMAX().X -1 ; ++x){
//						 COORD t;
//						 t.X = x;
//						 t.Y = *it;
//						 table->SetCell(t, {0, RED});
//						 table->ClearLine(*it);
//
//					 }
//
//				 }
				 break;
			 }
			 this->ShowObject();
			 break;

		 }


		 }

}


bool Remote::Start(){
// repeat while Y

	    while(table->GetPositionFigure().Y < table->GetPositionMAX().Y)//for exit
	    {

	        while(table->ShiftDown()){};
	        while(this->Down() != false){
	        	if(kbhit()) this->KeyDown();
//	        	while(kbhit())getch();
	           	this->ShowObject();
	        	Sleep(350);
	        	table->ClearFigure(table->GetPositionFigure());
	        }
	        this->ShowObject();
	        table->PullFigure(position);
	        table->Zummer();
	        table->ZeroPositionFigure();
	        vector<int > lines;

	        lines = table->FindFullLines();
	        for(auto it = lines.begin(); it != lines.end(); ++it){
	        	for(int x = table->GetPositionMIN().X + 1; x < table->GetPositionMAX().X -1 ; ++x){
	        		COORD t;
	        		t.X = x;
	        		t.Y = *it;
	        		table->SetCell(t, {0,RED});

	        		table->ClearLine(*it);
	        		table->SetCountLines();
	        		table->DisplayCount(table->GetCountLines());

	        	}

	        }
	        while(table->ShiftDown()){}
	        return false;
	    }
	    return false;
}

void Remote::ShowObject(){


	table->Display(table->GetPositionFigure());
}

bool Remote::Left(){
	map<pair<int,int>,pair<bool, COLORFIGURE>> figuremap = table->GetFigure() ->GetViewFigure(); // ����� �����

// � ����� ���������� ����� ������ � ������ �������� ������������ ������� ������� �� �� ��� X ������� ��� ����� �����
	// �� 1 (-1)

			COORD timeposition;
	for(auto it= figuremap.begin(); it != figuremap.end(); ++it){
		if( it->second.first == 1){
			timeposition.X = table->GetPositionFigure().X + it->first.first - 1;
			timeposition.Y = table->GetPositionFigure().Y + it->first.second;
			if(table->GetCell(timeposition).first == 1) return false;

		}
	}
	// ���� �������� ����������
	table->SetPositionFigure({-1,0});
	return true;

}

bool Remote::Right(){
	map<pair<int,int>,pair<bool, COLORFIGURE>> figuremap = table->GetFigure() ->GetViewFigure(); // ����� �����

	// ��� ��� ������� � ����� � ������ ����� ������ ��������, �� ����� ����� ������� �� ��������� 1 ����������� ������

	//const auto p = minmax_element(figuremap)

	// �������� �� ���������� ����� ���� ���������� ������� �������������� ���� ��� ����������� ������
//	if(table->GetPositionMAX().X + 1 == position.X){
//		return false;
//	}

			COORD timeposition;
	for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
		if( it->second.first == 1){
			timeposition.X = table->GetPositionFigure().X + it->first.first + 1;
			timeposition.Y = table->GetPositionFigure().Y + it->first.second;
			if(table->GetCell(timeposition).first == 1) return false;

		}
	}
	// ���� �������� ����������
	table->SetPositionFigure({1,0});

	return true;

}
bool Remote::Down(){
	map<pair<int,int>,pair<bool, COLORFIGURE>> figuremap = table->GetFigure() ->GetViewFigure(); // ����� �����
	COORD timeposition;
		for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
			if( it->second.first == 1){
				timeposition.Y = table->GetPositionFigure().Y + it->first.second + 1;
				timeposition.X = table->GetPositionFigure().X + it->first.first;
				if(table->GetCell(timeposition).first == 1 ) {
					table->SetPositionFigure({0,0});
					return false;
				}

			}

		}


		// ���� �������� ����������
			table->SetPositionFigure({0,1});

			return true;
}

bool Remote::Rotation(){
	// �������� ������� ������� �������� ������
	map<pair<int,int>,pair<bool, COLORFIGURE>> figuremap = table->GetFigure() ->GetViewFigure(); // ����� �����
	COORD timeposition;
		for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
				if( it->second.first == 1){
					timeposition.X = table->GetPositionFigure().X + it->first.first;
					timeposition.Y = table->GetPositionFigure().Y;
					table->SetCell(timeposition, {0,it->second.second});

				}
		}
// ��������������
	table->GetFigure()->SelectElement(90);
	figuremap = table->GetFigure() ->GetViewFigure(); // ����� �����

	// ������ ������

	//COORD timeposition;
	for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
			if( it->second.first == 1){
				timeposition.X = table->GetPositionFigure().X + it->first.first;
				timeposition.Y = table->GetPositionFigure().Y;
	// ���� ���� ��������� �� ���� ��� ������� �����.
				if(table->GetCell(timeposition).first == 1) {

					table->GetFigure()->SelectElement(-90);
					figuremap = table->GetFigure() ->GetViewFigure(); // ����� �����


					for(auto it= figuremap.begin() ; it != figuremap.end(); ++it){
						if( it->second.first == 1){
							timeposition.X = table->GetPositionFigure().X + it->first.first;
							timeposition.Y = table->GetPositionFigure().Y;
							table->SetCell(timeposition, {1, it->second.second});

									}
							}

					return false;

			}
		}
	}


	return true;
}
