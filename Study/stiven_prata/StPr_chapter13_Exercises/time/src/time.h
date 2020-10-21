#pragma once
#include <iostream>
#include <string>


class A1 {
public:
	 virtual void Show() { std::cout << "A" << std::endl;}
		A1(){}
		virtual ~A1(){}
	};

	class B1 : public A1 {
	public:
	B1(){}
	virtual ~B1(){}
		virtual void Show() { std::cout << "Dima" << std::endl;}
	};

