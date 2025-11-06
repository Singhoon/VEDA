#include <iostream>

using namespace std;
// 예외 시에 어떤 데이터타입을 throw하느냐에 따라서 catch블록에서 따로 처리할 수 있다
// 예외를 미리 정의하지 못하면 catch블록의 인자로 ...을 넣으면 된다
int main() {

	try {
		int input;
		cout << "정수 중 하나를 입력하세요 : ";
		cin >> input;

		if (input > 0) {
			cout << "throw 1" << endl;
			throw 1;
			cout << "after throw 1" << endl;
		}

		if (input < 0) {
			cout << "throw -1.0f" << endl;
			throw - 1.0f;
			cout << "after throw -1.0f" << endl;
		}

		if (input == 0) {
			cout << "throw Z" << endl;
			throw 'Z';
			cout << "after throw Z" << endl;
		}
	}
	/*
	catch (int a) {
		cout << "catch " << a << endl;
	}
	catch (float b) {
		cout << "catch " << b << endl;
	}
	catch (char c) {
		cout << "catch " << c << endl;
	}
	*/
	catch (...) {
		cout << "catch all" << endl;
	}
	return 0;
}