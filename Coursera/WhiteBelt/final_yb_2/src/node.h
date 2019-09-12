#pragma once

#include "date.h"

#include <string>
#include <memory>
#include <iostream>

using namespace std;


enum class Comparison {

	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation
{
	Or,
	And
};



class Node {
public:
	virtual bool Evaluate(const Date& d, const string& e) const = 0;
	virtual ~Node(){}
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode( const Comparison& c,  const Date& date);
	bool Evaluate(const Date& d, const string& e) const override;

private:
	const Date date_;
	const Comparison comp_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& c,  const string& event);
	bool Evaluate(const Date& d, const string& e) const override;

private:
	const Comparison comp_;
	const string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode( const LogicalOperation& op,  shared_ptr<Node> left,
		 shared_ptr<Node> right);
	bool Evaluate(const Date& d, const string& e) const override;
private:
	const LogicalOperation op_;
	shared_ptr<Node> left_;
	shared_ptr<Node> right_;
};

class EmptyNode : public Node {
public:

	bool Evaluate(const Date& d, const string& e) const override;
};



