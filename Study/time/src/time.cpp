#include <iostream>
#include "point.h"

using namespace std;



int main() {

//	Point fff;
	cout << "Point" << endl;

		Point p;
	 Point* p1 = p.createPoint(3,4);
	 Point* p2 = p.createPoint(1,2);


//	 Point p;


	cout << "distance= " << p1->getDistance(p2) << endl;

	p1->z = 5;
	p2->printZ();


	return 0;
}
