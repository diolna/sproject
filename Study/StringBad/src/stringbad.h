#pragma once
#include <iostream>

class StringBad {
public:
	StringBad(const char *s);
	StringBad();
	StringBad(const StringBad &);
	StringBad& operator=(const StringBad &);
	~StringBad();
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
private:
	char * str;
	int len;
	static int num_strings;
};
