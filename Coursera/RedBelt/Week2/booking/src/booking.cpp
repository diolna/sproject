#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Hotels {
public:
	void BOOK(const int& t, const string& name_hotel, const int& client_id);
	int CLIENTS(const string& name_hotel);
	int ROOMS(const string& name_hotel);

private:
	map<string, set<int>> day_clients_;
	map<string, map<int, int>> hotels_; 	// в отеле забронировали номера клиенты
	map<string, set<int>> client_time_;
};

void Hotels::BOOK(const int& time, const string& name, const int& client) {

}

int Hotels::CLIENTS(const string& name){
		if( hotels_.at(name).size()==0 ){
			return 0;
		} else {
				return day_clients_.size();

		}
}
int Hotels::ROOMS(const string& name){

}



int main() {
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
	      int time_booking, client_id;
	      string hotel_name;
	      cin >> time_booking >> hotel_name >> client_id;
	      h.BOOK(time_booking, hotel_name, client_id);
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
