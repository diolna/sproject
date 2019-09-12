//#include "phone_number.cpp"
#include "phone_number.h"
#include <iostream>


using namespace std;

int main(){


	PhoneNumber p("+b38-455-878979");
	cout << p.GetInternationalNumber() << endl;
	cout << p.GetCountryCode()<< endl;
	cout << p.GetCityCode() << endl;
	cout << p.GetLocalNumber() << endl;






}

