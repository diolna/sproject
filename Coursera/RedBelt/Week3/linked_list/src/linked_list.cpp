#include "test_runner.h"
#include <iostream>

#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
  struct Node {
    T value;
    Node* next = nullptr;
  };


  ~LinkedList(){

	  while(head!=nullptr){
		  Node* temp = head->next;

		  delete head;
		  head = temp;
	  }

  }

  void PushFront(const T& value){

			  Node* new_node = new Node;
			  new_node->value = value;
			  new_node->next = head;

			  head = new_node;

  }
  void InsertAfter(Node* node, const T& value){
	  if(node== nullptr) {
		  PushFront(value);
		  return;
	  } else {
		  Node* pointer_temp = node->next; // old-new - old 1
		  //��������� ������ old1
		  Node* new_elem = new Node; // creaded new element

		  new_elem->next = pointer_temp;  // inizializate new element links to old 1
		  new_elem->value = value;
		  node->next = new_elem;  // inizialization links in old element points to new element
	   }
  }
  void RemoveAfter(Node* node){
	  if(node == nullptr){ PopFront();return;}
	  if(node->next == nullptr){return;}
	  Node* temp = node->next->next; // node-remove- next
	  //��� ��������� �� ������� ��������� �� ���������.
	  // ����� � node ��������  ��������� �� ����
	  Node* temp_del = node->next; // save pointer to de element
	  node->next = temp;
	  delete temp_del;
  }

  void PopFront(){
	 if(head!=nullptr){
	  Node * tmp = head->next; // save pointer to next element after head

	  delete head;				//delete head

	  head = tmp;			// new head

	 }

  }

  Node* GetHead() { return head; }
  const Node* GetHead() const { return head; }

private:
  Node* head = nullptr;
};

template <typename T>
vector<T> ToVector(const LinkedList<T>& list) {
  vector<T> result;
  for (auto node = list.GetHead(); node; node = node->next) {
    result.push_back(node->value);
  }
  return result;
}

void TestPushFront() {
  LinkedList<int> list;

  list.PushFront(1);
  ASSERT_EQUAL(list.GetHead()->value, 1);
  list.PushFront(2);
  ASSERT_EQUAL(list.GetHead()->value, 2);
  list.PushFront(3);
  ASSERT_EQUAL(list.GetHead()->value, 3);

  const vector<int> expected = {3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);
}

void TestInsertAfter() {
  LinkedList<string> list;

  list.PushFront("a");
  auto head = list.GetHead();
  ASSERT(head);
  ASSERT_EQUAL(head->value, "a");

  list.InsertAfter(head, "b");
  const vector<string> expected1 = {"a", "b"};
  ASSERT_EQUAL(ToVector(list), expected1);

  list.InsertAfter(head, "c");
  const vector<string> expected2 = {"a", "c", "b"};
  ASSERT_EQUAL(ToVector(list), expected2);
}

void TestRemoveAfter() {
  LinkedList<int> list;
  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }

  const vector<int> expected = {5, 4, 3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);

  auto next_to_head = list.GetHead()->next;
  list.RemoveAfter(next_to_head); // ������� 3
  list.RemoveAfter(next_to_head); // ������� 2

  const vector<int> expected1 = {5, 4, 1};
  ASSERT_EQUAL(ToVector(list), expected1);

  while (list.GetHead()->next) {
    list.RemoveAfter(list.GetHead());
  }
  ASSERT_EQUAL(list.GetHead()->value, 5);
}

void TestPopFront() {
  LinkedList<int> list;

  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }
  for (int i = 1; i <= 5; ++i) {
    list.PopFront();
  }

  ASSERT(list.GetHead()==nullptr);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestPushFront);
  RUN_TEST(tr, TestInsertAfter);
  RUN_TEST(tr, TestRemoveAfter);
  RUN_TEST(tr, TestPopFront);
  return 0;
}
