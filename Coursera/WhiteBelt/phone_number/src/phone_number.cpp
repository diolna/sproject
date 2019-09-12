

#include <sstream>
#include <iostream>


using namespace std;

#include "phone_number.h"
#include <exception>




 PhoneNumber::PhoneNumber(const string &international_number){
		istringstream input(international_number);
		string country, city, number;
		char plus;


		if(input){
			input.get(plus);
			getline(input, country, '-');
			getline(input, city, '-');
			getline(input, number);

			if( plus!='+' || country.find('+')!=-1 || country.empty()|| city.empty() || number.empty()){
							throw  invalid_argument("invalid argument");
			}else{

				country_code_ = country;
				city_code_ = city;
				local_number_ = number;
			}
		}
}


string PhoneNumber::GetCountryCode() const{
	return country_code_;
}
string PhoneNumber::GetCityCode() const{
	return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
	return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}
