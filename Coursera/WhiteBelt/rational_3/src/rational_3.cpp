
#include <iostream>
//#include <cmath>

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


bool operator==(const Rational& lhs, const Rational& rhs) {

	return lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator();


}
Rational operator*(const Rational& lhs, const Rational& rhs)  {

	return {lhs.Numerator()*rhs.Numerator(), lhs.Denominator()*rhs.Denominator()};


}
Rational operator/(const Rational& lhs, const Rational& rhs) {


	return {lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator()};
}


int main() {



    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
