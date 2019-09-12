
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

struct FirstName {
	string value;
	explicit	FirstName(string new_value) {
		value = new_value;
	}
};
struct LastName {
	string value;
	explicit	LastName(string new_value) {
		value = new_value;
	}
};
struct Day {
	int value;
	explicit	Day(int new_value) {
		value = new_value;
	}
};
struct Month {
	int value;
	explicit	Month(int new_value) {
		value = new_value;
	}
};
struct Year {
	int value;
	explicit	Year(int new_value) {
		value = new_value;
	}
};

struct Student {
	string first_name;
	string  last_name;
	int day;
	int month;
	int year;

	Student(FirstName new_firstname, LastName new_lastname, Day new_day, Month new_month, Year new_year) {
		first_name = new_firstname.value;
		last_name = new_lastname.value;
		day = new_day.value;
		month = new_month.value;
		year = new_year.value;

	}

};
 


int main()
{
	int N;
	vector<Student> students;
	cin >> N;
	for (int i = 0; i <= N - 1; ++i) {
		string firstname, lastname;
		int day, month, year;
		cin >> firstname >> lastname >> day >> month >> year;
		Student student = { FirstName(firstname), LastName(lastname), Day(day), Month(month), Year(year) };
		students.push_back(student);
	}
	int M, K, number_students;
	string operation;
	cin >> M;
	//cout << students.size();
	for (int i = 0; i <= M - 1; ++i) {
		cin >> operation;
		cin >> K;
		if (K <= students.size() && K > 0) {
			if (operation == "name") {

				cout << students[K - 1].first_name << " " << students[K - 1].last_name << endl;
			}
			else if (operation == "date") {
				cout << students[K - 1].day << "." << students[K - 1].month << "." << students[K - 1].year << endl;
			}
			else {
				cout << "bad request" << endl;
			}
		}
		else
		{
			cout << "bad request" << endl;
		}
		
	}


	


    return 0;
}

