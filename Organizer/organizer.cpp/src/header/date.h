#pragma once

#include <iostream>

using namespace std;

class Date {
public:
	Date(int year, int month, int day);
	int& GetYear()  ;
	 int& GetMonth() ;
	 int& GetDay()  ;

private:
	int year_;
	int month_;
	int day_;

};

bool operator<( Date& lhs,  Date& rhs);
