#include "student_new.h"
#include <iostream>

double Student::Average() const {
	return ArrayDb::Average();
}


double& Student::operator[](int i){
	return ArrayDb::operator [](i);
}

const double& Student::operator [](int i) const {
	return ArrayDb::operator [](i);
}

std::ostream& operator<<(std::ostream& os, const Student& s){
	os << "Scores for" << (const String&) s << ":\n";
	os << (const ArrayDb&) s;
	return os;

}
std::istream& operator>>(std::istream& is,  Student& stu){
		is >> (String&) stu;
		return is;
}
