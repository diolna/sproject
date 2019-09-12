#include <iostream>
#include <string>
#include<vector>
using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLengs) {
	int x=0;
	vector<string> ddd;
    for(size_t i=0; i>=words.size()-1; ++i){
    	for (size_t n = 0; n < words[i].size() / 2; ++n) {
    		if (words[i,n] != words[words.size() - i - 1]) {
    	}else{
   	    	if(words[i].size()-1 < minLengs){
   	    		}else{
   	    			ddd[x] = words[i];
   	    			++x;
   	    		}
   	    	}

    	}
    }
    	return ddd;
    }

int main() {
	int lang, number;
	vector<string> x,y;
	cout << "Enter number of words ";
	cin >> number;
	for(int i=0; i == number; ++i){
		cout << "Enter word" << endl;
		cout << "For exin Enter X " << endl;
		cin >> x[i];
	}
	y=PalindromFilter(x,lang);
	for(size_t i=0; i<=y.size(); ++i){
		cout << y[i];
	}


	return 0;
}
