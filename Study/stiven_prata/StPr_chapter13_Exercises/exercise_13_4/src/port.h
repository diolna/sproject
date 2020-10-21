#pragma once

#include <iostream>

class Port {
public:
	Port(const char* br = "none", const char* st =  "none", int b =0);
	Port(const Port& po);
	virtual ~Port() {delete [] brand;}
	Port& operator=(const Port& po);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount() const { return bottles; }
	virtual void Show() const ;
	friend std::ostream& operator<<(std::ostream & os, const Port& po);


private:
	char* brand;
	char style[20];
	int bottles;
};


class VintagePort : public Port {
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort(){ delete [] nickname; }
	VintagePort& operator=(const VintagePort& vp);
	void Show() const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
private:
	char* nickname;
	int year;
};
