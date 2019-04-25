#include "test_runner.h"

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <numeric>
#include <future>

using namespace std;



int SumToVector( const vector<int>& one
		, const vector<int>& two) {

	future<int> f = async([&one] {
			return accumulate(one.begin(), one.end(), 0);
});
	int result = accumulate( two.begin(), two.end(), 0);

	return result + f.get();
}

int main() {


cout << SumToVector({1,1,1,1}, {3,3,3});

  return 0;
}
