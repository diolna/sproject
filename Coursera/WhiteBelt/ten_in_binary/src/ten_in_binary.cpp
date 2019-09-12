#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,x;
	vector<int> binary;
	cin >> n;
	do{
		if(n%2==0){
			x=0;
			binary.push_back(x);
		}else {
			x=1;
			binary.push_back(x);
		}
		n = n/2;
	}while(n!=0);
	for(int i=binary.size()- 1; i>=0; --i){
		cout << binary[i];
	}
	return 0;
}
