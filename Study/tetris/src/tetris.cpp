#include "Figure.h"
#include "FigureSquare.h"
#include "GameTable.h"
#include "Line.h"
#include <string>
#include "Remote.h"

#include <iostream>
#include <string>

using namespace std;

int main() {



GameTable* tab = new GameTable;
Figure* f = new FigureSquare;
Figure* f2 = new Line;
Remote* remote = new Remote(tab);


*tab = *tab + *f;
remote->Start();
//
//cout << "  ";
//*tab = *tab + *f2;
//
//remote -> ShowObject();
//
//cout << endl;



//while(tabRemote->Start()){}
int x;
cin >> x;


	return 0;
}




