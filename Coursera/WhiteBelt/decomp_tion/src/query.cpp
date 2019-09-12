#include <iostream>
#include "query.h"


using namespace std;


istream& operator >> (istream& is, Query& q) {
	string op;
	is >> op;
		if (op == "NEW_BUS") {
			q.type = QueryType::NewBus;
			string b;
			is >> b;
			q.bus = b;
			int stop_count;
			is >> stop_count;
			string stop;
			q.stops.resize(stop_count);
			for (int i=0; i<=q.stops.size()-1; ++i) {
				is >> stop;

				q.stops[i]=stop;


			}
		}
			else
					if (op == "BUSES_FOR_STOP") {
						q.type = QueryType::BusesForStop;
						string stop;
						is >> stop;
						q.stop = stop;
					}
					else
						if (op == "STOPS_FOR_BUS") {
							q.type = QueryType::StopsForBus;
							string bus;
							is >> bus;
							q.bus = bus;
						}
						else
							if (op == "ALL_BUSES") {
								q.type = QueryType::AllBuses;

							}

  return is;
}
