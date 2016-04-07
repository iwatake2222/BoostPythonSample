#include <iostream>
#include "func.h"

int getNumber()
{
	std::cout << "Hello World in C" << std::endl;
	return 123;
}

int setGetNumber(int x)
{
	std::cout << "Set " << x << std::endl;
	return x;
}

char const* getString()
{
	return "Hello from C";
}

POINT getPoint()
{
	POINT point;
	point.x=10;
	point.y=20;
	return point;
}

