

#include <iostream>
using namespace std;

void func(int & a);

int main() {

	int a;
	func(a);

	cout << "value a = " << a << endl;

	return 0;
}

void func(int& a){
	int c = 888;
	a = c;
}
