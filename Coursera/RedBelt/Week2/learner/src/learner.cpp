#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <iterator>

#include "profile.h"

using namespace std;

class Learner {
 private:
  vector<string> dict;
  set<string> sort_dict;


 public:
  int Learn(const vector<string>& words) {
	  LOG_DURATION("learn");

    int newWords = 0;
    for (const auto& word : words) {

    	if(sort_dict.find(word)== sort_dict.end()){
      //if (find(sort_dict.begin(), sort_dict.end(), word) == sort_dict.end()) {
        ++newWords;
        //dict.push_back(word);
        sort_dict.insert(word);
      }
    }
    return newWords;
  }

  vector<string> KnownWords() {
	LOG_DURATION("knowWords:sssss");
  // sort(dict.begin(), dict.end());
   // dict.erase(unique(dict.begin(), dict.end()), dict.end());
	dict.erase(dict.begin(), dict.end());
	dict.insert(dict.end()
			, make_move_iterator(sort_dict.begin())
			, make_move_iterator(sort_dict.end()));

    return dict;
  }
};

int main() {

  LOG_DURATION("total: ");
  Learner learner;
  string line;

  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }

    cout << learner.Learn(words) << "\n";
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }

}
