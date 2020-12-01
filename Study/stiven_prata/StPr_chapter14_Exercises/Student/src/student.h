#pragma once
#include "arraydb.h"
#include "string_user.h"
#include <iostream>

class Student {
public:
	Student() : name("Null student"), scores() {}
	Student(const String& s) : name(s), scores() {}
	Student(int n) : name("Null"), scores(n) {}
	Student(const String& s,int n ) : name(s), scores(n) {}
	Student(const String&s , const ArrayDb& a) : name(s), scores(a) {}
	Student(const char* str, const double * pd, int n) : name(str), scores(pd, n) {}
	~Student() {}
	double& operator[](int i);
	const double& operator[](int i) const ;
	double Avarage() const;

	friend std::ostream& operator<<(std::ostream& os, const Student & stu);
	friend std::istream& operator>>(std::istream& is,  Student & stu);
private:
	String name;
	ArrayDb scores;

};
