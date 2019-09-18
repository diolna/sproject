#include "NYTypePizzaStore.h"
#include "Pizza.h"
#include <string>

using namespace std;


Pizza* NYTypePizzaStore::CreatePizza(string type) {

		if(type == "vegi")
			return  new NYStyleVegiPizza;
		else if(type == "cheese")
			return  new NYStyleCheesePizza;

		else return  new Pizza;


	}// createPizza(string type)

Pizza* NYTypePizzaStore::OrderPizza(string type) {

	return this->CreatePizza(type);


}



