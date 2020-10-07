#include "Stock.h"
#include <iostream>
#include <cstring>

Stock::Stock(){
//    std:: cout << "creat obiject Stock()\n";
	company = new char[9];
	strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val =0.0;
}

Stock::Stock(const char* co, int n, double pr){
//	std::cout << "creat object Stock(const char*co, int n double pr)\n";
	company = new char[strlen(co) + 1];
	strcpy(company, co);
	shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock(){
	delete [] company;
}

void Stock::buy(int num, double price){
	if(num < 0){
		std::cerr << "Number of shared purchased can`t be negative."
				<< "Transaction is abortes.\n";
	}
	else {
		shares+= num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(int num, double price){
	if(num > shares){
		std::cerr << "You can`t sell more that you have!"
				<< "Transaction is aborted. \n";
	}
	else{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price){
	share_val = price;
	set_tot();
}

void Stock::show() const {
	std::cout << "Company: " << company
			<< "Shares: " << shares << '\n'
			<< "Share Price: $" << share_val
			<< "Total Worth: $" << total_val << '\n';
}
const Stock& Stock::topval(const Stock& s) const {
	if(s.total_val > total_val){
		return s;
	}
	else
		return *this;
}

std::ostream& operator << (std::ostream& os, const Stock& s){
	os << "Company: " << s.company
				<< "Shares: " << s.shares << '\n'
				<< "Share Price: $" << s.share_val
			<< "Total Worth: $" << s.total_val << '\n';

	return os;
	}

