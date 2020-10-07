#include <iostream>
#include "stringbad.h"

void callmy1(StringBad &);
void callmy2(StringBad);

int main() {

	StringBad headline1("Celery Stalks at Mitnight");
	StringBad headline2("Lattuce Prey");
	StringBad sports("Spinach Leaves Bowl for Dollars");
	std::cout << "headline1: " << headline1 << std::endl;
	std::cout << "headline2: " << headline2 << std::endl;
	std::cout << "sports: " <<sports << std::endl;
	callmy1(headline1);
	std::cout << "headline1: " << headline1 << std::endl;
	callmy2 (headline2);
	std::cout << "headline2: " << headline2 << std::endl;
	std::cout << "Initialize one object to another:\n";
	StringBad sailor = sports;
	std::cout << "sailor: " << sailor << std::endl;
	std::cout << "Assign one object to another:\n";
	StringBad knot;
	knot = headline1;
	std::cout << "knot: " << knot << std::endl;
	std::cout << "End of main()\n";

	return 0;
}


void callmy1(StringBad& rsb){
	std::cout << "String passed by reference:\n";
	std::cout << "     \"" << rsb << " \"\n";

}
void callmy2(StringBad sb){
	std::cout << "String passed by value:\n";
	std::cout << "   \"" << sb << "\"\n";
}
