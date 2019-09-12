#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string w){
	for(size_t i=1; i <=w.size()/2; ++i){
		if(w[i]!=w[w.size()-i-1]){}

			}else
		     }

return true;
}

int main() {
	string x;
	cin >> x;
	if(IsPalindrom(x)== 0){
		cout << "false";
	}else{
		cout << "true";
	}

				return 0;
}
