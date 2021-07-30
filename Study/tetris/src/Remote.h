#pragma once

#include <iostream>
#include "GameTable.h"
#include <windows.h>

using namespace std;

class Remote   {

public:

	//Remote(){};
	Remote(GameTable* tab) : table(tab){};
	bool Left();
	bool Right();
	bool Down();
	bool Start(); // двигает и рисует фигуры
	bool Rotation();
	void ShowObject();



private:

	GameTable* table;
	COORD position;

};
