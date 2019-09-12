
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
#include <map>


using namespace std;

struct Lang {
	string name;
	int age;
};

using LangIt = vector<string>:: iterator;
template <typename It>
void PrintRange(It range_begin, It range_end){
	for(auto it= range_begin; it!=range_end; ++it){

	cout << *it << " ";

}
}

int main() {


	set<string> langs_ ={"Pyton", "C++", "C", "Java", "C#"};

		//string& res1 = *result2;
		//res1 = "D++";
		//cout << *result2 << endl;

		PrintRange(begin(langs_), end(langs_));
		cout << endl;
		//PrintRange(begin(langs_[0]), end(langs_[0]));
		auto it1 = langs_.find("C++");
		PrintRange(begin(langs_), it1);
		cout << endl;

	vector<Lang> langss ={
				{"Pyton", 26},
				{"C++", 34},
				{"C", 45},
				{"Java", 22},
				{"C#", 17}};


auto result1 =	find_if(
			begin(langss), end(langss), [](const Lang& lang){
		return lang.name[0]== 'D';
	});

string lang_ = langss[1].name;
auto it = begin(lang_);
cout << *it;
++it;
cout << *it << endl;

for(auto it= begin(langss); it!=end(langss); ++it){

	cout << it->name << " ";

}
cout << endl;




if(result1== end(langss)){
	cout << "Not found" << endl;
}else {

	cout << result1->age << endl;

}
cout << begin(langss)->name << endl << begin(langss)->age << endl;
	vector<string> langs ={"Pyton", "C++", "C", "Java", "C#"};
auto result =	find_if(
			begin(langs), end(langs), [](const string& lang){
		return lang[0]== 'C';
	});
	string& res = *result;
	res = "D++";
	cout << *result << endl;

	PrintRange(begin(langs), end(langs));
	PrintRange(begin(langs[0]), end(langs[0]));

	return 0;
}


