

#include <iostream>
#include <iomanip>
#include <exception>
#include <string>


using namespace std;




class Rational {
public:
Rational() {
		numerator_min = 0;
		denominator_min = 1;
	}

	Rational(int numerator, int denominator) {
		numerator_min = numerator;
				denominator_min = denominator;
				if(denominator_min == 0){

					throw invalid_argument("invalid_argument");

				}
				bool is_positive = (numerator>=0 && denominator >= 0 ||
									numerator<0 && denominator < 0 );
				  int n = Nod(numerator, denominator);
				   if(numerator_min == 0){
				    	denominator_min =1;
				    }else{
					    numerator_min = (is_positive ? 1 : -1) * abs(numerator_min/ n);
					    denominator_min = abs(denominator_min/n);
				    }
	}




	int Numerator() const {

		return numerator_min;

	}
	int Denominator() const {
		return denominator_min;
	}

private:


	int numerator_min;
	int denominator_min;
	int Nod( int& num,  int& denom) {
		num = abs(num);
		denom= abs(denom);
		while (num>0 && denom>0) {

							if (num > denom) {
								num %= denom;
							}
							else {
								denom %= num;
							}
						}

						return num+denom;

			}

};

Rational operator/(const Rational& lhs, const Rational& rhs) {

	if(rhs.Numerator()==0){
		throw domain_error("domain_error");
	}
	return {lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator()};
}


int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument& ia) {
    	cout << ia.what()<< endl;
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error& de) {
    	cout << de.what()<< endl;
    }

    cout << "OK" << endl;
    return 0;
}
