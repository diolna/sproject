#include "test_runner.h"
#include "profile.h"

#include <cstdint>
#include <iterator>
#include <numeric>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

template <typename RandomIt>
<<<<<<< HEAD
void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {
	LOG_DURATION("FUNC");
  vector<typename RandomIt::value_type> pool;
  move(first, last, back_inserter(pool));
  RandomIt cur_pos = first;
  size_t size_pool = last-first;
  RandomIt begin = first;
  for(size_t i=0; i< size_pool; ++i){

	   *(first++) = move(*(cur_pos));
	   *(++cur_pos ) = move({0});
	   -- size_pool;
	   if(size_pool==0) break;
	   cur_pos = (cur_pos + step_size-1)% size_pool;



  }
//  while (!pool.empty()) {
//    *(first++) = move(pool[cur_pos]);
//
//    pool.erase(move(pool.begin() + cur_pos));
//    if (pool.empty()) {
//      break;
//    }
//    cur_pos = (cur_pos + step_size - 1) % pool.size();
//  }
}
=======
//void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {
//	LOG_DURATION("all func");
//  deque<typename RandomIt::value_type> pool;  //создали вектор и заносим туда numbers
//
//  for(auto it = first; it!=last; ++it){
//	  pool.push_back(move(*it));
//
//  }
//
//  size_t cur_pos = 0;
//  int n =0;
//  //size_t pool_size = pool.size();
//   while (!pool.empty()) {
//
//	   {
//		   LOG_DURATION("add");
//
//		   for(auto it = pool.begin(); it!=pool.end(); ++it){
//			   cout << *it << " ";
//		   }
//		   cout << endl;
//
//	cout << "iteration = " << n << "cursor = " << cur_pos << endl;
//
//    *(first++) = move(pool[cur_pos]);    //изменяем сам numbers
//
//	   }
//
//    {
//    	LOG_DURATION("erase");
//
//    pool.erase(pool.begin() + cur_pos);
//    }
//    //--pool_size;
//    if (pool.empty()) {
//      break;
//    }
//	//if(pool_size == 0) break;
//    cur_pos = (cur_pos + step_size - 1) % pool.size();
//    ++n;
//  }
	void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {

	    vector<typename RandomIt::value_type> pool;
	    move(first, last, std::back_inserter(pool));
	    vector<bool> killed;
	    killed.assign(last-first, false);
	    size_t cur_pos = 0;

	    int count = 0;
	    for (auto it = first; it != last; it++) {
	        *first++ = move(pool[cur_pos]);
	        killed[cur_pos] = true;
	        if (++count == killed.size()) {
	            break;
	        }
	        for(int i = 0; i < step_size; ){
	            cur_pos++;
	            if (cur_pos == pool.size()) {
	                cur_pos = 0;
	            }
	            if (!killed[cur_pos]) {
	                i++;
	            }
	        }
	    }
	}


>>>>>>> 8c7f0daeeed1e18cf9630b585042c8b16e15e13a

vector<int> MakeTestVector() {
  vector<int> numbers(10);
  iota(begin(numbers), end(numbers), 0);
  return numbers;
}

void TestIntVector() {
  const vector<int> numbers = MakeTestVector();
  {
    vector<int> numbers_copy = numbers;
    MakeJosephusPermutation(begin(numbers_copy), end(numbers_copy), 1);
    ASSERT_EQUAL(numbers_copy, numbers);
  }
  {
    vector<int> numbers_copy = numbers;
    MakeJosephusPermutation(begin(numbers_copy), end(numbers_copy), 3);
    ASSERT_EQUAL(numbers_copy, vector<int>({0, 3, 6, 9, 4, 8, 5, 2, 7, 1}));
  }
}

// Это специальный тип, который поможет вам убедиться, что ваша реализация
// функции MakeJosephusPermutation не выполняет копирование объектов.
// Сейчас вы, возможно, не понимаете как он устроен, однако мы расскажем,
// почему он устроен именно так, далее в блоке про move-семантику —
// в видео «Некопируемые типы»

struct NoncopyableInt {
  int value;
  //NoncopyableInt(const int a) {value = a;}
  
  NoncopyableInt(const NoncopyableInt&) = delete;
  NoncopyableInt& operator=(const NoncopyableInt&) = delete;

  NoncopyableInt(NoncopyableInt&&) = default;
   NoncopyableInt& operator=(NoncopyableInt&&) = default;
};

bool operator == (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
  return move(lhs.value) == move(rhs.value);
}

ostream& operator << (ostream& os, const NoncopyableInt& v) {
  return os << move(v.value);
}

void TestAvoidsCopying() {
  vector<NoncopyableInt> numbers;

  NoncopyableInt a = {1};
  numbers.push_back(move(a));
  a = {2};
  numbers.push_back(move(a));
  a = {3};
  numbers.push_back(move(a));
  a = {4};
  numbers.push_back(move(a));
  a = {5};
  numbers.push_back(move(a));

<<<<<<< HEAD
  numbers.push_back({1});
  numbers.push_back({2});
  numbers.push_back({3});
  numbers.push_back({4});
  numbers.push_back({5});
=======
  MakeJosephusPermutation(begin(numbers), end(numbers), 2 );
>>>>>>> 8c7f0daeeed1e18cf9630b585042c8b16e15e13a


  vector<NoncopyableInt> expected;
<<<<<<< HEAD
  expected.push_back({1});
  expected.push_back({3});
  expected.push_back({5});
  expected.push_back({4});
  expected.push_back({2});
=======
  a = {1};
  expected.push_back(move(a));
    a = {3};
    expected.push_back(move(a));
    a = {5};
    expected.push_back(move(a));
    a = {4};
    expected.push_back(move(a));
    a = {2};
    expected.push_back(move(a));
>>>>>>> 8c7f0daeeed1e18cf9630b585042c8b16e15e13a

  ASSERT_EQUAL(numbers, expected);
}

int main() {

  TestRunner tr;
  RUN_TEST(tr, TestIntVector);
  RUN_TEST(tr, TestAvoidsCopying);
  return 0;
}
