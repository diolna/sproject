#pragma once
#include "AbstractBottle.h"
#include "AbstractWater.h"

using namespace std;


class CocaColaBottle : public AbstractBottle {

public:

	void Interact(AbstractWater& water);

};
