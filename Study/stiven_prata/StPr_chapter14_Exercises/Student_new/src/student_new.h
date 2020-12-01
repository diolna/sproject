#pragma once
#include "String.h"
#include "ArrayDb.h"
#include <iostream>

class Student :  private String,
				private ArrayDb {

public:
	Student() : String("Null Student"), ArrayDb() {}
	Student(const String& s) : String(s), ArrayDb() {}
	Student(int n) : String("Nully"), ArrayDb(n) {}
	Student(const String& s, int n) : String(s), ArrayDb(n) {}
	Student(const String& s, const ArrayDb & a) : String(s), ArrayDb(a) {}
	Student(const char* str, const double *pd, int n) : String(str), ArrayDb(pd, n) {}
	~Student() {}
	double& operator[](int i);
	const double& operator[](int i ) const;
	double Average() const;
	// Friend method
	friend std::ostream& operator<<(std::ostream& os, const Student & stu );
	friend std::istream& operator>>(std::istream& is, Student& stu);


private:

};
