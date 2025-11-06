#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

//using namespace std;

class ShapeManager {
private:
	Shape* sPtr[50];
	int shapeCount;
public:
	ShapeManager();
	~ShapeManager();
	// 1 원 2 사각형 3 삼각형
	void addShape(); // 여기서 키보드 입력 받아서 객체 생성
	void showArea();
};