
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

template <typename T>
void PrintSet(T& s){
	for(auto i: s){
		cout << "first " << i.first << " second " << i.second << endl;
	}

}


int main() {

	pair<int, int> p;
	set<pair<int, int>> s;

for(int i=0; i<4; ++i){
	s.insert({i,i+1});
}

PrintSet(s);
for(int i =0 ; i < 4; ++i){
	s.insert({i+1, i+1});
}
PrintSet(s);

	return 0;
}
