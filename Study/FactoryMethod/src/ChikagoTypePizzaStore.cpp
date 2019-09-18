#include "ChikagoTypePizzaStore.h"
#include "ChikagoStyleCheesePizza.h"
#include "ChikagoStyleVegiPizza.h"
#include "Pizza.h"

#include <iostream>

using namespace std;

Pizza* ChikagoTypePizzaStore::CreatePizza(string type){
		if(type == "vegi")
				return  new ChikagoStyleVegiPizza;
			else if(type == "cheese")
				return  new ChikagoStyleCheesePizza;

			else return  new Pizza;


		}// createPizza(string type)

	Pizza* ChikagoTypePizzaStore::OrderPizza(string type) {

		return this->CreatePizza(type);


	}
