#pragma once
#include "Worker.h"

class Singer : virtual public Worker {
public:
	Singer() : Worker(), voice(other) {}
	Singer(const String& s, long n, int v = other) : Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {}
	void Show() const;
	void Set();
protected:
private:
	enum { other, alto, contralto, soprano, bass, baritone, tenor};
	enum {Vtypes = 7};
	static char *pv[Vtypes];
	int voice;
};
