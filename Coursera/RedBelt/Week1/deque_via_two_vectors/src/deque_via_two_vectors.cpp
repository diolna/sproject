#include <iostream>
#include <vector>
//#include "test_runner.h"

using namespace std;

template<typename T>
class Deque {
public:
		Deque() {}

	T& operator[](size_t index){
		if(dequePushFront.size()<=index){return dequePushBack[index - dequePushFront.size()];}
				else{return dequePushFront[dequePushFront.size()-index-1];}
	}
	const T operator[](size_t index) const{
		if(dequePushFront.size()<=index){return dequePushBack[index - dequePushFront.size()];}
						else{return dequePushFront[dequePushFront.size()-index-1];}
	}
	T& At(size_t index)  {
		if (index < dequePushFront.size() && (!dequePushFront.empty())) {
				return dequePushFront.at(dequePushFront.size() - index-1);
			}
			else {return dequePushBack.at(index - dequePushFront.size());
		}
	}


	const T& At(size_t index) const	{
		if (index < dequePushFront.size() && (!dequePushFront.empty())) {
						return dequePushFront.at(dequePushFront.size() - index-1);
					}
					else {
						return dequePushBack.at(index - dequePushFront.size());
				}
			}
	const bool Empty()const {return dequePushFront.size()==0 && dequePushBack.size()==0;}
	T& Front(){
		if(dequePushFront.empty()){return *dequePushBack.begin();}
		return *(dequePushFront.end()-1);
	}
	const T& Front() const{
		if(dequePushFront.empty()){return *dequePushBack.begin();}
		return *(dequePushFront.end()-1);
	}
	T& Back(){
		if(dequePushBack.empty()){return *dequePushFront.begin();}
		return *(dequePushBack.end()-1);
	}
	const T& Back() const {
		if(dequePushBack.empty()){return *dequePushFront.begin();}
		return *(dequePushBack.end()-1);
	}
	void PushFront(T element){	dequePushFront.push_back(element);}
	void PushBack(T element){dequePushBack.push_back(element);}
	size_t Size() const  {return dequePushFront.size()+dequePushBack.size();	}

private:
	vector<T>  dequePushFront;
	vector<T>	dequePushBack;

};
/*
void TestDeque() {
	Deque<int> dec;
	 ASSERT_EQUAL(dec.Empty(), 1);
	 ASSERT_EQUAL(dec.Size(), 0u);
	 dec.PushBack(4);
	 ASSERT_EQUAL(dec.Size(),1);
	 ASSERT_EQUAL(dec.Front(), 4);
	 ASSERT_EQUAL(dec.Back(), 4);
	 dec.PushFront(5);
	 ASSERT_EQUAL(dec.Front(), 5);
	 ASSERT_EQUAL(dec.At(0), 5);
	 dec.PushBack(2);
	 ASSERT_EQUAL(dec.At(2), 2);
	 ASSERT_EQUAL(dec[0], 5);
	 ASSERT_EQUAL(dec[1], 4);
	 ASSERT_EQUAL(dec[2], 2);
	 ASSERT_EQUAL(dec.Empty(), 0);
	 dec.PushFront(22);
	 ASSERT_EQUAL(dec[0], 22);
	 dec.PushFront(345);
	 ASSERT_EQUAL(dec[0], 345);
	 dec.PushBack(444);
	 ASSERT_EQUAL(dec[dec.Size()-1], 444);
}
*/

int main() {
/*
	 TestRunner tr;
	  RUN_TEST(tr, TestDeque);

*/
	  return 0;

	}
