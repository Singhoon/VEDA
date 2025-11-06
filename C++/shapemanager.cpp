#include "ShapeManager.h"
#include <iostream>
using namespace std;

ShapeManager::ShapeManager() {
	shapeCount = 0;
	cout << "ShapeManager 생성" << endl;
}
ShapeManager::~ShapeManager() {
	cout << "ShapeManager 소멸 (모든 도형 삭제)" << endl;
	for (int i = 0; i < shapeCount; i++) {
		delete sPtr[i];
	}
}
void ShapeManager::addShape() {
	// 배열이 꽉 찼는지 확인
	if (shapeCount >= 50) {
		cout << "배열이 꽉 찼습니다. (최대 50개)" << endl;
		return;
	}

	int type;
	cout << "추가할 도형 (1:원, 2:사각형, 3:삼각형) >> ";
	cin >> type;

	switch (type) {
	case 1: { // 원 (Circle)
		double r;
		cout << "반지름 입력 >> ";
		cin >> r;
		// sPtr 배열의 "다음 빈 칸"에 새 객체 주소를 넣음
		sPtr[shapeCount] = new Circle(r);
		break;
	}
	case 2: { // 사각형 (Rectangle)
		int w, h;
		cout << "너비와 높이 입력 >> ";
		cin >> w >> h;
		sPtr[shapeCount] = new Rectangle(w, h);
		break;
	}
	case 3: { // 삼각형 (Triangle)
		int w, h;
		cout << "밑변과 높이 입력 >> ";
		cin >> w >> h;
		sPtr[shapeCount] = new Triangle(w, h); // Triangle(w,h)가 있다고 가정
		break;
	}
	default:
		cout << "잘못된 입력입니다." << endl;
		return; // 잘못 입력했으면 카운트를 늘리지 않고 종료
	}

	// 도형이 성공적으로 추가되었으므로 카운트 1 증가
	shapeCount++;
	cout << "도형이 추가되었습니다. (현재 " << shapeCount << "개)" << endl;
}
void ShapeManager::showArea() {
	if (shapeCount == 0) {
		cout << "표시할 도형이 없습니다." << endl;
		return;
	}

	cout << "--- 모든 도형의 면적 ---" << endl;

	for (int i = 0; i < shapeCount; i++) {
		cout << "도형 " << (i + 1) << "의 면적: " << sPtr[i]->getArea() << endl;
	}
}
