

#include <iostream>
#include "Client.h"
#include "CocaColaFactory.h"
#include "PepsiFactory.h"

using namespace std;

int main() {
	cout << "Abstract Factory" << endl; // prints !!!Hello World!!!


	//AbstractFactory *factory1 = new CocaColaFactory;
	Client *c1 = new Client( *new CocaColaFactory);
	Client *c2 = new Client(*new PepsiFactory);

	c1->CreatProduct();
	c2->CreatProduct();

	cout << " and and and" << endl;

	PepsiFactory factoryPepsiOdessa;
	Client client3(factoryPepsiOdessa);
	client3.CreatProduct();

	Client * client4 = new Client(*new PepsiFactory);










	return 0;
}
