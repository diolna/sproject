#include <iostream>
#include <string>
#include <map>
#include <set>
#include <numeric>
#include <vector>
#include "test_runner.h"
#include <cstdint>
#include <queue>

using namespace std;


class Booking {

public:

			void BOOK(const int64_t& time, const string& name_hotel
					, const int64_t& client, const int64_t& room_count);
			int64_t CLIENTS(const string& name_hotel);
			int64_t ROOMS(const string& name_hotel);


private:
	map<string, map<int64_t, set<int64_t>>> time_; 	// в отеле забронировали  в время клиенты
	map<string, map<int64_t, queue<int64_t>>> rooms_; // в отеле забронировали в время комнат
	map<string, queue<int64_t>> rooms1_;
	map<string, pair<int64_t, int64_t>> time1_;

};



void Booking::BOOK(const int64_t& time, const string& name_hotel
					, const int64_t& client, const int64_t& room_count) {



					time_[name_hotel][time].insert(client);
					for(auto i=0; i < room_count; ++i){
					rooms_[name_hotel][time].push(1);
					}

					for(auto& i: time_){
						if(time - i.second.begin()->first >= 86400 )  {
							int64_t time_del = time  - 86400;
							auto it_clients = i.second.upper_bound(time_del);
							i.second.erase(i.second.begin(), it_clients);

						}
					}
					for(auto& i: rooms_){
						if(time - i.second.begin()->first >= 86400 )  {
								int64_t time_del = time  - 86400;
								auto it_clients = i.second.upper_bound(time_del);
								for(auto it = i.second.begin();  it!= it_clients; ++it){
										rooms1_[i.first].pop();
															}
								i.second.erase(i.second.begin(), it_clients);
						}
					}




}


int64_t Booking::CLIENTS(const string& name_hotel){
	set<int64_t> clients1;
		if(time_.count(name_hotel) == 0 ) {

			return 0;
		}
		if(time_.find(name_hotel)->second.size()==0 ) {
			return 0;
		}
		for(auto& i: time_.find(name_hotel)->second) {

			clients1.insert(i.second.begin(), i.second.end());


		}
		return clients1.size();
}

int64_t Booking::ROOMS(const string& name_hotel){

	int64_t rooms = 0;
	if(rooms_.count(name_hotel) == 0 ) {

		return 0;
	}
	if(rooms_.find(name_hotel) ->second.size()==0){
		return 0;
	}
		auto it = rooms_.find(name_hotel);

		map<int64_t, queue<int64_t>> v;
		v = it->second;
		cout << v.size();
		for(int64_t y=0; y < v.size(); ++y){
				rooms += v[y];
			}


	return rooms;
}

void test() {
    Booking manager;

    // Test empty bookings
    ASSERT_EQUAL(manager.CLIENTS("mariott"), 0);
    ASSERT_EQUAL(manager.ROOMS("mariott"), 0);

    manager.BOOK(0, "mariott", 1, 10);
    manager.BOOK(0, "mariott", 2, 1);
    manager.BOOK(0, "mariott", 3, 1);
    manager.BOOK(0, "mariott", 4, 1);
    manager.BOOK(0, "hilton", 1, 1);
    manager.BOOK(1, "hilton", 2, 1);

    // Test correctness
    ASSERT_EQUAL(manager.CLIENTS("mariott"), 4);
    ASSERT_EQUAL(manager.ROOMS("mariott"), 13);
    ASSERT_EQUAL(manager.CLIENTS("hilton"), 2);
    ASSERT_EQUAL(manager.ROOMS("hilton"), 2);

    // Test event past 1 day resets statics
    manager.BOOK(86400, "mariott", 1, 1);
    ASSERT_EQUAL(manager.CLIENTS("mariott"), 1);
    ASSERT_EQUAL(manager.ROOMS("mariott"), 1);
    ASSERT_EQUAL(manager.CLIENTS("hilton"), 1);
    ASSERT_EQUAL(manager.ROOMS("hilton"), 1);

    // Test no clients and room for the last day
    manager.BOOK(86401, "mariott", 5, 1);
    ASSERT_EQUAL(manager.CLIENTS("mariott"), 2);
    ASSERT_EQUAL(manager.ROOMS("mariott"), 2);
    ASSERT_EQUAL(manager.CLIENTS("hilton"), 0);
    ASSERT_EQUAL(manager.ROOMS("hilton"), 0);

    // test add client cek in sek
    {
    manager.BOOK(86402, "mar", 6,3);
    manager.BOOK(86402, "mar", 6,3);
    ASSERT_EQUAL(manager.CLIENTS("mar"), 1 );
    ASSERT_EQUAL(manager.ROOMS("mar"), 6 );
    manager.BOOK(86402000, "mmm", 6,7);
    ASSERT_EQUAL(manager.ROOMS("mar"), 0 );
    ASSERT_EQUAL(manager.CLIENTS("mar"), 0 );
    ASSERT_EQUAL(manager.CLIENTS("mmm"), 1);
    }
    {
    		Booking v;
    		v.BOOK(0, "aaa", 6,3);
    	    v.BOOK(0, "aaa", 7,3);
    	    v.BOOK(1, "aaa", 6,3);
    	    v.BOOK(1, "aaa", 7,3);
    	    ASSERT_EQUAL(v.CLIENTS("aaa"), 2 );
    	    ASSERT_EQUAL(v.ROOMS("aaa"), 12 );
    	    v.BOOK(86400, "aaa", 6,7);
    	    ASSERT_EQUAL(v.ROOMS("aaa"), 13 );
    	    ASSERT_EQUAL(v.CLIENTS("aaa"), 2 );

    }
}

int main() {

TestRunner tr;
RUN_TEST(tr, test);

////	map<int, map<int, int>> aaa = { {1,{{1,2}}}, {2,{{2,3}}}, {3,{{3,4}}}};
////	map<int,map<int,int>>::iterator it = aaa.find(1);
////	int nnn = it->first;
////	int nnn1 = it->second.begin()->first;
////	int nnn2 = it->second.begin() -> second;
////	cout << nnn << " " << nnn1 << " " << nnn2;
//
//

	// Для ускорения чтения данных отключается синхронизация
	  // cin и cout с stdio,
	  // а также выполняется отвязка cin от cout
	  ios::sync_with_stdio(false);
	  cin.tie(nullptr);

	  Booking h;

	  int32_t query_count;
	  cin >> query_count;

	  for (int32_t query_id = 0; query_id < query_count; ++query_id) {
	    string query_type;
	    cin >> query_type;


	    if (query_type == "BOOK") {

	      int32_t  client_id;
	      int64_t rooms_count;
	      int64_t time_booking;
	      string hotel_name;
	      cin >> time_booking >> hotel_name >> client_id >> rooms_count;
	      h.BOOK(time_booking, hotel_name, client_id, rooms_count);

	    } else if (query_type == "CLIENTS") {

	    		string hotel_name;
	    		cin >> hotel_name;
	    		cout << h.CLIENTS(hotel_name) << endl;
	    } else if ( query_type == "ROOMS"){
	    		string hotel_name;
	    		cin >> hotel_name;
	    		cout << h.ROOMS(hotel_name) << endl;

	  }
	  }
	  return 0;
}
