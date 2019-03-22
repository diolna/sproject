#include <iostream>
#include <string>
#include <map>
#include <set>
<<<<<<< HEAD
#include <deque>
=======
#include <numeric>
#include <vector>
>>>>>>> 60b9b48049f93b112ff52cb0298fd5dcca7544a3

using namespace std;


class Booking {

public:
<<<<<<< HEAD
	void BOOK(const int& t, const string& name_hotel
			, const int& client_id, const int& room_c);
=======
	void BOOK(const int& time, const string& name_hotel, const int& client_id, const int& room_count);
>>>>>>> 60b9b48049f93b112ff52cb0298fd5dcca7544a3
	int CLIENTS(const string& name_hotel);
	int ROOMS(const string& name_hotel);

private:
<<<<<<< HEAD
	map<string, map<int, map<int, int>>> book;
	map<string, deque<int>> clients_day_;

};

void Booking::BOOK(const int& time, const string& name_hotel
			, const int& client_id, const int& room_c) {
=======
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


>>>>>>> 60b9b48049f93b112ff52cb0298fd5dcca7544a3

		if(book.count(name_hotel)==0){
			book.at(name_hotel).at(client_id).at(room_c) = time;
		}
}

<<<<<<< HEAD
int Booking::CLIENTS(const string& name){
		if( book.at(name).size()==0 ){
			return 0;
		} else {
				return clients_day_.size();
=======
int Hotels::CLIENTS(const string& name){
>>>>>>> 60b9b48049f93b112ff52cb0298fd5dcca7544a3

				return 0;


}
<<<<<<< HEAD
int Booking::ROOMS(const string& name){
	if( book.at(name).size()==0 ){
				return 0;
			} else {
					return clients_day_.size();

			}
=======
int Hotels::ROOMS(const string& name){
	return 0;
>>>>>>> 60b9b48049f93b112ff52cb0298fd5dcca7544a3
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

	  Booking h;

	  int query_count;
	  cin >> query_count;

	  for (int query_id = 0; query_id < query_count; ++query_id) {
	    string query_type;
	    cin >> query_type;
	    int user_id;
	    cin >> user_id;

	    if (query_type == "BOOK") {
<<<<<<< HEAD
	      int time_booking, client_id, room_c;
	      string hotel_name;
	      cin >> time_booking >> hotel_name >> client_id >> room_c;
	      h.BOOK(time_booking, hotel_name, client_id, room_c);
=======
	      int time_booking, client_id, rooms_count;
	      string hotel_name;
	      cin >> time_booking >> hotel_name >> client_id >> rooms_count;
	      h.BOOK(time_booking, hotel_name, client_id, rooms_count);
>>>>>>> 60b9b48049f93b112ff52cb0298fd5dcca7544a3
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
