#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>


#include "profile.h"

using namespace std;

class ReadingManager {
public:

  void Read(int user_id, int page_count) {
    if (users_.count(user_id) == 0) {
             users_.insert(pair<const int, int>(user_id, page_count));
             users_pages.insert(page_count);
      }else{
	  	auto it = users_pages.find(users_.at(user_id));
	  	users_pages.erase(it);
	  	users_[user_id] = page_count;
	  	users_pages.insert(page_count);
      }

  }

  double Cheer(int user_id) const {
	 if (users_.count(user_id) == 0) {
         return 0;
    }
    if (users_.size() == 1) {
         return 1;
    }
    auto it_lim = users_pages.lower_bound(users_.at(user_id));
    return distance(users_pages.begin(), it_lim)*1.0/(users_pages.size()-1);
    }

private:

  map<int, int> users_;   // user_id, number_pages;

  multiset<int> users_pages;

};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
    	 cout << setprecision(6) << manager.Cheer(user_id) << "\n";

    }
  }

  return 0;
}
