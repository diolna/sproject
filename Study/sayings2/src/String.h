#pragma once
#include <iostream>

class String {
public:
	String(const char *s);
	String();
	String(const String &);
	String& operator=(const String &);
	~String();
	String& operator=(const char* );
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& is,  String& st);
	int lenght() const {return len;}
	friend bool operator > (const String& st1, const String& st2);
	friend bool operator < (const String& st1, const String& st2);
	friend bool operator ==(const String& st1, const String& st2);
	friend std::istream&  operator>>(std::istream & is, String & st);
	char& operator[](int i);
	const char& operator[](int i) const;
	static int HowMany() {return num_string;}

	private:
	char * str;
	int len;
	static int num_string;
	static const int CINLIM = 80;


};

