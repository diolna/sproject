#include "PepsiFactory.h"
#include "PepsiWater.h"
#include "PepsiBottle.h"

#include <iostream>

using namespace std;

AbstractWater* PepsiFactory::CreatWater() {

		return new PepsiWater;
}

AbstractBottle* PepsiFactory::CreatBottle() {

		return new PepsiBottle;
}
