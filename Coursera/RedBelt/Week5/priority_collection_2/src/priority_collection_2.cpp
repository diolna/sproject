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

  // Добавить объект с нулевым приоритетом
  // с помощью перемещения и вернуть его идентификатор
    Id Add(T object){


	  ++max_id_;
	 data_[max_id_][move(object)] = 0;

	 priority_[0].insert(max_id_);
	  return max_id_;
  }


  // Добавить все элементы диапазона [range_begin, range_end)
  // с помощью перемещения, записав выданные им идентификаторы
  // в диапазон [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end,
           IdOutputIt ids_begin){

	  	  for(auto it = range_begin; it!= range_end; ++it){
	  		  ++max_id_;
	  		  data_[max_id_][made_move(*it)] = 0;
	  		priority_[0].insert(max_id_);
	  		  if(it == range_begin) ids_begin = prev(data_.end());
	  	  }

  }

  // Определить, принадлежит ли идентификатор какому-либо
  // хранящемуся в контейнере объекту
  bool IsValid(Id id) const{
	  if(data_.count(id)>0) return true;
	  else return false;
  }

  // Получить объект по идентификатору
  const T& Get(Id id) const {
	  	  return data_[id].first;
  }

  // Увеличить приоритет объекта на 1
  void Promote(Id id){



//	int pr = data_[id][make_move_iterator(data_[id].begin())->first];
//
//	priority_[pr].erase(id);
//	++pr;
//	data_[id][make_move_iterator(data_[id].begin())->first] = pr;
//	priority_[pr].insert(id);
	  auto it = data_[id].begin();
	  ++it->second;
  }

  // Получить объект с максимальным приоритетом и его приоритет
  pair<const T&, int> GetMax() const {    // map<Id, map<T, int>>
	  return data_[max_id_];
  }

  // Аналогично GetMax, но удаляет элемент из контейнера
  pair<T, int> PopMax(){

	  pair<T, int> p;
	  --max_id_;

	  //p.first = move(make_move_iterator(data_[max_id_+1].begin())->first);
	  //p.second = data_[max_id_+1].begin()->second;




	  return move(data_[max_id_ + 1]);

  }

private:
  // Приватные поля и методы
  map<Id, map<T, int>> data_;
  Id max_id_=0;
  map<int, set<Id>> priority_;

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

int main() {

  TestRunner tr;
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
