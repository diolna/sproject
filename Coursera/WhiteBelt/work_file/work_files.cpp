


#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void PrintFile(const string& path) {
	string line;
	ifstream input(path);
	if (input.is_open()) {
		while (getline(input, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "Error" << endl;
	}
}


int main()
{
	PrintFile("input.txt");



    return 0;
}

