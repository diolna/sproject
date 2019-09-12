#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
int e;
	double x1= (-b+sqrt(b*b - 4*a*c))/2*a;
	double x2=(-b-sqrt(b*b - 4*a*c))/2*a;
	cout << x1;
	cout << x2;


	return 0;
}
