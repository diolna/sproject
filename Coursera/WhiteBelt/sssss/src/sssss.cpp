#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLengs) {

	vector<string> ddd;

	string w;
	int x = 0;
	for (size_t  i = 0; i <= words.size() - 1; ++i) {

		w = words[i];
		//cout << "read word = " << w << "size word " << w.size() << endl ;
			for (size_t n = 0; n <= w.size() / 2; ++n) {
				if (w.size() < minLengs) {
					x = 1;
					//cout << "langs " << minLengs << " x = " << x << endl;
				}else if (w[n] != w[w.size() - n - 1]) {
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
	int lang,n;
	string word, words;
	vector<string> x ;
	vector<string> y;
	cout << "Enter words into coma "<< endl;


	cin>>words;
	cout << words << endl;






	cout << "Enter minimum Langs word wich need for output ";
	cin >> lang;
	y = PalindromFilter(x, lang);
	for (size_t i = 0; i <= y.size()-1; ++i) {
		cout << y[i] << " " ;
	}


	return 0;
}

