#include <iostream>
#include <string>
#include <map>
#include <set>
#include <numeric>
#include <vector>

using namespace std;

class Hotels {
public:
	void BOOK(const int& time, const string& name_hotel, const int& client_id, const int& room_count);
	int CLIENTS(const string& name_hotel);
	int ROOMS(const string& name_hotel);

private:
	map<string, map<int, set<int>>> time_; 	// в отеле забронировали номера клиенты
	map<string, map<int, int>> rooms_;
	map<string, vector<int>> clients_in_hotel_day;
	int current_time_;
};

void Hotels::BOOK(const int& time, const string& name_hotel, const int& client, const int& room_count) {
			time_[name_hotel][time].insert(client);
			rooms_[name_hotel][client] = room_count;
			map<string, map <int, set<int>>>::iterator it = time_.begin();
			//map<string, map<int, int>>:: iterator it2 = lower_bound(it->second.end()->first);



}

int Hotels::CLIENTS(const string& name){

				return 0;


}
int Hotels::ROOMS(const string& name){
	return 0;
}



int main() {

	map<int, map<int, int>> aaa = { {1,{{1,2}}}, {2,{{2,3}}}, {3,{{3,4}}}};
	map<int,map<int,int>>::iterator it = aaa.find(1);
	int nnn = it->first;
	int nnn1 = it->second.begin()->first;
	int nnn2 = it->second.begin() -> second;
	cout << nnn << " " << nnn1 << " " << nnn2;



	// Для ускорения чтения данных отключается синхронизация
	  // cin и cout с stdio,
	  // а также выполняется отвязка cin от cout
	  ios::sync_with_stdio(false);
	  cin.tie(nullptr);

	  Hotels h;

	  int query_count;
	  cin >> query_count;

	  for (int query_id = 0; query_id < query_count; ++query_id) {
	    string query_type;
	    cin >> query_type;
	    int user_id;
	    cin >> user_id;

	    if (query_type == "BOOK") {
	      int time_booking, client_id, rooms_count;
	      string hotel_name;
	      cin >> time_booking >> hotel_name >> client_id >> rooms_count;
	      h.BOOK(time_booking, hotel_name, client_id, rooms_count);
	    } else if (query_type == "CLIENTS") {
	    		string hotel_name;
	    		cout << h.CLIENTS(hotel_name) << endl;
	    } else if ( query_type == "ROOMS"){
	    		string hotel_name;
	    		cout << h.ROOMS(hotel_name) << endl;
	    }
	  }

	  return 0;
}
