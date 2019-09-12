	// bus_stop2_1.cpp: определяет точку входа для консольного приложения.
	//

	//#include "stdafx.h"
	#include <iostream>
	#include <map>
	#include <vector>
	#include <string>

	using namespace std;

	//void PrintResult(const map<vector<string>, int>& c) {
	//	for (auto & i : c) {
	//		cout << "New bus "<< i.second << endl;
	//		}
	//}


	int main()
	{
		map<vector<string>, int> stops_bus;
		vector<string> stops;
		int q;
		cin >> q;
		for (int i = 0; i <q; ++i) {
			int number_stops;
			string stop;
			int index = 0;
			cin >> number_stops;
			stops.resize(number_stops);
			for (int i = 0; i <= number_stops - 1; ++i) {
				cin >> stop;
				stops[i] = stop;
			}
			if (stops_bus.size() == 0) {
				stops_bus[stops]++;
				//PrintResult(stops_bus);
				cout << "New bus " << 1 << endl;
			}
			else {
				for (auto i : stops_bus) {
					if (i.first == stops) {
						index = 1;
						cout << "Already exists for " << i.second << endl;
					}
				}
				if (index == 0) {
					int new_value = stops_bus.size();
					stops_bus[stops] = new_value + 1;
					//PrintResult(stops_bus);
					cout << "New bus " << stops_bus.size() << endl;
				}
				else {
					index = 0;

				}
			}
		}

		for(auto i: stops_bus){
			cout << i.second;
			for(auto n: i.first){
				cout << n << " ";
			}
			cout << endl;
		}

		//int ddd;
		//cin >> ddd;
		return 0;
	}

