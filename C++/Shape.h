#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <iostream>

class Shape {
private :
	//std::string name = "";
public:
	Shape(std::string n);
	Shape();
	virtual ~Shape();
	//virtual void show();
	virtual double getArea() = 0;  // 가상함수 생성
	static int totalCount;
	static void showCount();
};

#endif 

