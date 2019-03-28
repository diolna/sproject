#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:

  T* Allocate(){
	  if(freed_object_.empty()){
		  T* object = new T;
		  selected_object_.insert(object);
		  return object;
	  }else{
		   auto x =freed_object_.front();
		  selected_object_.insert(x);
		 freed_object_.pop();
		 return x;
	  }
  }
  T* TryAllocate(){
	  if(freed_object_.empty()){
	  		 return nullptr;
	  	  }else{
	  		   auto x =freed_object_.front();
	  		  selected_object_.insert(x);
	  		 freed_object_.pop();
	  		 return x;
	  	  }
  }

  void Deallocate(T* object){
	if(selected_object_.find(object)== selected_object_.end()){
		throw invalid_argument("invalid arg");
	}
	freed_object_.push(object);
	selected_object_.erase(object);
  }

  ~ObjectPool(){
	  while(!freed_object_.empty()){
		  delete freed_object_.front();
		  freed_object_.pop();

	  }
	  for(auto  it =selected_object_.begin(); it!= selected_object_.end(); ++it){
	 		   delete *it;
	 		   selected_object_.erase(it);

	 	  }
  }


private:
  // Добавьте сюда поля
  set<T*> selected_object_;
  queue<T*> freed_object_;


};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
