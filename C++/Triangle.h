#pragma once
#include "Shape.h"
#define _CIRCLE_H_
using namespace std;

class Triangle : public Shape { // public 안적으면 private
	int base = 1; // 생성자에서 초기화 해도 됨
	int height = 1;

public:
	Triangle();
	Triangle(int base, int height);
	virtual ~Triangle() override;
	virtual double getArea() override;
	friend ostream& operator<<(ostream& op1, Triangle& op2);
};