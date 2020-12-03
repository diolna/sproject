#include "Waiter.h"

void Waiter::Set(){
	Worker::Set();
	std::cout << "Enter waiter`s panache rating: ";
	std::cin >> panache;
	while(std::cin.get() != '\n') continue;
}

void Waiter::Show() const {
	std::cout << "Category: waiter\n";
	Worker::Show();
	std::cout << "Panache rating: " << panache << "\n";
}
