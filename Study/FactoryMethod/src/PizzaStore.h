#pragma once

#include "Pizza.h"
#include <iostream>
#include <string>

using namespace std;



// fabrica
class PizzaStore {

public:

	 virtual Pizza* OrderPizza(string) = 0;
	 virtual Pizza*  CreatePizza(string) = 0;



};



