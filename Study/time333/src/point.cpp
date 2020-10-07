

#include "point_class.h"
#include "math.h"
#include <iostream>

using namespace std;


  Point* Point::createPoint( double x, double y){
    Point* point = new Point;
	point->x = x;
	point->y = y;
	return point;
}

double Point::getDistance(  Point* other){
	double dx = this->x - other->x;
	double dy = this->y - other->y;

	return sqrt( dx * dx + dy * dy);
}

void Point::printZ(){

	cout << "z="  << this->z << endl;
}


