#pragma once
#include <iostream>

using namespace std;

template <typename T>

class Stack {
public:
	Stack();
	bool isfool();
	bool isempty();
	bool push(T& item);
	bool pop(T& item);

private:

enum {Max=10};
T item[Max];
int top;
};

template <typename T>
bool Stack<T>::isfool(){
	return top == Max;
}

template <typename T>
bool Stack<T>::isempty(){
	return top == 0;
}
template <typename T>
bool Stack<T>::push(T& it){
	if(top < 10) {
	top++;
	item[top] = it;
	return true;
	} else {
		return false;
	}
}
template <typename T>
bool Stack<T>::pop(T& it){
	if(top > 0 ){
		it = item[top--];
		return true;
	}else {
		return false;
	}
}
