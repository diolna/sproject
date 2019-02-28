
#include <iostream>
using namespace std;

int main() {

	auto IsEven = [](int x) {
	    return x % 2 == 0;
	  };
	cout << IsEven(5) << endl;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
