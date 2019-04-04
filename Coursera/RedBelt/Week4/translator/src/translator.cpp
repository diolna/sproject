#include "test_runner.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <string_view>
#include <iostream>

using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target){
	  string a, b;
	  a = source;
	  b = target;

	 auto aa = ss.insert(a);
	 auto bb = ss.insert(b);

	  base_s_t_[*aa.first].push_back(*bb.first);
	  base_t_s_[*bb.first].push_back(*aa.first);
//	  base_s_t_[source].push_back(target);
//	  base_t_s_[target].push_back(source);

  }
  string_view TranslateForward(string_view source) const{
	  if(base_s_t_.count(source)==1) {

		  return *(prev(base_s_t_.at(source).end()));
	  } else {
		  return "";
	  }
  }
  string_view TranslateBackward(string_view target) const {
	  if(base_t_s_.count(target)==1) {

	  		  return *(prev(base_t_s_.at(target).end()));
	  	  } else {
	  		  return "";
	  	  }
  }

private:
  set<string> ss;
  map<string_view, vector<string_view>> base_s_t_;
  map<string_view, vector<string_view>> base_t_s_;
};

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}
void TestMy(){
	Translator trans;
	{
		string okno = "okno";
		string stol = "stol";
		trans.Add(okno, string("window"));
		trans.Add(stol, string("table"));
	}

	ASSERT_EQUAL(trans.TranslateForward("okno"), "window");
	  ASSERT_EQUAL(trans.TranslateBackward("table"), "stol");
	  ASSERT_EQUAL(trans.TranslateBackward("stol"), "");

}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  RUN_TEST(tr, TestMy);
  return 0;
}
