
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
Rational operator+(const Rational& lhs, const Rational& rhs)  {
	int num =lhs.Numerator()*rhs.Denominator()+ rhs.Numerator()*lhs.Denominator();
	int denom = lhs.Denominator()*rhs.Denominator();
	return {num, denom};


}
Rational operator-(const Rational& lhs, const Rational& rhs) {


	return {(lhs.Numerator()*rhs.Denominator()- rhs.Numerator()*lhs.Denominator()),
		lhs.Denominator()*rhs.Denominator()};

}


int main() {
/*	{
	Rational r1(1, 60000000);
	Rational r2(1, -3);
Rational r3 = r1+r2;
	cout << " num = "<<  r3.Numerator() <<" denominator = " <<  r3.Denominator() << " ";
	}
*/
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



	cout << "OK" << endl;



	return 0;
}

