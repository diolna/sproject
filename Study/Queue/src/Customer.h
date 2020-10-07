#pragma once

class Customer {
public:
	Customer() {arrive = processtime = 0;}
	void set(long when);
	long when() const {return arrive;}
	int ptime() const {return processtime;}
 private:
	long arrive;  // time arrive client
	int processtime; // time processing client
};
