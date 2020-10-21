

#include <iostream>
#include "port.h"


int main() {

	Port p;
	p.Show();
	Port b("Visky", "malina", 3);
	b.Show();
	b += 25;
	std::cout << std::endl;
	b.Show();
	p = b;
	p.Show();
	VintagePort c("aaa", 22, "ccc", 1877);
	c.Show();
	Port* point = &c;
	std::cout << "point 1: " << std::endl;
	point->Show();
	point = &b;
	std::cout << "point 2: " << std::endl;
	point ->Show();



	return 0;
}
