// bus_stop.cpp: ���������� ����� ����� ��� ����������� ����������.
//
//#include "stdafx.h"
#include<map>
#include<vector>
#include<string>
#include <iostream>

using namespace std;


bool findline(const map<string, vector<string>>& a, const string& b) {
	for (auto & i : a) {
		if (i.first == b) return true;
	}
	return false;
}

int main()
{
	map<string, vector<string>> route;
	vector<string> vector_bus;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string op;
		cin >> op;
		if (op == "NEW_BUS") {

			string number_bus;
			int stop_count;
			cin >> number_bus;
			cin >> stop_count;
			vector<string> stops;
			string stop;
			for (int i = 0; i < stop_count; ++i) {
				cin >> stop;
				stops.push_back(stop);
			}
			route[number_bus] = stops;
			vector_bus.push_back(number_bus);
		}
		else if (op == "ALL_BUSES") {
			if (route.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (auto& i : route) {
					cout << "Bus " << i.first << ":" << " ";
					for (auto& x : i.second) {				// ��������� ������
						cout << x << " ";
					}
					cout << endl;
				}
			}

		}
		else if (op == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (findline(route, bus) == false) {
				cout << "No bus" << endl;
			}
			else {
				string stop;


					for(auto& s: route){					//���������� ��� ��������� ������� ��������
						if (s.first == bus) {			// ���� ����� ������ ������� �� ����� �������� ���������

							for (auto& l : s.second) {
								int index = 0;
								cout << "Stop ";
								cout << l << ":";
								stop = l;				//������� ��������� �������� � ���������� S
								for (int k = 0; k <= vector_bus.size() - 1; ++k) {		// ���������� ��� ���������� �������� � ��� ������� ��� ��� ���������.
									if (vector_bus[k] != bus) {

										for (auto& i : route) {		// ���������� ����� ��� ��������
											if (i.first == vector_bus[k]) {		// ��������� ������ �� ����в� �� �� �����
												for (auto& k : i.second) {  //���������� ��������� ��������
													if (k == stop) {		// ���� ������ ���������
														index = 1;			// ��������� ��� �������� ����
														cout << " " << i.first;  // ���������� ����� ���������
												}
											}
										}
									}
								}
							}
							if (index == 0) {
								cout << " no interchange" << endl;
							}
							else {
								index = 0;
								cout << endl;
							}
						}
					}
				}
			}
		}
		else if (op == "BUSES_FOR_STOP") {
			string stop;
			map<int, string> out;
			int index = 0;

			cin >> stop;
			for (auto k : route) {
				for (auto h : k.second) {
					if (h == stop) {
						index = 1;
						for (int i = 0; i <= vector_bus.size() - 1; ++i) {
							if (k.first == vector_bus[i]) {
								out[i] = k.first;
							}

						}
					}
				}
			}
			if (index == 0) {
				cout << "No stop" << endl;
			}
			else {
				for (auto i : out) {
					cout << i.second << " ";
				}
				index = 0;
				cout << endl;
			}
		}




	}
	//int ddd;
	//cout << "the end";
	//cin >> ddd;

	return 0;
}

