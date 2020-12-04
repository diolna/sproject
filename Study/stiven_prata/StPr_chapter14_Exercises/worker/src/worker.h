#pragma once
#include "String.h"

class Worker {

public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const String& s, long n) : fullname(s), id(n) {}
	virtual ~Worker() = 0 ;
	virtual void Set() = 0;
	virtual void Show() const = 0;
protected:
	virtual void Data() const;
	virtual void Get();

private:
		String fullname;
		long id;
};
