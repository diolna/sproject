#include <iostream>






int main() {

	char aaa[20];
	int i =0;

	std::cin.get(aaa, 5);
	while(std::cin.get() != '\n'){
		i++;
		continue;
	}
	std::cout << "i = " << i << "\n";

	for(int i= 0; i < 5; i++){
	std::cout << "read from stream " << std::cin.get() << std::endl;
	}

	std::cout << "aaa[2]= " << aaa[2]<< std::endl;

	return 0;
}
