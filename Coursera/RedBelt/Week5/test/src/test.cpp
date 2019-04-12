
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v = {2,3,4,5};

	vector<int>::iterator first = v.begin();
	vector<int>::iterator last = v.end();

	cout << "first = " << *first << endl;
	*first = v[4];
	cout << "first = " << *first << endl;
	size_t i = 1;
	cout << "v[" << i <<"]=" << v[1] << endl;

	cout << 6%4 << endl;

	return 0;
}
