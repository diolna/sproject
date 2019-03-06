#include <string>
#include <vector>
using namespace std;

#define TOKENPASTE(y) x##y
#define TOKENPASTE2( y) TOKENPASTE( y)
#define UNIQ_ID TOKENPASTE2(__COUNTER__)  // COUNTER не является стандартом С но поддерживается
										// если не поддерживается используем __LINE__



int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};

}
