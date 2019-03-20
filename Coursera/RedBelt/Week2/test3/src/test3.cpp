#include <iostream>
#include <vector>
#include <string>
#include <chrono>


using namespace std;
using namespace std::chrono;

vector<string> func(){
	vector<string> result;
	for(int i=0; i<28000; ++i){
		result.insert(begin(result), to_string(i));
	}
	return result;
}

int main() {
	auto start = steady_clock::now();

	cout << func().size() << endl;
	auto finish = steady_clock::now();
	cout <<  duration_cast<milliseconds>(finish-start).count() << endl;
	return 0;
}
