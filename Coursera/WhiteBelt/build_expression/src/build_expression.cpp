#include <iostream>
#include <string>
#include <deque>

using namespace std;


int main() {
	deque<string> expression;
	int x = 0, n=0;  // value and number operation;
	string o, o1;	// operation;

	cin >> x >> n;
	if (n == 0) {

		cout << x;
		return 0;
	}
	string value = to_string(x);
	string first_sk = "(";
	string last_sk = ")";
	expression.push_back(value);
	while (n != 0) {
		cin >> o >> o1;
		expression.push_front(first_sk);
		expression.push_back(last_sk);
		expression.push_back(" ");
		expression.push_back(o);
		expression.push_back(" ");
		expression.push_back(o1);

		--n;
	}
	for(auto i=0; i<=expression.size()-1; ++i){
	cout << expression[i];
	}

	return 0;
}
