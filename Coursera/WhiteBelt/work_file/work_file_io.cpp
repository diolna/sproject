

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;



void SaveFile(const string& path_in, const string& path_out) {
	string line;
	vector<string> file_data;
	ifstream input(path_in);
	if (input.is_open()) {
		while (getline(input, line)) {
			file_data.push_back(line);
		}
	}
	else {
		cout << "Error" << endl;
	}
	ofstream output(path_out);
	for (const auto& data : file_data) {
		output << data << endl;
	}
}


int main()
{
	
	SaveFile("input.txt", "output.txt");




	return 0;
}

