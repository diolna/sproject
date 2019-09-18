#pragma once

#include "Pizza.h"

class NYStyleCheesePizza : public Pizza {
private:
	string name;
public:
	NYStyleCheesePizza() {name = "NYStyleCheesePizza"; };
    string GetName() {return name;};
    void Prepare() { cout << "prepair - "; };
};
