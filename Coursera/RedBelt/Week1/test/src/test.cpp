
#include <ostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;




int main() {

	ostringstream os;
	os<<"aaa";
	ostringstream ss;


	[](ostream& s ){s << 2 << '\n';
		s << 3 << '\n';
	}(os);

	//f(os);

	cout << os.str();

	return 0;
}
