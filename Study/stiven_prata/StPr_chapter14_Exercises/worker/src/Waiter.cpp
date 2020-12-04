#include "Waiter.h"

void Waiter::Set(){
	std::cout << "Enter waiter`s name: ";
	Worker::Get();
	Get();

}

void Waiter::Show() const {
	std::cout << "Category: waiter\n";
	Worker::Data();
	Data();

}

void Waiter::Data() const {
	std::cout << "Panache rating: " << panache << "\n";
}

void Waiter::Get() {
	std::cout << "Enter waiter`s panache rating: ";
		std::cin >> panache;
		while(std::cin.get() != '\n') continue;
}
