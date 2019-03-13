#include "test_runner.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>

using namespace std;

template<typename Iterator>
class Page{
public:
	Page(Iterator f, Iterator l): first(f), last(l){}
	Iterator begin() const {return first;}
	Iterator end() const {return last;}
	Iterator begin() {return first;}
	Iterator end()  {return last;}
	 size_t size() const {return last-first;}// {return distance(first, last);}
private:
	Iterator first, last;
	};

template<typename Iterator>
Page<Iterator> makePage(Iterator begin, Iterator end){return {begin, end};}

template<typename Iterator>
class Paginator{
public:
	Paginator(Iterator begin, Iterator end,  size_t page_size_)
		: first(begin), last(end), page_size(page_size_)
		{

			if(first==last){return;}
			else if(page_size<=0){ pages= {{}};
				}else if(this->langs()<=page_size){
						pages = {{first, last}};
					}else{
						Iterator first1=first;
						for(size_t i=0; i<this->size1(); i++){
							if(first1+page_size< last){
								pages.push_back({first1, first1+page_size});
								first1 = first1+page_size;
							}else{
								pages.push_back({first1, last});
						}
					}
				}

		}
	auto begin() const {return pages.begin();};
    auto end() const {return pages.end();};
    auto begin() {return pages.begin();};
    auto end() {return pages.end();};

	size_t langs() const {return last-first;}// {return distance(first,last);}
	size_t size() const { return pages.size(); }
	size_t size1() {
		if(this->langs()%page_size!=0){return this->langs()/page_size+1;}
		else{return this->langs()/page_size ;}
	}




private:
	Iterator first, last;
	size_t page_size;
	vector<Page<Iterator>> pages;


};

template <typename C>
  auto Paginate(C& c, size_t page_size){
	Paginator pag(c.begin(), c.end(), page_size);
	return pag;
}

template <typename Application>
vector<vector<Application>> DistributeAmongScreens(const vector<Application>& apps, size_t& page_size) {
  vector<vector<Application>> result;
  for (const auto& page : Paginate(apps, page_size)) {
    result.push_back({page.begin(), page.end()});
  }
  // result[0] - все приложения, которые попадают на первый экран,
  // result[1] - все приложения, которые попадают на второй экран и т.д.
  return result;
}

void TestPageSize1(){
	{
	vector<int> v={2,2,2,2,2,2,2,2,2,2,2,2,2};
	vector<vector<int>> pp;
	  for (const auto& page : Paginate(v, 3)) {
	    pp.push_back({page.begin(), page.end()});
	  }

	ASSERT_EQUAL(pp[0].size(), 3);
	ASSERT_EQUAL(pp[1].size(), 3);
	ASSERT_EQUAL(pp[2].size(), 3);
	ASSERT_EQUAL(pp[3].size(), 3);
	ASSERT_EQUAL(pp[4].size(), 1);

	}
	{
	vector<int> v={2};
		vector<vector<int>> pp;
	for (const auto& page : Paginate(v, 7)) {
		    pp.push_back({page.begin(), page.end()});
		  }
	ASSERT_EQUAL(pp[0].size(), 1);

	}
}


void TestPageCounts() {
	{
  vector<int> v(15);

  ASSERT_EQUAL(Paginate(v, 1).size(), v.size());
  ASSERT_EQUAL(Paginate(v, 3).size(), 5u);
  ASSERT_EQUAL(Paginate(v, 5).size(), 3u);
  ASSERT_EQUAL(Paginate(v, 4).size(), 4u);
  ASSERT_EQUAL(Paginate(v, 15).size(), 1u);
  ASSERT_EQUAL(Paginate(v, 150).size(), 1u);
  ASSERT_EQUAL(Paginate(v, 14).size(), 2u);
	}
	{
		vector <int> v;
		 ASSERT_EQUAL(Paginate(v, 1).size(), 0);
	}
}


void TestLooping() {
  vector<int> v(15);
  iota(begin(v), end(v), 1);

  Paginator<vector<int>::iterator> paginate_v(v.begin(), v.end(), 6);
  ostringstream os;
  for (const auto& page : paginate_v) {
    for (int x : page) {
      os << x << ' ';
    }
    os << '\n';
  }

  ASSERT_EQUAL(os.str(), "1 2 3 4 5 6 \n7 8 9 10 11 12 \n13 14 15 \n");
}

void TestModification() {
  vector<string> vs = {"one", "two", "three", "four", "five"};
  for (auto page : Paginate(vs, 2)) {
    for (auto& word : page) {
      word[0] = toupper(word[0]);
    }
  }

  const vector<string> expected = {"One", "Two", "Three", "Four", "Five"};
  ASSERT_EQUAL(vs, expected);
}

void TestPageSizes() {
  string letters(26, ' ');

  Paginator letters_pagination(letters.begin(), letters.end(), 0);
  vector<size_t> page_sizes;
  for (const auto& page : letters_pagination) {
    page_sizes.push_back(page.size());
  }

  const vector<size_t> expected = {};
  ASSERT_EQUAL(page_sizes, expected);
}

void TestConstContainer() {
  const string letters = "abcdefghijklmnopqrstuvwxyz";

  vector<string> pages;
  for (const auto& page : Paginate(letters, 10)) {
    pages.push_back(string(page.begin(), page.end()));
  }

  const vector<string> expected = {"abcdefghij", "klmnopqrst", "uvwxyz"};
  ASSERT_EQUAL(pages, expected);
}

void TestPagePagination() {
  vector<int> v(22);
  iota(begin(v), end(v), 1);

  vector<vector<int>> lines;
  for (const auto& split_by_9 : Paginate(v, 9)) {
    for (const auto& split_by_4 : Paginate(split_by_9, 4)) {
      lines.push_back({});
      for (int item : split_by_4) {
        lines.back().push_back(item);
      }
    }
  }

  const vector<vector<int>> expected = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9},
      {10, 11, 12, 13},
      {14, 15, 16, 17},
      {18},
      {19, 20, 21, 22}
  };
  ASSERT_EQUAL(lines, expected);
}

int main() {
//	cout << "test" << endl;
//	vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
//	vector<vector<int>> res;
//	int count =0;
//	for(auto& i: Paginate(v,8)){
//		res.push_back({i.begin(), i.end()});
//		count++;
//		cout << "number vector  " << count<< " size vector = " << i.size() << " " ;
//		for(auto& x: i){
//
//			cout << " "<< x << " ";
//		}
//		cout << endl;
//	}
//
//	auto vec = DistributeAmongScreens(v);
//	for(auto& i: vec){
//		cout << "vector = " ;
//		for(auto& item: i){
//			cout << item << " ";
//		}
//		cout << endl;
//	}
//	auto pp = Paginate(v,8);
//	cout << "langs = " << pp.langs();

	TestRunner tr;
	  RUN_TEST(tr, TestPageCounts);
	  RUN_TEST(tr, TestLooping);
	  RUN_TEST(tr, TestModification);
	  RUN_TEST(tr, TestPageSizes);
	  RUN_TEST(tr, TestConstContainer);
	  RUN_TEST(tr, TestPagePagination);
	  RUN_TEST(tr, TestPageSize1);


	return 0;
}

