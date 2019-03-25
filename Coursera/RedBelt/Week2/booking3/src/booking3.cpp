#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;


struct Event{
	Event(size_t id_, long long time_, size_t count_) :
		id(id_), time(time_), count(count_) {}
	size_t id;
	long long time;
	size_t count;
};

class Hotel {
public:
	Hotel() = default;
	void Book(Event& e);
	size_t getClients( long long time);
	size_t getRooms(long long time);

private:
	void Update(long long time);
	long long current_time = -1'000000'000000'000000;
	queue<Event> events;
	map<size_t, size_t> clients;
	size_t rooms =0;

};

size_t Hotel:: getRooms(long long time){
	Update(time);
	return rooms;
}

size_t Hotel::getClients(long long time){
	Update(time);
	return clients.size();
}

void Hotel::Book(Event& e) {
	++clients[e.id];
	events.push(e);
	rooms +=e.count;
	Update(e.time);
}

void Hotel::Update(long long time){
	current_time = time;
	while(!events.empty() && events.front().time <= current_time-86400){
		if(clients[events.front().id] ==1){
			clients.erase(events.front().id);
		} else {
			--clients[events.front().id];
		}
		rooms -=events.front().count;
		events.pop();
	}
}

int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t q;
	cin >> q;
	map<string, Hotel> hotels;
	long long current_time = -1000000000000000000;
	for(size_t i=0; i<q; ++i){
		string query;
		cin >> query;
		if(query == "BOOK"){
			long long time;
			cin >> time;
			current_time = time;
			string name;
			cin >> name;
			size_t id;
			cin >> id;
			size_t count;
			cin >> count;
			Event e(id, time, count);
			hotels[name].Book(e);
		} else {
			string name;
			cin >> name;
			size_t res;
			if(query == "CLIENTS"){
				res = hotels[name].getClients(current_time);
			} else {
				res = hotels[name].getRooms(current_time);
			}
			cout << res << '\n';
		}

	}
	return 0;

}
