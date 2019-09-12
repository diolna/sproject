
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
		bool is_positive = numerator * denominator >= 0;
	    int n = Nod(numerator, denominator);
	    numerator_min = (is_positive ? 1 : -1) * abs(numerator_min/ n);
	    denominator_min = (numerator_min == 0) ? 1 : abs(denominator_min/n);

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
				while (num > 0 && denom > 0) {

					if (num > denom) {
						num %= denom;
					}
					else {
						denom %= num;
					}
				}

				return num + denom;

			}

};


bool operator==(const Rational& lhs, const Rational& rhs) {

	return lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator();


}
Rational operator+(const Rational& lhs, const Rational& rhs) {

	return {(lhs.Numerator()*rhs.Denominator()+ rhs.Numerator()*lhs.Denominator()),
										lhs.Denominator()*rhs.Denominator()};


}
Rational operator-(const Rational& lhs, const Rational& rhs) {


	return {(lhs.Numerator()*rhs.Denominator()- rhs.Numerator()*lhs.Denominator()),
		lhs.Denominator()*rhs.Denominator()};

}


int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
