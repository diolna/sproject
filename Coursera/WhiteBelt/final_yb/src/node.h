#pragma once

#include "date.h"
#include "condition_parser.h"

#include <iostream>
#include <string>
#include <functional>
#include <memory>




using namespace std;

enum class LogicalOperation{
	Or,
	And
};


class Node{
public:
	virtual int Evaluate(const Date& d, const string& ev)=0;
};

class DateComparisonNode: public Node {
public:
	 DateComparisonNode(Comparison& co, Date& d){}
	int Evaluate(const Date& d, const string& ev)  ;

private:



};

class EventComparisonNode: public Node{
public:
	int Evaluate(const Date& d, const string& ev)  ;

};

class LogicalOperationNode: public Node{
public:

	 LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node>& left, shared_ptr<Node>& Right);

		int Evaluate(const Date& d, const string& ev) ;

};

class EmptyNode: public Node {
public:
	int Evaluate(const Date& d, const string& ev);

};
