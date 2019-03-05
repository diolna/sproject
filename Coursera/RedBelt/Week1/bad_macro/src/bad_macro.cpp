#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) [&](ostream& os){							\
												\
									os << (x) << endl;		\
									os << (y) << endl;		\
								}(out)
//#define PRINT_VALUES(out,x,y) out <<(x) << endl; out << (y) << endl;

//void TestMacro(){
//
//}

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    int i = 5;
    string s = "red belt";
    PRINT_VALUES(output, i, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
  }, "PRINT_VALUES usage example");
 // int n=44;
  //if(n==44)
//	  PRINT_VALUES(cout, n, "dfdf");
//  else
//	  int ccc=43;
}
