#include "Circle.h"

Circle::Circle(double r) : Shape("Circle") {
	//name = "Circle";
	radius = r;
	cout << "Circle 생성자" << endl;
}
Circle::Circle() :Circle(1.0) {
	//name = "Circle";
	//radius = a;
	//cout << "Circle 생성자" << endl;
}
Circle::Circle(int r) : Circle(static_cast<double>(r)) {
	//name = "Circle";
	//radius = a;
	//cout << "Circle 생성자" << endl;
}
Circle::~Circle() {
}
double Circle::get() {
	return radius;
}
void Circle::set(int r) {
	radius = r;
}
double Circle::getArea() {
	return (this->radius * this->radius * 3.14);
}
bool Circle::operator==(const Circle& op2) {
	if (this->radius == op2.radius) return true;
	else return false;
}
Circle Circle::operator+(const Circle& op2) {
	Circle temp;
	temp.radius = this->radius + op2.radius;
	return temp;
}
Circle& Circle::operator+=(const Circle& op2) {
	this->radius = this->radius + op2.radius;
	return *this;
}

ostream& operator<<(ostream& op1, Circle& op2) { //cout은 이항연산자라서 두 개의 인자를 받는다. cout은 otream 객체이다
	op1 << op2.radius; // radius는 Circle 클래스의 private한 영역이기 때문에 friend 키워드를 지정해야 한다
	return op1;
}