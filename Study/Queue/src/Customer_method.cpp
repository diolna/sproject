#include <iostream>
#include "Customer.h"

void Customer::set(long when){
	processtime = rand()%3+1;
	arrive = when;
}
