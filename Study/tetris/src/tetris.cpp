#include "Figure.h"
#include "FigureSquare.h"
#include "GameTable.h"
#include "Line.h"
#include <string>
#include "Remote.h"
#include "Meander.h"
#include "CurvedLine.h"
#include "Piramida.h"

#include <iostream>
#include <string>

int GetRandomNumber(int min, int max);

using namespace std;

int main() {



GameTable* tab = new GameTable;
Figure* square = new FigureSquare;
Figure* line = new Line(0);
Figure* meander = new Meander(0);
Figure* curvedline = new CurvedLine(0);
Figure* piramida = new Piramida(0);
Remote* remote = new Remote(tab);

for(int i = 1; i<100; i++){
	switch (GetRandomNumber(1,5)){
	case 1:
		*tab = *tab + *square;
		remote->Start();
		break;
	case 2:
		*tab = *tab + *meander;
		remote->Start();
		break;
	case 3:
		*tab = *tab + *curvedline;
		remote->Start();
		break;
	case 4:
		*tab = *tab + *line;
		remote->Start();
		break;
	case 5:
		*tab = *tab + *piramida;
		remote->Start();
		break;
			}

}

//*tab = *tab + *square;
//for(int i = 0; i < 10; ++i){
//remote->Start();
//}
//
////cout << "new figure " << endl;
//*tab = *tab + *line;
//for(int i = 0; i < 8; ++i){
//remote->Start();
//}
//
//*tab = *tab + *meander;
//remote->Start();
//remote->Start();
//remote->Start();
//
//for(int i = 0; i < 5; ++i){
//*tab = *tab + *curvedline;
//remote->Start();
//}
//
//for(int i = 0; i < 5; ++i){
//*tab = *tab + *piramida;
//remote->Start();
//}
//
//
////while(tabRemote->Start()){}


	return 0;
}


int GetRandomNumber(int min, int max){

	 static const double fraction = 1/ (static_cast<double>(RAND_MAX) +1);
	return static_cast<int>(rand()*fraction*(max - min +1)+ min);
}



