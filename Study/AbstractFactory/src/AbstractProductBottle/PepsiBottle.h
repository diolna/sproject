#pragma once
#include "AbstractBottle.h"
#include "AbstractWater.h"

using namespace std;


class PepsiBottle : public AbstractBottle {

public:
	void CreateBottle();
	void Interact(AbstractWater& water);

};
