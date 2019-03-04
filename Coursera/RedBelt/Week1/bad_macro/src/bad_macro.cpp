#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) {							\
									out << (x) << endl;		\
									out << (y) << endl;		\
}

//void TestMacro(){
//
//}

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    string s="5";
    PRINT_VALUES(output, s, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
  }, "PRINT_VALUES usage example");
int i=2;
  //RUN_TEST(tr, TestMacro);
if(i==3)

	PRINT_VALUES(cout, i,i+1)

else{
			//PRINT_VALUES(cout, i+3,i);
	cout << "aaa";

}
}
