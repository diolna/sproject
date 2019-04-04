#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include "profile.h"

using namespace std;

vector<string_view> SplintIntoWordsView( string_view str){
	vector<string_view> result;
	size_t pos =0;
	const size_t pos_end = str.npos;

	while(true){
		size_t space = str.find(" ", pos);
		result.push_back(
//				space == pos_end
//				? str.substr(pos)
				 str.substr(pos, space - pos));
		if(space == pos_end) {
			break;
		} else {
			pos = space  + 1;
		}

	}
	return result;
}

string GenerateText(){
	const int SIZE = 100000000;
	string text(SIZE, 'a');
	for(int i = 100; i < SIZE; i += 100){
		text[i] =  ' ';
	}
	return text;
}

int main() {
	const string text = GenerateText();
	{ LOG_DURATION("string");
	const auto words = SplintIntoWordsView(text);
	cout << words[0] << endl;
	}


	return 0;
}
