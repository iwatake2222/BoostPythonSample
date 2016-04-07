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
