#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double a, b, c;
	cin >> a >> b >> c;
	double d= pow(b,2) - 4 *a * c;
	if(a == 0){
		if(c==0) cout << 0;
		else if(b == 0){
			cout<< " ";
			return 0;
		}
		else cout << -c/b;
	}
	else if(b==0 && c==0) cout << 0;
	else if(d == 0) cout << - b /(2*a);
	else if(d < 0) cout << " ";
	else cout << (- b + sqrt(d)) / (2 * a) << " " << (- b -sqrt(d)) / (2 * a);
	return 0;
}




