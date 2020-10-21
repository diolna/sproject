
#include <iostream>
#include "dma.h"


int main() {

	BaseDMA shirt("Portabelly", 8);
	LacksDMA balloon("red", "Blimbo", 4);
	HasDMA map("Mercator", "Buffalo Keys", 5);

	std::cout << shirt << std::endl;
	std::cout << balloon << std::endl;
	std::cout << map << std::endl;

	LacksDMA balloon2(balloon, "ddd");
//	HasDMA map2;
//	map2 = map;

	std::cout << balloon2 << std::endl;
//	std::cout << map2 << std::endl;

	return 0;
}
