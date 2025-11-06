#include "Shape.h"


Shape::Shape() {
	std::cout << "Shape 생성자 함수" << std::endl;
	totalCount += 1;
}

Shape::Shape(std:: string n) {
	std::cout << "Shape 생성자 함수" << std::endl;
	//name = n;
	totalCount += 1;
}
Shape::~Shape() {
	std::cout << "Shape 소멸자 함수" << std::endl;
}
/*
void Shape::show() {
	std::cout << "Shape show 함수" << std::endl;
}
*/
/*
double Shape::getArea() {
	std::cout << "Shape getArea 함수" << std::endl;
	return 0.0;
}
*/
void Shape::showCount() {
	std::cout << totalCount << std::endl;
}