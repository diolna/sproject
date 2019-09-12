
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	if(range_end-range_begin >=2){

	vector<typename RandomIt::value_type> res;
	vector<typename RandomIt::value_type> v = {range_begin, range_end};
   RandomIt it1 = v.begin() + (range_end-range_begin)/3;
   RandomIt it2 = it1+ (range_end-range_begin)/3;
 //  sort(v.begin(), it);
		   	MergeSort(v.begin(), it1);
		   	MergeSort(it1,it2);
			MergeSort(it2, v.end());

			merge(v.begin(), it1, it1, it2, back_inserter(res));
			merge(res.begin(), res.end(), it2, v.end(), range_begin);
			//copy(res.begin(), res.end(), range_begin);


	}


}



int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
