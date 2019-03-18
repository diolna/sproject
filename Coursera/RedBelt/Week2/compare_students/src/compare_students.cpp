#include "student.h"
#include "test_runner.h"
#include "profile.h"
<<<<<<< HEAD
=======

>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1
#include <algorithm>

using namespace std;

//Оптимизируйте эту функцию
<<<<<<< HEAD
bool Compare(Student first, Student second) {
  return first.Less(second);
}

void TestComparison() {
=======


bool Compare(const Student& first, const Student& second) {

  return first.Less(second);
}


void TestComparison() {
	LOG_DURATION("test comparision");
>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1
  Student newbie {
    "Ivan", "Ivanov", {
      {"c++", 1.0},
      {"algorithms", 3.0}
    },
    2.0
  };

  Student cpp_expert {
    "Petr", "Petrov", {
      {"c++", 9.5},
      {"algorithms", 6.0}
    },
    7.75
  };

  Student guru {
    "Sidor", "Sidorov", {
      {"c++", 10.0},
      {"algorithms", 10.0}
    },
<<<<<<< HEAD
    10.0
=======
    299999999999999.0
>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1
  };
  ASSERT(Compare(guru, newbie));
  ASSERT(Compare(guru, cpp_expert));
  ASSERT(!Compare(newbie, cpp_expert));
<<<<<<< HEAD
=======

>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1
}

void TestSorting() {
  vector<Student> students {
    {"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
    {"Semen", "Semenov", {{"maths", 4.}}, 4.},
    {"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
    {"Petr", "Petrov", {{"maths", 3.}}, 3.},
<<<<<<< HEAD
    {"Alexander", "Alexandrov", {{"maths", 1.}}, 1.}
  };
  sort(students.begin(), students.end(), Compare);
=======
	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
		{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
		{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
		{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
		{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
			{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
			{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
			{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
			{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
				{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
				{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
				{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
				{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
					{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
					{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
					{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
					{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
						{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
						{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
						{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
						{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
							{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
							{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
							{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
							{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
								{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
								{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
								{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
								{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
									{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
									{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
									{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
									{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
										{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
										{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
										{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
										{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
											{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
											{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
											{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
											{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
												{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
												{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
												{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
												{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
													{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
													{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
													{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
													{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
														{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
														{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
														{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
														{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
															{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
															{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
															{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
															{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																	{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																		{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																		{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},
																		{"Alexander", "Alexandrov", {{"maths", 1.}}, 1.},

  };
  {
	  LOG_DURATION("sort");
  sort(students.begin(), students.end(), Compare);
  }
  {
	  LOG_DURATION("is sorted");

>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1
  ASSERT(is_sorted(students.begin(), students.end(),
    [](Student first, Student second) {
      return first.Less(second);
    })
  );
<<<<<<< HEAD
=======
  }
}

int main() {
	{
  LOG_DURATION("total");
  TestRunner tr;
  RUN_TEST(tr, TestComparison);
  RUN_TEST(tr, TestSorting);
	}

	{

	}


  return 0;
>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1
}
