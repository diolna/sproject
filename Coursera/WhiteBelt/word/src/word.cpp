
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> v;
	string w;
	auto it = s.begin();
	 while(it!=s.end()) {

		 if (*it != ' ') {
			 w += *it;
		 }
		 else {
			 v.push_back(w);
			 w = "";
		 }
		 ++it;
	}
	 v.push_back(w);


	return v;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;



	return 0;
}
