
#include <iostream>
#include <cstdint>
using namespace std;




int main() {


	std::uint8_t c = 0b00000100;
	std::uint8_t a;
	a = 23;
	std::cout << a << std::endl;
	std::cout << !a << std::endl;

	if(!(c & (1 << 7)) == true) std::cout << "true ";
	else
		std::cout << "false";




	return 0;
}
