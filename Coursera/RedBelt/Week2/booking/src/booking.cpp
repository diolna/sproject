#include <iostream>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;


class Booking {

public:
	void BOOK(const int& t, const string& name_hotel
			, const int& client_id, const int& room_c);
	int CLIENTS(const string& name_hotel);
	int ROOMS(const string& name_hotel);

private:
	map<string, map<int, map<int, int>>> book;
	map<string, deque<int>> clients_day_;

};

void Booking::BOOK(const int& time, const string& name_hotel
			, const int& client_id, const int& room_c) {

		if(book.count(name_hotel)==0){
			book.at(name_hotel).at(client_id).at(room_c) = time;
		}
}

int Booking::CLIENTS(const string& name){
		if( book.at(name).size()==0 ){
			return 0;
		} else {
				return clients_day_.size();

		}
}
int Booking::ROOMS(const string& name){
	if( book.at(name).size()==0 ){
				return 0;
			} else {
					return clients_day_.size();

			}
}

int main() {
	// Для ускорения чтения данных отключается синхронизация
	  // cin и cout с stdio,
	  // а также выполняется отвязка cin от cout
	  ios::sync_with_stdio(false);
	  cin.tie(nullptr);

	  Booking h;

	  int query_count;
	  cin >> query_count;

	  for (int query_id = 0; query_id < query_count; ++query_id) {
	    string query_type;
	    cin >> query_type;
	    int user_id;
	    cin >> user_id;

	    if (query_type == "BOOK") {
	      int time_booking, client_id, room_c;
	      string hotel_name;
	      cin >> time_booking >> hotel_name >> client_id >> room_c;
	      h.BOOK(time_booking, hotel_name, client_id, room_c);
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
