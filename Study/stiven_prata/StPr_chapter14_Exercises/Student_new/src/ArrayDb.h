#pragma once

#include <iostream>

class ArrayDb {

public:
	ArrayDb();
	explicit ArrayDb(unsigned int z, double val = 0.0);
	ArrayDb(const double * n, const unsigned int s);
	ArrayDb(const ArrayDb& a);
	virtual ~ArrayDb();
	ArrayDb& operator=(const ArrayDb& a);
	friend std::ostream& operator<<(std::ostream& os, const ArrayDb& a);
	double& operator[](int i);
	const double& operator[](int i) const;
	unsigned int ArSize() const {return size; }
	double Average() const; // return the average value

private:

	double * arr;
	unsigned int size;

};
