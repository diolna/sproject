#include "student.h"
#include <iostream>

double Student::Avarage() const {
	return scores.Average();
}


double& Student::operator [](int i){
	return scores[i];
}

const double& Student::operator [](int i) const {
	return scores[i];
}

std::ostream& operator<<(std::ostream& os, const Student& stu){
	os << "Scores for" << stu.name << ":\n";
	os << stu.scores;
	return os;

}
std::istream& operator>>(std::istream& is,  Student& stu){
		is >> stu.name;
		return is;
}
