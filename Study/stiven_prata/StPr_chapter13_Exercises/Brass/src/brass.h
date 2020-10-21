#pragma once
#include <iostream>


class AcctABC {
public:
		AcctABC(const char* s = "Nullbody", long an = -1, double bal = 0.0);
		void Deposit(double amt);
		virtual void WithDraw(double amt) = 0;
		double Balance() const {return balance;}
		virtual void ViewAcct() const = 0;
		virtual ~AcctABC(){}
private:
		double balance;
		enum {MAX = 35};
		char fullName[MAX];
		long acctNum;
protected:
		const char* FullName() const {return fullName;}
		long AcctNum() const {return acctNum;}
		std::ios_base::fmtflags SetFormat() const;

};

class Brass : public AcctABC {
public:
	Brass(const char* s = "Nullbody", long an = -1, double bal = 0.0) :
		AcctABC(s, an, bal) {}
	void Deposit(double amt);
	virtual void WithDraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

class BrassPlus : public AcctABC {
public:
	BrassPlus(const char* s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500,
			double r = 0.10);
	BrassPlus(const Brass& ba, double ml = 500,	double r = 0.10);
	virtual void ViewAcct() const;
	virtual void WithDraw(double amt);
	void ResetMax(double m) {maxLoan = m;}
	void ResetRate(double r) {rate = r;}
	void ResetOwes() {owesBank = 0; }
	virtual ~BrassPlus() {}


private:
	double maxLoan;
	double rate;
	double owesBank;


};
