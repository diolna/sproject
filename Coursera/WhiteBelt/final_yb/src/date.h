#pragma once

#include <sstream>
#include <vector>

using namespace std;


struct Date {

	Date(){};
	Date(const vector<int> d) : date(d) {}
	Date(int, int, int) {}


vector<int> date = { year, month, day };
	int year;
	int month;
	int day;

};
