#include "Singer.h"

char * Singer::pv[] = {"other", "alto", "contralto", "sorpano", "bass", "baritone", "tenor"};

void Singer::Set() {
	std::cout << "Enter number for singer`s vocal range:\n";
	int i;
	for(i=0; i < Vtypes; i++){
		std::cout << i << ": " << pv[i] << " ";
				if(i%4 !=0)
					std::cout << '\n';
		std::cin >> voice;
		while(std::cin.get() != '\n') continue;

	}
}

void Singer::Show() const {
	std::cout << "Category singer\n";
	Worker::Show();
	std::cout << "Vocal range; " << pv[voice] << "\n";
}
