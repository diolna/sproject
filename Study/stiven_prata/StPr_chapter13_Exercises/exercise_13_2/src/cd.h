#pragma once
#include <cstring>

class Cd {
public:
	Cd( const char* s1,  const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd(){
		delete [] perfomance;
		delete [] label;
	};
	virtual void Report() const;
	Cd& operator=(const Cd& d);
private:
	char* perfomance;
	char* label;
	int selection;
	double playtime;
};

class Classic : public Cd {
public:
	Classic(const char* s1, const char* s2, const char* s3, int n, double x);
	Classic(const Classic& cl);
	Classic();
	virtual ~Classic(){
		delete [] task;
	}
	virtual void Report() const;
	Classic& operator=(const Classic& cl);
private:
	char* task;
};


