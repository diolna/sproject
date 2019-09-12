
#include <string>

#include <iostream>
#include <map>


using namespace std;



class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		f_name[year] = first_name;
		//cout << "add name in year " << year << " " << f_name[year] << endl;

	}
	void ChangeLastName(int year, const string& last_name) {
		l_name[year] = last_name;
		//cout << "add last name in year " << year << " " << l_name[year] << endl;
	}
	string GetFullName(int year) {

		string p1, p2;

		p1= GetLastName(year, f_name);
		p2= GetLastName(year, l_name);

		//cout << "f_name = " << p1 << "l_name = " << p2 << endl;

		if (p1 == "Incognito" && p2 == "Incognito") {
			return "Incognito";
		}else if (p1 == "Incognito" && p2 != "Incognito") {
			return p2 + " with unknown first name";
			} else
				if (p1 != "Incognito" && p2 == "Incognito") {
					return p1 + " with unknown last name";
				}
				else {
					return p1 + " " + p2;
				}

	}
private:

	map<int, string> f_name;
	map<int, string> l_name;

	string GetLastName(const int& y, const map<int, string>&  m) {

		if (m.size() == 0) { return "Incognito"; }
		if (m.begin()->first > y) {


			return "Incognito"; }

		string temp;
		for (const auto& i : m) {
			if (i.first <= y) { temp = i.second; }
		}
		//cout << temp << endl;
		return temp;



	}

};



int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		//cout << "input year = " << year << endl;
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}


	return 0;
}


