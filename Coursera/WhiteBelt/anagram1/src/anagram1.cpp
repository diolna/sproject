
#include <string>
#include<iostream>
#include <vector>
#include<map>

using namespace std;

string  BuildCharCounters(const string & w1, const string & w2) {

		map<int, char> char1;
		map<int, char> char2;
		string result;

		for ( const char & symbol : w1) {
			++char1[symbol];
		}
		for (const char & symbol : w2) {
			++char2[symbol];
		}


		if(char1== char2) {
			result= "YES";
		}
		else
		{
			result ="NO";
		}

		return result;
}

int main()
{
	string word1, word2;
	int number;
	vector<string> result;

	cin >> number;
	while (number > 0) {
		cin >> word1 >> word2;
		result.push_back(BuildCharCounters(word1, word2));
		--number;
	}
	for (const string & i:result) {
		cout << i << endl;
	}





    return 0;
}

