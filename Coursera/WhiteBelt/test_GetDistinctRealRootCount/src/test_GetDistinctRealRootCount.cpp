#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

int AisZero( const double& b, const double& c){
	double res;
	if(b!=0){
		res = 1;
	}
	else {
		res =0;
	}
	return res;
}

//int BisZero(const double& a, const double& c){
//	int res;
//	if(a>0 && c<0 ){
//	res = 2;
//	}else
//		if(a!=0 && c==0){
//		res =1;
//	}else if(a<0 && c>0){
//		res =2;
//	}else
//	{
///		res=0;
//	}
//	return res;
//}

int ABCnotZero(const double& a, const double& b, const double& c){
	int r=0;
	double d=(b*b-(4*a*c));
	if(d>0){
		r = 2;

	}else if(d==0)
	{
		r =1;

	}else if(d<0){
		r = 0;
	}
	return r;
}

int GetDistinctRealRootCount(double a, double b, double c) {
	int res1;
	if(a==0 ){
		 res1 = AisZero(b,c);
	//}//else if(b ==0){
	//	res1 =BisZero(a,c);

	}else
	{
	 res1 = ABCnotZero(a,b,c);
	}
	return res1;
}
//void TestAisZero(){
//	 AssertEqual(AisZero(1,10), 1, "a=0 b=1 c=10");
//	 AssertEqual(AisZero(0,10), 0, "a=0 b=0 c=10");
//////	 AssertEqual(AisZero(1,0), 1, "a=0 c=0 b =1");
//	  AssertEqual(AisZero(2,-10), 1, "a=0 c=-10 b=2");
//	  AssertEqual(AisZero(-2,-10), 1, "a=0 c=-10 b=2");
//	  AssertEqual(AisZero(0,-10), 0, "a=0 c=-10 b=2");


//}
//void TestBisZero(){
//
//	 AssertEqual(BisZero(1,0), 1, "a=1  c=0");
//	 AssertEqual(BisZero(1,-25), 2, "a=1 b=0 c=-25");
//	 AssertEqual(BisZero(1,25), 0, "a=1 c=25 b =0");
//	 AssertEqual(BisZero(2,-10), 2, "a=0 c=-10 b=0");
//	 AssertEqual(BisZero(0,-10), 0, "a=0 c=-10 b=0");
//	 AssertEqual(BisZero(-10,10), 2, "a=0 c=-10 b=0");
//
//}

void Test(){

	AssertEqual(GetDistinctRealRootCount(0,0,1), 0 , "a=0, b = 0, c= 1");
	AssertEqual(GetDistinctRealRootCount(0,0,-1), 0 , " a=0 b =0 c=-1");
	AssertEqual(GetDistinctRealRootCount(1,0,0), 1 , "a=1, b = 0, c= 0");
	AssertEqual(GetDistinctRealRootCount(-1,0,0), 1 , " a=-1 b =0 c=0");
	AssertEqual(GetDistinctRealRootCount(0,1,0), 1, " a=0 b= 1 c= 0" );
	AssertEqual(GetDistinctRealRootCount(0,-1,0), 1 , " a=0 b =-1 c=-0");
	AssertEqual(GetDistinctRealRootCount(-1,-1,-1), 0 , " a=-1 b =-1 c=-1");
	AssertEqual(GetDistinctRealRootCount(1,1,1), 0 , " a=1 b =1 c=1");
	AssertEqual(GetDistinctRealRootCount(-1,-1,1), 2 , " a=-1 b =-1 c=1");
	AssertEqual(GetDistinctRealRootCount(1,-1,-1), 2 , " a=1 b =-1 c=-1");
	AssertEqual(GetDistinctRealRootCount(1,1,-1), 2 , " a=1 b =1 c=-1");
	AssertEqual(GetDistinctRealRootCount(-1,1,-1), 0 , " a=-1 b =1 c=-1");
	AssertEqual(GetDistinctRealRootCount(0,-1,-1), 1 , " a=-0 b =-1 c=-1");
	AssertEqual(GetDistinctRealRootCount(0,1,1), 1 , " a=0 b =1 c=1");
	AssertEqual(GetDistinctRealRootCount(0,1,-1), 1 , " a=0 b =1 c=-1");
	AssertEqual(GetDistinctRealRootCount(0,-1,1), 1 , " a=0 b =-1 c=1");
	AssertEqual(GetDistinctRealRootCount(1,0,1), 0 , " a=1 b =0 c=1");
	AssertEqual(GetDistinctRealRootCount(-1,0,-1),0 , " a=-1 b =0 c=-1");
	AssertEqual(GetDistinctRealRootCount(-1,0,1), 2 , " a=-1 b =0 c=1");
	AssertEqual(GetDistinctRealRootCount(1,0,-1), 2 , " a=1 b =0 c=-1");
	AssertEqual(GetDistinctRealRootCount(1,1,0), 2 , " a=-1 b =1 c=0");
	AssertEqual(GetDistinctRealRootCount(-1,1,0), 2 , " a=-1 b =1 c=0");
	AssertEqual(GetDistinctRealRootCount(1,-1,0), 2 , " a=-1 b =-1 c=0");

}

int main() {
  TestRunner runner;

  runner.RunTest(Test, "abc");
  return 0;
}
