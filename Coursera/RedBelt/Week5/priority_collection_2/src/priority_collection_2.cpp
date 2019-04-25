#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <string>


using namespace std;



template <typename T>
class PriorityCollection {
public:
  using Id =   int;/* тип, используемый для идентификаторов */;
  using Pair = pair<T, int>;

  // Добавить объект с нулевым приоритетом
  // с помощью перемещения и вернуть его идентификатор
    Id Add(T object){


	  ++max_id_;
	// data_[max_id_][move(object)] = 0;
	  data_[max_id_].first = move(object);
	  data_[max_id_].second = 0;

	 priority_[0].insert(max_id_);
	  //prior[max_id_] = 0;
	  return max_id_;
  }


  // Добавить все элементы диапазона [range_begin, range_end)
  // с помощью перемещения, записав выданные им идентификаторы
  // в диапазон [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end,
           IdOutputIt ids_begin){
	  	  vector<Id> id_vec;

	  	  for(auto it = make_move_iterator(range_begin); it!= make_move_iterator(range_end); ++it){
	  		  ++max_id_;
	  		  id_vec.push_back(max_id_);
	  		  	  data_[max_id_].first = move(*it);
	  			  data_[max_id_].second = 0;
	  		priority_[0].insert(max_id_);
	  		//prior[max_id_] = 0;
	  	  }
	  	  move(id_vec.begin(), id_vec.end(), ids_begin);


  }

  // Определить, принадлежит ли идентификатор какому-либо
  // хранящемуся в контейнере объекту
  bool IsValid(Id id) const{
	  if(data_.count(id)>0) return true;
	  else return false;
  }

  // Получить объект по идентификатору
  const T& Get(Id id) const {
	  	  return data_.at(id).first;
  }

  // Увеличить приоритет объекта на 1
  void Promote(Id id){

	  int pr = data_.at(id).second;
	  ++data_.at(id).second;

	  priority_.at(pr).erase(id);
	  if(priority_.at(pr).size() == 0){
		  priority_.erase(pr);
	  }
	  ++pr;
	  priority_[pr].insert(id);

  }

  // Получить объект с максимальным приоритетом и его приоритет
  pair<const T&, int> GetMax() const {    // map<Id, map<T, int>>

	  return { data_.at(
			* (prev((prev(priority_.end())->second).end()))
		  ).first
		  ,  prev(priority_.end())->first };

	//  return {data_.at(max_id_).first, data_.at(max_id_).second};
  }

  // Аналогично GetMax, но удаляет элемент из контейнера
  pair<T, int> PopMax(){

	  pair<T, int> p;

	  Id id_max_pr = *(prev((prev(priority_.end())->second).end()));
	  int max_pr = prev(priority_.end())->first;
	  p = move(data_[id_max_pr]);
	  data_.erase(id_max_pr);
	  priority_.at(max_pr).erase(id_max_pr);
	  if(priority_.at(max_pr).size()==0){
		  priority_.erase(max_pr);
	  }
	  if(id_max_pr == max_id_){
		  --max_id_;
	  }




	  return p;

  }

private:
  // Приватные поля и методы
  map<Id, Pair> data_;
  Id max_id_=0;
  map<int, set<Id>> priority_;
  //map<Id, int> prior;

};



//using StringNonCopyable = string;
class StringNonCopyable : public string {
public:
  using string::string;  // Позволяет использовать конструкторы строки
  StringNonCopyable(const StringNonCopyable&) = delete;
 StringNonCopyable(StringNonCopyable&&) = default;
  StringNonCopyable& operator=(const StringNonCopyable&) = delete;
  StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
  PriorityCollection<StringNonCopyable> strings;
  const auto white_id = strings.Add("white");

  const auto yellow_id = strings.Add("yellow");

  const auto red_id = strings.Add("red");


  strings.Promote(yellow_id);

  for (int i = 0; i < 2; ++i) {
    strings.Promote(red_id);
  }

  strings.Promote(yellow_id);
  {
    const auto item = strings.PopMax();

    ASSERT_EQUAL(item.first, "red");
    ASSERT_EQUAL(item.second, 2);
  }
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "yellow");
    ASSERT_EQUAL(item.second, 2);
  }
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "white");
    ASSERT_EQUAL(item.second, 0);
  }
}

void TestGet() {
  PriorityCollection<StringNonCopyable> strings;
  const auto white_id = strings.Add("white");

  const auto yellow_id = strings.Add("yellow");

  const auto red_id = strings.Add("red");


  strings.Promote(yellow_id);

  for (int i = 0; i < 2; ++i) {
    strings.Promote(red_id);
  }

  strings.Promote(yellow_id);
  {
    const auto item = strings.GetMax();

    ASSERT_EQUAL(item.first, "red");
    ASSERT_EQUAL(item.second, 2);
  }

}
void TestAddIt(){
	PriorityCollection<StringNonCopyable> strings;
	vector<StringNonCopyable> vec;
	vec.push_back(move("white"));
	vec.push_back(move("red"));
	vec.push_back(move("yellow"));
	vector<int> vec1(vec.size(), 0);
	strings.Add(vec.begin(), vec.end(), vec1.begin() );

	ASSERT_EQUAL(vec1.size(), 3);
	ASSERT_EQUAL(vec1[2], 3);

	const auto white1_id = strings.Add("white1");
	const auto white2_id = strings.Add("white2");
	const auto white3_id = strings.Add("white3");

	strings.Add(vec.begin(), vec.end(), vec1.begin() );

	ASSERT_EQUAL(vec1.size(), 3);
	ASSERT_EQUAL(vec1[2], 9);


}

void TestGetMax(){
	PriorityCollection<StringNonCopyable> strings;

	const auto white1_id = strings.Add("white1");
	const auto white2_id = strings.Add("white2");


	for (int i = 0; i < 2; ++i) {
	    strings.Promote(white1_id);
	  }
	for (int i = 0; i < 5; ++i) {
		    strings.Promote(white2_id);
		  }

	auto p = strings.GetMax();
	ASSERT_EQUAL(p.first, "white2");
	ASSERT_EQUAL(p.second, 5);


}

int main() {

  TestRunner tr;


  RUN_TEST(tr, TestNoCopy);
  RUN_TEST(tr, TestGet);
  RUN_TEST(tr, TestAddIt);
  RUN_TEST(tr, TestGetMax);


  return 0;
}
