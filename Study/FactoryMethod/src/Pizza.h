#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Pizza {

public:
// �� �������� ���������� ������� � �������� ����� ������� ������.
	virtual void Prepare(){} ;
	virtual string GetName(){return "basic pizza";};

};


