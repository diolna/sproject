//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int a = 28;
	int b = 3;
	cout << a%b << endl;

	map<int, int> m = {{1,2},{2,3},{4,5},{6,7},{7,8}};
	unordered_map<int, int> um = {{1,2},{2,3},{4,5},{6,7},{7,8}};
	auto itmap = m.begin();
	auto itumap = um.begin();
//	auto it = itmap +3;
	auto it2 = itumap + 3;


	return 0;
}
