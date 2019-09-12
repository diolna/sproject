#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	const string path = "input.txt";
	ifstream input(path);
	int N, M, values;
	input >> N;
	input >> M;
	for (int  n= 0; n <= N-1; ++n) {
		for (int m =0 ; m <= M-1; ++m) {
			input >> values;
			input.ignore();
			cout  << setw(10) <<  values;
			if (m != M - 1) { cout << " "; }
		}
		cout << endl;
	}
    return 0;
}