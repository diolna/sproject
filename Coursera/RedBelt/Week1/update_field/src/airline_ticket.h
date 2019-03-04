#pragma once

#include <string>
using namespace std;

struct Date {
  int year, month, day;

  Date& operator=(const Date & rhs){

  	this->year=rhs.year;
  	this->month= rhs.month;
  	this->day= rhs.day;
  	return *this;
  }
};

struct Time {
  int hours, minutes;
};

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  int price;
};
