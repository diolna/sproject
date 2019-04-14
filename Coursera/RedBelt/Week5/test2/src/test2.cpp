#include "test_runner.h"

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// Объявляем Group<String> для произвольного типа String
// синонимом vector<String>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор групп — vector<Group<String>>.
template <typename String>
using Group = vector<String>;

// Ещё один шаблонный синоним типа
// позволяет вместо громоздкого typename String::value_type
// использовать Char<String>
template <typename String>
using Char = typename String::value_type;

// можно попробовать написать класс, который в конструкторе принимает vector обьектов
// прозиводит копирование єтого вектора и сортирует все его обьекті в отдельности.

// можно написать методы возвращающие позиции вектора в которых данные после сортировки оказались одинаковыми
// к примеру 1, 3, 4 возвращать можно в виде вектора v = {{1,5,6},{2}, {3,4}}

template <typename String>
class CmpStrings {
public:
	CmpStrings(vector<String> data)  {
		data_ = data;
		vector<size_t> word;
		size_t pos =0;
		sort(data_.begin(), data_.end());
			for(auto it_data = data_.begin(); it_data!=data_.end(); ++it_data) {

				cout << "test " << *it_data << " " << endl;
				auto it = lower_bound(it_data, data_.end(), *(it_data +  pos));
				while(it!= data_.end()){
					word.push_back(it - data_.begin());
					data_.erase(it);
					++it;

					it = lower_bound(it, data_.end(), *(it_data +  pos));

				}
				vec_.push_back(word);
				++pos;
			}

	}

	vector<vector<size_t>> GetVectorRepeatValue(){
							return vec_;
	}

private:
	vector<String> data_;
	vector<vector<size_t>> vec_;




};

template <typename String>
vector<Group<String>> GroupHeavyStrings(vector<String> strings) {

			CmpStrings<String> st(strings);
			for(auto i: st.GetVectorRepeatValue()) {
				for(auto y : i) {

					cout  << y << " ";
				}
				cout << "||";
			}
			cout << endl;
		}





void TestGroupingABC() {
  vector<string> strings = {"caab", "abc", "cccc", "bacc", "c"};
  auto groups = GroupHeavyStrings(strings);
  ASSERT_EQUAL(groups.size(), 2);
  sort(begin(groups), end(groups));  // Порядок групп не имеет значения
  ASSERT_EQUAL(groups[0], vector<string>({"caab", "abc", "bacc"}));
  ASSERT_EQUAL(groups[1], vector<string>({"cccc", "c"}));
}

void TestGroupingReal() {
  vector<string> strings = {"law", "port", "top", "laptop", "pot", "paloalto", "wall", "awl"};
  auto groups = GroupHeavyStrings(strings);
  ASSERT_EQUAL(groups.size(), 4);
  sort(begin(groups), end(groups));  // Порядок групп не имеет значения
  ASSERT_EQUAL(groups[0], vector<string>({"laptop", "paloalto"}));
  ASSERT_EQUAL(groups[1], vector<string>({"law", "wall", "awl"}));
  ASSERT_EQUAL(groups[2], vector<string>({"port"}));
  ASSERT_EQUAL(groups[3], vector<string>({"top", "pot"}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestGroupingABC);
  RUN_TEST(tr, TestGroupingReal);
  return 0;
}
