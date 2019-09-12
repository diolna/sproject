#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct BusesForStopResponse {
	vector<string> buses;
		bool nstop;
};
ostream& operator << (ostream& os, const BusesForStopResponse& r);
struct StopsForBusResponse {
	bool nbus;
		map<int, vector<string>> stops_buses;
		vector<string> stops;

};
ostream& operator << (ostream& os, const StopsForBusResponse& r);
struct AllBusesResponse {
	bool nbus;
		map<string, vector<string>> buses_stops;
};
ostream& operator << (ostream& os, const AllBusesResponse& r);
