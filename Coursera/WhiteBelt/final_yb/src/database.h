#pragma once

#include <string>
#include "date.h"
#include <map>
#include <set>
#include <functional>

using namespace std;


class Database {

public:
	void Add(const Date& d, const string& e);
	string Last(const vector<int>& data);  // argument parse data  type ?


	 int RemoveIf(function<void(const Date& d, const string &ev)>);


	vector<string> FindIf(function<void(const Date& d, const string &ev)>);

	void Print(const ostream& os);
	string& Last(Date& date);

private:

	map<Date, set<string>> base_;

};
