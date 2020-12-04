
#include <iostream>
#include "Worker.h"
#include "Waiter.h"
#include "Singer.h"
#include "SingingWaiter.h"
#include <cstring>

using namespace std;

const int SIZE = 5;

int main() {

	Worker* lolas[SIZE];
	int ct;
	for(ct =0; ct < SIZE; ct++){
		char choise;
		cout << "Enter the employee category:\n" <<
				"w: Waiter   s: Singer t: SingerWaiter q: Quit\n";
		cin >> choise;
		while(strchr("ewstq", choise) ==  NULL ){
			cout << "Please enter a w s t or q: ";
			cin >> choise;
		}
		if(choise == 'q')
			break;
		switch(choise){
		case 'w' : lolas[ct] = new Waiter;
			break;
		case 's' : lolas[ct] = new Singer;
			break;
		case 't' : lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct] ->Set();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for(i =0 ; i < ct; i++){
		cout << '\n';
		lolas[i] ->Show();
	}
	for(i = 0; i < ct; i++ ){
		delete lolas[i];
	}

	return 0;
}
