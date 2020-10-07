
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

	Stack aaa(4);

    unsigned long ccc;

	cout << "push " << aaa.push(111) << endl;
	cout << "push " << aaa.push(222) << endl;
	cout << "push " << aaa.push(333) << endl;
	cout << "push " << aaa.push(444) << endl;
	aaa.pop(ccc);
	cout << "pop" << ccc << endl;
	aaa.pop(ccc);
	cout << "pop" << ccc << endl;

	Stack bbb;
	bbb = aaa;

  bbb.pop(ccc);
//	aaa.pop(ccc);
	cout << "pop" << ccc << endl;

	return 0;
}
