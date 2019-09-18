#pragma once

#include "AbstractWater.h"
#include "AbstractBottle.h"
#include "AbstractFactory.h"


using namespace std;

class Client {
public:

	Client(AbstractFactory& factory);
	void CreatProduct();

private:
	AbstractWater* water;
	AbstractBottle* bottle;

};
