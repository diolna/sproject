
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <string>



using namespace std;



template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith( RandomIt range_begin, RandomIt range_end,  char prefix){

	pair<RandomIt, RandomIt> p;
	vector<char> v;
	string s;

	s= prefix;

	 p = equal_range(range_begin, range_end, s, [](const string& lhs, const string& rhs){
		return lhs.at(0)< rhs.at(0);
	});
	//cout << "prefix = "<< s <<" value_first = " << *(p.first) << "value second " << *(p.second) <<  endl;

	//for(auto it = lower_bound(range_begin, range_end, s,[prefix](const string& str){return str.at(0)== prefix;});
	//		it!=range_end; it = lower_bound(next(it), range_end, s, [prefix](const string& str){return str.at(0)==prefix;})){
	//cout << "prefix "<< s <<" value " << *it << " ";

//	}
		return p;

}


int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

  const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;

  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;

  return 0;
}
