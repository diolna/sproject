

#include <iostream>

using namespace std;

class Rational {
public:
	Rational() {
		numerator_min = 0;
		denominator_min = 1;
	}

	Rational(int numerator, int denominator) {
		if (numerator == 0) {
			numerator_min = 0;
			denominator_min = 1;
			return;
		}
		if (numerator * denominator < 0) {
			if (denominator < 0) {
				numerator_min = -numerator;
				denominator_min = -denominator;
			}
			}

			if(numerator <0 && denominator<0 ){

			numerator_min = -numerator;
			denominator_min = -denominator;
		}
				
			numerator_min /= Nod(numerator, denominator);
		   denominator_min /= Nod(numerator, denominator);
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
	int Nod(int& numerator, int& denominator) {
		while ((numerator) != 0 && (denominator) != 0) {

			if (numerator > denominator) {
				numerator %= denominator;
			}
			else {
				denominator %= numerator;
			}
		}

		return numerator_min + denominator_min;
		
	}

};

bool operator==(const Rational& lhs, const Rational& rhs) {

	return lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator();


}
Rational operator+(const Rational& lhs, const Rational& rhs) {

	int com_den = lhs.Denominator()*rhs.Denominator();
	Rational new_rational((com_den / lhs.Denominator()*lhs.Numerator())
		+ (com_den / rhs.Denominator()*rhs.Numerator()), com_den);
	return new_rational;
}
Rational operator-(const Rational& lhs, const Rational& rhs) {

	int com_den = lhs.Denominator()*rhs.Denominator();
	Rational new_rational((com_den / lhs.Denominator()*lhs.Numerator())
		- (com_den / rhs.Denominator()*rhs.Numerator()), com_den);
	return new_rational;
}


int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
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

