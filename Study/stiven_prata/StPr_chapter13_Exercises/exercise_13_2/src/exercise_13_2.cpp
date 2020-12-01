

#include <iostream>
#include "cd.h"

void Bravo(const Cd& disk);

int main() {

	Cd c1("Beatles", "Capitol", 14, 13.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips",
			2, 57.17);
	Cd* pcd = &c1;
	std::cout << "Using object directly:\n";
	c1.Report();
	c2.Report();
	std::cout << "Using type cd* pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	std::cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	std::cout << "Testing assigment: ";
	Classic copy;
	copy = c2;
	copy.Report();


	return 0;
}

void Bravo(const Cd& disk){
	disk.Report();
}