#include "database.h"
#include "condition_parser.h"
#include "test_runner.h"

#include <iostream>
#include <sstream>
#include <functional>
using namespace std;

bool CheckOutPut(const Database& db, const string& exp_string) {
    ostringstream os;
    db.Print(os);
    string out = os.str();
    return out == exp_string;
}

void TestDatabase() {
    {
        Database db;
        db.Add({2017, 12, 31}, "start");
        db.Add({2017, 12, 31}, "continue");
        db.Add({2017, 12, 31}, "make commit");
        db.Add({2017, 12, 31}, "refine");
        db.Add({2018, 1, 1}, "erase");
        db.Add({2018, 1, 1}, "erase");
        db.Add({2018, 1, 1}, "continue");
        db.Add({2018, 1, 1}, "refine");
        istringstream is("date == 2017-12-31");
        shared_ptr<Node> root = ParseCondition(is);
        auto predicate = [root](const Date& date, const string& event) {
            return root->Evaluate(date, event);
        };
        Assert(db.RemoveIf(predicate), "Remove specific date");
        Assert(!db.RemoveIf(predicate), "Remove already removed date");
        Assert(CheckOutPut(
                   db,
                   "2018-01-01 erase\n2018-01-01 continue\n2018-01-01 refine\n"),
               "Check print after remove all date");

    }
}
