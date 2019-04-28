#include "test_runner.h"
#include "profile.h"

#include <set>
#include <map>
#include <string>
#include <iostream>
#include <future>

using namespace std;



struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other){
	  for(auto& i : other.word_frequences){
		  if(this->word_frequences.count(i.first) > 0) {
			  this->word_frequences.at(i.first) += i.second;
		  } else {
			  this->word_frequences[i.first] = i.second;
		  }
	  }
  }
};

Stats ExploreLine(const set<string>& key_words, const string& line) {
	string word;
		Stats w;
		stringstream input;
		input << line;

		while(getline(input, word, ' ')){
		//set<char> punct = {'!', ',', '.', ':', '?','/','|','%'};
//		if(punct.count(word[word.size()-1])>0){
//			word.pop_back();
//		}

		if(key_words.count(word)>0) {
			if(w.word_frequences.count(word)>0) {
				++w.word_frequences.at(word);

			} else {
				w.word_frequences[word] = 1;

			}
		}
		}

		return w;
}

Stats ExploreKeyWordsSingleThread(
  const set<string>& key_words, istream& input
) {
  Stats result;
  for (string line; getline(input, line); ) {
    result += ExploreLine(key_words, line);
  }
  return result;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
	string line, s;
	Stats w;
	vector<string> v;
	size_t PAGE = 20000;
	size_t counter = 0;
	future<Stats> f1,f2;

	while(getline(input, line)){
		++counter;
		s += line + ' ';

		if(counter == PAGE) {

			v.push_back(s);
			s.clear();
			counter = 0;

		}
	}

	v.push_back(s);
//	for (auto& i : v){
//		cout << i << endl;
//	}


	f1 = async(ExploreLine, ref(key_words), ref(v[0]));
	if(v.size() >= 2){
	 f2 = async(ExploreLine, ref(key_words), ref(v[1]));
	 size_t i =2;
	while(v.size()-i >0){
		 w += ExploreLine(key_words, v[i]);
		 ++i;
	}

	}
	w += f1.get();
	if(v.size() >= 2){
	w += f2.get();
	}
//

		return w;


//	Stats w;
//	string line;
//	size_t PAGES =13000;
//	size_t counter=0;
//	stringstream input_page1, input_page2, input_page, input_page3;
//
//	bool flag2 = false;
//	bool flag3 = false;
//	bool flag = false;
//
//
//	future<Stats> f1, f2, f3, f4;
//
//
//
//
//	while(getline(input, line)){
//		++counter;
//		if(counter > PAGES * 3){
//			input_page3 << line + '\n';
//		}else if(counter > PAGES * 2 && counter <= PAGES * 3){
//			input_page2 << line + '\n';
//		}else if(counter > PAGES && counter <= PAGES * 2) {
//			input_page1 << line + '\n';
//		} else {
//			input_page << line + '\n';
//		}
//		if(counter == PAGES) {
//			f1 = async(ExploreKeyWordsSingleThread, ref(key_words), ref(input_page));
//			flag = true;
//		} else if (counter == PAGES * 2) {
//			f2 = async(ExploreKeyWordsSingleThread, ref(key_words), ref(input_page1));
//			flag2 = true;
//		} else if(counter == PAGES * 3) {
//			f3 = async(ExploreKeyWordsSingleThread, ref(key_words), ref(input_page2));
//			flag3 = true;
//		}
//	}
//
//	if( flag2 && flag && flag3){
//		f4 = async(ExploreKeyWordsSingleThread, ref(key_words), ref(input_page3));
//	} else if( !flag2 && flag){
//			f4 = async(ExploreKeyWordsSingleThread, ref(key_words), ref(input_page1));
//
//		} else if(!flag && !flag2 && !flag3) {
//			f4 = async(ExploreKeyWordsSingleThread, ref(key_words), ref(input_page));
//
//		} else if(flag && flag2 && !flag3) {
//			f4 = async(ExploreKeyWordsSingleThread, ref(key_words), ref(input_page2));
//		}
//
//	if(flag && flag2 && flag3 ){
//	w +=f1.get();
//	w += f2.get();
//	w += f3.get();
//
//
//	}else if( flag && !flag2 && !flag3){
//		w = f1.get();
//
//	} else if( flag && flag2 && !flag3){
//		w += f1.get();
//		w += f2.get();
//
//	}
//	w += f4.get();
//	return w;

}

void TestBasic() {

	LOG_DURATION("time ");
	const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
  ss << "this new yangle service really rocks\n";
  ss << "It sucks when yangle isn't available\n";
  ss << "10 reasons why yangle is the best IT company\n";
  ss << "yangle rocks others suck\n";
  ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}
void TestBasic1() {

	LOG_DURATION("time ");
	const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
  for(int i=0; i<10000; ++i){
  ss << "this new yangle service really rocks fff ddd ddd ddd ggg ggg ggg ggg dfdf dfd dfd dfd df df\n";
  ss << "It sucks when yangle isn't available df df df df ddsf dsf df dg dsg d dsg dsg dsg ds dsf ds\n";
  ss << "10 reasons why yangle is the best IT company df df ds dsf ewt t dsg gs g df sdfdsf df sdf \n";
  ss << "yangle rocks others suck dfsdf sdf sdf sdf sdf df dsfs sdf sdfsdf sdf dsfsdfdsf sdf sdf sdf sdfsdf\n";
  ss << "Goondex really sucks, but yangle rocks. Use yangle dsf dsf sdf dsf sdf  sdf sdf sdf g gw fds dsf\n";
  }

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 60000},
    {"rocks", 20000},
    {"sucks", 10000}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
  RUN_TEST(tr, TestBasic1);
}

