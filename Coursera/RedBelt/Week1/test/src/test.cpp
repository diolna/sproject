
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Date {
  int year, month, day;
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



template <class It, class Func>
void sort1(It b,It c, Func f){
	//f();
}



int main() {


//int x=5;
AirlineTicket aaa;

	vector<AirlineTicket> tixs = {
	    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
	    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
	    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
	    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
	    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
	  };

	vector<int> fff= {2, 4,5,5};

	//auto n = tixs.begin();

	sort1( fff.begin(), fff.end(), [](){return 0;});
	return 0;
}
