
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void PrintRange(const T& value){
	for(auto it= begin(value); it< end(value); ++it){
		cout <<*it << " ";
	}
}


using namespace std;

int main() {
vector<int> v;
int n;
cin >> n;
for(int i=1; i<=n; ++i){
	v.push_back(i);
}
bool logic = prev_permutation(begin(v), end(v));
cout << "logic = " << logic << endl;
PrintRange(v);
cout << endl;
while(prev_permutation(begin(v), end(v))){
	PrintRange(v);
	cout << endl;
}


	return 0;
}
