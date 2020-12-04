#include "worker.h"

Worker:: ~Worker() {}


void Worker::Data() const {
	std::cout << "Name: " << fullname << "\n";
	std::cout << "Employee ID: " << id << "\n";
}

void Worker::Get() {

		std::cin>> fullname;
		std::cout << "Enters Worker ID: ";
		std::cin >> id;
		while(std::cin.get() != '\n') continue;
}
