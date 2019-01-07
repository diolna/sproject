#pragma once

#include "node.h"
#include "test_runner.h"

using namespace std;

class AlwaysFalseNode : public Node {
    bool Evaluate(const Date& date, const string& event) const override;
};

void TestDateComparisonNode();
void TestEventComparisonNode();
void TestLogicalOperationNode();
void TestEmptyNode();
void TestNode();
