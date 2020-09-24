#include <iostream>
#include <cstring>
#include "stringbad.h"

int StringBad::num_strings = 0;

StringBad::StringBad(const char* s){
	len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
	num_strings++;
	std::cout << num_strings << " : \" " << str
			<< "\" object creater\n";

}

StringBad::StringBad(){
	len = 4;
	str = new char[4];
	num_strings++;
	std::cout << num_strings << ": \" " << str
			<< "\"default object created\n";
}

StringBad::~StringBad(){
	std::cout << " \" " << str << " \" object deleted, ";
	--num_strings;
	std::cout << num_strings << " leaft\n";
	delete []str;
}

std::ostream& operator<<(std::ostream& os, const StringBad & st){
	os << st.str;
	return os;
}



