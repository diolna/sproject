#pragma once
#include <cstring>

typedef unsigned long Item;

class Stack {
public:
	Stack(int n = 10);
	Stack(const Stack& st);
	~Stack();
	bool isempty() const ;
	bool isfull() const;
	bool push(const Item & item); // false if stack is full
	bool pop(Item & item);
	Stack& operator = (const Stack& st);
private:
	enum {MAX = 10};
	Item* pitems;
	int size;
	int top;
};

Stack::~Stack(){
	delete []pitems;
}

Stack::Stack(int n){
	pitems = new Item[n];
	size = n;
	top = 0;

}
Stack::Stack(const Stack& st){
	size = st.size;
	top = st.top;
	pitems = new Item[st.size];
	for(int i =1; i <size; i++){
		pitems[i] = st.pitems[i];
	}

}

bool Stack::isfull() const {

	if(top == size) return true;
	return false;

}

bool Stack::isempty() const {
	if(top == 0) return true;
	return false;
}

bool Stack::push(const Item& item){
	if(isfull()) return false;
	top++;
	pitems[top] = item;


	return true;
}
bool Stack::pop(Item& item){
	if(top >0 ){
		item = pitems[top];
		top--;
		return true;
}
	else
		return false;
}

Stack& Stack::operator =(const Stack& st){
	delete [] pitems;


	pitems = new Item[st.size];
	for(int i = 1; i < st.size; i++){
		pitems[i] =  st.pitems[i];
	}
	size = st.size;
	if(top >= st.size){
		top = st.size;
		std::cout << "test";
	}
	else

		top = st.top;


	return *this;

}
