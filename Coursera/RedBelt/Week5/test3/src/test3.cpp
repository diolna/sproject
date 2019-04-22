
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
template <typename String>
bool FindChar(String& a, String& b){
	sort(b.begin(), b.end());
	cout << b << endl;

	for(auto& it_char : a) {
//			auto it1 = std::find(b.begin(), b.end(), it_char);
			auto it1 = std::lower_bound(b.begin(), b.end(), it_char);



			if( *it1 != it_char){
				return true;
			}

	}
		return false;
}

template <typename String>
String ComputeStringKey(const String& string) {
  String chars = string;
  sort(begin(chars), end(chars));
  chars.erase(unique(begin(chars), end(chars)), end(chars));
  return chars;
}


int main() {

	string a = "bcafdrdfdfcccc";
	string b = "racbffd";
	cout << FindChar(a, b) << endl;
	cout << ComputeStringKey(a) << endl;


	return 0;
}
