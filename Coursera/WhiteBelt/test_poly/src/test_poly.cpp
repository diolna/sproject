#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>


using namespace std;

#include "test_runner.h"
#include "palyndrom.h"
#include "test.h"





int main() {
  TestRunner runner;
  runner.RunTest(TestOneSymbol, "OneSymbol");
  runner.RunTest(TestEmptyString, "EmptyString");
  runner.RunTest(TestPalindrom, "TestPalindrom");




  return 0;
}
