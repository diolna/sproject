#pragma once
#include <cstring>

class Cd {
public:
	Cd(const char* s1,  const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd(){};
	virtual void Report() const;
	Cd& operator=(const Cd& d);
private:
	char perfomance[50];
	char label[20];
	int selection;
	double playtime;
};

class Classic : public Cd {
public:
	Classic(char* s1, char* s2, char* s3, int n, double x);
	Classic(const Classic& cl);
	Classic();
	virtual ~Classic(){}
	virtual void Report() const;
	Classic& operator=(const Classic& cl);
private:
	char task[40];
};

//Cd::Cd(s1, s2, n, x){
//	std::strcpy(perfomance, s1, 49);
//	perfomance[49] = '\0';
//	std::strcpy(perfomance, s2, 19);
//		label[19] = '\0';
//}
