#pragma once

#include "PizzaStore.h"
#include <string>
#include "NYStyleVegiPizza.h"
#include "NYStyleCheesePizza.h"
#include "Pizza.h"


using namespace std;


class NYTypePizzaStore: public PizzaStore {

public:
	Pizza* CreatePizza(string type);
	Pizza* OrderPizza(string type);

}; // NYTypePizzaStore


