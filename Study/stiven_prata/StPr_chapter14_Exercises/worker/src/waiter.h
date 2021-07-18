#pragma once
#include "worker.h"
#include "String.h"

class Waiter : public virtual Worker {

public:
	Waiter() : Worker(), panache(0){}
	Waiter(const String& s, long n, int p = 0) : Worker(s,n), panache(p) {}
	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {}
	void Set();
	void Show() const;
protected:
	void Data() const;
	void Get();

private:
	int panache;

};
