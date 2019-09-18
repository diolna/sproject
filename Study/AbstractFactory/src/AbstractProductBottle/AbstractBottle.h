#pragma once
#include <iostream>
#include "AbstractWater.h"

using namespace std;

class AbstractBottle {
public:

	virtual void Interact(AbstractWater& water) =0;
};
