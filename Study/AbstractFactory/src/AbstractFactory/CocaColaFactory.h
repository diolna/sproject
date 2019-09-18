#pragma once
#include <iostream>

#include "AbstractFactory.h"


using namespace std;

class CocaColaFactory : public AbstractFactory {
public:
	AbstractWater* CreatWater();
	AbstractBottle* CreatBottle();
};
