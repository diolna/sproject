#include "stack.h"
#include "String.h"
using namespace std;

int main() {


	Stack<String> st;
	char c;
	String po;
	cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	while(cin >> c && toupper(c) != 'Q'){
		while(cin.get() != '\n') continue;
		if(!isalpha(c)){
			cout << '\a';
			continue;
		}
		switch (c){
		case 'A':
		case 'a': cout << "Enter a PO number to add: ";
				 cin >> po;
				 if(st.isfull())
					 cout << "stack already full\n";
				 else
					 st.push(po);
				 break;
		case 'P':
		case 'p': if(st.isempty())
						cout << "stack alraady empty\n";
		else	{
			st.pop(po);
			cout << "PO# " << po << " popped\n";
			break;
		}
		}
		cout << "please enter A to add a purchase order,\n"
				<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}
