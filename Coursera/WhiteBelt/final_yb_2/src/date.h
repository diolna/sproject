#pragma once
#include <vector>
#include <iostream>
using namespace std;




class Date {
public:

	Date(int y, int m, int d);

	int GetYear() const ;
	int GetMonth()const ;
	int GetDay() const ;


private:

	int year, month, day;

};

ostream& operator<<(ostream& os, const Date date);
ostream& operator<<(ostream& os, const pair<Date, string>& p);

bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);


Date ParseDate(istream& is);
//ostream& operator<<(ostream& os, const Date date);
