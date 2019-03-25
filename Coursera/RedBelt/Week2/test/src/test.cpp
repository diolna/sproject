#include "profile.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <map>
#include <vector>

using namespace std;

int main() {
	map<int, vector<int>> s ={{2,{3,4}},{4,{5,5}},{5,{6,6}},{8,{2,8}}};

	cout << s.size() << " - s.size() " << endl;
	s.erase(4);
	cout << s.size() << " - s.size() " << endl;
	auto it = s.find(5);
	s.erase(it);
	cout << s.size() << " - s.size() " << endl;
	it = s.find(8);
	cout << it->second[1] << endl;




//	{
//	LOG_DURATION("endl");
//	ofstream out("output.txt");
//	for(int i=0; i < 150000; ++i){
//	out << "London is the capital of Great Brinain. "
//		<< "I am a travelling down the river"
//		<< endl;
//	}
//	}
//	{
//		LOG_DURATION("'\\n'");
//
//		ofstream out("output.txt");
//		for(int i=0; i < 150000; ++i){
//		out << "London is the capital of Great Brinain. "
//			<< "I am a travelling down the river"
//			<< '\n';
//		}
//		}
//	{
//		string s= "aaaaa" ;
//		for( int i=0; i <10000; ++i){
//
//		}
//		vector<string> strings = {"fffff:", "dfdff"};//ReadStrings();
//
//		string joined_string =
//		    accumulate(begin(strings), end(strings),string());
//		for(auto& i: joined_string){
//			cout << i << " ";
//		}
//	}


}
