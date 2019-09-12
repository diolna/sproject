#include <iostream>

using namespace std;

int main() {
	int a=1;
	int b=10;
	//cin >> a >> b;
	do{
		if(a % 2 == 0){
			cout << a << " ";
		}
	 ++a;
	} while(a!=(b+1));

	return 0;
}
