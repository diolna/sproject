#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLengs) {

	vector<string> ddd;

	string w;
	int x = 0;
	for (size_t i = 0; i <= words.size() - 1; ++i) {

		w = words[i];
		//cout << "read word = " << w << "size word " << w.size() << endl ;
		for (size_t n = 0; n <= w.size() / 2; ++n) {
			if (w.size() < minLengs) {
				x = 1;
				//cout << "langs " << minLengs << " x = " << x << endl;
			}
			else if (w[n] != w[w.size() - n - 1]) {
				x = 1;
			}
			//cout << "number pin in word" << n << endl;
		}
		//cout << " posible word " << w << endl;
		if (x == 0) {
			//cout << "save word to vector" << endl;
			ddd.push_back(w);
			//cout << "element " << i << " = " << w << endl;
		}
		else {
			x = 0;
		}

	}
	return ddd;
}


int main() {
	int lang, n = 0;
	string word, words;
	vector<string> Vector_words, Vector;
	vector<string> y;
	cout << "Enter words into coma " << endl;
	//cin >> words;
	//Vector_words.push_back(words);
	while (cin >> words) {


			if (words[words.size() - 1] == ',') {
				Vector_words.push_back(words);
				//cout << "word write in [" << n << "]" << words << endl;
				++n;

			}
			else {
				Vector_words.push_back(words);
				//cout << "BREAK write in [" << n << "]" << words << endl;
				++n;
				break;
			}
			//cout << "end of primise" << endl;
		}
	//cout << "VECTOR =" << endl;
	for (auto i : Vector_words) {
		//cout << "words in vector =  " << i << endl;

	}
	//cout << "delate coma" << endl;
	for (auto i : Vector_words) {
		for (int y=0; y<=i.size()-1; ++y){
			if (i[y] != ',') {
				word = word + i[y];
			}

		}
		Vector.push_back(word);
		word.clear();
	}

	for (auto i : Vector) {
		//cout << "words in vector =  " << i << endl;

	}
	cout << "Enter minimum Langs word wich need for output ";
	cin >> lang;
	y = PalindromFilter(Vector, lang);
	for (size_t i = 0; i <= y.size() - 1; ++i) {
		cout << y[i] << " ";

	}
	int a;

	//cin >> a;
	return 0;
}
