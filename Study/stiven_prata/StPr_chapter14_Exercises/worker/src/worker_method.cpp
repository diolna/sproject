#include "worker.h"

Worker:: ~Worker() {}

void Worker::Set(){
	std::cout << "Enter worker`s name: ";
	std::cin>> fullname;
	std::cout << "Enters Worker ID: ";
	std::cin >> id;
	while(std::cin.get() != "\n") continue;
}

void Worker::Show() const {
	std::cout << "Name: " << fullname << "\n";
	std::cout << "Employee ID: " << id << "\n";


}
