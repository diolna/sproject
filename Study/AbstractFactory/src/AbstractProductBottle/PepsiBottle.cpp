#include <iostream>
#include "PepsiBottle.h"

using namespace std;

void PepsiBottle::Interact(AbstractWater& water){

	cout << "In Bottle Pepsi include ";
	water.Display();
	cout << endl;
}




