#include <fstream>
#include <vector>
#include <iostream>
#include <set>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

class LogDuration {
public:
	explicit LogDuration(const string& msg = "")
		: 	message(msg + ": ")
		,	start(steady_clock::now())
{
}
	~LogDuration(){
		auto finish = steady_clock::now();
		auto dur = finish - start;
		cerr << message <<  duration_cast<milliseconds>(dur).count()
				<< " ms" << endl;
	}
private:
	steady_clock::time_point start;
	string message;
};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)
#define LOG_DURATION(message) \
			LogDuration UNIQ_ID(__LINE__){message};

int main() {
	LOG_DURATION("total");

	ifstream in ("input.txt");
	int element_count;
	in >> element_count;
	set<int> elements;

	{
		LOG_DURATION("input");
		for(int i=0; i< element_count; ++i) {
			int x;
			in >> x;
			elements.insert(x);
		}
	}


}
