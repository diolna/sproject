#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

//#include "stdafx.h"
#include "date.h"








Date::Date(int y, int m, int d) :
	year(y), month(m), day(d) {}



int Date::GetYear()const  { return year; }
 int Date::GetMonth() const { return month; }
int Date::GetDay() const { return day; }

Date ParseDate(istream& is) {
	 try {
	        int y, m, d;
	        if (!(is >> y)) {
	            throw exception();
	        }

	        if (is.peek() != '-') {
	            throw exception();
	        } else {
	            is.ignore(1);
	        }

	        if (!(is >> m)) {
	            throw exception();
	        }

	        if (is.peek() != '-') {
	            throw exception();
	        } else {
	            is.ignore(1);
	        }

	        if (!(is >> d)) {
	            throw exception();
	        }

	        return {y, m, d};
	    } catch (exception& e) {
	        throw runtime_error("Wrong date format");
	    }
}
/*
	//char d2, d1;


	int year,month,day;

	if (input.eof()) {
		throw invalid_argument("augument not correct");
	}

	input >> year;
	if (input.peek() != '-') {
		throw invalid_argument("Wrong date format:");
	}
	input.ignore(1);
	input >> month;
	if (month > 12 || month <= 0) {
		throw invalid_argument("Month value is invalid: ");
	}
	if (input.peek() != '-') {
		throw invalid_argument("Wrong date format:");
	}
	input.ignore(1);
	input >> day;
	if (day > 31 || day <= 0) {
		throw invalid_argument("Day value is invalid: ");

	}

	Date date(year,month,day);
	//cout << "date parse " << date.GetMonth() << endl;
	return date;
}
*/

//ostream& operator<<(ostream& os, const Date date){
//	os<< setfill('0') << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth() <<
//					"-" << setw(2) << date.GetDay();
//
//	return os;
//}
ostream& operator<<(ostream& os, const Date date){
	os<< setfill('0') << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth() <<
					"-" << setw(2) << date.GetDay();

	return os;
}
ostream& operator<<(ostream& os, const pair<Date, string>& p){
	os << p.first << " " << p.second;
	return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) {
		return lhs.GetYear() < rhs.GetYear();
	}
	else if (lhs.GetMonth() != rhs.GetMonth()) {
		return lhs.GetMonth() < rhs.GetMonth();
	}
	else if (lhs.GetDay() != rhs.GetDay()) {
		return lhs.GetDay() < rhs.GetDay();
	}
	//cout << "operator<" << endl;
	return false;
}


bool operator==(const Date& lhs, const Date& rhs) {
	//cout << "== date";A
	   return (lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth()) &&
		(lhs.GetDay() == rhs.GetDay());

	}

bool operator!=(const Date& lhs, const Date& rhs) {
    if(lhs == rhs) {
        return false;
    } else {
        return true;
    }

}
    bool operator<=(const Date& lhs, const Date& rhs) {
        if(lhs < rhs || lhs == rhs) {
            return true;
        } else {
            return false;
        }
    }
    bool operator>(const Date& lhs, const Date& rhs) {
        if(lhs.GetYear() > rhs.GetYear()) {
            return  true;
        } else if (lhs.GetYear() == rhs.GetYear()) {
            if(lhs.GetMonth() > rhs.GetMonth()) {
                return  true;
            } else if (lhs.GetMonth() == rhs.GetMonth()) {
                if (lhs.GetDay() > rhs.GetDay()) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return  false;
        }
    }
    bool operator>=(const Date& lhs, const Date& rhs) {
        if(lhs > rhs || lhs == rhs) {
            return true;
        } else {
            return false;
        }
    }
