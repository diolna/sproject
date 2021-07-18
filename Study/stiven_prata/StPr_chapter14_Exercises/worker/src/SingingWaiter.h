#pragma once

#include "Singer.h"
#include "Waiter.h"

class SingingWaiter : public Singer, public Waiter {
public:
	SingingWaiter() {}
	SingingWaiter(const String &s, long n, int p= 0, int v = Singer::other):
		Worker(s,n), Waiter(s, n,  p), Singer(s, n, v) {}
	SingingWaiter(const Worker& wk, int p = 0, int v = Singer::other) : Worker(wk), Singer(wk, v), Waiter(wk, p) {}
	SingingWaiter(const Waiter & wt,  int v = Singer::other) : Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingingWaiter(const Singer& wt, int p = 0) : Worker(wt), Waiter(wt, p),Singer(wt) {}
	void Set();
	void Show() const;

protected:
	void Data() const;
	void Get();



};

