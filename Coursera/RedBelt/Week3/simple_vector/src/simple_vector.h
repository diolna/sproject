#pragma once

#include <cstdlib>
#include <algorithm>
//#include <iterator>
//#include <iostream>

using namespace std;

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector(){
	  size_t size = 0;
	  data = new T[size];
	 // *data = 0;
	  end_ = data;
	  top_ = end_;
  }
  explicit SimpleVector(size_t size){
	  data = new T[size];
	  end_ = data+size;
	  top_ = end_;
  }
  ~SimpleVector(){
	  delete[] data;
  }

  T& operator[](size_t index){
	  return *(data+index);
  }

  T* begin() {return data; }
  T* end(){return top_;}
  const T* begin() const {return data;}
  const T* end() const {return top_;}

  size_t Size() const {
	  return top_ - data;
  }
  size_t Capacity() const{
	  return end_ - data;
  }
  void PushBack(const T& value){
	  size_t size;
	  if(this->Size() < this->Capacity()){

		  ++top_;
		  *(top_-1)= value;
		//  cout << " <<< size = " << this->Size() << "cap = " << this->Capacity()
		//		  << " value = " << *top_ << endl;
	  }else  if(this->Capacity()== 0){
			  size =1;

			   delete[] data;
			   data = new T[size];
			    end_ = data + size;
			     top_ = end_;
			    *data = value;
			//    cout << " ==== size = " << this->Size() << "cap = " << this->Capacity()
			//   				  << " value = " << *top_ << endl;
		  } else if(this->Size() >= this->Capacity()){
			  size_t temp = this->Size();
			  size = 2* this->Capacity();
			  T* data1 = new T[size];
			  copy(data, end_, data1);
			  delete[] data;
			  data = data1;
			  end_ = data + size;
			  top_ = data + temp+1;
			  *(top_-1) = value;


		  // cout << ">>>> size = " << this->Size() << "cap = " << this->Capacity()
		  //				  << " value = " << *top_ << endl;

		  }

  }

private:
  T* data;
  T* end_;
  T* top_;

};
