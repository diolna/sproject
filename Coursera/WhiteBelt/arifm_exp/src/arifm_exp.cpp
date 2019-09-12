#include <iostream>
#include <string>

using namespace std;


int main(){
	string expression;
	int x, n;  // value and number operation;
	string o, o1;	// operation;
	if(n==0){

		cout << x;
		return 0;
	}
	cin >> x >> n;
	expression = to_string(x);
	string first_sk = "(";
	string last_sk = ")";
	while(n!=0){
		cin >> o >> o1;

		expression = first_sk + expression + last_sk + " " + o + " " + o1;

		--n;
	}

	cout << expression;



return 0;
}
