#include  <functional>
#include <memory>
#include <iostream>
#include <set>

using namespace std;

//#include "stdafx.h"
#include "node.h"
#include "date.h"
#include "condition_parser.h"
#include "database.h"

using namespace std;

DateComparisonNode::DateComparisonNode(const Comparison& comp,  const Date& date) : date_(date), comp_(comp){
	//cout << "constructor DateComparisonNode "  << endl;
}
EventComparisonNode::EventComparisonNode(const Comparison& comp,  const string& event): comp_(comp), event_(event) {
	//cout << "constructor DateComparisonNode " << endl;
}
LogicalOperationNode::LogicalOperationNode( const LogicalOperation& op,  shared_ptr<Node> left,
	 shared_ptr<Node> right): op_(op), left_(left), right_(right) {
	//cout << "constructor LogicalOperationNode " << endl;
}

bool DateComparisonNode::Evaluate(const Date& date_base, const string& ev) const {
	//cout << "DateComparisonNode::Evaluate " << endl;

	if (comp_ == Comparison::Equal) {return date_base == date_; }
	if (comp_ == Comparison::Less) { return date_base < date_; }
	if (comp_ == Comparison::LessOrEqual){return date_base<=date_;}
	if (comp_ == Comparison::Greater) { return date_base > date_; }
	if (comp_ == Comparison::GreaterOrEqual) {return date_base >= date_;}
	if (comp_ == Comparison::NotEqual) { return date_base != date_; }
	return false;
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event_base) const {
	//cout << "EventComparisonNode::Evaluate " << endl;
	//cout << " comp = " << static_cast<int>(comp_) << "event base=(" << event_base<< ") event pars=(" << event_ <<")"<< endl;
	if (comp_ == Comparison::Equal) { return event_base == event_; }
	if (comp_ == Comparison::Less) { return event_base < event_; }
	if (comp_ == Comparison::LessOrEqual) { return event_base <= event_; }
	if (comp_ == Comparison::Greater) { return event_base > event_;}
	if (comp_ == Comparison::GreaterOrEqual) {return event_base >= event_; }
	if (comp_ == Comparison::NotEqual) { return event_base != event_; }
	return false;
		}


bool  EmptyNode::Evaluate(const Date& d, const string& ev) const  {




	return true;
}




bool LogicalOperationNode::Evaluate(const Date& date_base, const string& ev) const {

	if (op_ == LogicalOperation::And) {

		bool date1 = left_->Evaluate(date_base, ev);
		bool date2 = right_->Evaluate(date_base, ev);

		if (date1 && date2) { return true; }
		else { return false; }
	}
	if (op_ == LogicalOperation::Or) {
		bool date1 = left_->Evaluate(date_base, ev);
		bool date2 = right_->Evaluate(date_base, ev);

		if (date1 || date2) { return true; }
		else { return false; }
	}
		return false;
}
