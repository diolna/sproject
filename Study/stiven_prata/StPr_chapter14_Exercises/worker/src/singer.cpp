#include "Singer.h"

char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "sorpano", "bass", "baritone", "tenor"};

void Singer::Set() {
	std::cout << "Enter Singer name";
	Worker::Get();
	Get();

}

void Singer::Get() {
	std::cout << "Enter number for singer`s vocal range:\n";
		int i;
		for(i=0; i < Vtypes; i++){
			std::cout << i << ": " << pv[i] << " ";
					if(i%4 == 3){
						std::cout << '\n';
					}
		}
		std::cin >> voice;
					while(std::cin.get() != '\n') continue;
}

void Singer::Show() const {
	std::cout << "Category singer\n";
	Data();
	Worker::Data();

}

void Singer::Data() const {
	std::cout << "Vocal range; " << pv[voice] << "\n";
}
