# Call C++ code from Python using Boost.Python
* Call the following modules written in C++ from Python
	* simple function
	* function returning struct
	* class
	* class function returning struct
	* class function returning enum

## Library needed
```
sudo apt install libboost-all-dev
```

## Build command
```
g++ -I/usr/include/python2.7 -fPIC -shared -o MyModule.so func.cpp ClassA.cpp MyModule.cpp -lboost_python

```

## Python Code
```
import MyModule

# simple functions
print MyModule.getNumber()
print MyModule.setGetNumber(4)
print MyModule.getString()

# struct
point = MyModule.getPoint()
print point.x

# class
classA = MyModule.ClassA( 55 )
print classA.a
print classA.getA();

# struct in class
vector = classA.getVector();
print vector.x

# enum in class
print classA.setGetColor(MyModule.ClassA_COLOR.RED);

```

## C++ Code
* MyModule.cpp
```
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python.hpp>
#include "func.h"
#include "ClassA.h"

using namespace boost::python;

BOOST_PYTHON_MODULE( MyModule )
{
	boost::python::def( "getNumber", getNumber );
	boost::python::def( "setGetNumber", setGetNumber );
	boost::python::def( "getString", getString );
	boost::python::def( "getPoint", getPoint );
	class_<POINT>("POINT", init<>())
		.add_property("x", &POINT::x)
		.add_property("y", &POINT::y)
	;

	class_<ClassA::VECTOR_2D>("ClassA::VECTOR_2D", init<>())
		.add_property("x", &ClassA::VECTOR_2D::x)
		.add_property("y", &ClassA::VECTOR_2D::y)
	;

	enum_<ClassA::COLOR>("ClassA_COLOR")
		.value("RED", ClassA::RED)
		.value("GREEN", ClassA::GREEN)
		.value("BLUE", ClassA::BLUE)
	;


	class_<ClassA>("ClassA", init<int>())
		.add_property("a", &ClassA::a)
		.def("getA", &ClassA::getA)
		.def("getVector", &ClassA::getVector)
		.def("setGetColor", &ClassA::setGetColor)
	;

}
```

* func.h
```
typedef struct 
{
	int x;
	int y;
} POINT;


int getNumber();
int setGetNumber(int x);
char const* getString();
POINT getPoint();
```

* func.cpp
```
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
```

* ClassA.h
```
#ifndef CLASS_A_H
#define CLASS_A_H

class ClassA {
public:
	typedef enum {
		RED   = 0,
		GREEN = 1,
		BLUE  = 2,
	} COLOR;

	typedef struct {
		int x;
		int y;
	} VECTOR_2D;

public:
	ClassA(int a);
	int a;
	int getA();
	VECTOR_2D getVector();
	COLOR setGetColor(COLOR color);
};

#endif /* CLASS_A_H */
```

* ClassA.cpp
```
#include "ClassA.h"

ClassA::ClassA(int _a) {
	a = _a;
}

int ClassA::getA() {
	return a;
}

ClassA::VECTOR_2D ClassA::getVector() {
	VECTOR_2D vector2D;
	vector2D.x = 3;
	vector2D.y = 4;
	return vector2D;
}


ClassA::COLOR ClassA::setGetColor(ClassA::COLOR color) {
	return color;
}
```
