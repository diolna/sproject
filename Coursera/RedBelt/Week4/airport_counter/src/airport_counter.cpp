#include "test_runner.h"
#include "profile.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <vector>
#include <set>


using namespace std;

// TAirport should be enum with sequential items and last item TAirport::Last_
template <typename TAirport>
class AirportCounter {
public:
  // ����������� �� ���������: ������ ��������� ���� ����
  AirportCounter(){

//	  for( uint32_t i = 0; i < static_cast<uint32_t>(TAirport::Last_); ++i){
//		 // data_[i] = Pair((TAirport)i, 0);
//		  data_[i] = 0;
//
//	  }
	  data_.fill(0);

  }

  // ����������� �� ��������� ��������� ���� TAirport
  template <typename TIterator>
  AirportCounter(TIterator begin, TIterator end) : AirportCounter() {

//
//	  for( uint32_t i = 0; i < static_cast<uint32_t>(TAirport::Last_); ++i){
//	 		 // data_[i] = Pair((TAirport)i, 0);
//		  	  data_[i] = 0;
//	  }

	  for(auto& i = begin; i!= end; ++i){

		 // data_.at(static_cast<uint32_t>(*i)).second +=1;
		  data_.at(static_cast<uint32_t>(*i)) +=1;

	  }

  }

  // �������� ���������� ���������, ������ �������
  size_t Get(TAirport airport) const {

	  uint32_t index = static_cast<uint32_t>(airport);
	 // return data_[index].second;
	  return data_[index];


  }

  // �������� ������ �������
  void Insert(TAirport airport){
	  uint32_t index = static_cast<uint32_t>(airport);
	  if(index <= static_cast<uint32_t>(TAirport::Last_)){
		  //data_[index].second +=1;
		  data_[index] +=1;
	  }

  }

  // ������� ���� ��������� ������� ��������
  void EraseOne(TAirport airport) {
	  	  uint32_t index = static_cast<uint32_t>(airport);
	  	  if(index <= static_cast<uint32_t>(TAirport::Last_)){
	  		  //if(data_[index].second !=0) {
	  		  if(data_[index]!=0){
	  			  	// data_[index].second -=1;
	  			  data_[index] -=1;
	  		  }
	  	  }
  }

  // ������� ��� ��������� ������� ��������
  void EraseAll(TAirport airport){
	  	  for(size_t i=0; i< data_.size(); ++i){
	  		  //data_[i].second = 0;
	  		  data_[i] = 0;
	  	  }
  }

  using Item = pair<TAirport, size_t>;
  using Items = array<Item, static_cast<uint32_t>(TAirport::Last_)>;

  // �������� ��������� ������, �� �������� ����� ����������������,
  // ������� ����� �������� ���� Item - ��� (��������, ����������),
  // ������������� �� ���������
  Items GetItems() const {
	 // return data_;
	  Items items;
	  for(size_t i=0; i< data_.size(); ++i){

		  items[i] = {static_cast<TAirport>(i), data_[i]};
	  }
	  return items;
  }
  pair<TAirport, size_t> Pair(TAirport x, size_t y){
	  return {x,y};

  }

private:

  //Items data_;
  array<size_t, static_cast<uint32_t>(TAirport::Last_)> data_;



};

void TestMoscow() {
  enum class MoscowAirport {
    VKO,
    SVO,
    DME,
    ZIA,
    Last_
  };

  const vector<MoscowAirport> airports = {
      MoscowAirport::SVO,
      MoscowAirport::VKO,
      MoscowAirport::ZIA,
      MoscowAirport::SVO,
  };
  AirportCounter<MoscowAirport> airport_counter(begin(airports), end(airports));

  ASSERT_EQUAL(airport_counter.Get(MoscowAirport::VKO), 1);
  ASSERT_EQUAL(airport_counter.Get(MoscowAirport::SVO), 2);
  ASSERT_EQUAL(airport_counter.Get(MoscowAirport::DME), 0);
  ASSERT_EQUAL(airport_counter.Get(MoscowAirport::ZIA), 1);

  using Item = AirportCounter<MoscowAirport>::Item;
  vector<Item> items;
  for (const auto& item : airport_counter.GetItems()) {
    items.push_back(item);
  }
  ASSERT_EQUAL(items.size(), 4);

#define ASSERT_EQUAL_ITEM(idx, expected_enum, expected_count) \
  do { \
    ASSERT_EQUAL(static_cast<size_t>(items[idx].first), static_cast<size_t>(MoscowAirport::expected_enum)); \
    ASSERT_EQUAL(items[idx].second, expected_count); \
  } while (false)

  ASSERT_EQUAL_ITEM(0, VKO, 1);
  ASSERT_EQUAL_ITEM(1, SVO, 2);
  ASSERT_EQUAL_ITEM(2, DME, 0);
  ASSERT_EQUAL_ITEM(3, ZIA, 1);

  airport_counter.Insert(MoscowAirport::VKO);
  ASSERT_EQUAL(airport_counter.Get(MoscowAirport::VKO), 2);

  airport_counter.EraseOne(MoscowAirport::SVO);
  ASSERT_EQUAL(airport_counter.Get(MoscowAirport::SVO), 1);

  airport_counter.EraseAll(MoscowAirport::VKO);
  ASSERT_EQUAL(airport_counter.Get(MoscowAirport::VKO), 0);
}

enum class SmallCountryAirports {
  Airport_1,
  Airport_2,
  Airport_3,
  Airport_4,
  Airport_5,
  Airport_6,
  Airport_7,
  Airport_8,
  Airport_9,
  Airport_10,
  Airport_11,
  Airport_12,
  Airport_13,
  Airport_14,
  Airport_15,
  Last_
};

void TestManyConstructions() {
  default_random_engine rnd(20180623);
  uniform_int_distribution<size_t> gen_airport(
    0, static_cast<size_t>(SmallCountryAirports::Last_) - 1
  );

  array<SmallCountryAirports, 2> airports;
  for (auto& x : airports) {

    x = static_cast<SmallCountryAirports>(gen_airport(rnd));
  }

  uint64_t total = 0;
  for (int step = 0; step < 100'000'000; ++step) {
    AirportCounter<SmallCountryAirports> counter(begin(airports), end(airports));
    total += counter.Get(SmallCountryAirports::Airport_1);

  }
  // Assert to use variable total so that compiler doesn't optimize it out
  ASSERT(total < 1000);
}

enum class SmallTownAirports {
  Airport_1,
  Airport_2,
  Last_
};

void TestManyGetItems() {
  default_random_engine rnd(20180701);
  uniform_int_distribution<size_t> gen_airport(
    0, static_cast<size_t>(SmallTownAirports::Last_) - 1
  );

  array<SmallTownAirports, 2> airports;
  for (auto& x : airports) {
    x = static_cast<SmallTownAirports>(gen_airport(rnd));
  }

  uint64_t total = 0;
  for (int step = 0; step < 100'000'000; ++step) {
    AirportCounter<SmallTownAirports> counter(begin(airports), end(airports));
    total += counter.Get(SmallTownAirports::Airport_1);

    for (const auto [airport, count] : counter.GetItems()) {
      total += count;
    }
  }
  // Assert to use variable total so that compiler doesn't optimize it out
  ASSERT(total > 0);
}

void TestMostPopularAirport() {
  default_random_engine rnd(20180624);
  uniform_int_distribution<size_t> gen_airport(
    0, static_cast<size_t>(SmallCountryAirports::Last_) - 1
  );

  array<pair<SmallCountryAirports, SmallCountryAirports>, 1000> dayly_flight_report;
  for (auto& x : dayly_flight_report) {
    x = {
      static_cast<SmallCountryAirports>(gen_airport(rnd)),
      static_cast<SmallCountryAirports>(gen_airport(rnd))
    };
  }

  const int days_to_explore = 365 * 500;

  vector<SmallCountryAirports> most_popular(days_to_explore);

  for (int day = 0; day < days_to_explore; ++day) {
    AirportCounter<SmallCountryAirports> counter;
    for (const auto& [source, dest] : dayly_flight_report) {
      counter.Insert(source);
      counter.Insert(dest);
    }

    const auto items = counter.GetItems();
    most_popular[day] = max_element(begin(items), end(items), [](auto lhs, auto rhs) {
      return lhs.second < rhs.second;
    })->first;
  }

  ASSERT(all_of(begin(most_popular), end(most_popular), [&](SmallCountryAirports a) {
    return a == most_popular.front();
  }));
}

int main() {
  TestRunner tr;

  // �� �������, ��������� ����� ������ ���� ������ �� ������ ���������
  // ���� ������. ���� ���� ����� ����� ���� ���� ������ ���� ������,
  // ���������� ��������� ���� ������� � ����������� �������. ��������,
  // ��� ����� ������ ������, � ���� ������� ����� �������.

  // ����� ����, �� �������� �������� ����������� ��� ���������� ����.

  LOG_DURATION("Total tests duration");
  RUN_TEST(tr, TestMoscow);
  RUN_TEST(tr, TestManyConstructions);
  RUN_TEST(tr, TestManyGetItems);
  RUN_TEST(tr, TestMostPopularAirport);
  return 0;
}
