#include <iostream>
#include <map>
#include <string>
#include <exception>

using namespace std;

template <typename Key, typename Value> Value& GetRefStrict(const map<Key, Value>& ma, const Key& k);


template <typename Key, typename Value>
  Value& GetRefStrict(  map<Key, Value>& ma, Key k){


		if(ma.count(k)==0){
			throw runtime_error("key not found");
		}else{

	return ma.at(k);
		}
}



int main() {

	map<int, string> m = {{0, "value"}};

	string& item =  GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // ������� newvalue


	return 0;
}
