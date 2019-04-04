#include <iostream>
#include "profile.h"
#include <string>
#include <string_view>
using namespace std;

string ConcatenateStringViews1(
	    string_view lhs, string_view rhs) {
	  return string(lhs) + string(rhs);
	}

	string ConcatenateStringViews2(
	    string_view lhs, string_view rhs) {
	  return string(lhs) + string(rhs);
	}

	string ConcatenateStringViews3(
	    string_view lhs, string_view rhs) {
	  return string(lhs) + string(rhs);
	}

	string ConcatenateStringViews4(
	    string_view lhs, string_view rhs) {
	  return string(lhs) + string(rhs);
	}

	string ConcatenateStringViews5(
	    string_view lhs, string_view rhs) {
	  return string(lhs) + string(rhs);
	}

	string ConcatenateStringViews6(
	    string_view lhs, string_view rhs) {
	  return string(lhs) + string(rhs);
	}

	string ConcatenateStringViews7(
	    string_view lhs, string_view rhs) {
	  return string(lhs) + string(rhs);
	}

	string ConcatenateStringViews8(
	    string_view lhs, string_view rhs) {
	  return string(lhs) + string(rhs);
	}

	string ConcatenateStringViews9(
	    string_view lhs, string_view rhs) {
	  string s(lhs);
	  s += rhs;
	  return s;
	}

	string ConcatenateStringViews10(
			    string_view lhs, string_view rhs) {
			cout  <<"size rhs " << rhs.size();
			cout  <<"size rhs " << string(lhs).size();
			  return string(lhs) += rhs;
			}

	string GenerateText(){
		const int SIZE = 10000000;
		string text(SIZE, 'a');
		for(int i = 100; i < SIZE; i += 100){
			text[i] =  ' ';
		}
		return text;
	}


int main() {
	string aa;
	cout << aa.max_size() << endl;

	string a = GenerateText();
	string b =  GenerateText();
//	{
//	LOG_DURATION("string1");
//	ConcatenateStringViews1(a,b);
//	}
//	{
//		LOG_DURATION("string2");
//		ConcatenateStringViews2(a,b);
//		}
//	{
//		LOG_DURATION("string3");
//		ConcatenateStringViews3(a,b);
//		}
//	{
//		LOG_DURATION("string4");
//		ConcatenateStringViews4(a,b);
//		}
//	{
//		LOG_DURATION("string5");
//		ConcatenateStringViews5(a,b);
//		}
//	{
//		LOG_DURATION("string6");
//		ConcatenateStringViews6(a,b);
//		}
//	{
//		LOG_DURATION("string7");
//		ConcatenateStringViews7(a,b);
//		}
//	{
//		LOG_DURATION("string8");
//		ConcatenateStringViews8(a,b);
//		}
	{
			LOG_DURATION("string9");
			string s = ConcatenateStringViews9(a,b);
			}
	{
			LOG_DURATION("string10");
			string s = ConcatenateStringViews10(a,b);
			}
	return 0;
}
