
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	set<pair<int, string>> aaa;
	int x;
	string y;
	for(int i = 0; i< 6; ++i){
		cin >> x >> y;
		aaa.insert({x,y});

	}
	for(auto i: aaa){
		cout << "first pair =" << i.first << "second pair = " << i.second << endl;

	}

	return 0;
}
