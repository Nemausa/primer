#pragma once

#include <iostream>
#include "Excerise.h"
#include <ostream>


class Base
{
public:
	virtual void f()
	{
		std::cout << "virtual Base::f()\n";
	}
};

class D1 : public Base
{
public:
	virtual void f()
	{
		std::cout << "virtual D1::f()\n";
	}
};

int main()
{
	D1 d1;
	Base *bp = &d1;
	bp->f();

	return 0;
}