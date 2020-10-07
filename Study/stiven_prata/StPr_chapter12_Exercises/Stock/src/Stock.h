#pragma once

#include <iostream>

class Stock {
public:
	Stock();
	Stock(const char* co, int n, double pr);
	~Stock();
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	void show() const;
	const Stock& topval(const Stock& s) const;
	friend std::ostream& operator<<(std::ostream& os, const Stock& s);
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void set_tot(){
		total_val = shares * share_val;
	}
};
