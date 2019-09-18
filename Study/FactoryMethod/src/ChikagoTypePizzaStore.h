#pragma once

#include <iostream>
#include <string>
#include "PizzaStore.h"

using namespace std;

class ChikagoTypePizzaStore : public PizzaStore {
public:
	Pizza* OrderPizza(string type);
	Pizza* CreatePizza(string type);

};
