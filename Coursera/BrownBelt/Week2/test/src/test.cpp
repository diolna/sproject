
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	stringstream is("aaaaaa bbbbb ccccc");
	char a;
	is>>a;
	cout << a << endl;
	is>>a;
	cout << a << endl;
	return 0;
}
