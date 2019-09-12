//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const  string&  a, const string& b){

			for(int i=0; i<=max(a.size()-1, b.size()-1); ++i){
				if(tolower(a[i])!= tolower(b[i])){
					return tolower(a[i]) < tolower( b[i]);
			}
		}
}

int main()
{
	int n;
	vector<string> st;

	string str;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str;

		st.push_back(str);
	}
	int d=0;

	sort(begin(st), end(st), compare);
	for (int i = 0; i < n; ++i) {
		cout << st[i] << " ";
	}
	return 0;
}
