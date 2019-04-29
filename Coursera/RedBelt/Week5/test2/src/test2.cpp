#include "test_runner.h"

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <numeric>
#include <future>

using namespace std;

struct S{
	int a;
	int&& b;
};

S Func(){
	S s;
	s.b = 3;
	s.a = 2;
	return s;

}



int main() {

	S aaa;
	aaa.a = 25;

int c = 2;
int& d = c;
int&& a = move(d);

int b = 5;
cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
 cout << Func().a << endl;

cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
b =0;
cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;;
c = 0;
cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;



  return 0;
}
