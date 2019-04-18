
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


template <typename String>

bool Cmp(String s){
	auto it = find(s.begin(), s.end(), 'a');
	if(it== s.end()) return false;
	else return true;
}

int main() {

	vector<string> vec ={ "dfdfdfdfdf" , "df", "abc", "cba" , "cbaa", "abca","abcd" };

	sort(vec.begin(), vec.end(),
			[](const string& a, const string& b){return a.size()> b.size();}
	);
	for(auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;


	return 0;
}
