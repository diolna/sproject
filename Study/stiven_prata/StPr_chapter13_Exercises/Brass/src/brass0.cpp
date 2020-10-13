#include "brass.h"
#include <iostream>
#include <cstring>

AcctABC::AcctABC(const char* s, long an, double bal){
	strncpy(fullName, s, MAX -1);
	fullName[MAX -1 ] = '\0';
	acctNum = an;
	balance = bal;

}
void AcctABC::Deposit(double amt ){
	if(amt < 0 )
		std::cout << "number be not (-) operation cancel\n ";
	else
		balance += amt;
}
void AcctABC::WithDraw(double amt){

		balance -= amt;

}

std::ios_base::fmtflags AcctABC::SetFormat() const {
	std::ios_base::fmtflags initialState = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.setf(std::ios_base::showpoint);
	std::cout.precision(2);
	return initialState;

}

void Brass::Withdraw(double amt){
	if(amt < 0)
		std::cout << "number be not (-) operation cancel \n";
	else if(amt <= Balance())
		AcctABC::WithDraw(amt);
	else
		std::cout << "$ " << amt << "not be money of account  operation cancel\n";
}




void Brass::ViewAcct() const {
	std::ios_base::fmtflags initialState = SetFormat();
	std::cout << "customer " << FullName() << std::endl;
	std::cout << "account Number " << AcctNum() << std::endl;
	std::cout << "balance count " << Balance() << std::endl;
	std::cout.setf(initialState);


}

BrassPlus::BrassPlus(const char*s , long int an, double bal, double ml, double r) :
		AcctABC(s, an, bal), maxLoan(ml), owesBank(0), rate(r) {}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : AcctABC(ba), maxLoan(ml),
		owesBank(0), rate(r) {}
void BrassPlus::ViewAcct() const {

	std::ios_base::fmtflags initialState = SetFormat();

	std::cout << "BrassPluss client: " << FullName() << std::endl;
	std::cout << "Account Number " << AcctNum() << std::endl;
	std::cout << "Balance $ " << Balance() << std::endl;
	std::cout << "Maximal in $ " << maxLoan << std::endl;
	std::cout << "Dolg " << owesBank << std::endl;
	std::cout << "% " << 100*rate << std::endl;
	std::cout.setf(initialState);
}

void BrassPlus::Withdraw(double amt){
	std::ios_base::fmtflags initialState = SetFormat();

		double bal = Balance();
		if(amt <= bal)
			AcctABC::WithDraw(amt);
		else if(amt <= bal + maxLoan - owesBank){
			double advance = amt - bal;
			owesBank += advance * (1.0+ rate);
			std::cout << "Bank avance = " << advance << std::endl;
			std::cout << "Fin rachod = " << advance * rate << std::endl;
			Deposit(advance);
			AcctABC::WithDraw(amt);
		}
		else
			std::cout << "Credit long canceld\n";
		std::cout.setf(initialState);

}
