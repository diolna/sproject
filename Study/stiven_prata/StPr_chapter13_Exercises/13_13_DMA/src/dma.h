#pragma once
#include <iostream>

class BaseDMA {
public:
	static int n;
	BaseDMA(const char* l = "null", int r = 0);
	BaseDMA(const BaseDMA& rs);
	virtual ~BaseDMA();
	BaseDMA& operator=(const BaseDMA& rs);
	friend std::ostream& operator<<(std::ostream & os, const BaseDMA& rs);
private:
	char * label;
	int rating;


};

class LacksDMA : public BaseDMA {
public:
	LacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	LacksDMA(const BaseDMA& rs, const  char* c = "null");
	friend std::ostream& operator<<(std::ostream& os, const LacksDMA& rs);
	~LacksDMA();
private:
	char color[40];
};

class HasDMA : public BaseDMA {
public:
	HasDMA(const char* s = "none", const char* l = "none", int r = 0);
	HasDMA(const char* s, const BaseDMA& rs);
	HasDMA(const HasDMA & hs);
	~HasDMA();
	HasDMA& operator=(const HasDMA& rs);
	friend std::ostream& operator<<(std::ostream &os, const HasDMA & rs);
private:
	char* style;
};
