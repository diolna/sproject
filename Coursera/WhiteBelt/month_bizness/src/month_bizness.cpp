#include <vector>
#include <iostream>
#include <string>

using namespace std;

void Next(vector<string>& month,  vector<int>& year) {
	int i = 1;
	while (i != year[0]){
		++i;
	}
	if (i >= 12) {
		i = 1;
		year[0] = i;   // change month
	}
	else {
		++i;
		year[0] = i;  // change month
	}
	if (year[year[0]] >= month.size()) {
		month.resize(year[year[0]]);  // change length month if it is more then the previos
	}else{
		string temp;
		for (int n =  month.size()- year[year[0]]; n > 0; --n) {
			temp += month[month.size()-n];
		}
		month.resize(year[year[0]]);
		month[month.size()-1] += temp;
	}
}

void Add(vector<string>& month, string& name_for_todo_list, const int& day) {
	month[day-1] += name_for_todo_list;
	month[day-1] += " ";   // space for counting words

}
void Dump(const vector<string> month, const int& day, vector<string>& print) {
	print.push_back(month[day-1]);
}

void PrintResult(const vector<string>& print){
	int number = 0;
	for (auto n : print) {
		string temp;
		int index = 0;
		for (auto i : print[number]) {
			if (i != ' ') {
				temp += i;
			}
			else {
				++index;
				temp += ' ';
			}
		}
		cout << index << " " << temp << endl;
		temp.clear();
		++number;
	}
}

int main() {
	int num, day;
	string operation_code;
	string name_for_todo_list;
	vector<string> month, print;
	vector<int> year = { 1,31,28,31,30,31,30,31,31,30,31,30,31 }; // Gregorian calendar 0-include number for month

	month.assign(31, "");
	day = 0;

	cin >> num;
	while (num != 0){
		--num;
		cin >> operation_code;
		if (operation_code == "ADD") {
			cin >> day;
			cin >> name_for_todo_list;
			Add(month, name_for_todo_list, day);
		}
		else {
			if (operation_code == "NEXT") {
				Next(month, year);
			}
			else {
				if (operation_code == "DUMP") {
					cin >> day;
					Dump(month, day, print);
				}
			}
		}
	}
	PrintResult(print);
	return 0;
}
