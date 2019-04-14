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

template <typename String>
vector<Group<String>> GroupHeavyStrings(vector<String> strings) {

							vector<Group<String>> v;      //1
							Group<String> g;			//1
							size_t pos = 0;					//1
							size_t current_pos = 0;				//1
							bool flag_if_not = false;			//1
							for(auto it = strings.begin(); it!= strings.end(); ++it){ //Q*Q*N*N*S

								// Q - количество встрок 100000
								// N -100
								// S max = 100
								// 1*10X16

								 g.clear(); 					//Q
								 if(!((*it).empty())){			//1
								 g.push_back(*it);				//1
								 }
								current_pos = pos + 1;			//1
								while( current_pos != pos) {	//Q*N*N*S


									if(current_pos == strings.size()) { //1
										current_pos =0;					//1
									}
									if(current_pos == pos) {			//1
										break;							//1
									}


									string s, s1;
									for(auto& ch : *it){
										s.push_back(char(ch));
									}
									for(auto& ch : *(strings.begin() + current_pos)) {
										s1.push_back(char(ch));
									}


									for(auto& it_char : s) { //N*N*S


										if((s1).find_first_of(it_char)== std::string::npos	) { //N*S
											flag_if_not = true;							//1
										}
									}
									for(auto& it_char : s1) {									//N*N*S
										if(s.find_first_of(it_char)== std::string::npos	) {		//N*S
												flag_if_not = true;								//1
												}
									}

	//								cout << endl;
									if(flag_if_not == false) {										//1
										if(!((*(strings.begin() + current_pos)).empty())){			//1
//											cout << "save " << (*(strings.begin() + current_pos)) << " " << endl;
										g.push_back(move(*(strings.begin() + current_pos)));		//1
										}
										}


									flag_if_not = false;			//1
									++current_pos;					//1
								}
								++pos;							//1
								if(!(g.empty())){						//1
								v.push_back(g);						//1
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

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestGroupingABC);
  RUN_TEST(tr, TestGroupingReal);
  RUN_TEST (tr, TestVectorSymbol);
  return 0;
}
