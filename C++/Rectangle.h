#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

// #include <iostream>      // <-- .h 파일에선 불필요
// #include <stdbool.h>     // <-- C++에선 불필요
#include "Shape.h"

using namespace std; // <-- 헤더 파일에서는 절대 사용하지 마세요.

class Rectangle : public Shape {
private:
	int width, height;

public:
	Rectangle();
	Rectangle(int w = 2, int h = 2);              // <-- 1. 여기에 기본값 추가
	Rectangle(double w = 2.0, double h = 2.0);  // <-- (변수명 'a', 'b' 대신 'w', 'h'로)
	virtual ~Rectangle() override;
	int getWidth();
	int getHeight();
	void set(int w = 2, int h = 2);               // <-- 1. 여기에 기본값 추가
	virtual double getArea() override;

	// (팁) 객체를 통째로 복사하는 것보다 const 참조(&)로 받는 것이 훨씬 효율적입니다.
	bool isSame(Rectangle& a);            // bool isSame(Rectangle a); 보다 좋음

	friend ostream& operator<<(ostream& op1, Rectangle& op2);
};

#endif