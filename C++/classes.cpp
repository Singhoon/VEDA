#include "ShapeManager.h"

// 생성자는 리턴타입이 없고 매개변수는 가질 수 있다
// 생성자 소멸자는 직접 삽입 안해도 컴파일러가 알아서 삽입해준다

int Shape::totalCount = 0;
int main() {

	ShapeManager manager; // ShapeManager 객체 1개 생성
	int choice;

	cout << "=== 도형 관리 프로그램 ===" << endl;

	// [핵심] 프로그램이 끝나지 않도록 무한 루프(while)를 돌립니다.
	while (true) {
		// 1. 메뉴 출력
		cout << "\n--- 메뉴 ---" << endl;
		cout << "1. 도형 추가" << endl;
		cout << "2. 모든 도형 면적 보기" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << "선택 >> ";

		// 2. 사용자 입력 받기
		cin >> choice;

		// 3. 입력에 따라 행동 결정 (switch)
		switch (choice) {
		case 1:
			cout << "\n[1. 도형 추가]" << endl;
			manager.addShape(); // manager 객체의 도형 추가 함수 호출
			break;

		case 2:
			cout << "\n[2. 모든 도형 면적 보기]" << endl;
			manager.showArea(); // manager 객체의 면적 보기 함수 호출
			break;

		case 0:
			cout << "\n프로그램을 종료합니다." << endl;
			// return 0;을 만나면 main 함수가 종료되고,
			// main이 끝나기 직전에 manager 객체의 소멸자(~ShapeManager)가
			// 자동으로 호출되어 모든 메모리를 정리합니다.
			return 0;

		default:
			cout << "\n[에러] 0, 1, 2 중에서 다시 입력해주세요." << endl;
			break;
		}
	}

	return 0; // (사실상 0번 메뉴 외에는 여기에 도달하지 못함)

	/*
	Circle c;

	cout << c.get() << endl;
	c.set(10);
	cout << c.get() << endl;
	cout << c.getArea() << endl;

	int n[5] = { int(1), int(2), int(3), int(4), int(5) };
	Circle cArr[5] = { Circle(1), Circle(2), Circle(3), Circle(4), Circle(5) };

	for (int i = 0; i < 5; i++) {
		//cout << n[i] << '\n';
		cout << cArr[i].get() << '\n';
	}
	Circle* p = new Circle;

	p = cArr;

	cout << p->get() << endl;
	cout << (p + 2)->get() << endl;
	cout << p[4].get() << endl;

	Circle* ptr = new Circle;

	ptr->set(100);
	cout << ptr->getArea() << endl;

	delete ptr;
	ptr = nullptr;
	*/

	/*
	int n;
	cin >> n;

	Circle* cp = new Circle[n];

	for (int i = 0; i < n; i++) {
		cout << (cp + i)->get() << endl;
	}

	delete[] cp;
	cp = nullptr;
	*/

	//Circle* pArr[] = { new Circle, new Circle(2), new Circle(3) };

	/*
	for (int i = 0; i < sizeof(pArr)/sizeof(Circle*); i++)  { // Circle* 대신에 Circle만 넣어서는 안됨
		cout << pArr[i]->get() << endl;
	}
	*/
	// delete[] pArr 안됨

	//circle객체 2개 입력받는데, 각각 radius 받아서 입력. 두 개의 circle객체가 동일한지 확인

	/*
	int n1, n2;
	cin >> n1 >> n2;

	Circle circle1 = Circle(n1); //Circle circle1(n1);
	Circle circle2 = Circle(n2); // Circle circle2(n2);

	cout << boolalpha << circle1.isSame(n2) << endl;
	//if (circle1.get() == circle2.get()) cout << "똑같음" << endl;
	// 내부에서 isSame함수를 만들어서 get함수 없이 한다. return값은 boolean이다.

	// 객체 생성 시에 Circle c(숫자); 처럼 처음에 생성할때부터 숫자를 넣어서 초기화 할 수 있다
	*/

	// rectangle 클래스도 만든다 가로 세로 있어야 되고, 가로세로가 똑같은지 확인하는 함수, 면적 구하는 함수 구현. 사각형은 사각형끼리. 원은 원끼리s

	/*
	Circle c(2);
	c.show();
	Rectangle r(5, 8);
	r.show();

	Shape* sPtr[2] = { &c, &r };// upcasting (부모클래스의 포인터로 자식클래스를 가르키는 것) <-> downcasting(자식클래스의 포인터로 부모클래스를 가르키는 것)
	for (int i = 0; i < 2; i++) {
		sPtr[i]->show();
	}
	//sPtr[0]->get();
	//sPtr[1]->getWidth();
	//sPtr[1]->getHeight();

	// 생성자는 부모 먼저, 소멸자는 자식 먼저
	*/

	/*
	Circle c(3);
	Circle c1 = c; // 복사생성자는 
	Circle c2(c);
	cout << "c2 : " << c2.get() << endl;
	cout << "c : " << c.get() << endl;
	*/

	/*
	c1 += c2;
	
	cout << "c1 : " << c1.get() << endl;
	c1 = c + c2; //반지름 더하기
	cout << c1.get() << endl;

	if (c1 == c2) cout << "same" << endl;
	else cout << "not same" << endl;
	
	
	cout << c1.get() << endl;
	*/

	/*
	Shape* sPtr[3] = { new Circle(10), new Rectangle(5, 7), new Triangle(3, 5)};
	for (int i = 0; i < 3; i++) cout << sPtr[i]->getArea() << endl;
	*/
	
	/*
	Circle c(10), c2(20);
	cout << c << " " << c2 << endl;
	
	
	Rectangle r(2, 2), r2(4, 4);
	cout << r << "\n" << r2 << endl;

	Triangle t(3, 4), t2(4, 5);
	cout << t << "\n" << t2 << endl;
	*/

	/*
	Shape::showCount();
	Circle c(10);
	Shape::showCount();
	Triangle t(3, 4);
	Shape::showCount();
	*/
}