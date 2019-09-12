

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

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

struct BusesForStopResponse {

	vector<string> buses;
	bool nstop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {

	if (r.nstop == true) {
		os << "No stop";
	}
	else {
		for (auto& i : r.buses) {
			os << i << " ";

		}
		//os << endl;
	}

	return os;
}

struct StopsForBusResponse {
	bool nbus;
	vector<string> stops;
	vector<string> buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {

	if (r.nbus == true) {
		os << "No bus";
	}
	else {
		for (auto& i : r.stops) {
			os << "Stop " << i << ": ";
			for (auto& n : r.buses) {
				os << n << " ";
			}

		}
		//os << endl;
	}
	return os;
}

struct AllBusesResponse {
	bool nbus;
	vector<string> buses;
	vector<string> stops;

};

ostream& operator << (ostream& os, const AllBusesResponse& r) {

	if (r.nbus == true) {
		os << "No buses";
	}
	else {
		for (auto& i : r.buses) {
			os << "Bus " << i << ": ";
			for (auto& n : r.stops) {
				os << n << " ";
			}
			os << endl;
		}

	}
	return os;

}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {



		buses_to_stops[bus] = stops;

		for (auto& stop : stops) {

			stops_to_buses[stop].push_back(bus);
		}


	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {

		BusesForStopResponse busforstop;

		busforstop.nstop = false;
		if (stops_to_buses.count(stop) == 0) {
			busforstop.nstop = true;
		}
		else {
			for (const string& bus : stops_to_buses.at(stop)) {
				busforstop.buses.push_back(bus);
			}

		}
		return busforstop;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {

		StopsForBusResponse  stopsforbus;
		stopsforbus.nbus = false;

		if (buses_to_stops.count(bus) == 0) {
			stopsforbus.nbus = true;
			return stopsforbus;
		}
		else {
			for (const string& stop : buses_to_stops.at(bus)) {
				stopsforbus.stops.push_back(stop);

				if (stops_to_buses.at(stop).size() == 1) {
					stopsforbus.buses.push_back("no interchange");

				}
				else {
					for (const string& other_bus : stops_to_buses.at(stop)) {
						if (bus != other_bus) {
							stopsforbus.buses.push_back(other_bus);

						}
					}
				}

			}
		}
		return stopsforbus;
	}


	AllBusesResponse GetAllBuses() const {
		AllBusesResponse allbuses;
		allbuses.nbus = false;
		if (buses_to_stops.empty()) {
			allbuses.nbus = true;
		}
		else {
			for (const auto& bus_item : buses_to_stops) {
				allbuses.buses.push_back(bus_item.first);
				for (const string& stop : bus_item.second) {
					allbuses.stops.push_back(stop);
				}

			}
		}
		return allbuses;
	}


private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;

	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:

			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}



	return 0;
}





