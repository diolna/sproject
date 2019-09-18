#pragma once
#include <iostream>

#include "AbstractFactory.h"

using namespace  std;

class PepsiFactory : public AbstractFactory {
public:
		AbstractWater* CreatWater();
		AbstractBottle* CreatBottle();
};
