#include "cd.h"
#include <cstring>
#include <iostream>

//class Cd
Cd::Cd( const char* s1,  const char* s2, int n, double x){
		selection = n;
		playtime = x;
		perfomance = new char[std::strlen(s1) + 1];
		strcpy(perfomance, s1);
		label = new char[std::strlen(s2) + 1];
		strcpy(label, s2);

	};

Cd::Cd(const Cd& d) : selection(d.selection), playtime(d.playtime) {

			perfomance = new char[std::strlen(d.perfomance) + 1];
			std::strcpy(perfomance, d.perfomance);
					label = new char[std::strlen(d.label) + 1];
					strcpy(label, d.label);
}
Cd::Cd() : selection(0), playtime(0.0) {
	perfomance = new char[50];
	label = new char[50];
}

void Cd::Report() const {
	std::cout << this->perfomance << std::endl;
	std::cout << this->label << std::endl;
	std::cout << this->selection << std::endl;
	std::cout << this->playtime << std::endl;

}

Cd& Cd::operator =(const Cd& d){
	if(this == &d) return *this;
	delete [] perfomance;
	delete []label;
	perfomance = new char[std::strlen(d.perfomance) + 1];
	std::strcpy(perfomance, d.perfomance);
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(label, d.label);
	selection = d.selection;
	playtime = d.playtime;
	return *this;
}




// Class Classic

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x) : Cd(s1,s2,n,x) {
		task = new char[std::strlen(s3)  + 1];
		strcpy(task, s3);
	}
Classic::Classic(const Classic& cl) : Cd(cl) {
	task = new char[std::strlen(cl.task)  + 1];
	strcpy(task, cl.task);
}
Classic::Classic() : Cd() {
	task = new char[50];



}

void Classic::Report() const  {

	Cd::Report();
	std::cout << this->task<< std::endl;

}

Classic& Classic::operator =(const Classic& d){
	if(this == &d) return *this;



	Cd::operator =(d);
	delete [] task;
	task = new char[strlen(d.task)  + 1];
	strcpy(task, d.task);
	return *this;
}

