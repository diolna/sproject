#include <iostream>
#include <cstring>
#include "string.h"

int  String::num_string = 0;

String::String(const String& st ){
	num_string++;
	len = st.len;
	str = new char[len +1];
	std::strcpy(str, st.str);
//	std::cout << "created - " << num_string << " object\n";

}
String& String::operator=(const String& st ){
	if(this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len +1];
	std::strcpy(str, st.str);
	return *this;
}

String::String(const char* s){
	num_string++;
	len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
//	std::cout << "created - " << num_string << " object\n";

}

String::String(){
	num_string++;
	len = 0;
	str = new char[1];
	str[0] = '\0';
//	std::cout << "created - " << num_string << " object\n";


}

String::~String(){
//	std::cout << "delete - " << num_string << " object\n";
	num_string--;
	delete []str;

}

std::ostream& operator<<(std::ostream& os, const String & st){
	os << st.str;
	return os;
}
std::istream& operator>>(std::istream& is, String & st){
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if(is)
		st = temp;
	while(is && is.get() != '\n')
		continue;

	return is;
}

	bool operator<(const String &st1, const String &st2){
		if(std::strcmp(st1.str, st2.str)<0)
			return true;
		else return false;

	}

	bool operator>(const String &st1, const String &st2){
			return (std::strcmp(st1.str, st2.str) > 0 );
		}

	bool operator==(const String &st1, const String &st2){
			return (std::strcmp(st1.str, st2.str) == 0 );
		}

	char & String::operator [](int i){
		return str[i];

	}

const char& String::operator[](int i) const {
	return str[i];
}

String& String::operator=(const char* s){
	delete [] str;
	len = std::strlen(s);
	str = new char[len +1];
	strcpy(str, s);
	return *this;
}



