#pragma once

#include "Pizza.h"



class ChikagoStyleVegiPizza: public Pizza {

private:

	string name;
	string dough;
	string sauce;
public:
	ChikagoStyleVegiPizza();
	string GetName() {return name;};
	void Prepare() { cout << " prepair Chikago - "; };
};
