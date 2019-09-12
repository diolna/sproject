#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	const string path = "input.txt";
	ifstream input(path);
	if (input.is_open()) {
		double values;
		cout << fixed << setprecision(3);
		while (!input.eof()) {
			input >> values;
			cout << values << endl;
		}
			
	}
	else {
		cout << "Error" << endl;
	}
    return 0;
}

