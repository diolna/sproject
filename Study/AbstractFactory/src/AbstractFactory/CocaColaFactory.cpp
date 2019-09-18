#include "CocaColaFactory.h"
#include "CocaColaWater.h"
#include "CocaColaBottle.h"

#include <iostream>

using namespace std;

AbstractWater* CocaColaFactory::CreatWater() {

		return new CocaColaWater;
}

AbstractBottle* CocaColaFactory::CreatBottle() {

		return new CocaColaBottle;
}
