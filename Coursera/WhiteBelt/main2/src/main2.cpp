#include <iostream>
using namespace std;

int main() {

	int a, b, n;
	n = 0;
	cin >> a >> b;
	//a = 0;
	//b = 0;
	int max = 2147483647;
	if(a > b){
		n = b;
	}else if( a<b){
		n = a;
	}else if(a==b){
		n = a;
	}

	for(int i = n; i>=0; --i ){
		if(a==0 && b==0) {
				cout << max ;
				break;
			}
		else if(a%i==0 && b%i==0) {
			cout << i;
			break;
		}
	}


	return 0;
}
