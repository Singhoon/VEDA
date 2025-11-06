#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <iostream>
#include "Shape.h"
using namespace std;

class Circle : public Shape{
private:
	double radius;

public:
	Circle();
	Circle(int);
	Circle(double);
	virtual ~Circle() override;
	double get();
	void set(int);
	virtual double getArea() override;
	bool operator==(const Circle& op2);
	Circle operator+(const Circle& op2);
	Circle& operator+=(const Circle& op2);
	friend ostream& operator<<(ostream& op1, Circle& op2);
};
#endif