#pragma once

#include <stdexcept>
#include <array>
#include <iterator>
#include <exception>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0) {
	  if(a_size > N) {
		  throw invalid_argument("");
	  } else {
		  size_ = a_size;
	  }
  }

  T& operator[](size_t index){
	  return arr[index];
  }
  const T& operator[](size_t index) const{
	  return arr[index];
  }

  T* begin() {
	  return arr.begin();
  }
  T* end(){
	  return &arr[this->Size()];
  }
   const T* begin() const {
	  return arr.begin();
  }
   const T* end() const {
	  return &arr[this->Size()];
  }

  size_t Size() const {
	  return size_;

  }
  size_t Capacity() const {
	  return N;
  }

  void PushBack(const T& value){

	  if(this->Size()< this->Capacity()){
		  size_ +=1;
		  arr[size_-1] = value;
	   } else {
		   throw overflow_error("");

	   }
	  }

  T PopBack(){
	  if(this->Size()!=0){
		  size_ -=1;
		  return arr[size_];
	  } else {
		  throw underflow_error("");
	  }

  }

private:
  array<T,N> arr;
  size_t size_ = 0;

};

