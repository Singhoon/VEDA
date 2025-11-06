#include "Rectangle.h"
#include <iostream>
using namespace std;

// [ 2. 마스터 생성자 ] - 얘만 일합니다.
Rectangle::Rectangle(int w, int h) : Shape("Rectangle") {
	width = w;
	height = h;
	cout << "Rectangle 생성자" << endl;
}

// [ 1. 위임자 (기본) ]
// ★★★ 이렇게 고쳐야 합니다 ★★★
// 마스터인 Rectangle(2, 2)를 호출합니다.
Rectangle::Rectangle() : Rectangle(2, 2) {
	// 본문 비움
}

// [ 3. 위임자 (double) ]
// ★★★ 이렇게 고쳐야 합니다 ★★★
// 인자로 받은 w, h를 int로 변환하여 마스터를 호출합니다.
Rectangle::Rectangle(double w, double h) : Rectangle(static_cast<int>(w), static_cast<int>(h)) {
	// 본문 비움
}


Rectangle::~Rectangle() {
}

// ★★★ [버그 수정] ★★★
int Rectangle::getHeight() {
	return height; // width -> height로 수정
}

// ... 나머지 함수는 그대로 ...
int Rectangle::getWidth() {
	return width;
}
void Rectangle::set(int a, int b) {
	width = a;
	height = b;
}
double Rectangle::getArea() {
	return (this->width * this->height);
}

bool Rectangle::isSame(Rectangle& a) {
	if (width == a.getWidth() && height == a.getHeight()) return true;
	else return false;
}
ostream& operator<<(ostream& op1, Rectangle& op2) {
	op1 << "width : " << op2.width << ", height : " << op2.height;
	return op1;
}