#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file= value; }
  bool GetLogLine(){return log_line;}
  bool GetLogFile() {return log_file;}

  void Log(const string& message){os<< message<< '\n';};


private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

#define LOG(logger, message) 							\
														\
if(logger.GetLogFile()&& logger.GetLogLine()){			\
				const string file= __FILE__;			\
				const int line_1= __LINE__;				\
				string ss= to_string(line_1);			\
				logger.Log(file+":"+ss+" "+message);	\
}else if(logger.GetLogFile()){							\
			const string file= __FILE__;				\
			logger.Log(file+" "+message);				\
}else if(logger.GetLogLine()){ 							\
	const int line_1= __LINE__;							\
	string ss= to_string(line_1);						\
	logger.Log("Line "+ss+" "+message);					\
}else{													\
														\
	logger.Log(message);								\
														\
}

void TestLog() {
/* ��� ��������� ����-������ � ���� ������ ��� ����� ����������� ����������
 * ������ ����� � ��������� �������� (��. ���������� expected ����). ����
 * �� ��������� �����-�� ��� ���� ������� TestLog, �� ��� ������ ����� ��������,
 * � ��� ���� �������� ������. ��� ��������.
 *
 * ����� ����� ��������, �� ���������� ����������� ������ #line
 * (http://en.cppreference.com/w/cpp/preprocessor/line), ������� ���������
 * �������������� ����� ������, � ����� ��� �����. ��������� ���, ������
 * ����� ������ ������� TestLog ����� ����������� ���������� �� ����, �����
 * ��� �� ��������� ����� ���*/
#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLog);
}
