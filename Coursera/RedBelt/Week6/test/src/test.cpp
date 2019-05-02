
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	vector<int> v(10);

	//iota(v.begin(), v.end(), 0);

	++v[1];
	for(auto& i: v){
			cout << i << " ";
		}

	return 0;
}
