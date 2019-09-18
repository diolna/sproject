#pragma once


#include "Pizza.h"



class NYStyleVegiPizza: public Pizza {

private:

	string name;
	string dough;
	string sauce;
public:
	NYStyleVegiPizza();
	string GetName() {return name;};
	void Prepare() { cout << " prepair - "; };
};


