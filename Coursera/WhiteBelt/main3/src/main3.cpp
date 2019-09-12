
#include <iostream>
using namespace std;

int main() {
	int a,b;
	int max =2147483647;
	cin>> a >> b;
	while(a>0 && b > 0){
		if(a>b){
			a=a%b;
		}else {
				b=b%a;
			}
		}

	if(a==0 && b==0){
	cout << max;
    }else {
	cout << a+b;
	}
	return 0;
}
