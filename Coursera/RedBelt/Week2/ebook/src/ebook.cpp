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
	  LOG_DURATION("read");
    if (users_.count(user_id) == 0) {
    	users_[user_id] = page_count;
    	users_pages.push_back(page_count);
    }else{
	 auto it = find(users_pages.begin(), users_pages.end(), users_.at(user_id));
	 users_pages.erase(it);
	 users_[user_id]= page_count;
	 users_pages.push_back(page_count);
   }
    sort(users_pages.begin(), users_pages.end());
  }

  double Cheer(int user_id) const {
	  LOG_DURATION("cheer");
    if (users_.count(user_id) == 0) {
         return 0;
    }
    if (users_.size() == 1) {
         return 1;
    }
    int a = users_.at(user_id);
    auto it_lim = lower_bound(users_pages.begin(), users_pages.end(), a);
    double number_read_pages_min = distance(users_pages.begin(), it_lim);
    if(number_read_pages_min <=0){
    	number_read_pages_min =0;
    }
    double total_read_pages = users_pages.size();
    number_read_pages_min= total_read_pages - number_read_pages_min;
    if(number_read_pages_min==0) {
    	return 0;
    }

    return (total_read_pages - number_read_pages_min)/(total_read_pages-1);
  }

private:

  map<int, int> users_;
  vector<int> users_pages;

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
