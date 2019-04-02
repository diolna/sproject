#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

int main() {

	int32_t n;
	list<int32_t> athlets;
	map<int32_t, list<int32_t>::iterator> dec;
	cin >> n;
	for(int32_t i = 0; i < n; ++i){
		int32_t pair1, pair2;

		cin >> pair1 >> pair2;
		if(athlets.empty()) {
			athlets.push_front(pair1);
			dec[pair1] = athlets.begin();
		} else if(dec.count(pair2) == 0 ) {
			athlets.push_back(pair1);
			dec[pair1] = prev(athlets.end());


		} else {
			auto it = athlets.insert(dec[pair2], pair1);
			dec[pair1] = it;
			}

	}
	for(auto& i: athlets){
		cout << i << " ";
	}



	return 0;
}
