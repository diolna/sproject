#pragma once

#include <iostream>

class Cow{

public:
	static int idnext;
	Cow();
	Cow(const char* na, const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator=(const Cow& c);
	void ShowCow();

private:
	char name[20];
	char* hobby;
	double weight;
	int id;



};


