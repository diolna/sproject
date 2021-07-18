#include "SingingWaiter.h"

void SingingWaiter::Data() const {
	Singer::Data();
	Waiter::Data();
}
void SingingWaiter::Get() {
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set() {
	std::cout << "Enter singing waiter`s name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const {
	Worker::Data();
	Data();
}
