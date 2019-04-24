
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

class StringNonCopyable : public string {
public:
  using string::string;  // Позволяет использовать конструкторы строки
  StringNonCopyable(const StringNonCopyable&) = delete;
 StringNonCopyable(StringNonCopyable&&) = default;
  StringNonCopyable& operator=(const StringNonCopyable&) = delete;
  StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

template <typename T>
class A {
public:

void Add(T object){

a[0][move(object)] = 0;


 }

// Увеличить приоритет объекта на 1
  void Promote(int id){

	//T key = data_[id].begin()->first;

//	int pr = a[id][make_move_iterator(a[id].begin())->first];

	//priority_[pr].erase(id);
//	++pr;
//	a[id][make_move_iterator(a[id].begin())->first] = pr;
	//priority_[pr].insert(id);

	  auto it = (a[id].begin());
	  it->second = 3;
	  auto i = (make_move_iterator(it))->first;
	  cout << it->first << endl;
	  cout << it->second << endl;
  }

private :
 map<int, map<T, int>> a;

};


int main() {

	A<StringNonCopyable> a;
	StringNonCopyable s;
	s = "aaa";
	a.Add("aaa");
	a.Promote(0);

	return 0;
}
