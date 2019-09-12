#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <string>



using namespace std;





template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith( RandomIt range_begin, RandomIt range_end,  const string& prefix){

	pair<RandomIt, RandomIt> p;
	vector<char> v;

	auto langs = prefix.size();



	 p = equal_range(range_begin, range_end, prefix, [langs](const string& lhs, const string& rhs){

		return lhs.substr(0,langs)< rhs.substr(0,langs);
	});
	//cout << "prefix = "<< s <<" value_first = " << *(p.first) << "value second " << *(p.second) <<  endl;

	//for(auto it = lower_bound(range_begin, range_end, s,[prefix](const string& str){return str.at(0)== prefix;});
	//		it!=range_end; it = lower_bound(next(it), range_end, s, [prefix](const string& str){return str.at(0)==prefix;})){
	//cout << "prefix "<< s <<" value " << *it << " ";

//	}
		return p;

}


int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}
