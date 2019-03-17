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
	  if(users_.count(user_id)==0){
      	users_[user_id] = page_count;
	  	page_[page_count].insert(user_id);
	  }else{
		  page_.erase(users_.at(user_id));
		  users_[user_id] = page_count;
		  page_[page_count].insert(user_id);
	   }

  }

  double Cheer(int user_id) const {
	  cout << "CHEER(" << user_id << ")" << endl;
	 if (users_.count(user_id) == 0) {

         return 0;
    }
    if (users_.size() == 1) {
         return 1;
    }

    	size_t count=0;
//    	cout << "page = " << users_.at(user_id) << endl;
    	auto it = page_.lower_bound(users_.at(user_id));
//    	cout << "elements = ";
//    	for(auto i= page_.begin(); i!=it; ++i){
//    		cout << i->first << " ";
//    	}
    	//cout << endl;
    	//if(prev(it)==page_.end()){return 0;}
    	for(auto it2= page_.begin(); it2!=(it); it2++){
    		 	++count;
    	}
    	cout << "count = " << count << "page= " << users_.at(user_id) << endl;
    	if(count==0){return 0;}


    return (count)*1.0/(users_.size()-1);
    }

private:

  map<int, int> users_;   // user_id, number_pages;
  map<int, set<int>> page_;


};


int main() {
  // ��� ��������� ������ ������ ����������� �������������
  // cin � cout � stdio,
  // � ����� ����������� ������� cin �� cout
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
