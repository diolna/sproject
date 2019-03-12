#include <iostream>
#include <vector>
#include <iterator>

using namespace std;



template<typename Iterator>
class Paginator{
public:
	Paginator(Iterator begin, Iterator end, const size_t& page_size_)
		: first(begin), last(end), page_size(page_size_)
		{}
	Iterator begin() const {return first;};
	Iterator end() const {return last;};
	size_t size() const {return distance(first,last);}

	vector<Paginator> SetVector() {
		cout << "this->size() = " << this->size()<< endl;
		if(this->size()<page_size){
				vector<Paginator> v={{first,first+this->size(),page_size},
								{first+this->size(), last}};
			return v;
		}else if(this->size()==page_size){
				cout << "==" << endl;
				return {{first, last, page_size}};
		}else{
			vector<Paginator> v;
			int n_page = this->size()/page_size;
			for(int i=0; i<n_page; ++i){
				if(first+page_size< last){
					v.push_back({first, first+page_size, page_size});
					first = first+page_size;
				}else{
				v.push_back({first, last, page_size});
			}
		}

		//vector<Paginator> v={{first,last,page_size},{first+2,last-1,page_size}};
		//return v;
	}
	}

private:
	Iterator first, last;
	size_t page_size;

};

template <typename C>
  auto Paginate(C& c, size_t page_size){
		Paginator pag(c.begin(), c.end(), page_size);
		//vector<C> v;
		return pag.SetVector();
}
//vect:ctor<vector<int>> result;
//  for (const auto& page : Paginate(apps, 20)) {
//    result.push_back({page.begin(), page.end()});
 // }
  // result[0] - все приложения, которые попадают на первый экран,
  // result[1] - все приложения, которые попадают на второй экран и т.д.
//  return result;
//}

int main() {
	cout << "test8" << endl;
	vector<int> v = {1,2,3,4,5,6};
	vector<vector<int>> res;
	int count =0;
	for(auto& i: Paginate(v,6)){
		res.push_back({i.begin(), i.end()});
		count++;
		cout << "number vector  " << count<< "=" ;
		for(auto& x: i){

			cout << " "<< x << " ";
		}
		cout << endl;
	}
//fgfgfgfgfgfgfdgfd

	return 0;
}
