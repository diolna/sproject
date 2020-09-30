#pragma once
#include "Customer.h"
#include <iostream>


template <class Item>
class Queue {
	struct Node{
			Item item;
			 Node* next;
		};
	enum {Q_SIZE = 10};

public:
	Queue( int qs = Q_SIZE);
	Queue(const Queue &q) : qsize(0), rear(0), front(0), items(0) {};
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
	bool isfull() const;
	bool isempty() const ;
	int queuecount() const;
	~Queue();
	 Queue& operator=(const Queue &q) { return *this; }



private:
	Node* front;
	Node* rear;
	int items;			//the current number elements
	const int qsize;  //max elements in Queue

};

template <class Item>


bool Queue<Item>::enqueue(const Item & item) {

			if(isfull())
				return false;
			Node* add = new Node;
			if(add == NULL)
				return false;
			add->item = item;
			items++;
			add->next = NULL;
			if(front == NULL)
				front = add;
			else
				rear->next = add;
			rear = add;
			return true;
}

template <class Item>
bool Queue<Item>::isfull() const {
	return items >= qsize;
}
template <class Item>
bool Queue<Item>::isempty() const {
	return items==0;
}

template <class Item>
int Queue<Item>::queuecount() const{
	return items;
}

template<class Item>
bool Queue<Item>::dequeue(Item & item){
	if(front == NULL)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if(items == 0)
		rear = NULL;
	return true;

}

template<class Item>
Queue<Item>::Queue( int qs) : qsize(qs){
	front = rear = NULL;
	items = 0;
}

template<class Item>
Queue<Item>::~Queue(){
	Node *temp = rear;
	while (front != NULL){
		temp = front;
		front = front->next;
		delete temp;

	}


}


