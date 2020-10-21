#include <iostream>
#include "dma.h"
#include <cstring>

//method BaseDMA

 int BaseDMA:: n = 0;



BaseDMA::BaseDMA(const char* l, int r){
	n++;
	std::cout << "Constructor creat BaseDMA object " << n << std::endl;

	label = new char[std::strlen(l)];
	strcpy(label, l);
	rating = r;
}

BaseDMA::BaseDMA(const BaseDMA& rs){
	n++;
	std::cout << "Constructor copy creat BaseDMA  object " << n << std::endl;

	label = new char[strlen(rs.label) +1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

BaseDMA::~BaseDMA(){
	std::cout << "erase object " << n << std::endl;
	n--;
	delete [] label;
}

BaseDMA& BaseDMA::operator =(const BaseDMA& rs){
	if(this == &rs) return * this;
	delete [] label;
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const BaseDMA& rs){
	os << "Label: " << rs.label << std::endl;
	os <<"Rating: " << rs.rating <<std::endl;
	return os;
}

//method LacksDMA

LacksDMA::LacksDMA(const char* c, const char*l, int r) : BaseDMA(l,r) {
	(BaseDMA::n) ++;
	std::cout << "Constructor creat LacksDMA object " << n << std::endl;

	strncpy(color, c, 39);
	color[39] = '\0';
}

LacksDMA::LacksDMA(const BaseDMA& rs, const char* c ) : BaseDMA(rs){
	n++;
	std::cout << "Constructor copy creat LacksDMA object " << n << std::endl;

	strncpy(color, c, 39);
		color[39] = '\0';
}
std::ostream& operator<<(std::ostream& os, const LacksDMA& ls){
	os << (const BaseDMA &) ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}
LacksDMA::~LacksDMA(){
		std::cout << "erase object " << n << std::endl;
			n--;
	}

//method HasDMA

HasDMA::HasDMA(const char* l, const char* s, int r) :BaseDMA(l,r){
	n++;
	std::cout << "Constructor creat HasDMA object " << n << std::endl;

	style = new char[strlen(s) + 1];
	strcpy(style, s);

}
HasDMA::HasDMA(const char* s, const BaseDMA& rs) : BaseDMA(rs) {
	n++;
	std::cout << "Constructor copy creat HasDMA object " << n << std::endl;

	style = new char[strlen(s) + 1];
		strcpy(style, s);
}
HasDMA::~HasDMA(){
	std::cout << "erase object " << n << std::endl;
		n--;
	delete [] style;
}
HasDMA& HasDMA::operator =(const HasDMA& rs){
	if(this == & rs) return *this;
	BaseDMA::operator =(rs);
	style = new char[strlen(rs.style) - 1];
	strcpy(style, rs.style);
	return *this;
}

std::ostream& operator <<(std::ostream& os, const HasDMA& hs){
	os << (const BaseDMA&) hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}


