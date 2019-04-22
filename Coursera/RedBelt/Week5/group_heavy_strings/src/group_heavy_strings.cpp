#include "test_runner.h"
#include "profile.h"

#include <algorithm>
#include <string>
#include <vector>
#include <deque>


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
bool FindChar(String& a, String& b){ //Q*Q где Q длина строки
//	sort(b.begin(), b.end());
	for(auto& it_char : a) {//максимальная длина строки max 100
			auto it1 = std::find(b.begin(), b.end(), it_char);   //100
//			auto it1 = std::lower_bound(b.begin(), b.end(), it_char);

//			if(*it1!= it_char){
			if( it1 == b.end()){ //1
				return true; //1
			}

	}
		return false; //1
}

//template <typename String>
//String ComputeStringKey(const String& string) {
//  String chars = string;
//  sort(begin(chars), end(chars));
//  chars.erase(unique(begin(chars), end(chars)), end(chars));
//  return chars;
//}

template <typename String>
using Key = String;


template <typename String>
Key<String> ComputeStringKey(const String& string) {
  String chars = string;
  sort(begin(chars), end(chars));
  chars.erase(unique(begin(chars), end(chars)), end(chars));
  return chars;
}


template <typename String>
vector<Group<String>> GroupHeavyStrings(vector<String> strings) {
	LOG_DURATION("func ");
  map<Key<String>, Group<String>> groups_map;
  for (String& string : strings) {
    groups_map[ComputeStringKey(string)].push_back(move(string));
  }
  vector<Group<String>> groups;
  for (auto& [key, group] : groups_map) {
    groups.push_back(move(group));
  }
  return groups;
}







//template <typename String>
//vector<Group<String>> GroupHeavyStrings(vector<String> strings){
//						LOG_DURATION("func_duration");
//						vector<Group<String>> v; //1
//						if(strings.empty()) { //1
//								return v;  //1
//							}
//
////						set<size_t> jump;  //1
//						Group<String> g;  //1
//						size_t pos = 0;  //1
//						size_t current_pos = 0;  //1
//						bool flag_if_not = false;  //1
//
//
//						for(auto it = strings.begin(); it!= strings.end(); ++it){  // N 10'000 число строк
//
//							 g.clear();  // N максимум но не будет так как весь контейнер очищатьне будтм
//							 if(!((*it).empty())){  //1
//								 g.push_back(*it);  //1
//							 }
//
//							current_pos = pos + 1;  //1
////							while(jump.count(current_pos)>0){
////								if(current_pos== strings.size()) break;
////								++current_pos;
////							}
//
//							while( current_pos <= strings.size()) { //n 10'000
//
//								if(current_pos == strings.size()) {
//									break;
//								}
////								while(jump.count(current_pos)>1){
////									++current_pos;
////									if(current_pos ==strings.size()) break;
////								}
////								if(ComputeStringKey(*it)== ComputeStringKey(*(strings.begin() + current_pos))){
////									flag_if_not = false;
////								}else {
////									flag_if_not = true;
////								}
//
//
//
//								flag_if_not = FindChar((*(it)),( *(strings.begin() + current_pos))); //Q*Q 10'000
//								if(flag_if_not != true){
//									flag_if_not = FindChar( *(strings.begin() + current_pos), *(it)); //Q*Q 10'000
//								}
//
//								if(flag_if_not == false) {
//									if(!((*(strings.begin() + current_pos)).empty())){
//										g.push_back(move(*(strings.begin() + current_pos)));
////										jump.insert(current_pos);
//									}
//								}
//								flag_if_not = false;
//								++current_pos;
//							}
//							++pos;
//							if(!(g.empty())){
//							v.push_back(move(g));
//							}
//						}
//						return v;
//}




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

void Test100000Stringl() {

	vector<string> strings;
	string a;
	char n = 'a';
	for(int i=0; i<100; ++i){
         ++n;


		a.push_back(n);
	}

	for(int i=0; i<100000; ++i) {
		strings.push_back(a);
	}


  auto groups = GroupHeavyStrings(strings);
  ASSERT_EQUAL(groups.size(), 1);

}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestGroupingABC);
  RUN_TEST(tr, TestGroupingReal);
  RUN_TEST (tr, TestVectorSymbol);
  RUN_TEST (tr, TestEmptyVector);
  RUN_TEST (tr, Test100000Stringl);
  return 0;
}
