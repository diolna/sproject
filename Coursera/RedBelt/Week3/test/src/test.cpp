
#include <iostream>
#include <set>

using namespace std;

int main() {
	int x =33;
	int y = 44;
	int *z = &x;
	cout << *z << endl;

	int *zz = &y;
	*z= * zz;
	cout << *z << endl;



	return 0;
}
