#pragma once
#include <iostream>
#include "AbstractBottle.h"
#include "AbstractWater.h"

using namespace std;


class AbstractFactory {
public:
	virtual AbstractWater* CreatWater() = 0;
	virtual AbstractBottle* CreatBottle() = 0;

};
