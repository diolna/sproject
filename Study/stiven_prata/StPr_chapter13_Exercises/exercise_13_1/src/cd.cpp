#include "cd.h"
#include <cstring>
#include <iostream>

//class Cd
Cd::Cd(const char* s1,  const char* s2, int n, double x){
		selection = n;
		playtime = x;
		std::strncpy(perfomance, s1, 49);
		perfomance[49] = '\0';
		std::strncpy(label, s2, 19);
		label[19] = '\0';
	};

Cd::Cd(const Cd& d) : selection(d.selection), playtime(d.playtime) {
			std::strncpy(perfomance, d.perfomance, 49);
			perfomance[49] = '\0';
			std::strncpy(label, d.label, 19);
			label[19] = '\0';
}
Cd::Cd() : perfomance("null"), label("null"),  selection(0), playtime(0.0) {}

void Cd::Report() const {
	std::cout << this->perfomance << std::endl;
	std::cout << this->label << std::endl;
	std::cout << this->selection << std::endl;
	std::cout << this->playtime << std::endl;

}

Cd& Cd::operator =(const Cd& d){
	if(this == &d) return *this;
	std::strncpy(perfomance, d.perfomance, 49);
	perfomance[49] = '\0';
	std::strncpy(label, d.label, 19);
		label[19] = '\0';
	selection = d.selection;
	playtime = d.playtime;
	return *this;
}




// Class Classic

Classic::Classic(char* s1, char* s2, char* s3, int n, double x) : Cd(s1,s2,n,x) {
		std::strncpy(task, s3, 39);
		task[39] = '\0';
	}
Classic::Classic(const Classic& cl) : Cd(cl) {
	std::strncpy(task, cl.task, 39);
	task[39] = '\0';
}
Classic::Classic() : Cd(), task("null") {}

void Classic::Report() const  {

	Cd::Report();
	std::cout << this->task<< std::endl;

}

Classic& Classic::operator =(const Classic& d){
	if(this == &d) return *this;
	Cd::operator =(d);
	std::strncpy(task, d.task, 39);
	task[39] = '\0';
	return *this;
}

