#include "port.h"
#include <iostream>
#include <cstring>

void Port::Show() const {
	std::cout << "Brand: " << this->brand << "\n";
	std::cout << "Kind: " << this->style << "\n";
	std::cout << "Bottels: " << this->bottles << "\n";
}

std::ostream& operator<<(std::ostream& os, const Port& po){
	return os << po.brand << ", " << po.style << ", " << po.bottles;
}

Port::Port(const char* br, const char* st, int b) {

	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);
	strncpy(style, st, 19);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port& po){

	brand = new char[std::strlen(po.brand) + 1];
	std::strcpy(brand, po.brand);
	strncpy(style, po.style, 19);
	style[19] = '\0';
	bottles = po.bottles;
}

Port& Port::operator =(const Port& po){
	if(this == &po) return *this;
	delete [] this->brand;
	brand = new char[std::strlen(po.brand) + 1];
	strcpy(brand, po.brand);
	strncpy(style, po.style, 19);
		style[19] = '\0';
		bottles = po.bottles;

}
Port& Port::operator +=(int b){
	this->bottles += b;
	return *this;
}
Port& Port::operator -=(int b){
	if(this->bottles - b <= 0 ) return *this;
	this->bottles -= b;
}

// VintagePort

VintagePort::VintagePort() : Port("none", "none", 0) {
	nickname = new char[5];
	strcpy(nickname, "none");
	this->year = 0;

}
VintagePort::VintagePort(const char * br, int b, const char * nn, int y) :
		Port(br, "none", b) {
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort& vp) : Port(vp) {
	nickname = new char[std::strlen(vp.nickname) + 1];
		std::strcpy(nickname, vp.nickname);
		year = vp.year;
}
VintagePort& VintagePort::operator =(const VintagePort& vp){
	if(this == &vp) return *this;
	Port::operator =(vp);
	delete [] this->nickname;
	nickname = new char[std::strlen(vp.nickname) +1 ];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}
void VintagePort::Show() const {
	Port::Show();
	std::cout << "nickname: " << nickname << "\n";
	std::cout << "year: " << year << "\n";

}
std::ostream& operator<<(std::ostream& os, const VintagePort& vp){
	os <<  (Port &) vp;
	os<< ", " << vp.nickname << ", " << vp.year;
	return os;
}


