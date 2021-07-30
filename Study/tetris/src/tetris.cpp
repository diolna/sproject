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
Figure* square = new FigureSquare;
Figure* line = new Line;
Figure* meander = new Meander;
Figure* curvedline = new CurvedLine;
Remote* remote = new Remote(tab);


*tab = *tab + *square;
for(int i = 0; i < 10; ++i){
remote->Start();
}

//cout << "new figure " << endl;
*tab = *tab + *line;
for(int i = 0; i < 8; ++i){
remote->Start();
}

*tab = *tab + *meander;
remote->Start();
remote->Start();
remote->Start();

*tab = *tab + *curvedline;
remote->Start();


//while(tabRemote->Start()){}


	return 0;
}




