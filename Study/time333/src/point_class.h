#pragma once

//using namespace std;

// struct Point;

class Point {
public:
	static int z;

	Point* createPoint(double x, double y);
	double getDistance( Point* other);
	void printZ();

private:
	double x;
	double y;

};


