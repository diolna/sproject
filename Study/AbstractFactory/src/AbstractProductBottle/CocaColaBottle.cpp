#include <iostream>
#include "CocaColaBottle.h"

using namespace std;

void CocaColaBottle::Interact(AbstractWater& water){

	cout << "In Bottle CocaCola include ";
	water.Display();
	cout << endl;
}




