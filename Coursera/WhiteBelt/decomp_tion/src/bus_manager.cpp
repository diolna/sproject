#include "bus_manager.h"
#include "responses.h"

using namespace std;


  void BusManager::AddBus(const string& bus, const vector<string>& stops){

	  buses_to_stops[bus] = stops;

	  		for (auto& stop : stops) {

	  			stops_to_buses[stop].push_back(bus);
	  		}


  }

  BusesForStopResponse BusManager:: GetBusesForStop(const string& stop) const {
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

  StopsForBusResponse BusManager:: GetStopsForBus(const string& bus) const {
	  StopsForBusResponse  stopsforbus;
	  		stopsforbus.nbus = false;

	  		if (buses_to_stops.count(bus) == 0) {
	  			stopsforbus.nbus = true;
	  			return stopsforbus;
	  		}
	  		else {
	  			int index=0;
	  			for (const string& stop : buses_to_stops.at(bus)) {
	  				stopsforbus.stops.push_back(stop);

	  				if (stops_to_buses.at(stop).size() == 1) {
	  					stopsforbus.stops_buses[index].push_back("no interchange");

	  				}
	  				else {
	  					for (const string& other_bus : stops_to_buses.at(stop)) {
	  						if (bus != other_bus) {
	  							stopsforbus.stops_buses[index].push_back(other_bus);

	  						}
	  					}

	  				}
	  				index++;
	  			}
	  		}
	  		return stopsforbus;
  }

  AllBusesResponse BusManager:: GetAllBuses() const {
	  AllBusesResponse allbuses;
	  		allbuses.nbus = false;
	  		if (buses_to_stops.empty()) {
	  			allbuses.nbus = true;
	  		}
	  		else {
	  			for (const auto& bus_item : buses_to_stops) {

	  				for (const string& stop : bus_item.second) {
	  					allbuses.buses_stops[bus_item.first].push_back(stop);
	  				}

	  			}
	  		}
	  		return allbuses;

  }


