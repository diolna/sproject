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

std::ostream& operator<<(std::ostream& os, const Student& s){
	os << "Scores for" << s.name << ":\n";
	os << s.scores;
	return os;

}
std::istream& operator>>(std::istream& is, const Student& s){
		is >> s.name;
		return is;
}
