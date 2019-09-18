#pragma once

#include "Pizza.h"



class ChikagoStyleCheesePizza: public Pizza {

private:

	string name;
	string dough;
	string sauce;
public:
	ChikagoStyleCheesePizza();
	string GetName() {return name;};
	void Prepare() { cout << " prepair Cheese - "; };
};
