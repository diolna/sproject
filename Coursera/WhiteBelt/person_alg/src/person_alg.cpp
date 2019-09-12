#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>


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

	 string GetFullNameWithHistory(int year) {
	    // получить все имена и фамилии по состоянию на конец года year
		 string temp;
		 vector<string> v_temp, v_temp1;
		 for(auto i: f_name){
			 if(i.first<=year){
				 v_temp.push_back(i.second);
			 }else{
				 break;
			 }
		 }
		 for(auto i: l_name){
		 			 if(i.first<=year){
		 				 v_temp1.push_back(i.second);
		 				 v_temp1.push_back(" ");
		 			 }else{
		 				 break;
		 			 }
		 		 }
		 int i;
		 string out_f="";
		 for(i=v_temp.size()-1; i <=0; --i){
			 out_f = out_f + v_temp[i];

		 }
	 return out_f;
	 }




	string GetFullName(int year) {

			string p1 = Find(f_name, year);
			string p2 = Find(l_name, year);

				//cout << "f_name = " << p1 << "l_name = " << p2 << endl;

				if (p1.empty() && p2.empty()) {
					return "Incognito";
				}else if (p1.empty()) {
					return p2 + " with unknown first name";
					} else
						if (p2.empty()) {
							return p1 + " with unknown last name";
						}
						else {
							return p1 + " " + p2;
						}





	}
private:

	map<int, string> f_name;
	map<int, string> l_name;

	string Find(const map<int, string>& names, int year) {
		auto iter_after = names.upper_bound(year);
		string name;
		if (iter_after != names.begin()) {
			name = (--iter_after)->second;
		}
		return name;
	}

};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
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
