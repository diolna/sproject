
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	if(range_end-range_begin >=2){

	vector<typename RandomIt::value_type> v = {range_begin, range_end};
   RandomIt it = v.begin() + (range_end-range_begin)/2;
 //  sort(v.begin(), it);
		   	MergeSort(v.begin(), it);
	//		for(auto i:v){
	//			cout << i << " ";
	//		}
	//		cout << endl;
	//	   	sort(it, v.end());
			MergeSort(it, v.end());
	//		for(auto i:v2){
	//						cout << i << " ";
	//					}
	//					cout << endl;


			merge(v.begin(), it, it, v.end(), (range_begin));

			//copy(res.begin(), res.end(), range_begin);


	}


}



int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
