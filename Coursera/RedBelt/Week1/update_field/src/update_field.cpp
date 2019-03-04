#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;


#define UPDATE_FIELD(ticket, field, values)    						\
																	\
																	\
			if(values.find(#field)!=values.end()){					\
				istringstream is(values.find(#field)->second);		\
				is >> ticket.field;									\
		}



bool operator<(Date lhs, Date rhs){
	if (lhs.year != rhs.year) {
			return lhs.year < rhs.year;
		}
		else if (lhs.month != rhs.month) {
			return lhs.month < rhs.month;
		}
		else if (lhs.day != rhs.day) {
			return lhs.day < rhs.day;
		}
		//cout << "operator<" << endl;
		return false;

}

bool operator==(Date lhs, Date rhs){
	return lhs.year==rhs.year&& lhs.month== rhs.month && lhs.day==rhs.day;
}
bool operator==(Time lhs, Time rhs){
	return lhs.hours==rhs.hours&& lhs.minutes== rhs.minutes;
}
ostream& operator<<(ostream& os, Date d){
	return os<< d.year<< "-"<<d.month<<"-"<<d.day<<endl;
}
istream& operator>>(istream& is, Date& d){
	char d1, d2;
	return is>>d.year>>d1>>d.month >> d2 >> d.day;
}

istream& operator>>(istream& is, Time& t){
	char d1;
	return is>>t.hours>>d1>>t.minutes;
}

ostream& operator<<(ostream& os, Time t){
	return os<< t.hours<< ":"<<t.minutes<<endl;
}
bool operator<(Time lhs, Time rhs){

	if (lhs.hours != rhs.hours) {
				return lhs.hours < rhs.hours;
			}
			else if (lhs.minutes != rhs.minutes) {
				return lhs.minutes < rhs.minutes;
			}
			return false;
}



void UpdateTicket(AirlineTicket& ticket, const map<string, string>& updates) {

  UPDATE_FIELD(ticket, to, updates);
  UPDATE_FIELD(ticket, from, updates);
  UPDATE_FIELD(ticket, price, updates);
  UPDATE_FIELD(ticket, airline, updates);

}

void TestUpdate() {

  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
