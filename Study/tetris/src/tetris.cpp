#include "Figure.h"
#include "FigureSquare.h"
#include "GameTable.h"
#include "Line.h"
#include <string>
#include "Remote.h"
#include "Meander.h"
#include "CurvedLine.h"

#include <iostream>
#include <string>

using namespace std;

int main() {



GameTable* tab = new GameTable;
Figure* f = new FigureSquare;
Figure* f2 = new Line;
Figure* meander = new Meander;
Figure* curvedline = new CurvedLine;
Remote* remote = new Remote(tab);


*tab = *tab + *f;
remote->Start();

cout << "new figure " << endl;
*tab = *tab + *f2;
remote->Start();

*tab = *tab + *meander;
remote->Start();

*tab = *tab + *curvedline;
remote->Start();


//while(tabRemote->Start()){}
int x;
cin >> x;


	return 0;
}




