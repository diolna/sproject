#include <iostream>
#include <cstring>
#include "string_user.h"
#include <cctype>

int  String::num_string = 0;

String::String(const String& st ){
	num_string++;
	len = st.len;
	str = new char[len +1];
	std::strcpy(str, st.str);
//	std::cout << "construcn copy created - " << num_string << " object\n";

}
String& String::operator=(const String& st ){
//	std::cout << "operator = " << std::endl;
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
//	std::cout << "operator =  char" << std::endl;
 	delete [] str;
	len = std::strlen(s);
	str = new char[len +1];
	strcpy(str, s);
	return *this;
}

String operator+(const String& st1, const String& st2){
//	std::cout << "operator + " << std::endl;
 	int len_plus= st1.len + st2.len;
	String s;
	s.str = new char[len_plus + 1];
	strcpy(s.str, st1.str);
	strcpy(s.str + st1.len, st2.str);
	s.len = len_plus;
	return s;
}

void String::stringlow(){
		for(int i = 0; i <= len; i++){
			str[i] = (char)tolower(str[i] );
		}

}

void String::stringup(){
		for(int i = 0; i <= len; i++){
			str[i] = (char)toupper(str[i] );
		}

}

int String::charcound(const char& ch){
	int count = 0;
	for(int i =0; i <= len; i++){
		if(ch == str[i]) count++;
	}
	return count;
}

