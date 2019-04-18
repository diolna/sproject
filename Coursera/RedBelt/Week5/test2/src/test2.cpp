#include "test_runner.h"

#include <algorithm>
#include <string>
#include <vector>
#include <set>

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
	CmpStrings(vector<String>& data)  {
		data_ = data;
		vector<size_t> word;
		set<int> complite_pos;
		size_t temp =0;

				for(auto it_data = data_.begin(); it_data!=data_.end(); ++it_data) {
				sort((*it_data).begin(), (*it_data).end());


			}
			auto it_current = data_.begin();
			while(it_current!= data_.end()){
				word.clear();
				if(it_current == data_.begin()){
				word.push_back(it_current - data.begin());
				complite_pos.insert(it_current - data.begin());
				}
				size_t pos =0 ;
				while(pos!= data_.size()-1){
				while(complite_pos.count(pos) > 0) {
					++pos;
					}
				if(data_.begin() + pos != data_.end()){
					if((*it_current).size() < (*(data_.begin() + pos)).size()){
						for(auto& i: *(it_current)){
							if(find(data_.begin() +pos
									, data_.end(), i) == data_.end()) {
								temp = 1;
							}
						}
						if(temp == 0 ) {
						word.push_back( pos);
						complite_pos.insert(pos);
						}
						temp =0;
					}

				}
				++pos;
				}



				while(complite_pos.count(it_current - data_.begin()) > 0) {

											++it_current;
								}
				++it_current;
				if(it_current != data_.end()){
				cout << *it_current << " ";
				}
				vec_.push_back(word);
		}

			cout << vec_.size() << endl;
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
			vector<Group<String>> v;
			Group<String> g;
			CmpStrings<String> st(strings);
			auto vvv = st.GetVectorRepeatValue();
			cout << "size " << vvv.size() << endl;
			for(auto& i: vvv) {
				for(auto& y : i) {

					g.push_back(strings[y]);
					cout << strings[y] << " ";
				}
				cout << endl;
				v.push_back(g);
			}

			return v;
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
