#include "responses.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.nstop == true) {
			os << "No stop";
		}
		else {
			for (auto& i : r.buses) {
				os << i << " ";

			}

		}
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.nbus == true) {
			os << "No bus";
		}
		else {
			int index =0;
			for (auto& i : r.stops_buses) {
				os << "Stop " << r.stops[index] << ": ";

				for (auto& n : i.second) {
					os << n << " ";
				}
				os << endl;
				index++;
				}
				}
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.nbus == true) {
			os << "No buses";
		}
		else {
			for (auto& i : r.buses_stops) {
				os << "Bus " << i.first << ": ";
				for (auto& n : i.second) {
					os << n << " ";
				}
				os << endl;
			}

		}
  return os;
}


