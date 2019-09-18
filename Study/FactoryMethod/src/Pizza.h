#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Pizza {

public:
// не ялвяется абстрактнім классом а является некой базовой пиццей.
	virtual void Prepare(){} ;
	virtual string GetName(){return "basic pizza";};

};


