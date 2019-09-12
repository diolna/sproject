
#include <iostream>
#include <sstream>
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
ostringstream& operator<<(ostringstream& stream, const Rational& rational){

		  stream << rational.Numerator();
		  stream << "/";
		  stream << rational.Denominator();


	return stream;
}
istringstream& operator>>(istringstream& stream,  Rational& rational){

			int num;
			int denom;
			stream >> num;
			cout << "num = " << num;
			stream.ignore(1);
			stream >> denom;
			cout <<  "denom = " << denom;

			rational ={num, denom};


	return stream;
}
ostream& operator<<(ostream& stream, const Rational& rational){
	cout << rational.Numerator()<< '/' << rational.Denominator();
	return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
