#include "test_runner.h"
#include "profile.h"

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

template <typename String>
vector<Group<String>> GroupHeavyStrings(vector<String> strings){
	LOG_DURATION("func");

						vector<Group<String>> v;
						Group<String> g;
						size_t pos = 0;
						size_t current_pos = 0;
						bool flag_if_not = false;
						if(strings.empty()) {
							return v;
						}
						for(auto it = strings.begin(); it!= strings.end(); ++it){

							 g.clear();
							 if(!((*it).empty())){
							 g.push_back(*it);
							 }
							current_pos = pos + 1;
							while( current_pos != pos) {


								if(current_pos == strings.size()) {
//									current_pos =0;
									break;
								}
//								if(current_pos == pos) {
//									break;
//								}
//								{
//									LOG_DURATION("find");

								for(auto& it_char : *(strings.begin() + current_pos)) {


									auto it1 = std::find((*it).begin(), (*it).end(), it_char);
									if( it1 == (*it).end()){
										flag_if_not = true;
									}
								}
								for(auto& it_char : *(it)) {

//								  auto symb = *(strings.begin() + current_pos);

//									auto it = std::find(symb.begin(), symb.end(), it_char);
									if(move(std::find((*(strings.begin() + current_pos)).begin()
												, (*(strings.begin() + current_pos)).end()
												, it_char))== (*(strings.begin() + current_pos)).end()){
											flag_if_not = true;
											}
								}
//								}

								if(flag_if_not == false) {
									if(!((*(strings.begin() + current_pos)).empty())){

									g.push_back(move(*(strings.begin() + current_pos)));
									}
									}


								flag_if_not = false;
								++current_pos;
							}
							++pos;
							if(!(g.empty())){
							v.push_back(move(g) );
							}
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
void TestVectorSymbol() {
  vector<vector<char>> strings = {{'c','a','a','b'}, {'a','b','c'}, {'c','c','c','c'}, {'b','a','c','c'}, {'c'}};
  auto groups = GroupHeavyStrings(strings);
  ASSERT_EQUAL(groups.size(), 2);
  sort(begin(groups), end(groups));  // Порядок групп не имеет значения
  ASSERT_EQUAL(groups[0], vector<vector<char>>({{'c','a','a','b'}, {'a','b','c'}, {'b','a','c','c'}}));
  ASSERT_EQUAL(groups[1], vector<vector<char>>({{'c','c','c','c'},{'c'}}));
}

void TestEmptyVector() {
  vector<vector<char>> strings;
  auto groups = GroupHeavyStrings(strings);
  ASSERT_EQUAL(groups.size(), 0);

}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestGroupingABC);
  RUN_TEST(tr, TestGroupingReal);
  RUN_TEST (tr, TestVectorSymbol);
  RUN_TEST (tr, TestEmptyVector);
  return 0;
}
