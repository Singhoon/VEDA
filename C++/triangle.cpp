#include "Triangle.h"

Triangle::Triangle():base(1),height(1),Shape("Triangle") {

}
Triangle::Triangle(int base, int height):Shape("Triangle") {
	this->base = base;
	this->height = height;
}
Triangle::~Triangle() {
	
}
double Triangle::getArea() {
	return (this->base * this->height)/2;
}
ostream& operator<<(ostream& op1, Triangle& op2) { 
	op1 << "base : " << op2.base << ", height : " << op2.height; 
	return op1;
}
