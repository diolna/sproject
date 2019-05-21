#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <tuple>



using namespace std;

struct Record {
  string id;
  string title;
  string user;
  int timestamp;
  int karma;

  bool operator==(const Record& other) {
	  return tie(id,title, user, timestamp, karma)
			  == tie(other.id, other.title, other.user, other.timestamp, other.karma);

  }
  bool operator<(const Record& other) const {
	  return id < other.id;
  }

};

 //Реализуйте этот класс
class Database {
public:
	using iterator = tuple<multimap<int, const Record*>::iterator
				, multimap<string, const Record*>::iterator
				, multimap< int, const Record*>::iterator>;

  bool Put(const Record& record) {
	  if(base.count(record.id) == 1) {
		  return false;
	  }
	  base[record.id] =  record;  // вставляем базу
	  const Record* rec = &base.at(record.id);
	  auto it_1 = rangebykarma.insert({record.karma, rec});  // вставляем Karma
	  auto it_2 = user_.insert({record.user, rec});    // вставляем user
	  auto it_3 = timestampbase.insert({record.timestamp, rec});  // вставляем timestamp
	  auto t = make_tuple(it_1, it_2, it_3);
	  iterators.insert({rec, t});
	  return true;
  }
  const Record* GetById(const string& id) const{
	  if(base.count(id) == 0 ) return nullptr;
	  return &base.at(id);
  }
  bool Erase(const string& id){
	   if(base.count(id) == 1) {
		   const Record* temp = &base.at(id);
		   auto element = iterators.find(temp);
		   rangebykarma.erase(get<0>(element->second));
		   user_.erase((get<1>(element->second)));
		   timestampbase.erase(get<2>(element->second));
		   iterators.erase(temp);
 		   base.erase(id);
		   return true;
	  }
	  return false;
  }

  template <typename Callback>
  void RangeByTimestamp(int low, int high, Callback callback) const{
	  auto it = timestampbase.lower_bound(low);
	  auto end = timestampbase.upper_bound(high);
	  while(it != end && callback(*(it->second))){
	  		  ++it;
	  	  }
  }

  template <typename Callback>
  void RangeByKarma(int low, int high, Callback callback) const {

	  auto it = rangebykarma.lower_bound(low);
	  auto end = rangebykarma.upper_bound(high);
	  while(it != end && callback(*(it->second))){
	  		  ++it;
	  	  }
  }

  template <typename Callback>
  void AllByUser(const string& user, Callback callback) const {
	  auto [it, end] = user_.equal_range(user);
	  //auto it = range.first;
	  if(it != end){
		  while(it != end && callback(*(it->second))){
		  	  ++it;
		  }
	  }
  }

private:
  unordered_map<string, Record> base;
  multimap<int, const Record*> timestampbase;
  multimap<string, const Record*> user_;
  multimap<int, const Record*> rangebykarma;
  multimap<const Record*, iterator> iterators;

};

//class Database {
//public:
//	using iterator = tuple<multimap<int, size_t>::iterator
//			, multimap<string, size_t>::iterator
//			, multimap< int, size_t>::iterator>;
//
//  bool Put(const Record& record) {
//	  auto it = id_s.find(record.id);
//	  if(it != id_s.end()){
//		  return false;
//	  }
//	  id_s.insert({record.id, count});
//	  auto it_1 = timestamp_s.insert({record.timestamp, count});
//	  auto it_2 = users.insert({record.user, count});
//	  auto it_3 = karma_s.insert({record.karma, count});
//	  auto t = make_tuple(it_1, it_2, it_3);
//	  iterators.insert({count, t});
//	  records.insert({count++, record});
//	  return true;
//
//
//  }
//  const Record* GetById(const string& id) const{
//  	  auto it = id_s.find(id);
//  	  if(it== id_s.end()){
//  		  return nullptr;
//  	  }
//  	  return &records.at(it->second);
//    }
//
//
//  bool Erase(const string& id){
//	  auto it =id_s.find(id);
//	  if(it == id_s.end()){
//		  return false;
//	  }
//	  size_t index = it->second;
//	  auto el = iterators[index];
//	  timestamp_s.erase(get<0>(el));
//	  users.erase(get<1>(el));
//	  karma_s.erase(get<2>(el));
//	  records.erase(index);
//	  iterators.erase(index);
//	  id_s.erase(it);
//	  return true;
//
//  }
//
//  template <typename Callback>
//  void RangeByTimestamp(int low, int high, Callback callback) const{
//	  auto it = timestamp_s.lower_bound(low);
//	  	  auto end = timestamp_s.upper_bound(high);
//	  	  while(it != end && callback(records.at(it->second))){
//	  		  ++it;
//	  	  }
//  }
//
//  template <typename Callback>
//  void RangeByKarma(int low, int high, Callback callback) const {
//
//	  auto it = karma_s.lower_bound(low);
//	  auto end = karma_s.upper_bound(high);
//	  while(it != end && callback(records.at(it->second))){
//		  ++it;
//	  }
//  }
//
//  template <typename Callback>
//  void AllByUser(const string& user, Callback callback) const {
//	  auto [it, end] = users.equal_range(user);
//	  //auto it = range.first;
//	  if(it != end){
//		  while(it != end && callback(records.at(it->second))){
//		  	  ++it;
//		  }
//	  }
//  }
//
//private:
//unordered_map<string, size_t> id_s;
//unordered_map<size_t, Record> records;
//multimap<int,size_t> timestamp_s;
//multimap<string,size_t> users;
//multimap<int, size_t> karma_s;
//size_t count =0;
//unordered_map<size_t, iterator> iterators;
//};

void TestRangeBoundaries() {
  const int good_karma = 1000;
  const int bad_karma = -10;

  Database db;
  db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
  db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});

  int count = 0;
  db.RangeByKarma(bad_karma, good_karma, [&count](const Record&) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestSameUser() {
  Database db;
  db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
  db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

  int count = 0;
  db.AllByUser("master", [&count](const Record&) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestReplacement() {
  const string final_body = "Feeling sad";

  Database db;
  db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
  db.Erase("id");
  db.Put({"id", final_body, "not-master", 1536107260, -10});

  auto record = db.GetById("id");
  ASSERT(record != nullptr);
  ASSERT_EQUAL(final_body, record->title);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestRangeBoundaries);
  RUN_TEST(tr, TestSameUser);
  RUN_TEST(tr, TestReplacement);
  return 0;
}
