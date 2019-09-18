#include <iostream>
#include "Client.h"
#include "AbstractWater.h"
#include "AbstractBottle.h"
#include "AbstractFactory.h"
#include "CocaColaFactory.h"
#include "PepsiFactory.h"

using namespace std;

void Client::CreatProduct() {

bottle->Interact(*water);

}

Client::Client(AbstractFactory& factory) {

	water =factory.CreatWater();
	bottle = factory.CreatBottle();

}



