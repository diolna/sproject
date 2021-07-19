

#include <iostream>
using namespace std;



int main() {
	char temp[10];
     cin.get(temp, 5);
     for(int i=0; i <10; i++){
	cout << "enter symbol " << temp[i] << endl;
     }
     int i = 0;
     while(true && cin.get()!= '\n')
     cout << ++i << endl;


	return 0;
}

