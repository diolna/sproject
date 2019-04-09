#include <iostream>
#include <map>
#include <string>
#include <string_view>


using namespace std;

int main() {
	map<string_view, string_view> m={ {"dima", "olga"}, {"natasha", "andrusha"}, {"test", "test1"}};
	map<string_view, string_view> s = { {"dima1", "olga"}, {"natasha", "andrusha"}, {"test", "test1"}};
	//map<int, int> iii = { {1,3}, {2,3}, {4,6}};

	for (const auto* map_ptr : {&m, &s}){
		auto it = map_ptr->find("dima");
		if(it== map_ptr->end()){cout << "not" << endl;}else{
		cout << it->first << endl;
	}

	}
	return 0;
}
