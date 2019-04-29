#include "test_runner.h"
#include "profile.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <random>
#include <mutex>
#include <future>
#include <list>


using namespace std;

//template <typename K, typename V>
//class ConcurrentMap {
//public:
//  static_assert(is_integral_v<K>, "ConcurrentMap supports only integer keys");
//
//  struct Segment {
//	  map<K,V> submap;
//	  mutex m;
//  };
//
//  size_t segment(K key) {
//        K abs = key >= 0 ? key : -key;
//        return abs % segments.size();
//    }
//
//  struct Access {
//    V& ref_to_value;
//    lock_guard<mutex>&& lock;
//  };
//
//
//Access GetAccess(K key, V value){
//
//	lock_guard<mutex> lock(m);
//
//	return {value, move(lock)};
//}
//
//
//
//  explicit ConcurrentMap(size_t bucket_count)
//  	  : segments(bucket_count)
//  {
//  }
//
//
//  Access operator[](const K &key) {
//
//        auto &s = segments[segment(key)];
////        lock_guard<mutex> lock(s.m);
//        lock_guard<mutex> lock(m);
//
//        return {s.submap[key], move(lock)};
//    }
//
//  map<K, V> BuildOrdinaryMap(){
////	  list<lock_guard<mutex>> locks;
////	  for(auto &s : segments){
////		  locks.emplace_back((s.m));
//////		  lock_guard<mutex> lock(m);
////	  }
//
////	  map<K,V> res;
////	  for(auto &s : segments){
////
////
////		  for(auto& i : s.submap){
////
////
////			 res[i.first] =  i.second;
////		  }
////	  }
////	  return res;
//	  map<K,V> res;
//	  //Access access;
//	  for( auto &s : segments){
//
//		  for(auto& i : s.submap) {
//			  auto access = GetAccess(i.first, i.second);
//			  res[i.first] = access.ref_to_value;
//		  }
//	  }
//	  return res;
//  }
//private:
//
//  vector<Segment> segments;
//  mutex m;
//};

template <typename K, typename V>
class ConcurrentMap {
public:
  static_assert(is_integral_v<K>, "ConcurrentMap supports only integer keys");

//  struct Segment {
//	  map<K,V> submap;
//	  mutex m;
//  };

//  size_t segment(K key) {
//        K abs = key >= 0 ? key : -key;
//        return abs % segments.size();
//    }

  struct Access {
	  lock_guard<mutex> guard;
    V& ref_to_value;
//    lock_guard<mutex>&& lock;
  };


//Access GetAccess(K key, V value){
//
//	lock_guard<mutex> lock(m);
//
//	return {value, move(lock)};
//}



  explicit ConcurrentMap(size_t bucket_count)
  	  : mutexMapVector(bucket_count)
  {
  }


  Access operator[](const K &key) {
	  size_t segmentNum = GetSegNumber(key);
	  auto& s = mutexMapVector[segmentNum];
	  return {lock_guard(s.first), s.second[key]};


    }

  map<K, V> BuildOrdinaryMap(){
	  map<K,V> result;
	  for(auto& item : mutexMapVector){
		  auto lock = lock_guard(item.first);
	  for(auto& [k,v] : item.second){
		  result[k] = v;
	  }
	  }
	  return result;
  }
private:

  vector<pair<mutex, map<K,V>>> mutexMapVector;

  size_t GetSegNumber(const K& key){
	  K absKey = key >= 0 ? key : - key;
	  return absKey % mutexMapVector.size();
  }

};


void RunConcurrentUpdates(                     // запускает ассинхронные потоки в количестве thread_count
												// при этом оборачивает их в класс ConcurrentMap который
		//делит контейнер map на thread_count частей изначально размер контейнера map key_count;

    ConcurrentMap<int, int>& cm, size_t thread_count, int key_count
) {
	// лямбда функция, которая запускается в каждом потоке.

	// при помощи генератора случайных чисел заполяетет вектор updates размером key_count; Случайность
	//обеспечивает входнй параметр seed
	//для вектора в классе ConcurrentMap сохраняестя ref_to_value++ для каждого ключа(элемента вектора)
	// два раза изменяется

  auto kernel = [&cm, key_count](int seed) {
    vector<int> updates(key_count);
    iota(begin(updates), end(updates), -key_count / 2);
    shuffle(begin(updates), end(updates), default_random_engine(seed));

    for (int i = 0; i < 2; ++i) {
      for (auto key : updates) {
        cm[key].ref_to_value++;

      }
    }
  };

  vector<future<void>> futures;
  for (size_t i = 0; i < thread_count; ++i) {
    futures.push_back(async(kernel, i));
  }
}

void TestConcurrentUpdate() {
  const size_t thread_count = 3;
  const size_t key_count = 50000;

  ConcurrentMap<int, int> cm(thread_count);       // создаем класс контролирующий mutex
  RunConcurrentUpdates(cm, thread_count, key_count); // записіваем данніе в классе

  const auto result = cm.BuildOrdinaryMap();  // возвращаем map ключи и значения формировал RunConcurrentUpdates
  ASSERT_EQUAL(result.size(), key_count);	//проверяем правильній ли размер
  for (auto&  i : result) {
    AssertEqual(i.second, 6, "Key = " + to_string(i.first)); //?????
  }
}

void TestReadAndWrite() {
  ConcurrentMap<size_t, string> cm(5);

  auto updater = [&cm] {
    for (size_t i = 0; i < 50000; ++i) {
      cm[i].ref_to_value += 'a';
    }
  };
  auto reader = [&cm] {
    vector<string> result(50000);
    for (size_t i = 0; i < result.size(); ++i) {
      result[i] = cm[i].ref_to_value;
    }
    return result;
  };

  auto u1 = async(updater);
  auto r1 = async(reader);
  auto u2 = async(updater);
  auto r2 = async(reader);

  u1.get();
  u2.get();

  for (auto f : {&r1, &r2}) {
    auto result = f->get();
    ASSERT(all_of(result.begin(), result.end(), [](const string& s) {
      return s.empty() || s == "a" || s == "aa";
    }));
  }
}

void TestSpeedup() {
  {
    ConcurrentMap<int, int> single_lock(1);

    LOG_DURATION("Single lock");
    RunConcurrentUpdates(single_lock, 4, 50000);
  }
  {
    ConcurrentMap<int, int> many_locks(100);

    LOG_DURATION("100 locks");
    RunConcurrentUpdates(many_locks, 4, 50000);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestConcurrentUpdate);
  RUN_TEST(tr, TestReadAndWrite);
  RUN_TEST(tr, TestSpeedup);
}
