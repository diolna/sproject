
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


	using  Pair = pair<T, int>;

void Add(T object){

	a[0].first = move(object);
	a[0].second = 0;




 }

// Увеличить приоритет объекта на 1
  void Promote(int id){

	++a[id].second;

  }

private :
 map<int, Pair> a;


};


int main() {

	int ttt = 2;
	vector<StringNonCopyable> v;
	v.push_back(move("red"));
	v.push_back(move("red1"));
	v.push_back(move("red2"));

	*v.begin() = "yellow";

	cout << v[0] << endl;


	A<StringNonCopyable> a;
	StringNonCopyable s;
	s = "aaa";
	a.Add("aaa");
	a.Promote(0);

	return 0;
}
