#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>



using namespace std;

struct Record {
  string id;
  string title;
  string user;
  int timestamp;
  int karma;

  bool operator==(const Record& other) {
	  return tie(id,title, user, timestamp, karma) == tie(id, title, user, timestamp, karma);
  }
};

 //Реализуйте этот класс
//class Database {
//public:
//  bool Put(const Record& record) {
//	  if(base.count(record.id) == 1) return false;
//	  base[record.id] =  record;
//	  int karma = record.karma;
//	  pair< const int, Record> mypair = {karma, record};
//	  rangebykarma.insert(mypair);
//	  pair<const string, Record> myuspair = {record.user, record};
//	  user_.insert(myuspair);
//	  pair<const int, Record> mypairtime = {record.timestamp, record};
//	  timestampbase.insert(mypairtime);
//	  return true;
//  }
//  const Record* GetById(const string& id) const{
//	  if(base.count(id) == 0 ) return nullptr;
//	  return &base.at(id);
//  }
//  bool Erase(const string& id){
//	  multimap<int, Record>::iterator it_temp;
//	  multimap<int, Record>::iterator it_temp1;
//	  multimap<string, Record>::iterator it_us;
//	  if(base.count(id) == 1) {
//		  Record temp = base.at(id);
//		  base.erase(id);
//		  for(auto it = timestampbase.begin(); it!=timestampbase.end(); ++it) {
//			  if(it->second == temp) { it_temp = it;}
//		  }
//		  timestampbase.erase(it_temp);
//		  for(auto it1 = user_.begin(); it1!=user_.end(); ++it1) {
//		  			  if(it1->second == temp) { it_us = it1;}
//		  		  }
//		  user_.erase(it_us);
//		  for(auto it = rangebykarma.begin(); it!=rangebykarma.end(); ++it) {
//		  			  if(it->second == temp) { it_temp1 = it;}
//		  		  }
//		  rangebykarma.erase(it_temp1);
//		  return true;
//	  }
//	  return false;
//  }
//
//  template <typename Callback>
//  void RangeByTimestamp(int low, int high, Callback callback) const{
//	  for(int i = low; i<=high; ++i){
//	  		  if(timestampbase.count(i) == 1) {
//	  			  const Record& r = (timestampbase.find(i))->second;
//	  			  if(callback(r) == false )  return;
//	  		  }
//	  	  }
//  }
//
//  template <typename Callback>
//  void RangeByKarma(int low, int high, Callback callback) const {
//
//	  for(int i = low; i<=high; ++i){
//		  if(rangebykarma.count(i) == 1) {
//			  const Record& r = (rangebykarma.find(i))->second;
//			  if(callback(r) == false )  return;
//		  }
//	  }
//  }
//
//  template <typename Callback>
//  void AllByUser(const string& user, Callback callback) const {
//	  auto [it, end] = user_.equal_range(user);
//	  //auto it = range.first;
//	  if(it != end){
//		  while(it != end && callback(it->second)){
//		  	  ++it;
//		  }
//	  }
//  }
//
//private:
//  unordered_map<string, Record> base;
//  multimap<int, Record> timestampbase;
//  multimap<string, Record> user_;
//  multimap<int, Record> rangebykarma;
//
//};

class Database {
public:
  bool Put(const Record& record) {
	  if(base.count(record.id) == 1) return false;
	  base[record.id] =  record;
	  int karma = record.karma;
	  pair< const int, Record> mypair = {karma, record};
	  rangebykarma.insert(mypair);
	  pair<const string, Record> myuspair = {record.user, record};
	  user_.insert(myuspair);
	  pair<const int, Record> mypairtime = {record.timestamp, record};
	  timestampbase.insert(mypairtime);
	  return true;
  }
  const Record* GetById(const string& id) const{
	  if(base.count(id) == 0 ) return nullptr;
	  return &base.at(id);
  }
  bool Erase(const string& id){
	  auto it =id_s.find(id);
	  if(it == id_s.end()){
		  return false;
	  }
	  size_t index = it->second;
	  auto el = iterators[index];
	  timestamp_s.erase(get<0>(el));
	  users
  }

  template <typename Callback>
  void RangeByTimestamp(int low, int high, Callback callback) const{
	  auto it = timestamp_s.lower_bound(low);
	  	  auto end = timestamp_s.upper_bound(high);
	  	  while(it != end && callback(records.at(it->second))){
	  		  ++it;
	  	  }
  }

  template <typename Callback>
  void RangeByKarma(int low, int high, Callback callback) const {

	  auto it = karma_s.lower_bound(low);
	  auto end = karma_s.upper_bound(high);
	  while(it != end && callback(records.at(it->second))){
		  ++it;
	  }
  }

  template <typename Callback>
  void AllByUser(const string& user, Callback callback) const {
	  auto [it, end] = users.equal_range(user);
	  //auto it = range.first;
	  if(it != end){
		  while(it != end && callback(records.at(it->second))){
		  	  ++it;
		  }
	  }
  }

private:
unordered_map<string, size_t> id_s;
unordered_map<size_t, Record> records;
multimap<int,size_t> timestamp_s;
multimap<string,size_t> users;
multimap<int, size_t> karma_s;
size_t count =0;
unordered_map<size_t, iterator> iterators;
};

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
