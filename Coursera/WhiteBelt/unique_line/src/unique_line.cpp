// bus_stops3_1.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <iostream>
#include <set>
#include<map>
#include<string>

using namespace std;


int main()
{
	map<set<string>, int> bus_stops;
	int n, stops_count;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string stop;
		set<string> stops_temp;
		cin >> stops_count;
		for (int n = 0; n < stops_count; ++n) {
			cin >> stop;
			stops_temp.insert(stop);
		}
			if (bus_stops.size() == 0 || bus_stops.count(stops_temp)==0) {
				int temp_value = bus_stops.size()+1;
				bus_stops[stops_temp]= temp_value;
				cout << "New bus " << bus_stops[stops_temp]<< endl;
			}
			else {
				 cout << "Already exists for " << bus_stops[stops_temp] << endl;
			}


	}

    return 0;
}


