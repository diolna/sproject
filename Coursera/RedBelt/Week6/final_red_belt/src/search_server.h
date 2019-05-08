#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <mutex>
#include <future>

using namespace std;

template <typename T>
class Synchronized {
public:
  explicit Synchronized(T initial = T())
    : value(move(initial))
  {
  }

  struct Access {
    T& ref_to_value;
    lock_guard<mutex> guard;
  };

  Access GetAccess() {
    return {value, lock_guard(m)};
  }

private:
  T value;
  mutex m;
};


class InvertedIndex {
public:
  void Add(const string& document);
  vector<pair<size_t, size_t>> Lookup(const string& word) const;

  const string& GetDocument(size_t id) const {
    return docs[id];
  }
  size_t GetSize(){
	  return docs.size();
  }
  size_t GetCount(){
	  return countindex;
  }
  size_t SetCount(size_t  i){
	  countindex = i;
	  return countindex;
  }
  bool FlagUpdate(bool f){
	  flag = f;
	  return flag;
  }
  bool GetFlag(){
	  return flag;
  }


private:
  map<string, vector<pair<size_t, size_t>>> index;
  vector<string> docs;
  size_t countindex = 0;
  bool flag = true;

};

class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input);
  void UpdateDocumentBase(istream& document_input);
  void AddQueriesStream(istream& query_input, ostream& search_results_output);


private:
  Synchronized<InvertedIndex> index;
  vector<future<void>> futures;
  size_t updateCount = 0;
  vector<future<InvertedIndex>> f_index;
};
