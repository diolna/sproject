#include <iostream>
#include <vector>

using namespace std;



template<typename Iterator>
class Paginator{
public:
	Paginator(const Iterator& begin, const Iterator& end, const size_t& page_size_){}
	Iterator begin(){return first;};
	Iterator end(){return last;};
	size_t size() const {return first-last/page_size;}

private:
	Iterator first, last;
	size_t page_size;

};
template <typename C>
 auto Paginate(C& c, size_t page_size){
		return {c.begin(), c.end()};
}

vector<vector<Application>> DistributeAmongScreens(const vector<Application>& apps) {
  vector<vector<Application>> result;
  for (const auto& page : Paginate(apps, 20)) {
    result.push_back({page.begin(), page.end()});
  }
  // result[0] - все приложения, которые попадают на первый экран,
  // result[1] - все приложения, которые попадают на второй экран и т.д.
  return result;
}

int main() {

	return 0;
}
