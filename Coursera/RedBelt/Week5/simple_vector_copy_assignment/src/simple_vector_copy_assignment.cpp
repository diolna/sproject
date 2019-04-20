#include "simple_vector.h"
#include "test_runner.h"

#include <numeric>
#include <vector>
#include <tuple>

using namespace std;

void TestCopyAssignment() {
  SimpleVector<int> numbers(10);
  iota(numbers.begin(), numbers.end(), 1);

  SimpleVector<int> dest;
  ASSERT_EQUAL(dest.Size(), 0u);

  dest = numbers;
  ASSERT_EQUAL(dest.Size(), numbers.Size());
  ASSERT(dest.Capacity() >= dest.Size());
  ASSERT(equal(dest.begin(), dest.end(), numbers.begin()));
}

//void TestCopy2Assignment() {
//  SimpleVector<int> numbers(10);
//  iota(numbers.begin(), numbers.end(), 1);
//
//  SimpleVector<int> dest;
//  ASSERT_EQUAL(dest.Size(), 0u);
//
//  SimpleVector<int> dest2;
//
//  dest2 = dest = numbers;
//  ASSERT_EQUAL(dest2.Size(), numbers.Size());
//  ASSERT(dest2.Capacity() >= dest2.Size());
//  ASSERT(equal(dest2.begin(), dest2.end(), numbers.begin()));
//}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestCopyAssignment);
//  RUN_TEST(tr, TestCopy2Assignment);
}
