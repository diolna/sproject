
#include <iostream>
#include "brass.h"
using namespace std;

const int CLIENTS = 10;
const int LEN = 40;

int main() {

	//13.9
//	Brass Porky("Porcelot Pigg", 381299, 4000.00);
//	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
//	Porky.ViewAcct();
//	std::cout << endl;
//	Hoggy.ViewAcct();
//	std::cout << endl;
//	std::cout << "ADD 1000$ in count Hogg:\n";
//	Hoggy.Deposit(1000);
//	std::cout << "A New sum in account $\n" << Hoggy.Balance() << std::endl;
//	std:cout << "withdrawing $4200 from Porky`s account:\n";
//	Porky.Withdraw(4200.00);
//	std::cout << "New sum in Pigg`s accound $\n" << Porky.Balance() << std::endl;
//	std::cout << "withdrawing $4200 fron Hoggy`s account:\n";
//	Hoggy.Withdraw(4200.00);
//	Hoggy.ViewAcct();
// end 13.9

	//13.10

//	Brass * p_clients[CLIENTS];
//	int i;
//	for(i = 0; i < CLIENTS; i++){
//		char temp[LEN];
//		long tempnum;
//		double tempbal;
//		char kind;
//		std::cout << "Enter client name: ";
//		std::cin.getline(temp, LEN);
//		std::cout << "Enter client account number: ";
//		std::cin >> tempnum;
//		std::cout << "Enter deposit sum: ";
//		std::cin >> tempbal;
//		std::cout << "Enter '1' for selection deposite type Brass " <<
//				"or '2' for selecton deposit type BrassPlus ";
//		while(std::cin >> kind && (kind != '1' && kind !='2'))
//			std::cout << "Enter 1 or 2 ";
//		if(kind == '1')
//			p_clients[i] = new Brass (temp, tempnum, tempbal);
//		else
//		{
//			double tmax, trate;
//			std::cout << "Enter maximal sum overdraft: ";
//			std::cin >> tmax;
//			std::cout << "Enter the interest rate on the loan as a decimal: ";
//			std::cin >>trate;
//			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
//		}
//		while(std::cin.get() != '\n')
//			continue;
//	}
//	std::cout << std::endl;
//	for(i =0; i < CLIENTS; i++){
//		p_clients[i]->ViewAcct();
//		std::cout << std::endl;
//	}
//	for(i =0; i < CLIENTS; i++){
//			delete p_clients[i];
//
//		}
//	std::cout << "Ready:\n";


	//13.12


	AcctABC * p_clients[CLIENTS];
	int i;
	for(i = 0; i < CLIENTS; i++){
		char temp[LEN];
		long tempnum;
		double tempbal;
		char kind;
		std::cout << "Enter client name: ";
		std::cin.getline(temp, LEN);
		std::cout << "Enter client account number: ";
		std::cin >> tempnum;
		std::cout << "Enter deposit sum: ";
		std::cin >> tempbal;
		std::cout << "Enter '1' for selection deposite type Brass " <<
				"or '2' for selecton deposit type BrassPlus ";
		while(std::cin >> kind && (kind != '1' && kind !='2'))
			std::cout << "Enter 1 or 2 ";
		if(kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			std::cout << "Enter maximal sum overdraft: ";
			std::cin >> tmax;
			std::cout << "Enter the interest rate on the loan as a decimal: ";
			std::cin >>trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while(std::cin.get() != '\n')
			continue;
	}
	std::cout << std::endl;
	for(i =0; i < CLIENTS; i++){
		p_clients[i]->ViewAcct();
		std::cout << std::endl;
	}
	for(i =0; i < CLIENTS; i++){
			delete p_clients[i];

		}
	std::cout << "Ready:\n";

	return 0;
}
