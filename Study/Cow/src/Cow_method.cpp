#include "Cow.h"
#include <iostream>
#include <cstring>


int Cow::idnext = 0;

Cow::Cow(const char* na, const char* ho, double wt) {
	idnext++;
	id = idnext;
	std::cout << "created object ID " << id << std::endl;
	int len_hobby = std::strlen(ho);
	hobby = new char[len_hobby +1];
	std::strcpy(name, na);
	std::strcpy(hobby, ho);
	weight = wt;

}

Cow::Cow() : name(""), weight(0) {
	idnext++;
	id = idnext;
	std::cout << "created object ID " << id << std::endl;
 	hobby = new char;
	hobby[0] = '\0';


}

Cow::~Cow(){

	std::cout << "delate object -" << id
	<< " name =  "<< this->name << '\n';
	delete[] hobby;
}

void Cow::ShowCow(){
		std::cout << "name Cow=  " << name
			<< " HOBBY = " << hobby  << "  weight = " << weight << " ID = " << id << std::endl;
}

 Cow::Cow(const Cow& c)
{
	 idnext++;
	 	id = idnext;
	 std::cout << "constructor copy " << this->id << " copy " << c.id << '\n';
//	delete [] hobby;
	std:: strcpy(name, c.name);

	hobby = new char[std::strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;

}

 Cow& Cow::operator =(const Cow& c)
 {

	 std::cout << "constructor (=) " << this->id << " = " << c.id << '\n';
	 delete [] hobby;
	 	std:: strcpy(name, c.name);

	 	hobby = new char[std::strlen(c.hobby) + 1];
	 	strcpy(hobby, c.hobby);
	 	weight = c.weight;
	 	return *this;

 }



