
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

void PrintSet(const set<string>& f){
		for(auto x:f){
			cout << x << endl;
		}
}

int main() {

	set<string> famous_persons;
	famous_persons.insert("Stroustrup");
	famous_persons.insert("Ritchie");
	PrintSet(famous_persons);


	return 0;
}
