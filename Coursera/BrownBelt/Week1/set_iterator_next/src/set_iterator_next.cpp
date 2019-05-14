#include "test_runner.h"
#include <cassert>
#include <deque>
#include <iostream>

using namespace std;


struct Node {
  Node(int v, Node* p)
    : value(v)
    , parent(p)
  {}

  int value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent;
};


class NodeBuilder {
public:
  Node* CreateRoot(int value) {
    nodes.emplace_back(value, nullptr);
    return &nodes.back();
  }

  Node* CreateLeftSon(Node* me, int value) {
    assert( me->left == nullptr );
    nodes.emplace_back(value, me);
    me->left = &nodes.back();
    return me->left;
  }

  Node* CreateRightSon(Node* me, int value) {
    assert( me->right == nullptr );
    nodes.emplace_back(value, me);
    me->right = &nodes.back();
    return me->right;
  }

private:
  deque<Node> nodes;
};


Node* Next(Node* me) {
//	cout << "Next : " << endl;
//	cout << " Node value = " << me->value;
//
//	if(me->right != nullptr){
//	cout << " right = " << me->right->value;
//	}
//	if(me->left != nullptr) {
//	cout << " left = " << me->left->value;
//	}
//	if(me->parent != nullptr) {
//	cout  << " parent = " << me->parent->value;
//
//	}
//	cout << endl;
	// у текущей вершины есть правое поддерево

	if(me->right != nullptr) {
	Node* temp = me->right;
		if(temp->left != nullptr){

			do{
					temp = temp->left;
			}while(temp->left!=nullptr);
			return temp;
		} else {
		return me->right;
		}
	//}
	//if{ // нет правого поддерева а вершина ялвяется левым ребенком у родителя


	}else if(me->parent!= nullptr) {
			if( me->right == nullptr && me == me->parent->left) {
				return me->parent;
	}


	//нет правого поддерква а вершина правый ребенок у родителя

	else if(me->right == nullptr && me == me->parent->right) {
		Node* par;
		par = me->parent;
		if(par == nullptr) return nullptr;

		do{

			if(par== par->parent->right) {

				par =par->parent;

			}
			else if(par == par->parent->left) { break;}


		}while(par->parent != nullptr);

		return (par->parent == nullptr ? nullptr : par->parent);
	}
	}
	return nullptr;

}





void Test1() {
  NodeBuilder nb;

  Node* root = nb.CreateRoot(50);
  ASSERT_EQUAL( root->value, 50 );

  Node* l = nb.CreateLeftSon(root, 2);
  Node* min = nb.CreateLeftSon(l, 1);
  Node* r = nb.CreateRightSon(l, 4);
  ASSERT_EQUAL( min->value, 1);
  ASSERT_EQUAL( r->parent->value, 2 );

  nb.CreateLeftSon(r, 3);
  nb.CreateRightSon(r, 5);

  r = nb.CreateRightSon(root, 100);
  l = nb.CreateLeftSon(r, 90);
  nb.CreateRightSon(r, 101);

  nb.CreateLeftSon(l, 89);
  r = nb.CreateRightSon(l, 91);

  ASSERT_EQUAL( Next(l)->value, 91);
  ASSERT_EQUAL( Next(root)->value, 89 );
  ASSERT_EQUAL( Next(min)->value, 2 );
  ASSERT_EQUAL( Next(r)->value, 100);

  while (min) {
    cout << min->value << '\n';
    min = Next(min);

  }
}

void TestRootOnly() {
  NodeBuilder nb;
  Node* root = nb.CreateRoot(42);
  ASSERT( Next(root) == nullptr);
};


int main() {
  TestRunner tr;
  RUN_TEST(tr, Test1);
  RUN_TEST(tr, TestRootOnly);
  return 0;
}


